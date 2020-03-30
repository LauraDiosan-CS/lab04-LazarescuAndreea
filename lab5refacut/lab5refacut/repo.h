#pragma once
#include "film.h"

class Repo {
private:
	Film film[20];
	int n;
public:
	Repo();
	~Repo();
	void add_film_repo(Film f);
	int delete_film_repo(Film f);
	void update_film_repo(Film& f, char*, char*, char*);
	int find_film_repo(Film f);
	int get_size();
	Film* get_all();
	Film get_item_from_position(int);
};
