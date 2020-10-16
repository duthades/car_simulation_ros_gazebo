[![Build Status](https://travis-ci.org/duthades/car_simulation_ros_gazebo.svg?branch=master)](https://travis-ci.org/duthades/car_simulation_ros_gazebo)
# car_simulation_ros_gazeb

A car simulation in a world using ROS and Gazebo.

[![A car with laser in a Gazebo world using ROS.
](https://yt-embed.herokuapp.com/embed?v=NQIqbieW0SM)](https://www.youtube.com/watch?v=NQIqbieW0SM "A car with laser in a Gazebo world using ROS.")



## Building the package
### Path for ROS workspace
```
$ WORKSPACE=~/catkin_ws
$ source ~/.bashrc
```

### Create catkin workspace
```
$ mkdir -p ~/$WORKSPACE/src
$ cd ~/$WORKSPACE/
$ catkin_make
$ source devel/setup.bash
$ sh -c "echo 'source $WORKSPACE/devel/setup.bash' >> ~/.bashrc"
```
### Cloning packages
```
$ cd $WORKSPACE/src
$ git clone https://github.com/duthades/car_simulation_ros_gazebo.git
```
### Installing Dependencies
```
$ sudo apt-get update
$ sudo apt-get install ros-melodic-laser-assembler ros-melodic-laser-geometry ros-melodic-pcl-ros ros-melodic-cmake-modules
$ sudo apt-get install libpcl1
$ source /opt/ros/melodic/setup.bash
```
### Compile the workspace
```
$ cd $WORKSPACE
$ catkin_make
$ source devel/setup.bash
```

## Running Simulation
Rviz:
```
roslaunch carsim_gazebo rviz.launch
```
Gazebo:
```
roslaunch carsim_gazebo carsim.launch
```
Laser Assembler
```
roslaunch carsim_gazebo assembler.launch
```
Keyboard Teleop:
```
rosrun carsim_gazebo teleop.py
```

## Acknowledgments and References
https://github.com/behnamasadi/laser_assembler

https://github.com/ayushgaud/gazebo_cars

http://gazebosim.org/tutorials?tut=ros_gzplugins

