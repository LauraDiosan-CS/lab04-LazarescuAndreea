#include "repo.h"
#include "film.h"
#include <iostream>
using namespace std;

Repo::Repo()
{
	this->n = 0;
}

void Repo::add_film_repo(Film f)
{
	this->film[this->n++] = f;
}

int Repo::delete_film_repo(Film f)
{
	int i = find_film_repo(f);
	if (i != -1)
	{
		film[i] = film[n - 1];
		n--;
		return 0;
	}
	return -1;
}

void Repo::update_film_repo(Film& f, char* titlu, char* data, char* genul)
{
	int i = find_film_repo(f);
	if (i != -1)
	{
		film[i].set_titlu(titlu);
		film[i].set_data(data);
		film[i].set_genul(genul);
	}
}

int Repo::find_film_repo(Film f)
{
	for (int i = 0; i < this->n; i++)
	{
		if (f == this->film[i])
		{
			return i;
		}
	}
	return -1;
}

Repo::~Repo()
{
	this->n = -1;
}

Film Repo::get_item_from_position(int i)
{
	return film[i];
}

Film* Repo::get_all()
{
	return film;
}

int Repo::get_size()
{
	return n;
}