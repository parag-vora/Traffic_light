# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appTraffic_light_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appTraffic_light_autogen.dir\\ParseCache.txt"
  "appTraffic_light_autogen"
  )
endif()
