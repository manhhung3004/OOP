#include"Music_Composser.h"
using namespace std;

void NewSong(vector<NOTE*>& Song)
{

	int choice = 0;
	do {
		system("cls");
		cout << "Chon loai not: \n";
		cout << "1/ Not lang.\n";
		cout << "2/ Not nhac.\n";
		cout << "3/ Ket thuc ban nhac.\n";

		while (!(cin >> choice) || choice > 3 || choice < 1)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Gia tri khong hop le! Hay nhap lai: \n";
		}

		switch (choice)
		{
		case 1:
			cout << "NOT LANG: \n";
			cout << "Bang truong do:   " << endl;
			cout << "* * * * * * * * * * *" << endl;
			cout << "* 1) Not tron.      *" << endl;
			cout << "* 2) Not trang.     *" << endl;
			cout << "* 3) Not den.       *" << endl;
			cout << "* 4) Not moc den.   *" << endl;
			cout << "* 5) Not moc doi.   *" << endl;
			cout << "* 6) Not moc ba.    *" << endl;
			cout << "* 7) Not moc tu.    *" << endl;
			cout << "* * * * * * * * * * *" << endl;
			Song.push_back(new Rest());
			cout << "Nhap vao truong do: \n";
			Song[Song.size() - 1]->SetL();

			break;
		case 2:
			cout << "NOT NHAC\n";
			cout << "Bang cao do:             Bang truong do:   " << endl;
			cout << "* * * * * * * *          * * * * * * * * * * *" << endl;
			cout << "*  1) Do.     *          *  1) Not tron.     *" << endl;
			cout << "*  2) Re.     *          * 2) Not trang.     *" << endl;
			cout << "*  3) Mi.     *          * 3) Not den.       *" << endl;
			cout << "*  4) Fa.     *          * 4) Not moc den.   *" << endl;
			cout << "*  5) Sol.    *          * 5) Not moc doi.   *" << endl;
			cout << "*  6) La.     *          * 6) Not moc ba.    *" << endl;
			cout << "*  7) Si.     *          * 7) Not moc tu.    *" << endl;
			cout << "* * * * * * * *          * * * * * * * * * * *" << endl;
			Song.push_back(new MusicNote());
			cout << "Nhap vao cao do:\n";
			Song[Song.size() - 1]->SetH();
			cout << "Nhap vao truong do:\n";
			Song[Song.size() - 1]->SetL();
			break;
		}

	} while (choice != 3);
	system("cls");
	Count(Song);
	MinMax(Song);
	cout << "Kiet tac vua duoc tao ra: " << endl;
	for (int i = 0; i < Song.size(); i++)
		Song[i]->PrintNote();
	cout << endl;
	cout << "Demo in 3: " << endl;
	for (int j = 0; j < Song.size(); j++)
		Song[j]->Sound();

	int choice2 = 0;
	do {
		cout << "1 Phat lai.\n";
		cout << "2 Tro ve menu.\n ";
		cin >> choice2;
		for (int j = 0; j < Song.size(); j++)
			Song[j]->Sound();
	} while (choice2 != 2);
	system("pause");

}