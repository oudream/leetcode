

set(gsl_alglorithms_sources
        1/1.1.cpp
#        2/2.1.cpp
#        3/3.1.cpp
        )

mc_merge_file_path(${gs_analysis_of_algorithm_path} "${gsl_alglorithms_sources}" gsl_alglorithms_source_filepaths)

source_group("algorithms" FILES ${gsl_alglorithms_source_filepaths})

add_executable(analysis_of_algorithm
        ${gsl_alglorithms_source_filepaths}
        )

mc_target_link_libraries(analysis_of_algorithm)

#set_target_properties(analysis_of_algorithm PROPERTIES FOLDER algorithms)

#mc_build_with_cc_static()



#############################################




