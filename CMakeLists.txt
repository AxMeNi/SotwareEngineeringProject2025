cmake_minimum_required(VERSION 3.10)

# set the project name
project(HelloProj VERSION 1.0)

# specify the C++ standard
# use the CMAKE_CXX_STANDARD variable
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# export configuration to source code
configure_file(cmake/HelloProjConfig.h.in HelloProjConfig.h)

# add the executable target named HelloWorld
add_executable(HelloWorld mains/hello.cpp)

# add binary tree to the list of paths to search includes
target_include_directories(HelloWorld PUBLIC "${PROJECT_BINARY_DIR}")

# QUAND ON FERA UN DIESE INCLUDE AVEC LES CHEVRONS, IL ACCEDERA AUX FICHIERS ENTRE LES CHEVRONS PRESENTS DANS LE BINARY DIR PRECISE CI-DESSUS (en l'occurrence le build)
# Le Project Binary Dir est précisé par défaut quand on fait le cmake .. dans build mais sinon quand on fait le cmake, si on veut préciser le PROJECT_BINARY_DIR on fait "cmake -B "path/to/build"" et si on eut préciser la source on rajoute "-S "path/to/source""