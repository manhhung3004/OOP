#include"Music_Composser.h"
using namespace std;

void Menu(vector <NOTE*>& Song)
{
	int choice1 = 0;

	do {
		system("cls");
		cout << " ______________________________________________________________\n";
		cout << "|                          MENU                                |\n";
		cout << "|  1/ Tao ban nhac moi.                                        |\n";
		cout << "|  2/ Phat ban nhac co san.                                    |\n";
		cout << "|  3/ Thoat chuong trinh.                                      |\n";
		cout << " --------------------------------------------------------------\n";

		while (!(cin >> choice1) || choice1 > 3 || choice1 < 1) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Gia tri khong hop le! Hay nhap lai: \n";
		}

		switch (choice1) {
		case 1:
			system("cls");
			NewSong(Song);
			break;
		case 2:
			SavedSong(Song);
			break;
		}
	} while (choice1 != 3);
}
