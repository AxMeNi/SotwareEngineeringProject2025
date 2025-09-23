set(target_name basic2)
add_library(${target_name} STATIC "")
target_sources(${target_name}
	PRIVATE "${PROJECT_SOURCE_DIR}/src/basic2/building.cpp"
	PRIVATE "${PROJECT_SOURCE_DIR}/src/basic2/rock.cpp"

	PRIVATE "${PROJECT_SOURCE_DIR}/include/basic2/rock.h"
	PRIVATE "${PROJECT_SOURCE_DIR}/include/basic2/dyn_array.h"
	PRIVATE "${PROJECT_SOURCE_DIR}/include/basic2/building.h"
)
target_include_directories(${target_name}
	PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
	$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
	$<INSTALL_INTERFACE:include>
)

export(TARGETS ${target_name} FILE 
	${PROJECT_BINARY_DIR}/${target_name}_target.cmake )

#install target lib2
install(TARGETS ${target_name}
	EXPORT ${target_name}
	DESTINATION lib2
)

#install target export
install(EXPORT ${target_name}
	FILE ${target_name}_target.cmake
	DESTINATION cmake/
)

#install includes
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION include/
)

#generated include
install(FILES ${PROJECT_BINARY_DIR}/HelloProjConfig.h
	DESTINATION include/
)