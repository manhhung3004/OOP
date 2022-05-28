#include"Music_composser.h"

void Menu(vector<NOTE*>& Song) {
    int choice1 = 0;

    do {
        system("cls");
        cout << "\t\t\t\t ______________________________________________________________\n";
        cout << "\t\t\t\t|                        ****** MENU *****                     |\n";
        cout << "\t\t\t\t|                       1/ Tao bai hat moi.                    |\n";
        cout << "\t\t\t\t|                       2/ Phat bai hat co san.                |\n";
        cout << "\t\t\t\t|                       3/ Thoat chuong trinh.                 |\n";
        cout << "\t\t\t\t --------------------------------------------------------------\n";
        cin >> choice1;
        switch (choice1) {
        case 1:
            system("cls");
            NewSong(Song);
            break;
        case 2:
            SavedSong();
            break;
        }
    } while (choice1 != 3);
}