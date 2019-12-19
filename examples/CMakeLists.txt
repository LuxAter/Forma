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
  list(LENGTH SRC_FILES FILE_COUNT)
  if(${FILE_COUNT} EQUAL 0)
    message(WARNING "No source files for ${EXAMPLE}")
  else()
    add_executable(${EXAMPLE} ${SRC_FILES})
    target_link_libraries(${EXAMPLE} forma)
  endif()
endforeach()
