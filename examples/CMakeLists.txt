# ##############################################################################
# BUILD MACRO
# ##############################################################################
macro(subdir_list result curdir)
  file(
    GLOB children
    RELATIVE ${curdir}
    ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()

subdir_list(EXAMPLES "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
foreach(EXAMPLE ${EXAMPLES})
  file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR} "${EXAMPLE}/*.cpp")
  add_executable(${EXAMPLE} ${SRC_FILES})
  target_link_libraries(${EXAMPLE} forma)
endforeach()
