#add the executable target named HelloWorld
add_executable(HelloWorld hello.cpp)
target_link_libraries(HelloWorld PRIVATE basic)
install(TARGETS HelloWorld DESTINATION bin)

add_executable(SimTown simtown.cpp)
target_link_libraries(SimTown PRIVATE basic2)
install(TARGETS SimTown DESTINATION bin)