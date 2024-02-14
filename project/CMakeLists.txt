# MIT License 
# Copyright (c) 2018-Today Michele Adduci <adduci@tutanota.com>
#
# Project-related instructions

# Activate Testing, if given
if(BUILD_TESTING)
  enable_testing()
endif()

#####################################
# Define Targets
#####################################
add_subdirectory(PingPong)

#####################################
# Define Install Targets
#####################################
install(TARGETS
  PingPong
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  PUBLIC_HEADER DESTINATION include
)

install(
  FILES 
    ${CMAKE_SOURCE_DIR}/project/TinyRenderer/include/TinyRenderer.h 
    ${CMAKE_BINARY_DIR}/exports/TinyRenderer_export.h
  DESTINATION 
    include/TinyRenderer)

install(FILES  
  ${CMAKE_SOURCE_DIR}/LICENSE
DESTINATION .)