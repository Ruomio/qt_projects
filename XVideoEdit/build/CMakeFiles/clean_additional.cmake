# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/XVideoEdit_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/XVideoEdit_autogen.dir/ParseCache.txt"
  "XVideoEdit_autogen"
  )
endif()
