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
		reservation.reservation_to_string();
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
		auto it = _chambresliste.begin(); // on selectionne une chambre dans le vecteur
		while (it != _chambresliste.end()) { // on test le type de chambre
			if (type == it->type()) {
				bool testdates = false;
				auto it1 = _reservationsliste.begin(); // si le type concorde on regarde si il y a une reservation en cour
				bool idpresentdanslareservation = false; // cette variable va servir pour le cas "ID chambre non present dans les reservations"
				while (it1 != _reservationsliste.end()) {				
					if (it->id() == it1->idroom()) { // test l'ID de la chambre et la p�riode de s�jour (relation reservation/chambre)
						idpresentdanslareservation = true;
						switch (index) { // on test la possibilit� de plusieurs r�servations sur des p�riodes diff�rents
						case 0:
							if ((dbegin < it1->dbegin() && dend < it1->dbegin()) || (dbegin > it1->dend() && dend > it1->dend())) { // on check les dates strictement inf ou sup au dates de reservations en cours
								index = std::distance(_chambresliste.begin(), it);
								testdates = true;
							}
							break;
						default:
							if ((dbegin < it1->dbegin() && dend < it1->dbegin()) || (dbegin > it1->dend() && dend > it1->dend())) {} // on check les dates strictement inf ou sup au dates de reservations en cours
							else { testdates = false; }
						}
					}
					++it1;
				}
				if (testdates == true) {
					return index;
				}
				else if (idpresentdanslareservation == false) {
					index = std::distance(_chambresliste.begin(), it);
					return index;
				}
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

	int Hotel::chooseClient(std::string name) {
		auto it = _clientsliste.begin();
		int numeroclient = 1; // Cette variable servira � afficher l'ordre dans lequel les clients sont trouv�s puis � conserver le num�ro du client voulu
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
		std::cout << "Choisissez le num�ro devant le client vous convenant" << std::endl;
		std::cin >> numeroclient; // On conserve le num�ro devant le client voulu
		auto it1 = stockage.begin();
		while (it1 != stockage.end()) {
			if (indice == numeroclient) {
				return it1->getIdClient();
			}
			++it1;
			indice++;
		}
		std::cout << "Aucun client ne porte ce nom ou le num�ro du client choisi est erron�, veuillez recommencer" << std::endl;
		assert(indice > numeroclient && numeroclient >= 1); // On met une condition qui ne peut �tre vrai � la sortie de la boucle ce qui permet d'arr�ter le programme 
	}

	void Hotel::searchAndDisplayReservation(int idresa) const {
		auto it = _reservationsliste.begin();
		it = find_if(it, _reservationsliste.end(), [idresa](const Reservation& obj) {return obj.idres() == idresa; });
		if (it != _reservationsliste.end()) {
			std::cout << *it;
		}
		else {
			std::cout << "erreur: la reservation n'existe pas";
		}
	}

	void operator<<(std::ostream& os, Hotel hotel) {
		hotel.displayHotel();
	}
}
