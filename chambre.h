#ifndef CHAMBRE_H
#define CHAMBRE_H

enum genre {Single, Double, Suite,Twin};

namespace gestion {
	class Chambre
	{
	private:
		int id_;
		genre type_;
		int price_;
	public:
		Chambre(int id, genre type, int price);
		int id() const;
		genre type() const;
		int price() const;
		void setRoom(int id, genre type, int price);

	};
};

#endif
