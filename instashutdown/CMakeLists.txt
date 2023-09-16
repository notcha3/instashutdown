# CMakeList.txt : CMake project for instashutdown, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (instashutdown "instashutdown.c" "instashutdown.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET instashutdown PROPERTY CXX_STANDARD 14)
endif()

# TODO: Add tests and install targets if needed.
