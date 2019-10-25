include_directories(${CMAKE_SOURCE_DIR}/deps/)

set(SOURCES
  main.cpp
  ../deps/tinytiffreader.cpp
  )

add_executable(dem2mesh ${SOURCES})

