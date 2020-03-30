#include <iostream>
#include "ui.h"
#include "film.h"
using namespace std;

void UI::add_film_ui(Service& serv)
{
	Film film;
	cin >> film;
	serv.add_film_service(film);
	cout << "Filmul a fost adaugat!" << endl;
}

void UI::delete_film_ui(Service& serv)
{
	Film film;
	cout << "Dati filmul de sters: " << endl;
	cin >> film;
	int rez = serv.delete_film_service(film);
	if (rez == 0) cout << "Filmul a fost sters!" << endl;
	else cout << "Filmul nu a fost gasit!" << endl;
}

void UI::update_film_ui(Service& serv, char* titlu, char* data, char* genul)
{
	Film film;
	cout << "Dati filmul de actualizat:" << endl;
	cin >> film;
	int i = find_film_ui(serv, film);
	if (i != -1)
	{
		serv.update_film_service(film, titlu, data, genul);
		cout << "Filmul a fost actualizat!" << endl;
	}
	else cout << "Filmul nu a fost gasit!" << endl;
}

int UI::find_film_ui(Service& serv, Film film)
{
	bool rez = serv.find_film_service(film);
	if (rez) return -1;
	return 0;
}

void UI::get_all(Service& serv)
{
	Film* film = serv.get_all();
	int n = serv.get_size();
	cout << "Filmele sunt:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << film[i];
	}
}

void UI::cautare_gen_film(Service& serv, char* genul)
{
	Film* film = serv.get_all();
	int n = serv.get_size();
	for (int i = 0; i < n; i++)
	{
		if (serv.cautare_gen_film(film[i].get_genul(), genul) == 1) cout << film[i];
	}
}

void UI::eliminare_filme_lansate_inainte_de_data(Service& serv, char* data)
{
	serv.eliminare_filme_lansate_inainte_de_data(data);
}

int UI::menu(Service& serv)
{
    bool gata = false;
    while (!gata)
    {
        cout << endl;
        cout << "1. Adaugare" << endl;
        cout << "2. Afisare" << endl;
        cout << "3. Stergere" << endl;
        cout << "4. Update" << endl;
        cout << "5. Cautarea tuturor filmelor dupa un gen dat" << endl;
        cout << "6. Eliminarea tuturor filmelor lansate inaintea unei date calendaristice" << endl;
        cout << "7. Undo" << endl;
        cout << "0. Iesire" << endl;
        cout << "Alegeti optiunea: " << endl;
        int op;
        cin >> op;
        if (op == 1)
        {
            add_film_ui(serv);
        }
        if (op == 2)
        {
            cout << endl;
            get_all(serv);
            cout << endl;
        }
        if (op == 3)
        {
            delete_film_ui(serv);
        }
        if (op == 4)
        {
            cout << endl;
            char titlu_nou[100];
            char data_noua[100];
            char genul_nou[100];
            cout << "Introduceti noul titlu: ";
            cin >> titlu_nou;
            cout << "Introduceti noua data: ";
            cin >> data_noua;
            cout << "Introduceti noul gen: ";
            cin >> genul_nou;

            update_film_ui(serv, titlu_nou, data_noua, genul_nou);
            cout << endl;
            cout << "Modificare cu succes!" << endl << endl;
        }
        if (op == 5)
        {
            char genul[100];
            cout << endl;
            cout << "Dati genul cautat: ";
            cin >> genul;
            cout << endl;
            cautare_gen_film(serv, genul);
            cout << endl;
        }
        if (op == 6)
        {
            char data[100];
            cout << endl << "Dati data calendaristica: ";
            cin >> data;
            cout << endl;
            eliminare_filme_lansate_inainte_de_data(serv, data);
            cout << endl;
        }
        if (op == 0)
        {
            gata = true;
            cout << endl;
        }
    }
    return 0;
}