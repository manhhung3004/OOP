#include"Music_Composser.h"
using namespace std;
/* Định nghĩa các hàm trong lớp NOTE*/


/*------------------ Cac ham khoi tao --------------*/
NOTE::NOTE()
{
	Lenght = 0;
	Name = " ";
}
NOTE::NOTE(int lenght)
{
	this->Lenght = lenght;
}
NOTE::~NOTE() {}

int NOTE::GetL() {
	return Lenght;
}

/* Dinh nghia cac ham trong lop Rest */
/*-----------------Cac ham khoi tao----------------*/
Rest::Rest() :NOTE() {
	Type = 1;
}
Rest::Rest(int type, int lenght) : NOTE(lenght) {
	Type = type;
}

/* Ham thao tac */
void Rest::SetL() {
	int L = 0;
	cout << "\t\t\t\t";
	while (!(cin >> L) || L > 7 || L < 1)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\t\t\t\tGia tri khong hop le! Hay nhap lai: \n";
	}
	Name = "Z";
	switch (L)
	{
	case 1:
		Lenght = 6400;
		Name += " 4";
		break;
	case 2:
		Lenght = 3200;
		Name += " 2";
		break;
	case 3:
		Lenght = 1600;
		Name += " 1";
		break;
	case 4:
		Lenght = 800;
		Name += " 1/2";
		break;
	case 5:
		Lenght = 400;
		Name += " 1/4";
		break;
	case 6:
		Lenght = 200;
		Name += " 1/8";
		break;
	case 7:
		Lenght = 100;
		Name += " 1/16";
		break;
	}
}
void Rest::SetH() {}

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
void Rest::PrintNote() {
	cout << Name << " ";
}


/* Dinh nghia cac ham trong lop Music note */
MusicNote::MusicNote() {
	Lenght = 0;
	Height = 0;
	Name = " ";
	Type = 2;
}

void MusicNote::SetH() {
	int H = 0;
	cout << "\t\t\t\t";
	while (!(cin >> H) || H < 1 || H>7)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\t\t\t\tGia tri khong hop le! Hay nhap lai: \n";
	}

	switch (H)
	{
	case 1:
		Height = 261;
		Name = "C";
		break;
	case 2:
		Height = 293;
		Name = "D";
		break;
	case 3:
		Height = 329;
		Name = "E";
		break;
	case 4:
		Height = 349;
		Name = "F";
		break;
	case 5:
		Height = 392;
		Name = "G";
		break;
	case 6:
		Height = 440;
		Name = "A";
		break;
	case 7:
		Height = 493;
		Name = "B";
		break;
	}
}

void MusicNote::SetL() {
	int L = 0;
	cout << "\t\t\t\t";
	while (!(cin >> L) || L < 1 || L>7)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Gia tri khong hop le! Hay nhap lai: \n";
	}

	switch (L)
	{
	case 1:
		Lenght = 6400;
		Name += " 4";
		break;
	case 2:
		Lenght = 3200;
		Name += " 2";
		break;
	case 3:
		Lenght = 1600;
		Name += " 1";
		break;
	case 4:
		Lenght = 800;
		Name += " 1/2";
		break;
	case 5:
		Lenght = 400;
		Name += " 1/4";
		break;
	case 6:
		Lenght = 200;
		Name += " 1/8";
		break;
	case 7:
		Lenght = 100;
		Name += "1/16";
		break;
	}
}

int MusicNote::GetH() {
	return Height;
}
int MusicNote::GetL() {
	return Lenght;
}

void MusicNote::PrintNote() {
	cout << Name << " ";
}
void MusicNote::Sound() {
	Beep(Height, Lenght);
}

// cac ham menu
void Count(vector<NOTE*>& Song) {
	int count = 0;
	for (int i = 0; i < Song.size(); i++)
		if (Song[i]->GetType() == 1) count++;
	cout << "\t\t\t\t";
	cout << "Bai hat co " << count << " not lang\n";
}

void MinMax(vector<NOTE*> Song)
{
	int MaxHight = 0;
	int MaxPos = 0;

	int pos = 0;
	while (Song[pos]->GetType() == 1)
	{
		pos++;
	}
	int MinHight = Song[pos]->GetH();
	int MinPos = 0;
	for (int i = 0; i < Song.size(); i++) {
		if (Song[i]->GetType() != 1) {
			int a = Song[i]->GetH();

			if (a > MaxHight)
			{
				MaxHight = a;
				MaxPos = i;
			}

			if (a < MinHight)
			{
				MinHight = a;
				MinPos = i;
			}
		}
	}

	cout << "\t\t\t\tNot co cao do cao nhat la: ";
	Song[MaxPos]->PrintNote();
	cout << endl;
	cout << "\t\t\t\tNot co cao do thap nhat la: ";
	Song[MinPos]->PrintNote();
	cout << endl;
}

bool Check(int a) {
	if (a <= 7 && a >= 1) return true;
	return false;
}

int Lenght_(int i)
{
	int temp = 0;
	switch (i)
	{
	case 32:
		temp = 3000;
		return temp;
		break;
	case 16:
		temp = 1500;
		return temp;
		break;
	case 8:
		temp = 750;
		return temp;
		break;
	case 4:
		temp = 375;
		return temp;
		break;
	case 2:
		temp =800 ;
		return temp;
		break;
	case 1:
		temp = 450;
		return temp;
		break;
	}
	return temp;
}

void Menu(vector <NOTE*>& Song)
{
	int choice1 = 0;

	do {
		system("cls");
		cout<< "\t\t\t\t __________________________________________________________\n";
		cout<< "\t\t\t\t|                    *****  MENU  *****                    |\n";
		cout<< "\t\t\t\t|                 1/ Tao ban nhac moi.                     |\n";
		cout<< "\t\t\t\t|                 2/ Phat ban nhac co san.                 |\n";
		cout<< "\t\t\t\t|                 3/ Thoat chuong trinh.                   |\n";
		cout << "\t\t\t\t ---------------------------------------------------------\n";
		while (!(cin >> choice1) || choice1 > 3 || choice1 < 1) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << setw(20) << "\t\t\t\tGia tri khong hop le! Hay nhap lai: \n";
		}
		switch (choice1) {
		case 1:
			system("cls");
			NewSong(Song);
			break;
		case 2:
			system("cls");
			SavedSong(Song);
			break;
		}
	} while (choice1 != 3);
}

void SavedSong(vector<NOTE*>& Song) {
	system("cls");
	cout << "\t\t\t\t __________________________________________________________\n";
	cout << "\t\t\t\t|                    *****  MENU  *****                    |\n";
	cout << "\t\t\t\t|                    Cac ban nhac san co                   |\n";
	cout << "\t\t\t\t|                 1/ Merry Christmas                       |\n";
	cout << "\t\t\t\t|                 2/ Happy birthday                        |\n";
	cout << "\t\t\t\t ----------------------------------------------------------\n";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "\t\t\t\tBai hat ban dang nghe la: Merry Christmas :>\n";
		Song1();
		break;
	case 2:
		cout << "\t\t\t\tBai hat ban dang nghe la: Happy birthday \n";
		Song2();
		break;
	}
}

void NewSong(vector<NOTE*>& Song)
{

	int choice = 0;
	do {
		system("cls");
		cout << "\t\t\t\t __________________________________________________________\n";
		cout << "\t\t\t\t|                    *****  MENU  *****                    |\n";
		cout << "\t\t\t\t|                    Chon loai note nhac                   |\n";
		cout << "\t\t\t\t|                 1/ Note Lang:                            |\n";
		cout << "\t\t\t\t|                 2/ Note Nhac.                            |\n";
		cout << "\t\t\t\t|                 3/ Ket thuc ban nhac                     |\n";
		cout << "\t\t\t\t ----------------------------------------------------------\n";

		while (!(cin >> choice) || choice > 3 || choice < 1)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "\t\t\t\tGia tri khong hop le! Hay nhap lai: \n";
		}

		switch (choice)
		{
		case 1:
			cout << "\t\t\t\tNOT LANG: \n";
			cout << "\t\t\t\tBang truong do:   " << endl;
			cout << "\t\t\t\t* * * * * * * * * * *" << endl;
			cout << "\t\t\t\t* 1) Not tron.      *" << endl;
			cout << "\t\t\t\t* 2) Not trang.     *" << endl;
			cout << "\t\t\t\t* 3) Not den.       *" << endl;
			cout << "\t\t\t\t* 4) Not moc den.   *" << endl;
			cout << "\t\t\t\t* 5) Not moc doi.   *" << endl;
			cout << "\t\t\t\t* 6) Not moc ba.    *" << endl;
			cout << "\t\t\t\t* 7) Not moc tu.    *" << endl;
			cout << "\t\t\t\t* * * * * * * * * * *" << endl;
			Song.push_back(new Rest());
			cout << "\t\t\t\tNhap vao truong do: \n";
			Song[Song.size() - 1]->SetL();
			break;
		case 2:
			cout << "\t\t\t\tNOT NHAC\n";
			cout << "\t\t\t\tBang cao do:                     Bang truong do:   " << endl;
			cout << "\t\t\t\t* * * * * * * *                * * * * * * * * * * *" << endl;
			cout << "\t\t\t\t*  1) Do.     *                *  1) Not tron.     *" << endl;
			cout << "\t\t\t\t*  2) Re.     *                * 2) Not trang.     *" << endl;
			cout << "\t\t\t\t*  3) Mi.     *                * 3) Not den.       *" << endl;
			cout << "\t\t\t\t*  4) Fa.     *                * 4) Not moc den.   *" << endl;
			cout << "\t\t\t\t*  5) Sol.    *                * 5) Not moc doi.   *" << endl;
			cout << "\t\t\t\t*  6) La.     *                * 6) Not moc ba.    *" << endl;
			cout << "\t\t\t\t*  7) Si.     *                * 7) Not moc tu.    *" << endl;
			cout << "\t\t\t\t* * * * * * * *                * * * * * * * * * * *" << endl;
			Song.push_back(new MusicNote()); 
			cout << "\t\t\t\tNhap vao cao do:\n";
			Song[Song.size() - 1]->SetH();
			cout << "\t\t\t\tNhap vao truong do:\n";
			Song[Song.size() - 1]->SetL();
			break;
		}

	} while (choice != 3);
	system("cls");
	Count(Song);
	MinMax(Song);
	cout << "\t\t\t\tKiet tac vua duoc tao ra: " << endl;
	cout << "\t\t\t\t";
	for (int i = 0; i < Song.size(); i++)
	{
		Song[i]->PrintNote();
	}	
	cout << endl;
	cout << "\t\t\t\tDemo in 3: " << endl;
	for (int j = 0; j < Song.size(); j++)
		Song[j]->Sound();

	int choice2 = 0;
	do {
		cout << "\t\t\t\t1 Phat lai.\n";
		cout << "\t\t\t\t2 Tro ve menu.\n ";
		cin >> choice2;
		if (choice2 == 2) {
			for (int j = 0; j < Song.size(); j++)
				Song[j]->Sound();
		}
	} while (choice2 != 2);
	system("pause");

}

int main() {
	vector<NOTE*> a;
	Menu(a);
	system("pause");
	return 0;
}

void Song1() {
	fstream file;
	file.open("Merry Christmas.txt", ios::in);
	if (file.is_open())
	{
		pair<string, int> pair[100];
		for (int i = 0; i < 100; i++) {
			file >> pair[i].first >> pair[i].second;
			// 261
			if (pair[i].first == "C4") {
				Beep(261, Lenght_(pair[i].second));
			}
			// 293
			else if (pair[i].first == "D4") {

				Beep(293, Lenght_(pair[i].second));
			}
			// 329
			else if (pair[i].first == "E4") {

				Beep(329, Lenght_(pair[i].second));
			}
			//349
			else if (pair[i].first == "F4") {

				Beep(261, Lenght_(pair[i].second));
			}
			// 392
			else if (pair[i].first == "G4") {

				Beep(392, Lenght_(pair[i].second));
			}
			//440
			else if (pair[i].first == "A4") {

				Beep(440, Lenght_(pair[i].second));
			}
			// 493
			else if (pair[i].first == "B4") {
				Beep(493, Lenght_(pair[i].second));
			}
			//523
			else if (pair[i].first == "C5") {
				Beep(523, Lenght_(pair[i].second));
			}
			//587
			else if (pair[i].first == "D5") {
				Beep(587, Lenght_(pair[i].second));
			}
			//659
			else if (pair[i].first == "E5") {
				Beep(659, Lenght_(pair[i].second));
			}
			//698
			else if (pair[i].first == "F5") {
				Beep(698, Lenght_(pair[i].second));
			}
			//783
			else if (pair[i].first == "G5") {
				Beep(783, Lenght_(pair[i].second));
			}
			//880
			else if (pair[i].first == "A5") {
				Beep(880, Lenght_(pair[i].second));
			}
			//987
			else if (pair[i].first == "B5") {
				Beep(987, Lenght_(pair[i].second));
			}
			Sleep(150);
		}
	}
	file.close();
}

void Song2() {
	fstream file;
	file.open("HappyBirthday.txt", ios::in);
	if (file.is_open())
	{
		pair<string, int> pair[100];
		for (int i = 0; i < 100; i++) {
			file >> pair[i].first >> pair[i].second;
			// 261
			if (pair[i].first == "C4") {
				Beep(261, Lenght_(pair[i].second));
			}
			// 293
			else if (pair[i].first == "D4") {

				Beep(293, Lenght_(pair[i].second));
			}
			// 329
			else if (pair[i].first == "E4") {

				Beep(329, Lenght_(pair[i].second));
			}
			//349
			else if (pair[i].first == "F4") {

				Beep(261, Lenght_(pair[i].second));
			}
			// 392
			else if (pair[i].first == "G4") {

				Beep(392, Lenght_(pair[i].second));
			}
			//440
			else if (pair[i].first == "A4") {

				Beep(440, Lenght_(pair[i].second));
			}
			// 493
			else if (pair[i].first == "B4") {
				Beep(493, Lenght_(pair[i].second));
			}
			//523
			else if (pair[i].first == "C5") {
				Beep(523, Lenght_(pair[i].second));
			}
			//587
			else if (pair[i].first == "D5") {
				Beep(587, Lenght_(pair[i].second));
			}
			//659
			else if (pair[i].first == "E5") {
				Beep(659, Lenght_(pair[i].second));
			}
			//698
			else if (pair[i].first == "F5") {
				Beep(698, Lenght_(pair[i].second));
			}
			//783
			else if (pair[i].first == "G5") {
				Beep(783, Lenght_(pair[i].second));
			}
			//880
			else if (pair[i].first == "A5") {
				Beep(880, Lenght_(pair[i].second));
			}
			//987
			else if (pair[i].first == "B5") {
				Beep(987, Lenght_(pair[i].second));
			}
			Sleep(150);
		}
	}
	file.close();
}