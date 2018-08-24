cmake_minimum_required(VERSION 2.8.3)
project(carsim_gazebo)
set(CMAKE_BUILD_TYPE Debug)

find_package(cmake_modules REQUIRED)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
  laser_geometry
)
find_package(PCL 1.6 REQUIRED COMPONENTS common apps)

catkin_package()

include_directories(${PCL_INCLUDE_DIRS} ${EIGEN_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)




MESSAGE("######################################################################PCL#####################################################################")
MESSAGE("PCL_FOUND:" ${PCL_FOUND})
MESSAGE("PCL_INCLUDE_DIRS:" ${PCL_LIBRARY_DIRS})
MESSAGE("PCL_LIBRARIES:" ${PCL_LIBRARIES})
MESSAGE("PCL_LIBRARY_DIRS:" ${PCL_LIBRARY_DIRS})
MESSAGE("PCL_VERSION:" ${PCL_VERSION})
MESSAGE("PCL_COMPONENTS:" ${PCL_COMPONENTS})
MESSAGE("PCL_DEFINITIONS:" ${PCL_DEFINITIONS})


MESSAGE("######################################################################catkin#####################################################################")
MESSAGE("catkin_LIBRARIES: " ${catkin_LIBRARIES})



add_executable(laser_assembler src/laser_assembler.cpp )
target_link_libraries(laser_assembler  ${catkin_LIBRARIES}  ${PCL_LIBRARIES}  )
