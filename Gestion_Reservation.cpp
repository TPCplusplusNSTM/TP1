#include "Hotel.h"
#include <iostream>
#include <vector>

int main() {
	//Création objet hotel
	gestion::Hotel h1("Le grand bleu", "Marseille", 1, 10);

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
	h1.addChambre(c1); h1.addChambre(c2); h1.addChambre(c3); h1.addChambre(c4); h1.addChambre(c5); h1.addChambre(c6); h1.addChambre(c7); h1.addChambre(c8); h1.addChambre(c9); h1.addChambre(c10);

	//Initialisation du vecteur _listeclients (classe Hotel)
	h1.addClient(cl1); h1.addClient(cl2); h1.addClient(cl3); h1.addClient(cl4); h1.addClient(cl5); h1.addClient(cl6); h1.addClient(cl7); h1.addClient(cl8); h1.addClient(cl9); h1.addClient(cl10);

	//Création objets Date
	date::Date d1(2021, 5, 1);
	date::Date d2(2021, 10, 1);

	date::Date d3(2021, 4, 1);
	date::Date d4(2022, 1, 16);

	date::Date d5(2021, 6, 22);
	date::Date d6(2022, 3, 6);

	date::Date d7(2021, 2, 10);
	date::Date d8(2023, 12, 25);

	date::Date d9(2021,2,10);
	date::Date d10(2021,2,12);

	//Création objets Reservation
	gestion::Reservation r1(1, d1, d2, 1, 1, 1);
	gestion::Reservation r2(2, d3, d4, 1, 2, 2);
	gestion::Reservation r3(3, d5, d6, 1, 3, 3);
	gestion::Reservation r4(4, d7, d8, 1, 4, 4);

	//Initialisation du vecteur _listereservations (classe Hotel)
	h1.addReservation(r1); h1.addReservation(r2); h1.addReservation(r3); h1.addReservation(r4);

	//affichage de l'hôtel
	std::cout << h1;




// 8.a)
	genre a = gestion::chooseTypeRoom();
	if (a == 0) {
		std::cout << "a = Single" << std::endl;
	}
	else {
		if (a == 1) {
			std::cout << "a = Double" << std::endl;
		}
		else {
			if (a == 2) {
				std::cout << "a = Suite" << std::endl;
			}
			else {
				std::cout << "a = Twin" << std::endl;
			}
		}
	}
	// 8.b)
	int index = h1.checkTypeDispo(a, d9, d10);
	h1.displayChambre(index);

    return 0;
}



