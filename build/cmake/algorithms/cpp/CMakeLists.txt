

set(gsl_alglorithms_heads
        global.h
        )

set(gsl_alglorithms_sources
        global.cpp
        main.cpp
#        1.two_sum.cpp
#        2.add_two_numbers.cpp
#        3.longest_substring_without_repeating_characters.cpp
#        4.median_of_two_sorted_arrays.cpp
#        5.longest_palindromic_substring.cpp
#        6.zigzag_conversion.cpp
#        7.reverse_integer.cpp
        8.string_to_integer_atoi.cpp
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
