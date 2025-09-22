#include <iostream>
#include <basic/message.h>

#include <cassert>
#include <sstream>

void test_version(){
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf()); // redirection

    print_version();

    std::cout.rdbuf(old); // restauration

    assert(buffer.str() == "project version is 1.0\n"); // test
}

// The test should pass if the main returns 0, if 1 : doesnt pass

int main() {
	test_version();
	return 0;
}