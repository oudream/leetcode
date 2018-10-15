

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
#        20.valid_parentheses.cpp
        22.generate_parentheses.cpp
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

#set(v_name1 "ou")
#set(v_name2 "dream")
#set(${v_name1}${v_name2} "ouyangjinhong")
#message("oudream is " ${oudream})
#message("oudream is " ${${v_name1}${v_name2}})

#############################################

mc_create_test1(kmp1)
mc_create_test1(divide_two_int1)
mc_create_test1(combination_loop1)
mc_create_test1(combination_loop2)
mc_create_test1(combination_recursion1)
mc_create_test1(combination_recursion2)
mc_create_test1(combination_recursion3)
mc_create_test1(combination_recursion4)
mc_create_test1(hannoi1)


#############################################

macro(mc_create_tool1 sCppName)
    set(gsl_tool_${sCppName}_heads
            global.h
            )

    set(gsl_tool_${sCppName}_sources
            global.cpp
            tool_${sCppName}.cpp
            )

    mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_tool_${sCppName}_heads}" gsl_tool_${sCppName}_head_filepaths)
    mc_merge_file_path(${gs_leetcode_algorithms_cpp_path} "${gsl_tool_${sCppName}_sources}" gsl_tool_${sCppName}_source_filepaths)

    source_group("algorithms" FILES ${gsl_tool_${sCppName}_head_filepaths} ${gsl_tool_${sCppName}_source_filepaths})

    add_executable(tool_${sCppName}
            ${gsl_tool_${sCppName}_head_filepaths} ${gsl_tool_${sCppName}_source_filepaths}
            )
endmacro()

#############################################

mc_create_tool1(create_tree1)
