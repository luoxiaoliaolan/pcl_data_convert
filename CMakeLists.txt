cmake_minimum_required(VERSION 3.20)
project(pcl_data_convert)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PCL REQUIRED COMPONENTS )

find_package(Boost REQUIRED COMPONENTS system filesystem)

include_directories(/usr/local/include/gflags/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${PCL_INCLUDE_DIRS}
                    ${CMAKE_CURRENT_SOURCE_DIR}/utils
                    ${CMAKE_CURRENT_SOURCE_DIR}/utils/io
                    ${Boost_INCLUDE_DIRS})



file(GLOB SRC_LIST ${PROJECT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/utils/io/*.cc)


add_executable(${PROJECT_NAME} ${SRC_LIST} include/point_types.h)

target_link_libraries(${PROJECT_NAME}
                    ${PCL_IO_LIBRARIES}
                    ${Boost_LIBRARIES}
                    gflags
                    glog)
