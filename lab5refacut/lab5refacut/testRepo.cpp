#include "testRepo.h"
#include "repo.h"
#include <assert.h>
using namespace std;
#include <iostream>

void test_repo()
{
	Repo repo;
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

	Film filme[3];
	filme[0] = f1;
	filme[1] = f2;
	repo.add_film_repo(f1);
	repo.add_film_repo(f2);

	for (int i = 0; i < repo.get_size(); i++)
	{
		assert(repo.get_all()[i] == filme[i]);
	}

	repo.delete_film_repo(f2);
	assert(repo.get_size() == 1);

	char* titlu3 = new char[10], * data3 = new char[10], * genul3 = new char[10];
	strcpy_s(titlu3, sizeof "Anohana", "Anohana");
	strcpy_s(data3, sizeof "17.05.2020", "17.05.2020");
	strcpy_s(genul3, sizeof "drama", "drama");
	repo.update_film_repo(f1, titlu3, data3, genul3);
	assert(strcmp(repo.get_all()[0].get_data(), "17.05.2020") == 0);

	cout << "Testele pentru repo au fost terminate cu succes!" << endl;
}