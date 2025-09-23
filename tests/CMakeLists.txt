if (NOT TARGET basic)
	cmake_minimum_required(VERSION 3.10)
	# set the project name
	project(HelloProjTest)
	find_package(HelloProj)
	enable_testing()
endif()

#add the executable target named TestHello
add_executable(TestHello test-hello.cpp)
target_link_libraries(TestHello PUBLIC basic)
add_test(NAME test_hello COMMAND TestHello) 
#test_hello est le nom du test du Ctest et TestHello st l'executable du test que l'on veut activer par la commande. On ajoute le test en question au target RUN_TESTS

#add the executable target named TestVersion
add_executable(TestVersion test-version.cpp) # On crée un target qui est un executable
target_link_libraries(TestVersion PUBLIC basic)
add_test(NAME test_version COMMAND TestVersion) 
# On ajoute le test en question au target  RUN_TESTS