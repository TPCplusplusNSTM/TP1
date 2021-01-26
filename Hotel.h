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
		int testAndAddClient(); // fonction utilis�e dans createReservation : v�rifie si le client est dans l'hotel et retourne son ID / sinon cr�e un nouveau client avec un ID valide
		void addReservation(Reservation reservation);
		Reservation createReservation(); // permet de cr�er une r�servation par un utilisateur

		void delChambre(int idchambre);
		void delClient(int idclient);
		void delReservation(int idresa);
		void cancelReservation(); //permet d'annuler une r�servation

		void setNameHotel(std::string name);
		void setVilleHotel(std::string ville);
		void setIdHotel(int id);
		void setReservation(); // permet de modifier une r�servation par l'utilisateur
		void setDatesAndRoom(Reservation& resa); // permet � l'utilisateur de d�finir les dates de son s�jour et le type de chambre

		void displayChambre(int index) const; // fonctions d'affichage 
		void displayHotel() const;
		void listChambres() const;
		void listClients() const;
		void listReservations() const;

		int chooseClient(std::string name) const; // retourne l'ID d'un client en fonction de son nom
		int findChambre(int idchambre) const;
		void searchAndDisplayChambre(int idchambre) const;
		int findClient(int idclient) const;
		void searchAndDisplayClient(int idclient) const; // affiche un client en fonction de son ID
		int findReservation(int idresa) const; // retourne l'index de la r�servation dans le vecteur
		void searchAndDisplayReservation(int idresa) const; // affiche une reservation en fonction de son ID

		void displayClientReservations(int idclient) const; // affiche les r�servations d'un client
		void displayClientReservations(std::string nom) const;

		int newIdClient(); // cr�e un identifiant utilisable
		int newIdReservation();

		int checkTypeDispo(genre type, date::Date ddebut, date::Date dfin) const; // permet de retourner l'index d'une chambre disponible, en fonction du genre et de la p�riode disponible.
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

	double priceRoom(Hotel hotel, int idroom); // permet de d�terminer le prix d'une chambre � partir de son identifiant
	void calc(Hotel hotel, Reservation reservation); // permet de calculer le prix d'une r�servation en connaissant l'h�tel
	void operator<<(std::ostream& os, Hotel hotel);
}
#endif