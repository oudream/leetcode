
if (MSVC)
    add_definitions(-D"_CRT_SECURE_NO_WARNINGS")
    add_definitions( "/wd4819" )
endif ()

set(gs_analysis_of_algorithm_path ${gs_project_path}/referto/analysis_of_algorithm)
add_subdirectory(analysis_of_algorithm)

if (${gs_project_enable_cpython})
#    add_subdirectory(python)
endif()