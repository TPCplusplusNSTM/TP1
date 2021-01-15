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
		int index = 0;
		bool test = false;
		auto it = _chambresliste.begin(); // on selectionne une chambre dans le vecteur
		while (it != _chambresliste.end()) { // on test le type de chambre
			if (type == it->type()) {
				auto it1 = _reservationsliste.begin(); // si le type concorde on regarde si il y a une reservation en cour
				while (it1 != _reservationsliste.end()) {
					if (it->id() == it1->idroom()) { // test l'ID de la chambre et la période de séjour (relation reservation/chambre)
						switch (index) {
						case 0:
							if ((dbegin < it1->dbegin() && dend < it1->dbegin()) || (dbegin > it1->dend() && dend > it1->dend())) { // on check les dates strictement inf ou sup au dates de reservations en cours
								index = std::distance(_chambresliste.begin(), it);
								test = true;
								std::cout << "date ok" << std::endl;
							}
							break;
						default:
							if ((dbegin < it1->dbegin() && dend < it1->dbegin()) || (dbegin > it1->dend() && dend > it1->dend())) {} // on check les dates strictement inf ou sup au dates de reservations en cours
							else { test = false; }
						}
						std::cout << "id ok" << std::endl;
					}
					++it1;
				}
				if (test == true) {
					return index;
				}
				std::cout << "type ok" << std::endl;
			}
			++it;
		}
		std::cout << "Erreur: Chambre indisponible, veuillez inserer un autre type de chambre " << std::endl;
		return index = 0;
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

	Client Hotel::chooseClient(std::string name) {
		auto it = _clientsliste.begin();
		int numeroclient = 1; // Cette variable servira à afficher l'ordre dans lequel les clients sont trouvés puis à conserver le numéro du client voulu
		int indice = 1; // Cette variable permettra de trouver le client voulu dans la seconde boucle while
		std::vector<Client> stockage = {};
		while (it != _clientsliste.end()) {
			if (it->getName() == name) {
				stockage.push_back(*it);
				std::cout << numeroclient << ") " << *it << std::endl;
				numeroclient++;
			}
			++it;
		}
		std::cout << "Choisissez le numéro devant le client vous convenant" << std::endl;
		std::cin >> numeroclient; // On conserve le numéro devant le client voulu
		auto it1 = stockage.begin();
		while (it1 != stockage.end()) {
			if (indice == numeroclient) {
				return *it1;
			}
			++it1;
			indice++;
		}
		std::cout << "Aucun client ne porte ce nom ou le numéro du client choisi est erroné, veuillez recommencer" << std::endl;
		assert(indice > numeroclient && numeroclient >= 1); // On met une condition qui ne peut être vrai à la sortie de la boucle ce qui permet d'arrêter le programme 
	}

	void operator<<(std::ostream& os, Hotel hotel) {
		hotel.displayHotel();
	}
}
