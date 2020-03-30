#include "film.h"
#include <cstring>
#include <sstream>
using namespace std;

Film::Film() {
	this->titlu = NULL;
	this->data = NULL;
	this->genul = NULL;
}

Film::Film(char* titlu, char* data, char* genul)
{
	this->titlu = new char[strlen(titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(titlu), titlu);

	this->data = new char[strlen(data) + 1];
	strcpy_s(this->data, 1 + strlen(data), data);

	this->genul = new char[strlen(genul) + 1];
	strcpy_s(this->genul, 1 + strlen(genul), genul);

}

Film::Film(const Film& f)
{
	this->titlu = new char[strlen(f.titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(f.titlu), f.titlu);

	this->data = new char[strlen(f.data) + 1];
	strcpy_s(this->data, 1 + strlen(f.data), f.data);

	this->genul = new char[strlen(f.genul) + 1];
	strcpy_s(this->genul, 1 + strlen(f.genul), f.genul);
}

char* Film::get_titlu()
{
	return this->titlu;
}

char* Film::get_data()
{
	return this->data;
}

char* Film::get_genul()
{
	return this->genul;
}

void Film::set_titlu(char* new_titlu)
{
	if (this->titlu)
	{
		delete[] this->titlu;
		this->titlu = NULL;
	}
	this->titlu = new char[strlen(new_titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(new_titlu), new_titlu);
}

void Film::set_data(char* new_data)
{
	if (this->data)
	{
		delete[] this->data;
		this->data = NULL;
	}
	this->data = new char[strlen(new_data) + 1];
	strcpy_s(this->data, 1 + strlen(new_data), new_data);
}

void Film::set_genul(char* new_gen)
{
	if (this->genul)
	{
		delete[] this->genul;
		this->genul = NULL;
	}
	this->genul = new char[strlen(new_gen) + 1];
	strcpy_s(this->genul, 1 + strlen(new_gen), new_gen);
}

Film& Film:: operator =(const Film& f)
{
	if (this == &f) return *this;
	this->set_titlu(f.titlu);
	this->set_data(f.data);
	this->set_genul(f.genul);
	return *this;
}

bool Film:: operator==(const Film& f)
{
	return strcmp(this->data, f.data) == 0 and strcmp(this->titlu, f.titlu) == 0 and strcmp(this->genul, f.genul) == 0;
}

Film::~Film()
{
	if (this->titlu)
	{
		delete[] this->titlu;
		this->titlu = NULL;
	}
	if (this->data)
	{
		delete[] this->data;
		this->data = NULL;
	}
	if (this->genul)
	{
		delete[] this->genul;
		this->genul = NULL;
	}
}

std::ostream& operator <<(std::ostream& os, const Film& f)
{
	os << "Titlul: " << f.titlu << " Data: " << f.data << " Gen: " << f.genul << std::endl;
	return os;
}

istream& operator>>(istream& is, Film& f)
{
	cout << "Dati titlul: ";
	char* titlu = new char[15];
	is >> titlu;
	cout << "Dati data: ";
	char* data = new char[10];
	is >> data;
	cout << "Dati genul: ";
	char* genul = new char[10];
	is >> genul;
	f.set_titlu(titlu);
	f.set_data(data);
	f.set_genul(genul);
	return is;
}

bool Film :: operator<(const Film& f)
{
	return (strcmp(titlu, f.titlu) < 0);
}