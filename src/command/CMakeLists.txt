add_library(command
commands.cpp
commands.h
flow.cpp
functions.cpp
math.cpp
operators.cpp
other.cpp
)

include_directories(
../
${CMAKE_SOURCE_DIR}
${CMAKE_BINARY_DIR}
${CMAKE_BINARY_DIR}/src
)
