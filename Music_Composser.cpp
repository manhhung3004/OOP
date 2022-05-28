#include"Music_Composser.h"
using namespace std;
/* Định nghĩa các hàm trong lớp NOTE*/




/*------------------ Cac ham khoi tao --------------*/
NOTE::NOTE()
{
	Lenght = 0;
}
NOTE::NOTE( int lenght)
{
	Lenght = lenght;
}
NOTE::~NOTE(){}

/* -----------------Cac ham thao tac----------------*/
void NOTE::PrintNote() {
	cout << Lenght << " ";
}



/* Dinh nghia cac ham trong lop Rest */
/*-----------------Cac ham khoi tao----------------*/
Rest::Rest():NOTE() {
	Type = 1;
}
Rest::Rest(int type, int lenght) :NOTE( lenght) {
	Type = type;
}

/* Ham thao tac */
void Rest::SetL() {
	cout << "Nhap vao truong do cua not: ";
	float a;
	cin >> a;
	if (a == 1)		Lenght = 500;
	if (a == 0.5)	Lenght = 250;
	if (a == 0.25)	Lenght = 125;
	if (a == 0.125) Lenght = 125 / 2;
	if (a == 0.0625)	Lenght = 125 / 4;
}
void Rest::SetH(){}

int Rest::GetL() 
{
	return Lenght;
}
int Rest::GetH() 
{
	return 0;
}

void Rest::Sound() {
	Beep(0, Lenght);
}
void Rest::PrintNote(){
	cout << Lenght;
}


/* Dinh nghia cac ham trong lop Music note */
void MusicNote::SetH() {
	cout << "Nhap vao cao do: ";
	int a = 0;
	switch (a) {
	case 1:
		Height = 440;
		break;
	}
}




// cac ham menu
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
		cin >> choice1;
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

void NewSong(vector<NOTE*>& Song)
{
	int choice = 0;
	do {
		cout << "Chon loai not: \n";
		cout << "1/ Not lang.\n";
		cout << "2/ Not nhac.\n";
		cout << "3/ Ket thuc ban nhac.\n";

		while (!(cin >> choice) && choice != 1 && choice != 2 && choice != 3)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Gia tri khong hop le! Hay nhap lai: \n";
		}

		switch (choice)
		{
		case 1:
			cout << "NOT LANG: \n";
			Song.push_back(new Rest());
			cout << "Nhap vao truong do: \n";
			Song[Song.size() - 1]->GetL();
			break;
		case 2:
			cout << "NOT NHAC\n";
			Song.push_back(new MusicNote());
			cout << "Nhap vao cao do:\n";
			Song[Song.size() - 1]->GetH();
			cout << "Nhap vao truong do:\n";
			Song[Song.size() - 1]->SetL();
			break;
		case 3:
			break;
		}
		
	} while (choice != 3);
}

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

void Count(vector<NOTE*>& Song) {
	int count = 0;
	for (int i = 0; i < Song.size() - 1; i++)
		if (Song[i]->GetType() == 1) count++;
	cout << "Bai hat co " << count << " not lang\n";
}

void MinMax(vector<NOTE*> Song)
{
	int MaxHight = 0;
	int MinHight = 0;
	for (int i = 0; i < Song.size(); i++) {
		int a = Song[i]->GetH();
		if (a > MaxHight) MaxHight = a;
		if (a < MinHight || a>0) MinHight = a;
	}

	cout << "Not co cao do cao nhat la: " << MaxHight << endl;
	cout << "Not co cao do thap nhat la: " << MinHight << endl;
}