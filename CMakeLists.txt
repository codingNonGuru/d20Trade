cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE None)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -fpermissive -g -w")

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Source)

file(GLOB_RECURSE SOURCE_FILES
	"${PROJECT_SOURCE_DIR}/*.cpp"
)

include_directories(/home/andrei/Documents/Code/Libraries/glm)
include_directories(/home/andrei/Documents/Code/Libraries/FlumenCore)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

link_directories(/home/andrei/Documents/Code/Libraries/FlumenCore)

project (d20Trade)
 
add_executable(d20Trade ${SOURCE_FILES})

target_link_libraries(d20Trade pthread Core)