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
		int getNbreservations() const;

		void setName(std::string name);
		void setIdClient(int idclient);
		void editClient(std::string name, int idclient);

		void editNbReservations(int reservations); // inutilisé dans le programme peut premettre un système de fidélité
		void addReservation();

		std::string toStringClient() const;

	private:
		std::string _name;
		int _idclient;
		int _nbreservations;
	};
	std::ostream& operator<<(std::ostream& os, Client client);
	std::string enterClient();
}
#endif