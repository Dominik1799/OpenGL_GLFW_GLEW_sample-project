cmake_minimum_required(VERSION 3.14)
project(OpenGL_GLFW_GLEW_sample-project)

set(CMAKE_CXX_STANDARD 14)
find_package (OpenGL REQUIRED)

# GLFW veci
include_directories("dependencies/GLFW/include")
link_directories("dependencies/GLFW/lib-mingw-w64")
#find_package (glfw3 REQUIRED)


# GLEW veci
# Settings -> Build,Execution, Deployment -> Cmake -> Cmake options : -DGLEW_STATIC=1
# ano aj s tym Dckom na zaciatku
include_directories("dependencies/GLEW/include")
link_directories("dependencies/GLEW/lib/Release/x64")
if (GLEW_STATIC)
    add_definitions(-DGLEW_STATIC=1)
endif (GLEW_STATIC)


set(SOURCE_FILES main.cpp)
add_executable(OpenGL_GLFW_GLEW_sample-project ${SOURCE_FILES})
target_link_libraries (OpenGL_GLFW_GLEW_sample-project ${OPENGL_LIBRARIES} glfw3 glu32 opengl32 glew32)