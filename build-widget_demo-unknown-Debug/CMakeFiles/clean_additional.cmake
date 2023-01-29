# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/widget_demo_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/widget_demo_autogen.dir/ParseCache.txt"
  "widget_demo_autogen"
  )
endif()
