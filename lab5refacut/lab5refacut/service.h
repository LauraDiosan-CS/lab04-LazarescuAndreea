#pragma once
#include "repo.h"
#include "film.h"

class Service
{
private:
	Repo repo;
public:
	Service();
	Service(const Repo&);
	void set_repo(const Repo&);
	void add_film_service(Film f);
	int delete_film_service(Film f);
	int find_film_service(Film f);
	void update_film_service(Film s, char*, char*, char*);
	int get_size();
	Film* get_all();
	~Service();
	int cautare_gen_film(char*, char*);
	void eliminare_filme_lansate_inainte_de_data(char*);
};