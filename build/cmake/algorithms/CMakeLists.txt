
if (MSVC)
    add_definitions(-D"_CRT_SECURE_NO_WARNINGS")
    add_definitions( "/wd4819" )
endif ()

add_subdirectory(cpp)

if (${gs_project_enable_cpython})
#    add_subdirectory(python)
endif()