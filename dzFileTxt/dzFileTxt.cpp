#include <iostream>
#include "zavd1.h"
#include "zavd2.h"

using namespace std;

int main()
{
    system("chcp 1251>null");
    cout << "Меню: \n[1] Прибрати неприйняті слова\n[2]Транслітерація с рос на англ\nВаш вибір: ";
    int choice;
    cin >> choice;
    int res = 0;
    switch (choice) {
    case 1: res = zavd1(); break;
    case 2: res = zavd2(); break;
    default: cout << "Error";  break;
    }
    return 0;
}
