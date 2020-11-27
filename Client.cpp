#include "Client.h"
namespace client {
	Client::Client(std::string name, int idclient) : _name(name), _idclient(idclient) {}

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
	std::string Client::toStringClient() const {
		return "Nom = " + _name + " ID = " + std::to_string(_idclient);
	}


}
