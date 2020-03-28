#pragma once
#include <ostream>

class Filme {
private:
	char* date;
	char* name;
	char* gen;

public:
	Filme();
	Filme(char*, char*, char*);
	Filme(const Filme&);
	~Filme();
	char* get_name();
	char* get_date();
	char* get_gen();
	void set_name(char*);
	void set_date(char*);
	void set_gen(char*);
	Filme& operator =(const Filme&);
	bool operator==(const Filme&);
	friend std::ostream& operator << (std::ostream&, const Filme&);

};
