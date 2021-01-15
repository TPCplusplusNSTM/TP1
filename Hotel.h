#ifndef HOTEL_H
#define HOTEL_H
#include "Chambre.h"
#include "Client.h"
#include "Reservation.h"
#include <cassert>

namespace gestion {
	class Hotel {
	public:
		Hotel(std::string name, std::string ville, int idhotel, int maxnbchambres);

		std::string getNameHotel() const;
		int getIdHotel() const;
		std::string getVilleHotel() const;

		void addChambre(Chambre chambre);
		void addClient(Client client);
		void addReservation(Reservation reservation);

		void setNameHotel(std::string name);
		void setVilleHotel(std::string ville);
		void setIdHotel(int id);
		int checkTypeDispo(genre& type, date::Date& ddebut, date::Date& dfin) const;

		void displayChambre(int index) const;
		void displayHotel() const;
		void listChambres() const;
		void listClients() const;
		void listReservations() const;
		Client chooseClient(std::string name);

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