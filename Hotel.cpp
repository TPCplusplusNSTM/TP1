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
	int Hotel::testAndAddClient() {
		int id = -1;
		//On demande le nom client ayant fait la réservation
		std::string name = gestion::enterClient();

		//On demande si le client est déja dans l'hôtel
		std::string estDansHotel = "test";
		while (estDansHotel == "test") {
			std::cout << "Le client est-il nouveau dans l'hôtel ? Entrer oui/non :";
			std::cin >> estDansHotel;
			std::cout << std::endl;

			//Si il n'est pas dans l'hôtel on l'ajoute, sinon on demande de choisir quel client choisir
			if (estDansHotel == "oui") {
				id = newIdClient();
				gestion::Client c(name, id);
				addClient(c);
			}
			else if (estDansHotel == "non") {
				id = chooseClient(name);
			}
			else {
				estDansHotel = "test";
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
		double prix_nuit = 0.0;
		double remise = 0.0;
		int id = 0;
		

		//On suppose que l'on rajoute les réservations dans l'hôtel h1
		ri.setIdhot(getIdHotel());
		int index = -1;
			while (index == -1) { // cette boucle while sert en cas de chambre indisponible
			// On commence par entrer les dates dans la reservation
			ri.enterDates();

			//On demande ensuite le prix d'une nuit et la remise sur le séjour
			std::cout << "Entrer le prix d'une nuit: ";
			std::cin >> prix_nuit;
			std::cout << std::endl << "Entrer la remise: ";
			std::cin >> remise;
			std::cout << std::endl;

			//On calcule le prix du séjour
			ri.calc(prix_nuit, remise);

			//On demande le type de chambre
			genre type = gestion::chooseTypeRoom();

			//On regarde si ce type de chambre est disponible et on stocke son index si elle l'est
			index = checkTypeDispo(type, ri.dbegin(), ri.dend()); // revoie -1 si chambre indisponible
			}

		//On ajoute l'identifiant de la chambre à la réservation
		std::vector<gestion::Chambre> listechambres = getListChambre();
		ri.setIdroom(listechambres[index].id());

		
		//On ajoute l'identifiant du client à la réservation
		id = testAndAddClient();
		ri.setIdclient(id);

		//On affecte un identifiant de réservation
		ri.setIdres(newIdReservation());
		
	return ri; //On retourne la réservation
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
		assert(checkDoublonReservation(idresa) == false && "Erreur : la reservation selectionne n'existe pas");
		auto it = _reservationsliste.begin() + findReservation(idresa);
		searchAndDisplayReservation(idresa); bool test = false;
		std::cout << "voulez-vous modifier cette reservation (Y/N)" << std::endl;
		while (test == false) {
			char a = 'a';
			std::cin >> a;
			if (a == 'Y') {
				std::cout << "entrez le numéro correspondant au type de modifications : " << std::endl;
				std::cout << " (1) : ID reservation " << std::endl;
				std::cout << " (2) : Dates de réservations " << std::endl;
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
					double prix_nuit = 0.0;
					double remise = 0.0;
					int index = -1;
					it->enterDates();

					//On demande ensuite le prix d'une nuit et la remise sur le séjour
					std::cout << "Entrer le prix d'une nuit: ";
					std::cin >> prix_nuit;
					std::cout << std::endl << "Entrer la remise: ";
					std::cin >> remise;
					std::cout << std::endl;

					//On calcule le prix du séjour
					it->calc(prix_nuit, remise);

					//On demande le type de chambre
					genre type = gestion::chooseTypeRoom();

					//On regarde si ce type de chambre est disponible et on stocke son index si elle l'est
					index = checkTypeDispo(type, it->dbegin(), it->dend()); // revoie -1 si chambre indisponible


					//On ajoute l'identifiant de la chambre à la réservation
					std::vector<gestion::Chambre> listechambres = getListChambre();
					it->setIdroom(listechambres[index].id());
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
				else { std::cout << " Erreur : aucune option sélectionne " << std::endl; }
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
		std::cout << "Choisissez le numero devant le client vous convenant" << std::endl;
		std::cin >> numeroclient; // On conserve le numéro devant le client voulu
		auto it1 = stockage.begin();
		while (it1 != stockage.end()) {
			if (indice == numeroclient) {
				return it1->getIdClient();
			}
			++it1;
			indice++;
		}
		std::cout << "Aucun client ne porte ce nom ou le numero du client choisi est errone, veuillez recommencer" << std::endl;
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

	void Hotel::searchAndDisplayChambre(int idchambre) const {
		auto it = _chambresliste.begin();
		it = find_if(it, _chambresliste.end(), [idchambre](const Chambre& obj) {return obj.id() == idchambre; });
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

	double priceRoom(Hotel hotel, int idroom) {
		std::vector<Chambre> chambresliste = hotel.getListChambre();
		auto it = chambresliste.begin();
		it = find_if(it, chambresliste.end(), [idroom](const Chambre& obj) {return obj.id() == idroom; });
		if (it != chambresliste.end()) {
			std::cout << "chambre choisi : " << *it;
			return it->price();
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
		double price = priceRoom(hotel, reservation.idroom());
		int days = 0;
		date::Date dind = reservation.dbegin();
		while (dind != reservation.dend()) {
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
