#pragma once
#include "Repo.h"
class Service
{
private:
	Repo repo;
public:
	void insert_service(char*, char*, char*);
	void deleteFilme(Filme s);
	int findFilme(Filme s);
	void UpdateFilme(Filme s, char*);
	int get_Size();
	Filme* get_All();
};