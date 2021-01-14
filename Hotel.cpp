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
	

	void Hotel::addChambre(gestion::Chambre& chambre) {
		_chambresliste.push_back(chambre);
	}
	void Hotel::addClient(gestion::Client& client) {
		_clientsliste.push_back(client);
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

	std::vector<int> Hotel::findIdGenreChambre(genre type) const {
		std::vector<int> listechambre;
		auto it = _chambresliste.begin();
		while (it != _chambresliste.end()) {
			it = find_if(it, _chambresliste.end(), [type](const Chambre& obj) {return obj.type() == type; });
			if (it != _chambresliste.end()) {
				listechambre.push_back(it->id());
				++it;
			}
			
		}
		return listechambre;
	}


	void Hotel::displayHotel() const {
		std::cout << "Details Hotel ----------------------------------------------------------------------" << std::endl;
		std::cout << "Nom= " << _name << ", Ville= " << _ville << ", ID= " << std::to_string(_idhotel) << ", Nb_de_chambres= " << std::to_string(_maxnbchambres) << ", Nb_dispo= " << std::endl;
		std::cout << " " << std::endl;
		listChambres();
		std::cout << " " << std::endl;
		listClients();
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
