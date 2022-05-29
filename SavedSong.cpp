#include"Music_Composser.h"
using namespace std;

void SavedSong(vector<NOTE*>& Song) {
	system("cls");
	cout << "Cac ban nhac co san: \n";
	cout << "\t1/ Hay trao cho anh.\n";
	cout << "\t2/ con co be be.\n";
	int choice = 0;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Dang hat hya trao cho anh :>\n";
		break;
	case 2:
		cout << "Dang hat con co be be\n";
		break;
	}
	system("pause");
}
