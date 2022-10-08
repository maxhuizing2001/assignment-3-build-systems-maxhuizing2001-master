cmake_minimum_required(VERSION 3.22.1)
project(assignment-3-build-systems-maxhuizing2001-master VERSION 0.1.0)
add_executable(lift_sim)
target_sources(lift_sim
        PRIVATE
        src/buttons.cpp,
        src/lift.cpp,
        src/lift_down_state.cpp,
        src/lift_init_state.cpp,
        src/lift_state.cpp,
        src/lift_steady_state.cpp,
        src/lift_up_state.cpp)

include_directory(inc)
target_compile_features(my_app PRIVATE cxx_std_20)
set_target_properties(my_app PROPERTIES CXX_EXTENSIONS OFF)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" OR
        "${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU" OR
        "${CMAKE_CXX_COMPILER_ID}" MATCHES "AppleClang")
    set(CXX_GNU_LIKE ON)
else()
    set(CXX_GNU_LIKE OFF)
endif()



Detect the compiler, if it's GNU, Clang or AppleClang set a variable GNU_COMPATIBLE to TRUE, otherwise set it to FALSE