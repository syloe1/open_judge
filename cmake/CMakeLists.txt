#Minimum CMake version required
cmake_minimum_required (VERSION 2.8)

#Project name and version
project(app)

#Find all source files in the current directory
aux_source_directory(. DIR_SRCS)

#Specify the generation target
add_executable(app ${DIR_SRCS})
