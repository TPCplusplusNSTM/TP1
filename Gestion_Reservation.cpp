#include "Hotel.h"
#include <cstdlib>

//====================================================================================================
//FONCTIONS DE TEST
//====================================================================================================

void testclasseClient() {
	std::cout << "On cree un client s'appelant Delacroix Michel et on lui attribue l'identifiant 1234 puis on verifie si tout fonctionne en utilisant ses getters" << std::endl;
	gestion::Client cli("Delacroix Michel", 1234);
	std::cout << "Nom du client = " << cli.getName() << std::endl << "Identifiant du client = " << cli.getIdClient() << std::endl << "Nombre de reservations = " << cli.getNbreservations() << std::endl;
	std::cout << "On modifie son nom en Dupuis Didier, son identifiant en 456 et son nombre de reservations en 2 avec nos methodes de modification" << std::endl;
	cli.editClient("Dupuis Didier", 456);
	cli.editNbReservations(2);
	std::cout << "Nom du client = " << cli.getName() << std::endl << "Identifiant du client = " << cli.getIdClient() << std::endl << "Nombre de reservations = " << cli.getNbreservations() << std::endl;
}

void testclasseChambre() {
	std::cout << "On cree une chambre ayant pour identifiant 2112, pour type Suite et pour prix 180" << std::endl;
	gestion::Chambre cha(2112, Suite, 180);
	std::cout << cha.chambre_to_string() << std::endl;
	std::cout << "On modifie son identifiant en 9889, son type en Double et son prix en 345 avec nos methodes de modification" << std::endl;
	cha.setId(9889);
	cha.setType(Double);
	cha.setPrice(345);
	std::cout << cha.chambre_to_string() << std::endl;
}

void testclasseHotel() {
	std::cout << "On cree un hotel ayant pour nom Hotel Fortune, pour ville Londres, pour identifiant 10 et pour capacité maximale de chambres 80" << std::endl;
	gestion::Hotel hot("HotelFortune", "Londres", 10, 80);
	gestion::Chambre cha(2112, Suite, 180);// on crée la chambre cha
	std::cout << hot;
	std::cout << "On va ajouter la chambre dans l'hotel avec la fonction addchambre()" << std::endl;
	hot.addChambre(cha);
	std::cout << hot;
}

void testclasseReservation() {
	std::cout << "On cree une reservation ayant pour tous les identifiants une valeur de 1, pour date de début le 12 juin 2023 et pour date de fin le 27 juin 2023" << std::endl;
	date::Date ddebut1(2023, 06, 12);
	date::Date dfin1(2023, 06, 27);
	gestion::Reservation res(1, ddebut1, dfin1, 1, 1, 1);
	std::cout << res.reservation_to_string() << std::endl;
	std::cout << "On modifie la date du debut au 09 mai 2022, la date de fin au 12 mai 2022 et le numero de la chambre en 23" << std::endl;
	date::Date ddebut2(2022, 05, 9);
	date::Date dfin2(2022, 05, 12);
	res.setDbegin(ddebut2);
	res.setDend(dfin2);
	res.setIdroom(23);
	std::cout << res.reservation_to_string() << std::endl;
	std::cout << "On affiche le cout de la reservation en supposant que le prix de la nuit coûte 100 euros et que l'on fait un remise de 10%" << std::endl;
	res.calc(100, 10);
}

void testValidationDates() {
	std::cout << "On va choisir les dates de réservations et afficher le nombre de nuits" << std::endl;
	gestion::Reservation r; // l'utilisateur ne pourra pas créer de réservations vide, nous utilisons le constructeur par défaut pour plus de simplicitée.
	r.enterDates();
}

void testChoixChambre(gestion::Hotel& h1, date::Date& d9, date::Date& d10) {
	genre a = gestion::chooseTypeRoom();
	int index = h1.checkTypeDispo(a, d9, d10);
	std::cout << "la chambre choisie est :" << std::endl;
	h1.displayChambre(index);
}

void testChoixClient(gestion::Hotel& h1) {
	std::cout << " voici afficher les clients de l'hotel : " << std::endl;
	h1.listClients();
	std::string nom = gestion::enterClient();
	int idclient = h1.chooseClient(nom);
	int index = h1.findClient(idclient);
	h1.searchAndDisplayClient(index);
}

void testValidationReservation(gestion::Hotel& h1) {
	h1.listReservations();
	h1.addReservation(h1.createReservation());
	h1.listReservations();
}

void testGestionReservations() {
	//11.b)
	//h1.searchAndDisplayReservation(4);

//11.c)
	//h1.displayClientReservations("Michel");

/*11.e)
h1.listReservations();
h1.cancelReservation();
h1.listReservations();
*/

/* 11 d)
h1.listReservations();
h1.setReservation();
h1.listReservations();
	return 0;
	*/
}

//====================================================================================================
// DEBUT MAIN PROGRAMME
//====================================================================================================

int main() {
	// Q.6)
	std::cout << "Question 6)" << std::endl;
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
	gestion::Client cl5("Jacky", 5);
	gestion::Client cl6("Lucas", 6);
	gestion::Client cl7("Jacky", 7);
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

	date::Date d9(2021, 2, 10);
	date::Date d10(2021, 2, 12);

	//Création objets Reservation
	gestion::Reservation r1(1, d1, d2, 1, 1, 1);
	gestion::Reservation r2(2, d3, d4, 1, 2, 2);
	gestion::Reservation r3(3, d5, d6, 1, 3, 3);
	gestion::Reservation r4(4, d7, d8, 1, 4, 4);

	//Initialisation du vecteur _listereservations (classe Hotel)
	h1.addReservation(r1); h1.addReservation(r2); h1.addReservation(r3); h1.addReservation(r4);

	//affichage de l'hôtel
	std::cout << h1;
	system("PAUSE");
	std::cout << std::endl;

	//----------------------------------------------------------------------------------------------------------------------

	//Question 2
	std::cout << "Question 2" << std::endl;
	testclasseClient();
	std::cout << std::endl;
	system("PAUSE");
	std::cout << std::endl;

	//Question 3
	std::cout << "Question 3" << std::endl;
	testclasseChambre();
	std::cout << std::endl;
	system("PAUSE");
	std::cout << std::endl;

	//Question 4
	std::cout << "Question 4" << std::endl;
	testclasseHotel();
	std::cout << std::endl;
	system("PAUSE");
	std::cout << std::endl;

	//Question 5
	std::cout << "Question 5" << std::endl;
	testclasseReservation();
	std::cout << std::endl;
	system("PAUSE");
	std::cout << std::endl;

	//Question 7
	std::cout << "Question 7" << std::endl;
	testValidationDates();
	std::cout << std::endl;
	system("PAUSE");
	std::cout << std::endl;

	//Question 8
	std::cout << "Question 8" << std::endl;
	testChoixChambre(h1,d9,d10);
	std::cout << std::endl;
	system("PAUSE");
	std::cout << std::endl;

	//Question 9
	std::cout << "Question 9" << std::endl;
	testChoixClient(h1);
	std::cout << std::endl;
	system("PAUSE");
	std::cout << std::endl;

	//Question 10
	std::cout << "Question 10" << std::endl;
	testValidationReservation(h1);
	std::cout << std::endl;
	system("PAUSE");
	std::cout << std::endl;

	//Question 11
	std::cout << "Question 11" << std::endl;
	testGestionReservations();
	std::cout << std::endl;
	system("PAUSE");
	std::cout << std::endl;

}

//====================================================================================================
// FIN MAIN PROGRAMME
//====================================================================================================

