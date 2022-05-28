#include"Music_composser.h"

void SavedSong() {
    system("cls");
    cout << "\t\t\t\t ______________________________________________________________\n";
    cout << "\t\t\t\t|                        ****** MENU *****                     |\n";
    cout << "\t\t\t\t|                        Cac ban nhac san co                   |\n";
    cout << "\t\t\t\t|                       1/ Anh nang cua anh.                   |\n";
    cout << "\t\t\t\t|                       2/                                     |\n";
    cout << "\t\t\t\t --------------------------------------------------------------\n";
    int choice = 0;
    cout << "\t\t\t\t"; cin >> choice;
    switch (choice) {
    case 1:
        cout << "\t\t\t\tDang hat hay trao cho anh :>\n";
        Song1();
        break;
    case 2:
        cout << "\t\t\t\tDang hat con co be be\n";
        Song2();
        break;
    }
    system("pause");
}