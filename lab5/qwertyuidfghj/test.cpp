#include "test.h"
#include "repo.h"
#include <cassert>
using namespace std;
#include <iostream>

void tests() {
	char* nume1 = new char[10], * data1 = new char[10], * gen1 = new char[10];
	char* nume2 = new char[10], * data2 = new char[10], * gen2 = new char[10];

	strcpy_s(nume1, sizeof "Joker", "Joker");
	strcpy_s(data1, sizeof "04.05.2020", "04.05.2020");
	strcpy_s(gen1, sizeof "drama", "drama");
	Filme s1(nume1, data1, gen1);

	strcpy_s(nume2, sizeof "Frozen", "Frozen");
	strcpy_s(data2, sizeof "16.04.2020", "16.04.2020");
	strcpy_s(gen2, sizeof "animatie", "animatie");
	Filme s2(nume2, data2, gen2);
	Repo repo;
	Filme gestiune[3];
	gestiune[0] = s1;
	gestiune[1] = s2;
	repo.insert(s1);
	repo.insert(s2);

	for (int i = 0; i < repo.get_Size(); i++)
	{
		assert(repo.get_All()[i] == gestiune[i]);
	}

	repo.deleteFilme(s2);
	assert(repo.get_Size() == 1);

	char* nume = new char[10];
	char* nume3 = new char[10], * data3 = new char[10], * gen3 = new char[10];
	strcpy_s(nume, sizeof "Joker", "Joker");
	strcpy_s(nume3, sizeof "Anohana", "Anohana");
	strcpy_s(data3, sizeof "17.05.2020", "17.05.2020");
	strcpy_s(gen3, sizeof "drama", "drama");
	Filme s3(nume3, data3, gen3);
	repo.UpdateFilme(s3, nume);
	assert(repo.get_All()[0]==s3);

	cout << "Testele au fost terminate cu succes!" << endl;
}