# ##############################################################################
# PROJECT
# ##############################################################################
cmake_minimum_required(VERSION 3.0.0)
project(Forma VERSION 0.1.1)
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(MAIN_PROJECT TRUE)
endif()

# ##############################################################################
# OPTIONS
# ##############################################################################
option(BUILD_SHARED_LIBS "Compile shared libraries" TRUE)
option(BUILD_STATIC_LIBS "Compile static libraries" TRUE)
option(BUILD_EXAMPELS "Compile included examples" ${MAIN_PROJECT})
set(FORMA_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(FORMA_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# ##############################################################################
# BUILD MODE
# ##############################################################################
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE
      "Debug"
      CACHE STRING "Build Mode" FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
  if(EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
              ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
              ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json)
  endif()
endif()

# ##############################################################################
# DEPENDENCIES
# ##############################################################################

# ##############################################################################
# LIBRARY
# ##############################################################################
add_subdirectory(src)

# ##############################################################################
# EXAMPLES
# ##############################################################################
add_subdirectory(examples)

# ##############################################################################
# PACKAGING
# ##############################################################################
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
