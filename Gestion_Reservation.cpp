#include "Date.h"
#include "Client.h"
#include "Hotel.h"
#include "Reservation.h"
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
	gestion::Chambre d(1,Single,0.99);
	std::cout << d.Chambre_to_string() << std::endl;
	gestion::Hotel e("Macumba", "Madrid", 1, 12);
	e.addChambre(d);
	e.displayHotel();
	date::Date dd(2020,12,16);
	date::Date df(2021,1,20);
	gestion::Reservation f(1,dd,df,1,1,1);
	f.calc(2.5, 10);
	std::cout << f.reservation_to_string() << std::endl;
	return 0;
}