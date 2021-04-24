cmake_minimum_required(VERSION "3.18.3")

set(CMAKE_CXX_VERSION 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -pedantic")

project("tema2")

file(GLOB_RECURSE SOURCES "source/*.cpp")

add_executable("${PROJECT_NAME}" "source/Main.cpp" "${SOURCES}")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "Main.cpp" DESTINATION src)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries("${PROJECT_NAME}" ${OpenCV_LIBS})
