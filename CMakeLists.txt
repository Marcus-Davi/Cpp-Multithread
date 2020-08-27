cmake_minimum_required(VERSION 3.8) #CMake Version
project (multithreading) #Project Name

find_package(OpenMP)

#set (Eigen3_DIR /home/projeto/Workspace/Coding/C++/Eigen/cmake) #Manually set Directory for Package

#find_package(Eigen3 3.3 REQUIRED PATHS /home/projeto/Workspace/Coding/C++/Eigen/cmake)  # Find Package

message(WARNING ${Eigen3_DIR}) # Send Message

#file(GLOB SOURCES "src/*.cpp") # Tell where are the source files (automatic)

#set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin) #executables in SRC/bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) #executables in SRC/build/bin


set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #Useful for YCM (vim autocomplete plugin, not essential)
add_executable(multithread src/mthread.cpp) #Add Executable
add_executable(openMP src/openMP.cpp)

#target_include_directories(project_name PUBLIC include)  # Project Including
#include_directories(${PCL_INCLUDE_DIRS}) # General Include

#target_link_libraries(project_name Eigen3::Eigen) # Project Linking
#link_directories(${PCL_LIBRARY_DIRS}) # General Linking
target_link_libraries(multithread pthread)
target_link_libraries(openMP PUBLIC OpenMP::OpenMP_CXX)

# Create Symlink for compile commands for YCM
if(CMAKE_EXPORT_COMPILE_COMMANDS)
		message(STATUS "compile commands ON")
	set(comp_file "compile_commands.json")
	execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${PROJECT_BINARY_DIR}/${comp_file} ${CMAKE_SOURCE_DIR}/src/${comp_file})

	else()
			message(STATUS "compile commands OFF")
	endif()


#PCL Example (from website)
#cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
#project(MY_GRAND_PROJECT)
#find_package(PCL 1.3 REQUIRED COMPONENTS common io)
#include_directories(${PCL_INCLUDE_DIRS})
#link_directories(${PCL_LIBRARY_DIRS})
#add_definitions(${PCL_DEFINITIONS})
#add_executable(pcd_write_test pcd_write.cpp)
#target_link_libraries(pcd_write_test ${PCL_LIBRARIES})
