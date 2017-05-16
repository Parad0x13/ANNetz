cmake_minimum_required(VERSION 3.6)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ANNetz)

file(GLOB ANNetz_SRC
	"src/*.h"
	"src/*.cpp"
)

project(ANNetz)
add_executable(ANNetz ${ANNetz_SRC})