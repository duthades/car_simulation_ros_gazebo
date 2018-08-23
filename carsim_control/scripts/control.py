#!/usr/bin/env python
import rospy
from std_msgs.msg import Float64

# Starts a new node
rospy.init_node('car_controller', anonymous=True)
topic_right = '/carsim/rightWheel_effort_controller/command'
topic_left = '/carsim/leftWheel_effort_controller/command'
right_publisher = rospy.Publisher(topic_right, Float64, queue_size=1)
left_publisher = rospy.Publisher(topic_left, Float64, queue_size=1)


def straight():
    right_publisher.publish(50)
    left_publisher.publish(50)


def leftTurn():
    right_publisher.publish(200)
    left_publisher.publish(-400)


def rightTurn():
    right_publisher.publish(-200)
    left_publisher.publish(200)


def stop():
    right_publisher.publish(0)
    left_publisher.publish(0)


def plan_route():

    #  velocity_publisher.publish(vel_msg)

    rate = rospy.Rate(60)
    while not rospy.is_shutdown():
        for i in range(30):
            straight()
            rate.sleep()
        for i in range(20):
            stop()
            rate.sleep()
        for i in range(20):
            leftTurn()
            rate.sleep()
        stop()
        break
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
