#include <iostream>
#include "repo.h"
#include "testRepo.h"
#include "testService.h"
#include "ui.h"
#include <string>
#include <Windows.h>

using namespace std;



int main()
{
    test_repo();
    test_service();
    Service serv;
    UI ui;
    ui.menu(serv);
}