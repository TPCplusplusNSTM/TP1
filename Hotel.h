#ifndef HOTEL_H
#define HOTEL_H
#include "Chambre.h"
#include "Client.h"
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
		int getChambresDispo() const;

		void addChambre(gestion::Chambre& chambre);
		void addClient(gestion::Client& client);
		void setNameHotel(std::string name);
		void setVilleHotel(std::string ville);
		void setIdHotel(int id);
		void displayHotel() const;
		void listChambres() const;
		void listClients() const;

	private:
		std::string _name;
		int _idhotel;
		std::string _ville;
		int _dispo;
		std::vector<gestion::Chambre> _chambresliste;
		std::vector<gestion::Client> _clientsliste;
		int  _maxnbchambres;
	};
	void operator<<(std::ostream& os, Hotel hotel);
}
#endif