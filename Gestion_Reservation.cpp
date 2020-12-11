#include "Date.h"
#include "Client.h"
#include "Hotel.h"
#include <iostream>


int main() {
	client::Client a("michel", 1);
	client::Client b("jean", 2);
	client::Client c("denis", 3);
	std::cout << a.toStringClient() << std::endl;
	std::cout << b.toStringClient() << std::endl;
	std::cout << c.toStringClient() << std::endl;
	a.editClient("michel sardou", 1);
	b.addReservation();
	std::cout << a.toStringClient() << std::endl;
	std::cout << b.toStringClient() << std::endl;
	hotel::Hotel d("Santa_Maria","Madrid",1,52);
	std::cout << d.toStringHotel() << std::endl;
}