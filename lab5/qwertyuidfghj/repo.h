#pragma once
#include "film.h"

class Repo {
private:
	Filme film[101];
	int n;

public:
	Repo();
	~Repo();
	void insert(Filme);
	void deleteFilme(Filme s);
	int findFilme(Filme s);
	int get_Size();
	Filme* get_All();
	void UpdateFilme(Filme& s,  char*);
};
