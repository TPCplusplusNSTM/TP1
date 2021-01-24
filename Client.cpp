#include "Client.h"
#include <assert.h>
namespace gestion {
	Client::Client(std::string name, int idclient) : _name(name), _idclient(idclient), _nbreservations(0) {}

	int Client::getIdClient() const {
		return _idclient;
	}
	std::string Client::getName() const {
		return _name;
	}
	int Client::getNbreservations() const {
		return _nbreservations;
	}

	void Client::editClient(std::string name, int idclient) {
		setName(name);
		setIdClient(idclient);
	}
	void Client::editNbReservations(int reservations) {
		_nbreservations = reservations;
	}
	void Client::addReservation() {
		_nbreservations += 1;
	}
	std::string Client::toStringClient() const {
		return "Nom = " + _name + ", ID = " + std::to_string(_idclient) + ", nb_reservations = " + std::to_string(_nbreservations);
	}
	void Client::setName(std::string name) {
		assert(name != "" && name != " ");
		_name = name;
	}
	void Client::setIdClient(int idclient) {
		_idclient = idclient;
	}

	std::string enterClient() {
		std::string name;
		std::cout << "Entrer le nom du client" << std::endl;
		std::cin >> name;
		return name;
	}

	std::ostream& operator<<(std::ostream& os, Client client) {
		os << client.toStringClient() << std::endl;
		return os;
	}
}
