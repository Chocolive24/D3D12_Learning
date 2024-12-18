cmake_minimum_required(VERSION 3.22)
project(D3D12_Learning)

set(CMAKE_CXX_STANDARD 17)

# Find required packages
find_package(directx-headers CONFIG REQUIRED)

# find_package(imgui CONFIG REQUIRED)

# Create the Main library
file(GLOB_RECURSE MAIN_SRC_FILES include/*.h src/*.cpp)
add_library(main_lib ${MAIN_SRC_FILES})
set_target_properties(main_lib PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(main_lib PUBLIC include/)
target_link_libraries(main_lib PUBLIC Microsoft::DirectX-Headers)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE main_lib Microsoft::DirectX-Headers)
