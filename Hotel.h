#ifndef HOTEL_H
#define HOTEL_H
#include "Chambre.h"
#include "Client.h"
#include "Reservation.h"
#include <iostream>
#include <string>
#include <vector>

namespace gestion {
	class Hotel {
	public:
		Hotel(std::string name, std::string ville, int idhotel, int maxnbchambres);

		std::string getNameHotel() const;
		int getIdHotel() const;
		std::string getVilleHotel() const;

		void addChambre(gestion::Chambre& chambre);
		void addClient(gestion::Client& client);

		void setNameHotel(std::string name);
		void setVilleHotel(std::string ville);
		void setIdHotel(int id);
		std::vector<int> findIdGenreChambre(genre type) const;

		void displayHotel() const;
		void listChambres() const;
		void listClients() const;
		void listReservations() const;

	private:
		std::string _name;
		int _idhotel;
		std::string _ville;
		std::vector<Chambre> _chambresliste;
		std::vector<Client> _clientsliste;
		std::vector<Reservation> _reservationsliste;
		int _maxnbchambres;
	};
	void operator<<(std::ostream& os, Hotel hotel);
}
#endif