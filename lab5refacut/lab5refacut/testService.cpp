#include "testService.h"
#include "service.h"
#include <assert.h>

void test_service()
{
	/*Adaugare*/
	Service serv;
	char* titlu1 = new char[10], * data1 = new char[10], * genul1 = new char[10];
	char* titlu2 = new char[10], * data2 = new char[10], * genul2 = new char[10];

	strcpy_s(titlu1, sizeof "Joker", "Joker");
	strcpy_s(data1, sizeof "04.05.2020", "04.05.2020");
	strcpy_s(genul1, sizeof "drama", "drama");
	Film f1(titlu1, data1, genul1);

	strcpy_s(titlu2, sizeof "Frozen", "Frozen");
	strcpy_s(data2, sizeof "16.04.2020", "16.04.2020");
	strcpy_s(genul2, sizeof "animatie", "animatie");
	Film f2(titlu2, data2, genul2);
	serv.add_film_service(f1);
	serv.add_film_service(f2);
	assert(strcmp(serv.get_all()[0].get_data(), "04.05.2020") == 0);

	/*Update*/
	char* titlu3 = new char[10], * data3 = new char[10], * genul3 = new char[10];
	strcpy_s(titlu3, sizeof "Anohana", "Anohana");
	strcpy_s(data3, sizeof "17.05.2020", "17.05.2020");
	strcpy_s(genul3, sizeof "drama", "drama");
	serv.update_film_service(f1, titlu3, data3, genul3);
	assert(strcmp(serv.get_all()[0].get_data(), "17.05.2020") == 0);

	/*Delete*/
	serv.delete_film_service(f2);
	assert(serv.get_size() == 1);

	/*Test eliminare filme dupa o data calendaristica*/
	Film f3(titlu1, data1, genul1);
	serv.add_film_service(f3);
	assert(serv.get_size() == 2);
	char* data_calendaristica = new char[10];
	strcpy_s(data_calendaristica, sizeof "06.05.2020", "06.05.2020");
	serv.eliminare_filme_lansate_inainte_de_data(data_calendaristica);
	assert(serv.get_size() == 1);

	/*Test filtrare dupa gen*/
	Film f4(titlu1, data1, genul1);
	serv.add_film_service(f4);
	assert(serv.get_size() == 2);


	cout << "Testele pentru service au fost terminate cu succes!" << endl;
}