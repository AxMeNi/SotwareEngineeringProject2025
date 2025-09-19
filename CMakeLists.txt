cmake_minimum_required(VERSION 3.10)

# set the project name
project(HelloProj VERSION 1.0)

# specify the C++ standard
# use the CMAKE_CXX_STANDARD variable
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# export configuration to source code
configure_file(cmake/HelloProjConfig.h.in HelloProjConfig.h)

# QUAND ON FERA UN DIESE INCLUDE AVEC LES CHEVRONS, IL ACCEDERA AUX FICHIERS ENTRE LES CHEVRONS PRESENTS DANS LE BINARY DIR PRECISE CI-DESSUS (en l'occurrence le build)
# Le Project Binary Dir est précisé par défaut quand on fait le cmake .. dans build mais sinon quand on fait le cmake, si on veut préciser le PROJECT_BINARY_DIR on fait "cmake -B "path/to/build"" et si on eut préciser la source on rajoute "-S "path/to/source""

#add libraries
add_subdirectory(src/basic)

#add executable
option(HELLOWORD_WITH_EXECUTABLES "Compile mains" ON)
if(HELLOWORD_WITH_EXECUTABLES)
	message(STATUS "Configuring Hello World with executables")
	add_subdirectory(mains)
endif()

#add tests
option(HELLOWORLD_WITH_TESTS "Compile tests" ON)
if(HELLOWORLD_WITH_TESTS)
	enable_testing() 
	# We are defining a bunch of tests by Calling Ctest
	# enable_testing() will create a new Target called_testing
	message(STATUS "Configuring HelloWorld with tests")
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../tests ${CMAKE_BINARY_DIR}/tests_build)
endif()

# create the package configuration file
include(CMakePackageConfigHelpers)
configure_package_config_file(
	cmake/HelloProjConfig.cmake.in
	HelloProjConfig.cmake
	INSTALL_DESTINATION cmake/
)

#install project configuration file
install(
	FILES ${PROJECT_BINARY_DIR}/HelloProjConfig.cmake
	DESTINATION cmake/
	)


# Configure CPack
if(WIN32)
	set(CPACK_GENERATOR "ZIP")
else()
	set(CPACK_GENERATOR "TGZ")
endif()

# This must always be last!
include(CPack)