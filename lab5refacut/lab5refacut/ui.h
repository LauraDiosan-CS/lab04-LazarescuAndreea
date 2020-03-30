#pragma once
#include "service.h"
#include "film.h"
#include "repo.h"

class UI
{
private:
	Repo repo;
public:
	void add_film_ui(Service& serv);
	void delete_film_ui(Service& serv);
	void update_film_ui(Service& serv, char*, char*, char*);
	int find_film_ui(Service& serv, Film);
	void get_all(Service& serv);
	void cautare_gen_film(Service& serv, char* genul);
	void eliminare_filme_lansate_inainte_de_data(Service& serv, char* data);
	int menu(Service& serv);
};