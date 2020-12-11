#include "Client.h"
#include <assert.h>
namespace client {
	Client::Client(std::string name, int idclient) : _name(name), _idclient(idclient), _nbreservations(0) {}

	int Client::getIdClient() const {
		return _idclient;
	}
	std::string Client::getName() const {
		return _name;
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
		return "Nom = " + _name + " ID = " + std::to_string(_idclient);
	}
	void Client::setName(std::string name) {
		assert(name != "" && name != " ");
		_name = name;
	}
	void Client::setIdClient(int idclient) {
		assert(idclient != 0);
		_idclient = idclient;
	}

}
