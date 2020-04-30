cmake_minimum_required(VERSION 3.8) #CMake Version
project (multithread) #Project Name

#set (Eigen3_DIR /home/projeto/Workspace/Coding/C++/Eigen/cmake) #Manually set Directory for Package

#find_package(Eigen3 3.3 REQUIRED PATHS /home/projeto/Workspace/Coding/C++/Eigen/cmake)  # Find Package

message(WARNING ${Eigen3_DIR}) # Send Message

file(GLOB SOURCES "src/*.cpp") # Tell where are the source files (automatic)

#set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin) #executables in SRC/bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) #executables in SRC/build/bin


set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #Useful for YCM (vim autocomplete plugin, not essential)
add_executable(multithread ${SOURCES}) #Add Executable

#target_include_directories(project_name PUBLIC include)  # Project Including
#include_directories(${PCL_INCLUDE_DIRS}) # General Include

#target_link_libraries(project_name Eigen3::Eigen) # Project Linking
#link_directories(${PCL_LIBRARY_DIRS}) # General Linking
target_link_libraries(multithread pthread)

#PCL Example (from website)
#cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
#project(MY_GRAND_PROJECT)
#find_package(PCL 1.3 REQUIRED COMPONENTS common io)
#include_directories(${PCL_INCLUDE_DIRS})
#link_directories(${PCL_LIBRARY_DIRS})
#add_definitions(${PCL_DEFINITIONS})
#add_executable(pcd_write_test pcd_write.cpp)
#target_link_libraries(pcd_write_test ${PCL_LIBRARIES})
