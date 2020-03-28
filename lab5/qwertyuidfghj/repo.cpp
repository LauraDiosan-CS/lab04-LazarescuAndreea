#include "repo.h"
#include "film.h"
#include <iostream>
using namespace std;

Repo::Repo()
{
	this->n = 0;
}

Repo::~Repo()
{
	this->n = 0;
}

void Repo::insert(Filme expence)
{
	this->film[this->n++] = expence;
}

int Repo::get_Size()
{
	return this->n;
}

Filme* Repo::get_All()
{
	return this->film;
}

int Repo::findFilme(Filme s)
{
	for (int i = 0; i < this->n; i++)
	{
		if (s == this->film[i])
		{
			return i;
		}
	}
	return -1;
}

void Repo::deleteFilme(Filme s)
{
	int poz = this->findFilme(s);
	if (poz >= 0 && poz <= n - 1) {
		for (int i = poz; i <= n - 2; i++)
			this->film[i] = this->film[i + 1];
		n--;
	}
}

void Repo::UpdateFilme(Filme& s, char* name)
{
	for (int i = 0; i < this->n; i++)
	{
		if (strcmp(name, this->film[i].get_name())==0)
		{
			this->film[i].set_name(s.get_name());
			this->film[i].set_date(s.get_date());
			this->film[i].set_gen(s.get_gen());
		}
	}
}