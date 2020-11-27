#ifndef CLIENT_H
#define CLIENT_H
#include <string>

namespace client {
	class Client {
	public:
		Client(std::string name, int idclient);
		int getIdClient() const;
		std::string getName() const;
		void editClient(std::string name, int idclient);
		std::string toStringClient() const;

	private:
		std::string _name;
		int _idclient;
	};
}
#endif