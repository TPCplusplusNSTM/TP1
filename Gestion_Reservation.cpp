#include "Date.h"
#include "Client.h"
#include "Hotel.h"
#include "Reservation.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<gestion::Reservation> _listeresa;
	gestion::Hotel a("Le grand bleu", "Marseille", 1, 10);
	gestion::Chambre a1(1, Single, 100);
	gestion::Chambre a2(2, Single, 100);
	gestion::Chambre a3(3, Single, 100);
	gestion::Chambre a4(4, Double, 125);
	gestion::Chambre a5(5, Double, 125);
	gestion::Chambre a6(6, Double, 125);
	gestion::Chambre a7(7, Double, 125);
	gestion::Chambre a8(8, Double, 125);
	gestion::Chambre a9(9, Suite, 210);
	gestion::Chambre a10(10, Suite, 210);
	gestion::Client b1("Michel", 1);
	gestion::Client b2("Jacky", 2);
	gestion::Client b3("Dominique", 3);
	gestion::Client b4("Jean-Louis", 4);
	gestion::Client b5("Bernadette", 5);
	gestion::Client b6("Lucas", 6);
	gestion::Client b7("Nathan", 7);
	gestion::Client b8("Zain", 8);
	gestion::Client b9("Maxime", 9);
	gestion::Client b10("Emma", 10);
	a.addChambre(a1); a.addChambre(a2); a.addChambre(a3); a.addChambre(a4); a.addChambre(a5); a.addChambre(a6); a.addChambre(a7); a.addChambre(a8); a.addChambre(a9); a.addChambre(a10);
	a.addClient(b1); a.addClient(b2); a.addClient(b3); a.addClient(b4); a.addClient(b5); a.addClient(b6); a.addClient(b7); a.addClient(b8); a.addClient(b9); a.addClient(b10);
	std::cout << a;
    date::Date d1(2021, 5, 1);
    date::Date d2(2021, 10, 1);
    gestion::Reservation r1(1, d1, d2, 1, 1, 1);
    return 0;
}



