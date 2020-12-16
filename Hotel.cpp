#include "Hotel.h"

namespace gestion {
	Hotel::Hotel(std::string name, std::string ville, int idhotel, int maxnbchambres) : _name(name), _idhotel(idhotel), _ville(ville), _dispo(0), _maxnbchambres(maxnbchambres) {}
	std::string Hotel::getNameHotel() const {
		return _name;
	}
	int Hotel::getIdHotel() const {
		return _idhotel;
	}
	std::string Hotel::getVilleHotel() const {
		return _ville;
	}
	int Hotel::getChambresDispo() const {
		return _dispo;
	}
	void Hotel::displayHotel() const {
		std::cout << "Details Hotel ----------------------------------------------------------------------" << std::endl;
		std::cout << "Nom= " << _name << ", Ville= " << _ville << ", ID= " << std::to_string(_idhotel) << ", Nb_de_chambres= " << std::to_string(_maxnbchambres) << ", Nb_dispo= " << std::to_string(_dispo) << std::endl;
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

	void operator<<(std::ostream& os, Hotel hotel){
		hotel.displayHotel();
	}
	
}
