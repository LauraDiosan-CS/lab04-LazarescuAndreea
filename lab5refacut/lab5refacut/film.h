#pragma once
#include <iostream>
#include <string>
using namespace std;

class Film 
{
private:
	char* titlu;
	char* data;
	char* genul;

public:
	Film();
	Film(char*, char*, char*);
	Film(const Film&);
	Film(string);
	~Film();

	char* get_titlu();
	char* get_data();
	char* get_genul();

	void set_titlu(char*);
	void set_data(char*);
	void set_genul(char*);

	Film& operator =(const Film&);
	bool operator==(const Film&);
	bool operator<(const Film&);

	friend std::ostream& operator << (std::ostream&, const Film&);
	friend std::istream& operator>>(istream&, Film&);
};
