# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles\\SubscriptionManagement_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SubscriptionManagement_autogen.dir\\ParseCache.txt"
  "SubscriptionManagement_autogen"
  )
endif()
