#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>

namespace gestion {
	class Client {
	public:
		Client(std::string name, int idclient);
		int getIdClient() const;
		std::string getName() const;
		void editClient(std::string name, int idclient);
		std::string toStringClient() const;
		void setName(std::string name);
		void setIdClient(int idclient);
		void editNbReservations(int reservations);
		void addReservation();
	private:
		std::string _name;
		int _idclient;
		int _nbreservations;
	};
	std::ostream& operator<<(std::ostream& os, Client client);
	std::string enterClient();
}
#endif