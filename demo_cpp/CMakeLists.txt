cmake_minimum_required(VERSION 3.24)
project(demo_cpp)

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

## The CMake toolchain file
#set(CMAKE_TOOLCHAIN_FILE D:/works/vcpkg/scripts/buildsystems/vcpkg.cmake)

if (WIN32)

    set(EXTRA_SRC_DIRS ${VCPKG_INSTALLED_DIR}/x64-windows/include)

    if (CMAKE_BUILD_TYPE MATCHES Debug)
        set(EXTRA_LIB_DIRS ${VCPKG_INSTALLED_DIR}/x64-windows/debug/lib)
        set(EXTRA_DLL_DIRS ${VCPKG_INSTALLED_DIR}/x64-windows/debug/bin)
        set(EXTRA_LIBS spdlogd fmtd uv)
    else()
        set(EXTRA_LIB_DIRS ${VCPKG_INSTALLED_DIR}/x64-windows/lib)
        set(EXTRA_DLL_DIRS ${VCPKG_INSTALLED_DIR}/x64-windows/bin)
        set(EXTRA_LIBS spdlog fmt uv)
    endif()

elseif (APPLE)

    set(EXTRA_SRC_DIRS ${VCPKG_INSTALLED_DIR}/x64-osx/include)

    if (CMAKE_BUILD_TYPE MATCHES Debug)
        set(EXTRA_LIB_DIRS ${VCPKG_INSTALLED_DIR}/x64-osx/debug/lib)
        set(EXTRA_DLL_DIRS ${VCPKG_INSTALLED_DIR}/x64-osx/debug/bin)
        set(EXTRA_LIBS spdlogd fmtd uv_a)
    else()
        set(EXTRA_LIB_DIRS ${VCPKG_INSTALLED_DIR}/x64-osx/lib)
        set(EXTRA_DLL_DIRS ${VCPKG_INSTALLED_DIR}/x64-osx/bin)
        set(EXTRA_LIBS spdlog fmt uv_a)
    endif()

elseif (UNIX)

    set(EXTRA_SRC_DIRS ${VCPKG_INSTALLED_DIR}/x64-linux/include)
    set(EXTRA_LIB_DIRS ${VCPKG_INSTALLED_DIR}/x64-linux/lib)
    set(EXTRA_DLL_DIRS ${VCPKG_INSTALLED_DIR}/x64-linux/bin)

    set(EXTRA_LIBS spdlog fmt uv_a)

endif ()

aux_source_directory(src SRC_DIR)

add_executable(demo_cpp ${SRC_DIR})

target_include_directories(demo_cpp PRIVATE ${EXTRA_SRC_DIRS})
target_link_directories(demo_cpp PRIVATE ${EXTRA_LIB_DIRS})
target_link_libraries(demo_cpp PRIVATE ${EXTRA_LIBS})
