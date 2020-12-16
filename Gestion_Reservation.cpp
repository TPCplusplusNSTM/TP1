#include "Date.h"
#include "Client.h"
#include "Hotel.h"
#include <iostream>


int main() {
	gestion::Client a("michel", 1);
	gestion::Client b("jean", 2);
	gestion::Client c("denis", 3);
	std::cout << a.toStringClient() << std::endl;
	std::cout << b.toStringClient() << std::endl;
	std::cout << c.toStringClient() << std::endl;
	a.editClient("michel sardou", 1);
	b.addReservation();
	std::cout << a.toStringClient() << std::endl;
	std::cout << b.toStringClient() << std::endl;
}