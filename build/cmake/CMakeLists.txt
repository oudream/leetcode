#cmake . -G "Visual Studio 12 2013" --build "/ddd/specialty/leetcode/build/cmake" -B"/ddd/specialty/leetcode/build/cmake-vs2013-win32"
#cmake . -G "Visual Studio 14 2015" --build "/ddd/specialty/leetcode/build/cmake" -B"/ddd/specialty/leetcode/build/cmake-vs2015-win32"
#cmake . -G "Visual Studio 14 2015 Win64" --build "/ddd/specialty/leetcode/build/cmake" -B"/ddd/specialty/leetcode/build/cmake-vs2015-win64"
#cmake . -G "Visual Studio 15 2017" --build "/ddd/specialty/leetcode/build/cmake" -B"/ddd/specialty/leetcode/build/cmake-vs2017-win32"
#cmake . -G "Visual Studio 15 2017 Win64" --build "/ddd/specialty/leetcode/build/cmake" -B"/ddd/specialty/leetcode/build/cmake-vs2017-win64"
#cmake . --build "/ddd/specialty/leetcode/build/cmake" -B"/ddd/specialty/leetcode/build/cmake-vs-local"
#cd /d "/ddd/specialty/leetcode/build/cmake-vs-local"

#cmake . -G "Xcode" --build "/ddd" -B"/ddd/cmake-xcode"

#cmake --build .


cmake_minimum_required(VERSION 3.0)

project(LEETCODE VERSION 1.0.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)

### depend path
#CMAKE_CURRENT_SOURCE_DIR (current file path)
if (NOT gs_project_path)
    set(gs_project_path ${CMAKE_CURRENT_SOURCE_DIR}/../..)
endif()

message('PROJECT-PATH: ' ${gs_project_path})
message(${CMAKE_C_COMPILER_ID})
message(${CMAKE_CXX_COMPILER_ID})
#message(${CMAKE_PREFIX_PATH})

set(gs_project_include_path ${gs_project_path}/cpp/include)
set(gs_project_3rd_path ${gs_project_path}/cpp/3rd)
set(gs_leetcode_algorithms_cpp_path ${gs_project_path}/algorithms/cpp)

if (NOT gs_project_deploy_path)
    set(gs_project_deploy_path ${gs_project_path}/build/deploy)
    if (UNIX)
        set(gs_project_output_path_debug ${gs_project_deploy_path}/unix/bin_d)
        set(gs_project_output_path_release ${gs_project_deploy_path}/unix/bin)
    endif()
    if (WIN32)
        set(gs_project_output_path_debug ${gs_project_deploy_path}/win32/bin_d)
        set(gs_project_output_path_release ${gs_project_deploy_path}/win32/bin)
        if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
            #        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc -static-libstdc++")
            #        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
            set(gs_project_output_path_debug ${gs_project_deploy_path}/win32/bin_gnu_d)
            set(gs_project_output_path_release ${gs_project_deploy_path}/win32/bin_gnu)
        endif()
    endif()

    SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${gs_project_output_path_debug}")
    SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${gs_project_output_path_release}")
    SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${gs_project_output_path_debug}")
    SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${gs_project_output_path_release}")
    SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${gs_project_output_path_debug}")
    SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${gs_project_output_path_release}")

    message(${gs_project_output_path_debug})
    message(${gs_project_output_path_release})
endif()

message("----------------------------------------------------------------------")

include(common.cmake)

include_directories(${gs_project_include_path})

###lib exe
add_subdirectory(algorithms)

message(bging 001)
#message(MSVC)
message(end 001)
