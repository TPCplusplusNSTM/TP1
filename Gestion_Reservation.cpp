#include "Date.h"
#include "Client.h"
#include "Hotel.h"
#include "Reservation.h"
#include <iostream>
#include <vector>

int main() {
	//Création objet hotel
	gestion::Hotel a("Le grand bleu", "Marseille", 1, 10);

	//Création objets Chambre
	gestion::Chambre c1(1, Single, 100);
	gestion::Chambre c2(2, Single, 100);
	gestion::Chambre c3(3, Single, 100);
	gestion::Chambre c4(4, Double, 125);
	gestion::Chambre c5(5, Double, 125);
	gestion::Chambre c6(6, Double, 125);
	gestion::Chambre c7(7, Double, 125);
	gestion::Chambre c8(8, Double, 125);
	gestion::Chambre c9(9, Suite, 210);
	gestion::Chambre c10(10, Suite, 210);

	//Création objets Client
	gestion::Client cl1("Michel", 1);
	gestion::Client cl2("Jacky", 2);
	gestion::Client cl3("Dominique", 3);
	gestion::Client cl4("Jean-Louis", 4);
	gestion::Client cl5("Bernadette", 5);
	gestion::Client cl6("Lucas", 6);
	gestion::Client cl7("Nathan", 7);
	gestion::Client cl8("Zain", 8);
	gestion::Client cl9("Maxime", 9);
	gestion::Client cl10("Emma", 10);

	//Initialisation du vecteur _listechambres (classe Hotel)
	a.addChambre(c1); a.addChambre(c2); a.addChambre(c3); a.addChambre(c4); a.addChambre(c5); a.addChambre(c6); a.addChambre(c7); a.addChambre(c8); a.addChambre(c9); a.addChambre(c10);

	//Initialisation du vecteur _listeclients (classe Hotel)
	a.addClient(cl1); a.addClient(cl2); a.addClient(cl3); a.addClient(cl4); a.addClient(cl5); a.addClient(cl6); a.addClient(cl7); a.addClient(cl8); a.addClient(cl9); a.addClient(cl10);

	//affichage de l'hôtel
	std::cout << a;

	//Création objets Date
    date::Date d1(2021,5,1);
    date::Date d2(2021,10,1);

	date::Date d3(2021,4,1);
	date::Date d4(2022,1,16);

	date::Date d5(2021,6,22);
	date::Date d6(2022,3,6);

	date::Date d7(2021,2,10);
	date::Date d8(2023,12,25);

	//Création objets Reservation
    gestion::Reservation r1(1, d1, d2, 1, 1, 1);
	gestion::Reservation r2(2, d3, d4, 1, 2, 2);
	gestion::Reservation r3(3, d5, d6, 1, 3, 3);
	gestion::Reservation r4(4, d7, d8, 1, 4, 4);

    return 0;
}



