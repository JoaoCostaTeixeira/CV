cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
add_executable( ex20 ex20.cpp )
target_link_libraries( ex20 ${OpenCV_LIBS} )

