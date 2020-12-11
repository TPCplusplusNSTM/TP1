#include "Client.h"
namespace client {
	Client::Client(std::string name, int idclient) : _name(name), _idclient(idclient), _nbreservations(0) {}

	int Client::getIdClient() const {
		return _idclient;
	}
	std::string Client::getName() const {
		return _name;
	}
	void Client::editClient(std::string name, int idclient) {
		if (name != "" && name != " ") {
			_name = name;
		}
		if (idclient != 0) {
			_idclient = idclient;
		}
	}
	void Client::editNbReservations(int reservations) {
		_nbreservations = reservations;
	}
	void Client::addReservation() {
		_nbreservations += 1;
	}
	std::string Client::toStringClient() const {
		return "Nom = " + _name + " ID = " + std::to_string(_idclient);
	}


}
