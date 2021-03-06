#include "Hotel.h"

namespace gestion {
	Hotel::Hotel(std::string name, std::string ville, int idhotel, int maxnbchambres) : _name(name), _idhotel(idhotel), _ville(ville), _maxnbchambres(maxnbchambres) { assert(idhotel >= 0 && maxnbchambres >= 0); }
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
	int Hotel::testAndAddClient() {
		int id = -1;
		//On demande le nom du client ayant fait la r�servation
		std::string name = gestion::enterClient();

		//On demande si le client est d�ja dans l'h�tel
		std::string nouveaudanshotel = "test";
		while (nouveaudanshotel == "test") {
			std::cout << "Le client est-il nouveau dans l'hotel ? Entrer oui/non :";
			std::cin >> nouveaudanshotel;
			std::cout << std::endl;

			//Si il n'est pas dans l'h�tel on l'ajoute, sinon on demande de choisir quel client choisir
			if (nouveaudanshotel == "oui") {
				id = newIdClient();
				gestion::Client c(name, id);
				addClient(c);
			}
			else if (nouveaudanshotel == "non") {
				id = chooseClient(name);
			}
			else {
				nouveaudanshotel = "test";
				std::cout << "Erreur : veuillez entrer oui/non :" << std::endl;
			}
		}
		return id;
	}
	void Hotel::addReservation(Reservation reservation) {
		assert(checkDoublonReservation(reservation) && "erreur : ID deja defini");
		_reservationsliste.push_back(reservation);
		reservation.reservation_to_string();
	}
	Reservation Hotel::createReservation() {
		gestion::Reservation ri;
		int id = -1;
		//On suppose que l'on rajoute les r�servations dans l'h�tel h1
		ri.setIdhot(getIdHotel());
		
		//Determination des dates et de la chambre
		setDatesAndRoom(ri);
		
		//On ajoute l'identifiant du client � la r�servation
		id = testAndAddClient();
		ri.setIdclient(id);

		//On affecte un identifiant de r�servation
		ri.setIdres(newIdReservation());
		
	return ri; //On retourne la r�servation
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
		assert(checkDoublonReservation(idresa) == false && "Erreur : la reservation selectionne n'existe pas");
		auto it = _reservationsliste.begin() + findReservation(idresa);
		bool test = false;
		std::cout << "voulez-vous modifier cette reservation (Y/N)" << std::endl;
		while (test == false) {
			char a = 'a';
			std::cin >> a;
			if (a == 'Y') {
				std::cout << "entrez le numero correspondant au type de modifications : " << std::endl;
				std::cout << " (1) : ID reservation " << std::endl;
				std::cout << " (2) : Dates de reservations " << std::endl;
				std::cout << " (3) : ID hotel " << std::endl;
				std::cout << " (4) : ID client " << std::endl;
				int b = 0;
				std::cin >> b;
				if (b == 1) {
					int id = -1;
					std::cout << " entrez l'ID de reservation souhaite " << std::endl;
					std::cin >> id;
					if (checkDoublonReservation(id) == true && id >= 0) {
						it->setIdres(id);
					}
					else { std::cout << "Erreur : l'ID selectionne existe deja ou est negatif " << std::endl; }
				}
				else if (b == 2) {
					date::Date debut(0, 0, 0);
					date::Date fin(0, 0, 1);
					it->setDbegin(debut); it->setDend(fin); //on evite les conflits de dates avec la r�servation que l'on veut modifier
					setDatesAndRoom(*it);				
				}
				else if (b==3){
					std::cout << " entrez l'ID d'hotel souhaite " << std::endl;
					int id = -1;
					std::cin >> id;
					it->setIdhot(id);
				}
				else if (b == 4) {
					int id = -1;
					id = testAndAddClient();
					it->setIdclient(id);
				}
				else { std::cout << " Erreur : aucune option selectionne " << std::endl; }
				test = true;
			} 
			else if (a == 'N') {
				std::cout << "annulation" << std::endl;
				test = true;
			}
			else { std::cout << "veuillez saisir (Y/N)" << std::endl; }
		}
	}
	void Hotel::setDatesAndRoom(Reservation& resa) {
		int index = -1; double remise = 0.0;
		while (index == -1) {
			resa.enterDates();

			//On demande le type de chambre
			genre type = gestion::chooseTypeRoom();

			//On regarde si ce type de chambre est disponible et on stocke son index si elle l'est
			index = checkTypeDispo(type, resa.getDbegin(), resa.getDend()); // revoie -1 si chambre indisponible
		}
		//On ajoute l'identifiant de la chambre � la r�servation
		std::vector<gestion::Chambre> listechambres = getListChambre();
		resa.setIdroom(listechambres[index].getIdChambre());

		//On demande ensuite la remise sur le s�jour
		std::cout << std::endl << "Entrer la remise: ";
		std::cin >> remise;
		std::cout << std::endl;

		//On calcule le prix du s�jour
			resa.calc(listechambres[index].getPrice(), remise);
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

	

	int Hotel::chooseClient(std::string name) const {
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
		std::cout << "Choisissez le numero devant le client vous convenant" << std::endl;
		std::cin >> numeroclient; // On conserve le num�ro devant le client voulu
		auto it1 = stockage.begin();
		while (it1 != stockage.end()) {
			if (indice == numeroclient) {
				return it1->getIdClient();
			}
			++it1;
			indice++;
		}
		std::cout << "Aucun client ne porte ce nom ou le numero du client choisi est errone, veuillez recommencer" << std::endl;
		assert(indice > numeroclient && numeroclient >= 1); // On met une condition qui ne peut �tre vrai � la sortie de la boucle ce qui permet d'arr�ter le programme 
	}

	int Hotel::findChambre(int idchambre) const {
		auto it = _chambresliste.begin();
		it = find_if(it, _chambresliste.end(), [idchambre](const Chambre& obj) {return obj.getIdChambre() == idchambre; });
		if (it != _chambresliste.end()) {
			std::cout << "chambre choisi : " << *it;
			return std::distance(_chambresliste.begin(), it);
		}
		else {
			assert(it == _chambresliste.end() && "erreur : la chambre choisi n'existe pas");
		}
	}

	void Hotel::searchAndDisplayChambre(int idchambre) const {
		auto it = _chambresliste.begin();
		it = find_if(it, _chambresliste.end(), [idchambre](const Chambre& obj) {return obj.getIdChambre() == idchambre; });
		if (it != _chambresliste.end()) {
			std::cout << "chambre choisi : " << *it;
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

	void Hotel::searchAndDisplayClient(int idclient) const {
		auto it = _clientsliste.begin();
		it = find_if(it, _clientsliste.end(), [idclient](const Client& obj) {return obj.getIdClient() == idclient; });
		if (it != _clientsliste.end()) {
			std::cout << "client choisi : " << *it;
		}
		else {
			assert(it == _clientsliste.end() && "erreur : le client choisi n'existe pas");
		}
	}

	int Hotel::findReservation(int idresa) const {
		auto it = _reservationsliste.begin();
		it = find_if(it, _reservationsliste.end(), [idresa](const Reservation& obj) {return obj.getIdRes() == idresa; });
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
		it = find_if(it, _reservationsliste.end(), [idresa](const Reservation& obj) {return obj.getIdRes() == idresa; });
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
			it = find_if(it, _reservationsliste.end(), [idclient](const Reservation& obj) {return obj.getIdClient() == idclient; });
			if (it != _reservationsliste.end()) {
				results.push_back(*it);
				++it;
			}
		}
		if (results.empty() == false) {
			std::cout << "liste des reservations du client :" << std::to_string(idclient) << std::endl;
			auto it = results.begin();
			while (it != results.end()) {
				std::cout << *it;
				++it;
			}
		}
		else {
			std::cout << "Le client selectionne n'a pas de reservations" << std::endl;
		}
	}

	void Hotel::displayClientReservations(std::string nom) const { // on surcharge la fonction pour le nom
		displayClientReservations(chooseClient(nom));
	}

	int Hotel::newIdClient() {
		int id = 1; int r = 0;
		bool estValide = false;
		while (estValide==false) {
			estValide = true;
			auto it = _clientsliste.begin();
			while (it != _clientsliste.end()) {
				if (id == it->getIdClient()) {
					estValide = false;
					it++;
				}
				else { it++; }
			}
			r = id;
			id++;
		}
		return r;
	}

	int Hotel::newIdReservation() {
		int id = 1; int r = 0;
		bool estValide = false;
		while (estValide==false) {
			estValide = true;
			auto it = _reservationsliste.begin();
			while (it != _reservationsliste.end()) {
				if (id == it->getIdRes()) {
					estValide=false;
					it++;
				}
				else { it++; }
			}
			r = id;
			id++;
		}
		return r;
	}

	int Hotel::checkTypeDispo(genre type, date::Date dbegin, date::Date dend) const {
		int index = 0;
		auto it = _chambresliste.begin(); // on selectionne une chambre dans le vecteur
		while (it != _chambresliste.end()) { // on test le type de chambre
			if (type == it->getType()) {
				bool testdates = false;
				auto it1 = _reservationsliste.begin(); // si le type concorde on regarde si il y a une reservation en cours
				bool idpresentdanslareservation = false; // cette variable va servir pour le cas "ID chambre non present dans les reservations"
				while (it1 != _reservationsliste.end()) {
					if (it->getIdChambre() == it1->getIdChambre()) { // test l'ID de la chambre et la p�riode de s�jour (relation reservation/chambre)
						idpresentdanslareservation = true;
						switch (index) { // on test la disponibilit�e de plusieurs r�servations sur des p�riodes diff�rentes
						case 0:
							if ((dbegin < it1->getDbegin() && dend < it1->getDbegin()) || (dbegin > it1->getDend() && dend > it1->getDend())) { // on check les dates strictements inf ou sup aux dates de reservations en cours
								index = std::distance(_chambresliste.begin(), it);
								testdates = true;
							}
							break;
						default:
							if ((dbegin < it1->getDbegin() && dend < it1->getDbegin()) || (dbegin > it1->getDend() && dend > it1->getDend())) {} // on check les dates strictements inf ou sup aux dates de reservations en cours
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
		it = find_if(it, _chambresliste.end(), [idchambre](const Chambre& obj) {return obj.getIdChambre() == idchambre; });
		if (it != _chambresliste.end()) {
			return false;
		}
		else {
			return true;
		}
	}

	bool Hotel::checkDoublonChambre(Chambre chambre) const {
		return checkDoublonChambre(chambre.getIdChambre());
	}

	bool Hotel::checkDoublonReservation(int idresa) const {
		auto it = _reservationsliste.begin();
		it = find_if(it, _reservationsliste.end(), [idresa](const Reservation& obj) {return obj.getIdRes() == idresa; });
		if (it != _reservationsliste.end()) {
			return false;
		}
		else {
			return true;
		}
	}

	bool Hotel::checkDoublonReservation(Reservation resa) const {
		return checkDoublonReservation(resa.getIdRes());
	}

//=================================================================================================
// free functions
//=================================================================================================

	double priceRoom(Hotel hotel, int idroom) {
		std::vector<Chambre> chambresliste = hotel.getListChambre();
		auto it = chambresliste.begin();
		it = find_if(it, chambresliste.end(), [idroom](const Chambre& obj) {return obj.getIdChambre() == idroom; });
		if (it != chambresliste.end()) {
			std::cout << "chambre choisi : " << *it;
			return it->getPrice();
		}
		else {
			assert(it == chambresliste.end() && "erreur : la chambre choisi n'existe pas");
		}
	}

	void calc(Hotel hotel, Reservation reservation) {
		double remise;
		std::cout << "Entrer la remise faite : ";
		std::cin >> remise;
		std::cout << std::endl;
		double price = priceRoom(hotel, reservation.getIdChambre());
		int days = 0;
		date::Date dind = reservation.getDbegin();
		while (dind != reservation.getDend()) {
			dind.nextDay();
			days++;
		};
		double total = price * days * (1 - remise / 100);
		reservation.setTotal(total);
		std::cout << "Le prix du sejour sera de " << total << " euros" << std::endl;
	}
	
	void operator<<(std::ostream& os, Hotel hotel){
		hotel.displayHotel();
	}
}
