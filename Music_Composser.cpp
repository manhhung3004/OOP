#include"Music_Composser.h"
using namespace std;
/* Định nghĩa các hàm trong lớp NOTE*/




/*------------------ Cac ham khoi tao --------------*/
NOTE::NOTE()
{
	Lenght = 0;
	Name = " ";
}
NOTE::NOTE( int lenght)
{
	Lenght = lenght;
}
NOTE::~NOTE(){}

int NOTE::GetL() {
	return Lenght;
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
	int L = 0;

	while (!(cin >> L) || L > 7 || L < 1)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Gia tri khong hop le! Hay nhap lai: \n";
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
	while (!(cin >> H) || H < 1 || H>7)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Gia tri khong hop le! Hay nhap lai: \n";
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
		if (Song[i]->Type == 1) count++;
	cout << "Bai hat co " << count << " not lang\n";
}

void MinMax(vector<NOTE*> Song)
{
	int MaxHight = 0;
	int MaxPos = 0;
	
	int pos = 0;
	while (Song[pos]->Type == 1)
	{
		pos++;
	}
	int MinHight = Song[pos]->GetH();
	int MinPos = 0;
	for (int i = 0; i < Song.size(); i++) {
		if (Song[i]->Type != 1) {
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

	cout << "Not co cao do cao nhat la: ";
	Song[MaxPos]->PrintNote();
	cout << endl;
	cout << "Not co cao do thap nhat la: ";
	Song[MinPos]->PrintNote();
	cout << endl;
}

bool Check(int a) {
	if (a <= 7 && a >= 1) return true;
	return false;
}




