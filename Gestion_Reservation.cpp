#include "Date.h"
#include "Client.h"
#include <iostream>

int main() {
	client::Client a("Michael", 1);
	std::cout << a.toStringClient() << std::endl;
	a.editClient(" ", 03);
	std::cout << a.toStringClient() << std::endl;
	return 0;
}
