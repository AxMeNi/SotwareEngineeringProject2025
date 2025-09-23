#include <basic/message.h>

#include <iostream>

int main()
{
    std::cout << "#<hello.cpp> EXECUTING HELLO.CPP IN MAIN FOLDER" << std::endl;
    
    // EXECUTING THE CODE OF THE HELLOWORLD PROJECT

	std::cout << "#<hello.cpp> EXECUTION OF HELLO_WORLD() and PRINT_VERSION()" << std::endl;
    hello_world();
    print_version();

	std::cout << "End of program" << std::endl;

	return 0;

}


