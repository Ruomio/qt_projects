# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/OpenHash_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/OpenHash_autogen.dir/ParseCache.txt"
  "OpenHash_autogen"
  )
endif()
