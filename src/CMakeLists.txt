set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${FORMA_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${FORMA_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${FORMA_BINARY_DIR})

# # ##############################################################################
# # DEPENDENCIES
# # ##############################################################################
# add_subdirectory(${FORMA_SOURCE_DIR}/extern ${FORMA_BINARY_DIR}/extern)

# ##############################################################################
# SOURCE FILES
# ##############################################################################
set(SOURCES core.cpp application.cpp)
configure_file("${FORMA_SOURCE_DIR}/include/forma/version.hpp.in"
               "${FORMA_SOURCE_DIR}/include/forma/version.hpp")

# ##############################################################################
# STATIC TARGET
# ##############################################################################
if(BUILD_STATIC_LIBS)
  add_library(forma_static STATIC ${SOURCES})
  add_library(forma::static ALIAS forma_static)
  target_include_directories(forma_static PUBLIC ${FORMA_SOURCE_DIR}/include)
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

  target_link_libraries(forma_shared PUBLIC spdlog)
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
