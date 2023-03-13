cmake_minimum_required(VERSION 3.24)
project(demo_cpp)

set(CMAKE_CXX_STANDARD 20)

# The CMake toolchain file
set(CMAKE_TOOLCHAIN_FILE /Users/vulko/code/git/vcpkg/scripts/buildsystems/vcpkg.cmake)

# The directory which contains the installed libraries for each triplet
set(VCPKG_INSTALLED_DIR /Users/vulko/code/git/vcpkg/installed)

# Automatically copy dependencies into the output directory for executables.
set(VCPKG_APPLOCAL_DEPS ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(EXTRA_SRC_DIRS ${VCPKG_INSTALLED_DIR}/x64-osx/include)
set(EXTRA_LIB_DIRS ${VCPKG_INSTALLED_DIR}/x64-osx/lib)
set(EXTRA_DLL_DIRS ${VCPKG_INSTALLED_DIR}/x64-osx/bin)

set(EXTRA_LIBS spdlog fmt uv_a)

aux_source_directory(src SRC_DIR)

add_executable(demo_cpp ${SRC_DIR})

target_include_directories(demo_cpp PRIVATE ${EXTRA_SRC_DIRS})
target_link_directories(demo_cpp PRIVATE ${EXTRA_LIB_DIRS})
target_link_libraries(demo_cpp PRIVATE ${EXTRA_LIBS})
