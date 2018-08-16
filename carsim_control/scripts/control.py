#!/usr/bin/env python
import rospy
from std_msgs.msg import Float64

# Starts a new node
rospy.init_node('car_controller', anonymous=True)
topic_right = '/carsim/rightWheel_effort_controller/command'
topic_left = '/carsim/leftWheel_effort_controller/command'
right_publisher = rospy.Publisher(topic_right, Float64, queue_size=10)
left_publisher = rospy.Publisher(topic_left, Float64, queue_size=10)


def straight():
    right_publisher.publish(50)
    left_publisher.publish(50)


def leftTurn():
    pass


def rightTurn():
    pass


def stop():
    right_publisher.publish(0)
    left_publisher.publish(0)


def plan_route():

    #  velocity_publisher.publish(vel_msg)

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        right_publisher.publish(300)
        left_publisher.publish(-300)
        rate.sleep()

        # Loop to move the turtle in an specified distance
        # while(temp < distance):

        # velocity_publisher.publish(vel_msg)
        # temp =+1

        # After the loop, stops the robot


if __name__ == '__main__':
    try:
        # Testing our function
        plan_route()
    except rospy.ROSInterruptException:
        pass
