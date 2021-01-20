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
	std::vector<Chambre> Hotel::getListChambre() const {
		return _chambresliste;
	}
	

	void Hotel::addChambre(Chambre chambre) {
		assert(checkDoublonChambre(chambre) && "erreur : ID deja defini" );
		_chambresliste.push_back(chambre);
	}
	void Hotel::addClient(Client client) {
		assert(checkDoublonClient(client) && "erreur : ID deja defini");
		_clientsliste.push_back(client);
	}
	void Hotel::addReservation(Reservation reservation) {
		assert(checkDoublonReservation(reservation) && "erreur : ID deja defini");
		_reservationsliste.push_back(reservation);
		reservation.reservation_to_string();
	}
	Reservation Hotel::createReservation() {
		Reservation a;
		int index = -1;
		Date db; Date de;
		while (index == -1) {
			std::cout << "entrez la date de debut de sejour" << std::endl;
			db = a.enterDate();
			std::cout << "entrez la date de fin de sejour" << std::endl;
			de = a.enterDate();
			while (a.checkDates(db, de) == false) {
				std::cout << "entrez la date de debut de sejour" << std::endl;
				db = a.enterDate();
				std::cout << "entrez la date de fin de sejour" << std::endl;
				de = a.enterDate();
			}
			genre type = chooseTypeRoom();
			index = checkTypeDispo(type, db, de);
		}
		auto it =_chambresliste.begin()+ index;
		int idclient = 0;
		std::cout << "entrez l'ID du client" << std::endl;
		std::cin >> idclient;
		int idhotel = 0;
		std::cout << "entrez l'ID de l'hotel" << std::endl;
		std::cin >> idhotel;
		int idresa = 0;
		std::cout << "entrez l'ID de reservation" << std::endl;
		std::cin >> idresa;
		while (checkDoublonReservation(idresa) == false) {
			if (checkDoublonReservation(idresa) == false) {
				std::cout << "erreur: ID daje utilise" << std::endl;
			}
			std::cout << "entrez l'ID de reservation" << std::endl;
			std::cin >> idresa;
		}
		Reservation r(idresa, db, de, idhotel, it->id(), idclient);
		return r;
	}

	void Hotel::delChambre(int idchambre) {
		int index = findChambre(idchambre);
		_chambresliste.erase(_chambresliste.begin()+index);
	}
	void Hotel::delClient(int idclient) {
		int index = findClient(idclient);
		_clientsliste.erase(_clientsliste.begin()+index);
	}
	void Hotel::delReservation(int idresa) {
		int index = findReservation(idresa);
		_reservationsliste.erase(_reservationsliste.begin()+index);
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
	void Hotel::setReservation() {
		std::cout << "vous avez selectionne modifier reservation" << std::endl;
		int idresa = enterIDReservation();
		searchAndDisplayReservation(idresa); bool test = false;
		std::cout << "voulez-vous modifier cette reservation (Y/N)" << std::endl;
		while (test == false) {
			char a = 'a';
			std::cin >> a;
			if (a == 'Y') {
				auto it = _reservationsliste.begin() + findReservation(idresa);
				_reservationsliste.erase(it);
				_reservationsliste.emplace_back(createReservation());
				std::cout << "la reservation a bien ete modifie" << std::endl;
				test = true;
			} 
			else if (a == 'N') {
				std::cout << "annulation" << std::endl;
				test = true;
			}
			else { std::cout << "veuillez saisir (Y/N)" << std::endl; }
		}
	}

	int Hotel::checkTypeDispo(genre type, date::Date dbegin, date::Date dend) const{
		int index = 0;	
		auto it = _chambresliste.begin(); // on selectionne une chambre dans le vecteur
		while (it != _chambresliste.end()) { // on test le type de chambre
			if (type == it->type()) {
				bool testdates = false;
				auto it1 = _reservationsliste.begin(); // si le type concorde on regarde si il y a une reservation en cour
				bool idpresentdanslareservation = false; // cette variable va servir pour le cas "ID chambre non present dans les reservations"
				while (it1 != _reservationsliste.end()) {				
					if (it->id() == it1->idroom()) { // test l'ID de la chambre et la période de séjour (relation reservation/chambre)
						idpresentdanslareservation = true;
						switch (index) { // on test la possibilité de plusieurs réservations sur des périodes différents
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
		return index = -1;
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

	void Hotel::cancelReservation() {
		std::cout << "vous avez selectionne annuler reservation" << std::endl;
		int idresa = enterIDReservation();
		searchAndDisplayReservation(idresa); bool test = false;
		std::cout << "voulez-vous annuler cette reservation (Y/N)" << std::endl;
		while (test == false) {
			char a = 'a';
			std::cin >> a;
			switch (a) {
			case 'Y':
				delReservation(idresa);
				std::cout << "la reservation a bien ete annule" << std::endl;
				test = true;
				break;
			case 'N':
				std::cout << "annulation" << std::endl;
				test = true;
				break;
			default:
				std::cout << "veuillez saisir (Y/N)" << std::endl;
			}
		}

	}

	int Hotel::chooseClient(std::string name) const {
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
				return it1->getIdClient();
			}
			++it1;
			indice++;
		}
		std::cout << "Aucun client ne porte ce nom ou le numéro du client choisi est erroné, veuillez recommencer" << std::endl;
		assert(indice > numeroclient && numeroclient >= 1); // On met une condition qui ne peut être vrai à la sortie de la boucle ce qui permet d'arrêter le programme 
	}

	int Hotel::findChambre(int idchambre) const {
		auto it = _chambresliste.begin();
		it = find_if(it, _chambresliste.end(), [idchambre](const Chambre& obj) {return obj.id() == idchambre; });
		if (it != _chambresliste.end()) {
			std::cout << "chambre choisi : " << *it;
			return std::distance(_chambresliste.begin(), it);
		}
		else {
			assert(it == _chambresliste.end() && "erreur : la chambre choisi n'existe pas");
		}
	}
	int Hotel::findClient(int idclient) const {
		auto it = _clientsliste.begin();
		it = find_if(it, _clientsliste.end(), [idclient](const Client& obj) {return obj.getIdClient() == idclient; });
		if (it != _clientsliste.end()) {
			std::cout << "client choisi : " << *it;
			return std::distance(_clientsliste.begin(), it);
		}
		else {
			assert(it == _clientsliste.end() && "erreur : le client choisi n'existe pas");
		}
	}

	int Hotel::findReservation(int idresa) const {
		auto it = _reservationsliste.begin();
		it = find_if(it, _reservationsliste.end(), [idresa](const Reservation& obj) {return obj.idres() == idresa; });
		if (it != _reservationsliste.end()) {
			std::cout << "reservation choisi : " << *it;
			return std::distance(_reservationsliste.begin(), it);
		}
		else {
			assert(it == _reservationsliste.end() && "erreur : la reservation choisi n'existe pas");
		}
	}

	void Hotel::searchAndDisplayReservation(int idresa) const {
		auto it = _reservationsliste.begin();
		it = find_if(it, _reservationsliste.end(), [idresa](const Reservation& obj) {return obj.idres() == idresa; });
		if (it != _reservationsliste.end()) {
			std::cout << "reservation choisi : " << *it;
		}
		else {
			std::cout << "erreur: la reservation n'existe pas";
		}
	}

	void Hotel::displayClientReservations(int idclient) const {
		std::vector<Reservation> results;
		auto it = _reservationsliste.begin();
		while (it != _reservationsliste.end()) {
			it = find_if(it, _reservationsliste.end(), [idclient](const Reservation& obj) {return obj.idcli() == idclient; });
			if (it != _reservationsliste.end()) {
				results.push_back(*it);
				++it;
			}
		}
		if (results.empty() == false) {
			std::cout << "liste des réservations du client :" << std::to_string(idclient) << std::endl;
			auto it = results.begin();
			while (it != results.end()) {
				std::cout << *it;
				++it;
			}
		}
		else {
			std::cout << "Le client sélectionné n'a pas de réservations" << std::endl;
		}
	}

	void Hotel::displayClientReservations(std::string nom) const { // on surcharge la fonction pour le nom
		displayClientReservations(chooseClient(nom));
	}

	int Hotel::newIdClient() {
		int id = 0;
		bool estValide = false;
		while (!estValide) {
			auto it = _clientsliste.begin();
			while (it != _clientsliste.end()) {
				if (id != it->getIdClient()) {
					return id;
				}
				else { it++; }
			}
			id++;
		}
	}

	int Hotel::newIdReservation() {
		int id = 0;
		bool estValide = false;
		while (!estValide) {
			auto it = _reservationsliste.begin();
			while (it != _reservationsliste.end()) {
				if (id != it->idres()) {
					return id;
				}
				else { it++; }
			}
			id++;
		}
	}

	bool Hotel::checkDoublonClient(int idclient) const {
		auto it = _clientsliste.begin();
		it = find_if(it, _clientsliste.end(), [idclient](const Client& obj) {return obj.getIdClient() == idclient; });
		if (it != _clientsliste.end()) {
			return false;
		}
		else {
			return true;
		}
		
	}

	bool Hotel::checkDoublonClient(Client client) const {
		return checkDoublonClient(client.getIdClient());
	}

	bool Hotel::checkDoublonChambre(int idchambre) const {
		auto it = _chambresliste.begin();
		it = find_if(it, _chambresliste.end(), [idchambre](const Chambre& obj) {return obj.id() == idchambre; });
		if (it != _chambresliste.end()) {
			return false;
		}
		else {
			return true;
		}
	}

	bool Hotel::checkDoublonChambre(Chambre chambre) const {
		return checkDoublonChambre(chambre.id());
	}

	bool Hotel::checkDoublonReservation(int idresa) const {
		auto it = _reservationsliste.begin();
		it = find_if(it, _reservationsliste.end(), [idresa](const Reservation& obj) {return obj.idres() == idresa; });
		if (it != _reservationsliste.end()) {
			return false;
		}
		else {
			return true;
		}
	}

	bool Hotel::checkDoublonReservation(Reservation resa) const {
		return checkDoublonReservation(resa.idres());
	}

	void operator<<(std::ostream& os, Hotel hotel){
		hotel.displayHotel();
	}
}
