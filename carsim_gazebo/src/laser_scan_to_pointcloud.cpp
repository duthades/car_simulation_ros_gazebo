//http://answers.ros.org/question/11232/how-to-turn-laser-scan-to-point-cloud-map/
//http://wiki.ros.org/laser_geometry
//http://wiki.ros.org/laser_pipeline/Tutorials/IntroductionToWorkingWithLaserScannerData
//https://github.com/ros-perception/laser_assembler/tree/hydro-devel/test
//http://wiki.ros.org/laser_geometry


#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <laser_geometry/laser_geometry.h>

class My_Filter {
     public:
        My_Filter();
        void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan);
     private:
        ros::NodeHandle node_;
        laser_geometry::LaserProjection projector_;
        tf::TransformListener tfListener_;

        ros::Publisher point_cloud_publisher_;
        ros::Subscriber scan_sub_;
};

My_Filter::My_Filter(){
        scan_sub_ = node_.subscribe<sensor_msgs::LaserScan> ("/carsim/laser/scan", 100, &My_Filter::scanCallback, this);
        point_cloud_publisher_ = node_.advertise<sensor_msgs::PointCloud2> ("/cloud", 100, false);
        tfListener_.setExtrapolationLimit(ros::Duration(0.1));
}

void My_Filter::scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan){
    sensor_msgs::PointCloud2 cloud;
    projector_.transformLaserScanToPointCloud("base_link", *scan, cloud, tfListener_);
    point_cloud_publisher_.publish(cloud);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "my_filter");

    My_Filter filter;

    ros::spin();

    return 0;
}


/*tfListener_.waitForTransform("hokuyo_link", "world",
                                     scan->header.stamp + ros::Duration().fromSec(scan->ranges.size()*scan->time_increment),
                                     ros::Duration(2.5))
*/
