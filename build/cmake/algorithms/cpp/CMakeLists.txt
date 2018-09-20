

set(gsl_alglorithms_heads
        global.h
        )

set(gsl_alglorithms_sources
        global.cpp
        main.cpp
        two_sum1.cpp
        )

mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_alglorithms_heads}" gsl_alglorithms_head_filepaths)
mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_alglorithms_sources}" gsl_alglorithms_source_filepaths)

source_group("algorithms" FILES ${gsl_alglorithms_head_filepaths} ${gsl_alglorithms_source_filepaths})

add_executable(leetcode_algorithms
        ${gsl_alglorithms_head_filepaths} ${gsl_alglorithms_source_filepaths}
        )

mc_target_link_libraries(leetcode_algorithms)

#set_target_properties(leetcode_algorithms PROPERTIES FOLDER algorithms)

#mc_build_with_cc_static()
