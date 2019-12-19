set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# ##############################################################################
# SOURCE FILES
# ##############################################################################
set(SOURCES core.cpp application.cpp)

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
endif()

# ##############################################################################
# ALIASING
# ##############################################################################
if(BUILD_SHARED_LIBS)
  add_library(forma ALIAS forma_shared)
elseif(BUILD_STATIC_LIBS)
  add_library(forma ALIAS forma_static)
endif()
