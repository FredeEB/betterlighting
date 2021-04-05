project(betterlighting)
cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

### COMPILEOPTIONS
include(cmake/compile-options.cmake)

### BINARY
add_executable(bl)
target_link_libraries(bl PUBLIC compile-options)

add_subdirectory(src)

### DEPLOYMENT
install(TARGETS bl)

### TESTING
enable_testing()
option(BUILD_TESTING "Build unittests" ON)
if(BUILD_TESTING)
  add_subdirectory(test)
endif()

### EXTRA OPTIONS
option(ENABLE_CLANG_TIDY "Sets whether clang tidy should fix code or not" OFF)
if(ENABLE_CLANG_TIDY MATCHES ON)
  set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-header-filter=$(realpath ..)")
endif()

option(ENABLE_SANITIZERS "Enable address and undefined snitizers" OFF)
if(ENABLE_SANITIZERS MATCHES ON)
  target_link_libraries(bl PUBLIC -fsanitize=address,undefined)
  target_compile_options(bl PUBLIC -fsanitize=address,undefined)
endif()
