cmake_minimum_required(VERSION 3.11)

project (
  use-librtidevice
  VERSION 0.1)

find_package (
  librtidevice REQUIRED
  PATHS "/home/alexander/iue/cdr/rti-3-tmp/build/"
  )


###### TMP
#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pg")
#SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -pg")


add_executable ( run
  "src/main.cpp"
  )
target_compile_features (
  run
  PRIVATE
  cxx_std_11
  )
target_link_libraries (
  run
  PRIVATE
  librtidevice::librtidevice
  )
