#include "laser_geometry/laser_geometry.h"
#include "message_filters/subscriber.h"
#include "ros/ros.h"
#include "sensor_msgs/PointCloud.h"
#include "tf/message_filter.h"
#include "tf/transform_listener.h"

class LaserScanToPointCloud {
   public:
    ros::NodeHandle n_;
    laser_geometry::LaserProjection projector_;
    tf::TransformListener listener_;
    message_filters::Subscriber<sensor_msgs::LaserScan> laser_sub_;
    tf::MessageFilter<sensor_msgs::LaserScan> laser_notifier_;
    ros::Publisher scan_pub_;

    LaserScanToPointCloud(ros::NodeHandle n)
        : n_(n),
          laser_sub_(n_, "/carsim/laser/scan", 10),
          laser_notifier_(laser_sub_, listener_, "base_link", 10) {
        laser_notifier_.registerCallback(
            boost::bind(&LaserScanToPointCloud::scanCallback, this, _1));
        laser_notifier_.setTolerance(ros::Duration(0.01));
        scan_pub_ = n_.advertise<sensor_msgs::PointCloud>("/cloud", 1);
    }

    void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan_in) {
        sensor_msgs::PointCloud cloud;
        try {
            projector_.transformLaserScanToPointCloud("base_link", *scan_in,
                                                      cloud, listener_);
        } catch (tf::TransformException& e) {
            std::cout << e.what();
            return;
        }

        // Do something with cloud.

        scan_pub_.publish(cloud);
    }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "my_scan_to_cloud");
    ros::NodeHandle n;
    LaserScanToPointCloud lstopc(n);

    ros::spin();

    return 0;
}
