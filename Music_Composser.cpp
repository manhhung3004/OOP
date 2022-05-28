#include"Music_composser.h"
/* Định nghĩa các hàm trong lớp NOTE*/
/*------------------ Cac ham khoi tao --------------*/
NOTE::NOTE()
{
    Lenght = 0;
}
NOTE::NOTE(int &lenght)
{
    Lenght = lenght;
}
NOTE::~NOTE() {}

/* -----------------Cac ham thao tac----------------*/
void NOTE::PrintNote() {
    cout << Lenght << " ";
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
    int a;
    cout << "\t\t(1)Dau lang tron: \n";
    cout << "\t\t(2)Dau lang trang: \n";
    cout << "\t\t(3)Dau lang den: \n";
    cout << "\t\t(4)Dau lang moc den: \n";
    cout << "\t\t(5)Dau lang moc doi: \n";
    cout << "\t\t(6)Dau lang moc ba: \n";
    cout << "\t\t(7)Dau lang moc tu: \n";
    cin >> a;
    switch (a)
    {
    case 1: Lenght = 6400; break;
    case 2: Lenght = 3200; break;
    case 3: Lenght = 1600; break;
    case 4: Lenght = 800; break;
    case 5: Lenght = 400; break;
    case 6: Lenght = 200; break;
    case 7: Lenght = 100; break;
    }
}
void Rest::SetH() {

}

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
    cout << Lenght;
}
/* Dinh nghia cac ham trong lop Music note */
MusicNote::MusicNote() {
    Height = 0;
}
MusicNote::MusicNote( int height) {
    Height = height ;
}

void MusicNote::SetH() {
    int temp;
    cout << "(1)Do: \n";
    cout << "(2)Re: \n";
    cout << "(3)Mi: \n";
    cout << "(4)Pha: \n";
    cout << "(5)Sol: \n";
    cout << "(6)La: \n";
    cout << "(7)Si: \n";
    cout << "(8)Do': \n";
    cin >> temp;
    switch (temp)
    {
    case 1: Height = 261; break;
    case 2: Height = 293; break;
    case 3: Height = 329; break;
    case 4: Height = 349; break;
    case 5: Height = 392; break;
    case 6: Height = 440; break;
    case 7: Height = 493; break;
    }
}

void MusicNote::SetL()
{
    int a;
    cout << "\t\t(1)Not tron: \n";
    cout << "\t\t(2)Not trang: \n";
    cout << "\t\t(3)Not den: \n";
    cout << "\t\t(4)Not moc den: \n";
    cout << "\t\t(5)Not moc doi: \n";
    cout << "\t\t(6)Not moc ba: \n";
    cout << "\t\t(7)Not moc tu: \n";
    cin >> a;
    switch (a)
    {
    case 1: Lenght = 6400; break;
    case 2: Lenght = 3200; break;
    case 3: Lenght = 1600; break;
    case 4: Lenght = 800; break;
    case 5: Lenght = 400; break;
    case 6: Lenght = 200; break;
    case 7: Lenght = 100; break;
    }
}

int MusicNote::GetH()
{
    return Height;
}

int MusicNote::GetL()
{
    return Lenght;
}

void MusicNote::PrintNote()
{
    cout << "Cao do: " << Height << endl;
    cout << "Truong do: " << Lenght << endl;
}

void MusicNote::Sound()
{
    Beep(GetH(), GetL());
}

/* Cac ham thao tac*/

int Lenght_(int i) {
    int temp = 0 ;
    switch (i)
    {
    case 32: return temp = 3200; break;

    case 16: return temp = 1600; break;

    case 8:  return temp = 800; break;

    case 4:  return temp = 400; break;

    case 2:  return temp = 200; break;

    case 1:  return temp = 100; break;
    }
}

void Count(vector<NOTE*>Song) {
    int count = 0;
    for (int i = 0; i < Song.size() - 1; i++)
        if (Song[i]->GetType() == 1) count++;
    cout << "\t\t\t\tBai hat co " << count << "\t\t\t\t not lang\n";
}

void MinMax(vector<NOTE*> Song)
{
    int MaxHight = 0;
    int MaxPos = 0;

    int MinHight = Song[0]->GetH();
    int MinPos = 0;
    for (int i = 0; i < Song.size(); i++) {
        int a = Song[i]->GetH();

        if (a > MaxHight)
        {
            MaxHight = a;
            MaxPos = i;
        }

        if (a < MinHight || a > 0)
        {
            MinHight = a;
            MinPos = i;
        }
    }

    cout << "Not co cao do cao nhat la: ";
    Song[MaxPos]->PrintNote();
    cout << "Not co cao do thap nhat la: ";
    Song[MinPos]->PrintNote();
}
