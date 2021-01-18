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
		std::vector<Chambre> getListChambre() const;

		void addChambre(Chambre chambre);
		void addClient(Client client);
		void addReservation(Reservation reservation);

		void setNameHotel(std::string name);
		void setVilleHotel(std::string ville);
		void setIdHotel(int id);

		int checkTypeDispo(genre type, date::Date ddebut, date::Date dfin) const; // permet de retourner l'index d'une chambre disponible, en fonction du genre et de la p�riode.

		void displayChambre(int index) const;
		void displayHotel() const;
		void listChambres() const;
		void listClients() const;
		void listReservations() const;
		int chooseClient(std::string name) const;
		void searchAndDisplayReservation(int idresa) const; // affiche une reservation en fonction de son ID
		void displayClientReservations(int idclient) const;
		void displayClientReservations(std::string nom) const;

		int newIdClient(); // cr�er un identifiant utilisable
		int newIdReservation();

		bool checkDoublonClient(int idclient) const; // permet de tester si un identifiant est d�ja utilis�
		bool checkDoublonClient(Client client) const;
		bool checkDoublonChambre(int idchambre) const;
		bool checkDoublonChambre(Chambre chambre) const;
		bool checkDoublonReservation(int idresa) const;
		bool checkDoublonReservation(Reservation resa) const;

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