cmake_minimum_required(VERSION 3.24)
project(argent)

#####
# Optional values to change per project.
#####

option(ARGENT_WINDOW_USE_GLFW CACHE ON)
option(ARGENT_DRIVER_USE_OPENGL CACHE ON)
option(ARGENT_DRIVER_USE_VULKAN CACHE ON)
option(ARGENT_DRIVER_USE_DX11 CACHE ON)

#####
# Depending on the system, certain options must be off.
#####

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
  
# DX11 is not available on Linux.
  if (ARGENT_DRIVER_USE_DX11)
    set(ARGENT_DRIVER_USE_DX11 OFF)
    message(STATUS "ARGENT LINUX: Cannot use DX11 on Linux, this driver will be automatically shut off.")
  endif()

endif()


#####
# Log info about what argent is going to do.
#####

message(STATUS "Argent Options:")
message("\tARGENT_WINDOW_USE_GLFW = ${ARGENT_WINDOW_USE_GLFW}")
message("\tARGENT_DRIVER_USE_OPENGL = ${ARGENT_DRIVER_USE_OPENGL}")
message("\tARGENT_DRIVER_USE_VULKAN = ${ARGENT_DRIVER_USE_VULKAN}")
message("\tARGENT_DRIVER_USE_DX11 = ${ARGENT_DRIVER_USE_DX11}")

#####
# Find required libraries we are using.
#####

find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)

#####
# Build libraries.
#####
add_subdirectory("libs")

#####
# Determine sources for argent based on options.
#####

set(argentSources "")

if (ARGENT_DRIVER_USE_OPENGL)
  list(APPEND argentSources
    "src/GL/InstanceGL.cpp")
endif()

add_library(argent STATIC ${argentSources})

#####
# Argent set target include directories.
#####

target_include_directories(argent PUBLIC "src/")

#####
# Link libraries for argent.
#####

target_link_libraries(argent glad)