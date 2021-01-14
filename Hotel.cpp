#include "Hotel.h"

namespace gestion {
	Hotel::Hotel(std::string name, std::string ville, int idhotel, int maxnbchambres) : _name(name), _idhotel(idhotel), _ville(ville), _maxnbchambres(maxnbchambres) {}
	std::string Hotel::getNameHotel() const {
		return _name;
	}
	int Hotel::getIdHotel() const {
		return _idhotel;
	}
	std::string Hotel::getVilleHotel() const {
		return _ville;
	}
	

	void Hotel::addChambre(Chambre chambre) {
		_chambresliste.push_back(chambre);
	}
	void Hotel::addClient(Client client) {
		_clientsliste.push_back(client);
	}
	void Hotel::addReservation(Reservation reservation) {
		_reservationsliste.push_back(reservation);
	}
	void Hotel::setNameHotel(std::string name) {
		_name = name;
	}
	void Hotel::setVilleHotel(std::string ville) {
		_ville = ville;
	}
	void Hotel::setIdHotel(int id) {
		_idhotel = id;
	}

	int Hotel::checkTypeDispo(genre& type, date::Date& dbegin, date::Date& dend) const{
		bool test = false;
		auto it = _chambresliste.begin();
		while (it != _chambresliste.end() && test==false) { // on test le type de chambre
			if (type == it->type()) {
				auto it1 = _reservationsliste.begin();
				while (it1 != _reservationsliste.end() && test==false) {
					if ((it->id() == it1->idroom()) && ((dbegin < it1->dbegin() && dend < it1->dbegin()) || (dbegin > it1->dend() && dend > it1->dend()))) { // test l'ID de la chambre et la période de séjour 
						test = true;
						int index = std::distance(_chambresliste.begin(), it);
						return index;
					}
					++it1;
				}
			}
			++it;
		}
		if (test == false) {
			std::cout << "Ce type de chambre n'est pas disponible, saisissez un autre type" << std::endl;
			return 0; // on renvoie une valeur par défaut pour éviter le vide
		}
	}

	void Hotel::displayChambre(int index) const {
		auto it = _chambresliste.begin() + index;
		std::cout << *it;
	}

	void Hotel::displayHotel() const {
		std::cout << "Details Hotel ----------------------------------------------------------------------" << std::endl;
		std::cout << "Nom= " << _name << ", Ville= " << _ville << ", ID= " << std::to_string(_idhotel) << ", Nb_de_chambres= " << std::to_string(_maxnbchambres) << ", Nb_dispo= " << std::endl;
		std::cout << " " << std::endl;
		listChambres();
		std::cout << " " << std::endl;
		listClients();
		std::cout << " " << std::endl;
		listReservations();
		std::cout << "------------------------------------------------------------------------------------" << std::endl;
	}
	
	void Hotel::listChambres() const {
		auto it = _chambresliste.begin();
		std::cout << "Liste des chambres :" << std::endl;
		while (it != _chambresliste.end()) {
			Chambre z = *it;
			std::cout << z;
			++it;
		}
	}

	void Hotel::listClients() const {
		auto it = _clientsliste.begin();
		std::cout << "Liste des clients :" << std::endl;
		while (it != _clientsliste.end()) {
			Client z = *it;
			std::cout << z;
			++it;
		}
	}

	void Hotel::listReservations() const {
		auto it = _reservationsliste.begin();
		std::cout << "Liste des reservations :" << std::endl;
		while (it != _reservationsliste.end()) {
			Reservation z = *it;
			std::cout << z;
			++it;
		}
	}

	void operator<<(std::ostream& os, Hotel hotel) {
		hotel.displayHotel();
	}
}
