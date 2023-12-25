# How to use:
#   mkdir build
#   cd build
#   cmake ..
#   make
#
cmake_minimum_required(VERSION 3.10)
 
project(POD-MAP
  VERSION 0.1.0
)
 
find_package(gf REQUIRED)
 
add_executable(client
  src/client/client.cc
  src/maplogic/map.cc
  src/maplogic/map_saver.cc
  # and the rest of your sources
)

add_executable(map_test
    src/maplogic/map_test.cc
    src/maplogic/map.cc
    src/maplogic/map_saver.cc
    # and the rest of your sources
)

target_link_libraries(client
  PRIVATE
    gf::graphics
    gf::net
    
)
