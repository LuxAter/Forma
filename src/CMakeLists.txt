set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${FORMA_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${FORMA_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${FORMA_BINARY_DIR})

# ##############################################################################
# SOURCE FILES
# ##############################################################################
set(SOURCES core.cpp application.cpp log.cpp layer.cpp layer_stack.cpp)
if(MSVC
   OR MSYS
   OR MINGW
   OR WIN32)
  list(APPEND SOURCES platform/windows/windows_window.cpp)
elseif(APPLE)
  list(APPEND SOURCES platform/apple/apple_window.cpp)
elseif(UNIX AND NOT APPLE)
  list(APPEND SOURCES platform/linux/linux_window.cpp)
endif()
configure_file("${FORMA_SOURCE_DIR}/include/forma/version.hpp.in"
               "${FORMA_SOURCE_DIR}/include/forma/version.hpp")

# ##############################################################################
# STATIC TARGET
# ##############################################################################
if(BUILD_STATIC_LIBS)
  add_library(forma_static STATIC ${SOURCES})
  add_library(forma::static ALIAS forma_static)
  target_include_directories(forma_static PUBLIC ${FORMA_SOURCE_DIR}/include)

  set_target_properties(
    forma_static
    PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)

  target_link_libraries(forma_static PUBLIC spdlog::spdlog)
  target_link_libraries(forma_static PUBLIC fmt::fmt)
  target_link_libraries(forma_static PUBLIC glfw)
endif()

# ##############################################################################
# SHARED TARGET
# ##############################################################################
if(BUILD_SHARED_LIBS)
  add_library(forma_shared SHARED ${SOURCES})
  add_library(forma::shared ALIAS forma_shared)
  target_include_directories(forma_shared PUBLIC ${FORMA_SOURCE_DIR}/include)

  set_target_properties(
    forma_shared
    PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)

  target_link_libraries(forma_shared PUBLIC spdlog::spdlog)
  target_link_libraries(forma_shared PUBLIC fmt::fmt)
  target_link_libraries(forma_shared PUBLIC glfw)
endif()

# ##############################################################################
# ALIASING
# ##############################################################################
if(BUILD_SHARED_LIBS)
  add_library(forma ALIAS forma_shared)
  add_library(forma::forma ALIAS forma_shared)
elseif(BUILD_STATIC_LIBS)
  add_library(forma ALIAS forma_static)
  add_library(forma::forma ALIAS forma_static)
endif()
