#include <iostream>
#include <basic/message.h>

#include <cassert>
#include <sstream>

void test_hello_world(){
    std::ostringstream buffer;        // flux temporaire
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf()); // redirection

    hello_world();                     // appel de ta fonction

    std::cout.rdbuf(old);              // restauration de cout

    assert(buffer.str() == "Hello World!\n");  // test
}

//The test should pass if the main returns 0, if 1 : doesnt pass

int main() {
	test_hello_world();
	return 0;
}