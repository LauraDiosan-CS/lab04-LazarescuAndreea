#include <iostream>
#include "repo.h"
#include "test.h"

using namespace std;

void menu()
{
    cout << "1. Adaugare" << endl;
    cout << "2. Afisare" << endl;
    cout << "3. Stergere" << endl;
    cout << "4. Update" << endl;
    cout << "x. Iesire" << endl;
}

bool except_date(char* string) {

    int list_of_days[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int nrok = 0, nrzile, nrluni, i;
    int nran = 0;
    if ('9' >= string[0] and string[0] >= '0' and '9' >= string[1] and string[1] >= '0' and string[2] == '.' and string[5] == '.')
    {
        nrzile = (string[0] - '0') * 10 + (string[1] - '0');
        nrluni = (string[3] - '0') * 10 + (string[4] - '0');
    }

    else
        return false;

    i = 6;
    while (i < strlen(string))
    {
        if (string[i] == '.')
            return false;
        nran = nran * 10 + (string[i] - '0');
        i = i + 1;
    }
    if (0 < nrluni and nrluni <= 12 and list_of_days[nrluni] >= nrzile and nrzile > 0 and (nran % 4 == 0 or nran % 400 == 0))
        nrok = nrok + 1;

    else
        if (0 < nrluni and nrluni <= 12 and list_of_days[nrluni] > nrzile and nrzile > 0)
            nrok = nrok + 1;

    if (nrok == 1)
        return true;

    else
        return false;
}

int main()
{
    tests();
    int op = 1;
    char date[250], name[250], gen[250];
    Repo repo;
    while (op)
    {
        menu();
        cout << "Alegeti optiunea: ";
        cin >> op;
        if (op == 1)
        {
            cout << "Dati titlul: ";
            cin >> name;
            int ok = 1;
            while (ok == 1)
            {
                cout << "Dati data: ";
                cin >> date;
                if (except_date(date))
                    ok = 0;
            }
            cout << "Dati genul: ";
            cin >> gen;
            cout << endl;
            cout << "Film adaugat!";
            cout << endl;
            cout << endl;
            Filme filme(name, date, gen);
            repo.insert(filme);
        }
        if (op == 2)
        {
            for (int i = 0; i < repo.get_Size(); i++)
                cout<<i+1<<". " << repo.get_All()[i];
            cout << endl;
        }
        if (op == 3)
        {
            repo.get_All();
            cout << endl;
            char name_sters[100];
            char date_sters[100];
            char gen_sters[100];

            cout << "Introduceti titlul: ";
            cin >> name_sters;
            cout << "Introduceti data: ";
            cin >> date_sters;
            cout << "Introduceti genul: ";
            cin >> gen_sters;

            Filme s(name_sters, date_sters, gen_sters);
            repo.deleteFilme(s);
            cout << endl;
            cout << "Film sters!" << endl;
        }
        if (op == 4)
        {
            repo.get_All();
            cout << endl;
            char name_new[100];
            char date_new[100];
            char gen_new[100];
            char name[100];
            cout << "Introduceti titlul: ";
            cin >> name;
            cout << "Introduceti noul titlul: ";
            cin >> name_new;
            cout << "Introduceti noua data: ";
            cin >> date_new;
            cout << "Introduceti noul genul: ";
            cin >> gen_new;

            Filme s(name_new, date_new, gen_new);
            repo.UpdateFilme(s, name);
            cout << endl;
            cout << "  Modificare cu succes! "<<endl;
            

        }
    }
    return 0;
}