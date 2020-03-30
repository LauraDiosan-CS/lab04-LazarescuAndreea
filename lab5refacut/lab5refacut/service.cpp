#include "service.h"
#include "film.h"

Service::Service()
{
}

Service::Service(const Repo& r)
{
	repo = r;
}

void Service::set_repo(const Repo& r)
{
	repo = r;
}

void Service::add_film_service(Film f)
{
	repo.add_film_repo(f);
}

int Service::delete_film_service(Film f)
{
	if (repo.delete_film_repo(f) == 0) return 0;
	return -1;
}

int Service::find_film_service(Film f)
{
	return repo.find_film_repo(f);
}

void Service::update_film_service(Film f, char* titlu, char* data, char* genul)
{
	repo.update_film_repo(f, titlu, data, genul);
}

Film* Service::get_all()
{
	return this->repo.get_all();
}

int Service::get_size()
{
	return this->repo.get_size();
}

Service::~Service()
{
}

int Service::cautare_gen_film(char* gen_film, char* gen_cautat)
{
	if (strcmp(gen_film, gen_cautat) == 0) return 1;
	return 0;
}

void Service::eliminare_filme_lansate_inainte_de_data(char* data_calendaristica)
{
	for (int i = 0; i < repo.get_size(); i++)
		if (strcmp(repo.get_all()[i].get_data(), data_calendaristica) < 0) repo.delete_film_repo(repo.get_all()[i]);
}