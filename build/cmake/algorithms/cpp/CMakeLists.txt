

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
#        8.string_to_integer_atoi.cpp
#        9.palindrome_number.cpp
#        11.container_with_most_water.cpp
        20.valid_parentheses.cpp
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


#############################################

macro(mc_create_test1 sCppName)
    set(gsl_test_${sCppName}_heads
            global.h
            )

    set(gsl_test_${sCppName}_sources
            global.cpp
            test_${sCppName}.cpp
            )

    mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_test_${sCppName}_heads}" gsl_test_${sCppName}_head_filepaths)
    mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_test_${sCppName}_sources}" gsl_test_${sCppName}_source_filepaths)

    source_group("algorithms" FILES ${gsl_test_${sCppName}_head_filepaths} ${gsl_test_${sCppName}_source_filepaths})

    add_executable(test_${sCppName}
            ${gsl_test_${sCppName}_head_filepaths} ${gsl_test_${sCppName}_source_filepaths}
            )
endmacro()

#############################################

set(gsl_test_kmp1_heads
        global.h
        )

set(gsl_test_kmp1_sources
        global.cpp
        test_kmp1.cpp
        )

mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_test_kmp1_heads}" gsl_test_kmp1_head_filepaths)
mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_test_kmp1_sources}" gsl_test_kmp1_source_filepaths)

source_group("algorithms" FILES ${gsl_test_kmp1_head_filepaths} ${gsl_test_kmp1_source_filepaths})

add_executable(test_kmp1
        ${gsl_test_kmp1_head_filepaths} ${gsl_test_kmp1_source_filepaths}
        )

#############################################

set(gsl_test_divide_two_int1_heads
        global.h
        )

set(gsl_test_divide_two_int1_sources
        global.cpp
        test_divide_two_int1.cpp
        )

mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_test_divide_two_int1_heads}" gsl_test_divide_two_int1_head_filepaths)
mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_test_divide_two_int1_sources}" gsl_test_divide_two_int1_source_filepaths)

source_group("algorithms" FILES ${gsl_test_divide_two_int1_head_filepaths} ${gsl_test_divide_two_int1_source_filepaths})

add_executable(test_divide_two_int1
        ${gsl_test_divide_two_int1_head_filepaths} ${gsl_test_divide_two_int1_source_filepaths}
        )

#############################################

set(gsl_test_combination_loop1_heads
        global.h
        )

set(gsl_test_combination_loop1_sources
        global.cpp
        test_combination_loop1.cpp
        )

mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_test_combination_loop1_heads}" gsl_test_combination_loop1_head_filepaths)
mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_test_combination_loop1_sources}" gsl_test_combination_loop1_source_filepaths)

source_group("algorithms" FILES ${gsl_test_combination_loop1_head_filepaths} ${gsl_test_combination_loop1_source_filepaths})

add_executable(test_combination_loop1
        ${gsl_test_combination_loop1_head_filepaths} ${gsl_test_combination_loop1_source_filepaths}
        )

#############################################

set(gsl_test_combination_loop2_heads
        global.h
        )

set(gsl_test_combination_loop2_sources
        global.cpp
        test_combination_loop2.cpp
        )

mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_test_combination_loop2_heads}" gsl_test_combination_loop2_head_filepaths)
mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_test_combination_loop2_sources}" gsl_test_combination_loop2_source_filepaths)

source_group("algorithms" FILES ${gsl_test_combination_loop2_head_filepaths} ${gsl_test_combination_loop2_source_filepaths})

add_executable(test_combination_loop2
        ${gsl_test_combination_loop2_head_filepaths} ${gsl_test_combination_loop2_source_filepaths}
        )

#############################################

set(gsl_test_combination_recursion1_heads
        global.h
        )

set(gsl_test_combination_recursion1_sources
        global.cpp
        test_combination_recursion1.cpp
        )

mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_test_combination_recursion1_heads}" gsl_test_combination_recursion1_head_filepaths)
mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_test_combination_recursion1_sources}" gsl_test_combination_recursion1_source_filepaths)

source_group("algorithms" FILES ${gsl_test_combination_recursion1_head_filepaths} ${gsl_test_combination_recursion1_source_filepaths})

add_executable(test_combination_recursion1
        ${gsl_test_combination_recursion1_head_filepaths} ${gsl_test_combination_recursion1_source_filepaths}
        )

#set(v_name1 "ou")
#set(v_name2 "dream")
#set(${v_name1}${v_name2} "ouyangjinhong")
#message("oudream is " ${oudream})
#message("oudream is " ${${v_name1}${v_name2}})

#############################################

mc_create_test1(combination_recursion2)
