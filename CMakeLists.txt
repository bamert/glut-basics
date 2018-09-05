cmake_minimum_required(VERSION 3.2)

project(glut-basics CXX)
# Use C++11 features.
set (REQ_CPP11_FEATURES  cxx_strong_enums cxx_auto_type)

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#to find our own Find file for EGL
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")


find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})

if(UNIX AND NOT APPLE)
  set(LINUX TRUE)
endif()

#only enable parallel/algorithm(based on openMP) for the gnu parallel sort on linux.
set(CMAKE_C_COMPILER gcc-5)
set(CMAKE_CXX_COMPILER g++-5)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wno-everything -Wno-deprecated-declarations -framework GLUT -framework OpenGL -msse4.2 ")

add_executable(window window.cpp)
target_link_libraries(window ${GLUT_LIBRARIES} )

add_executable(mouse mouse.cpp)
target_link_libraries(mouse ${GLUT_LIBRARIES} )

