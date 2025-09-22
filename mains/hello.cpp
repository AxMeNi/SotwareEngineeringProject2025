#include <basic/message.h>
#include <basic/dyn_array.h>
#include <basic/building.h>
#include <basic/rock.h>
#include <iostream>

int main()
{
    std::cout << "#<hello.cpp> EXECUTING HELLO.CPP IN MAIN FOLDER" << std::endl;
    
    // EXECUTING THE CODE OF THE HELLOWORLD PROJECT

	std::cout << "#<hello.cpp> EXECUTION OF HELLO_WORLD() and PRINT_VERSION()" << std::endl;
    hello_world();
    print_version();

	// EXECUTING THE CODE OF THE DYN ARRAY AND BUILDING PROJECT

	std::cout << "#<hello.cpp> EXECUTION OF THE CODE FROM THE CLASS OF GUILLAUME" << std::endl;
    DynArray< Building > street;
	std::cout << "Welcome to SimTown! Please Enter IDs (-99 to finish)" << std::endl;
	int id = -1;
	std::cin >> id;
	while(id != -99) {
		Building tmp(id, 5);
		street.push_back(tmp);
		std::cin >> id;
	}
	for(unsigned int i = 0; i<street.size(); ++i ) {
		std::cout << street[i] << std::endl;
	}
	if(street.size() >= 2 ) {
		street[0].swap_rock(street[1], 2, 4);
	}
	std::cout << "End of program" << std::endl;

	return 0;

}