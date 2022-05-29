#pragma once
#include<iostream>
#include<fstream>
#include<windows.h> // WinApi header 
#include<vector>
#include<string>
#include<cstring>
#include <iomanip>  

using namespace std;

// NOTE
class NOTE {
protected:
    int Type;
    int Lenght;
    string Name;
public:

    NOTE();
    NOTE(int lenght);
    virtual ~NOTE();

    string GetName()
    {
        return Name;
    }

    int GetType() {
        return Type;
    }

    virtual void SetL() = 0;
    virtual void SetH() = 0;

    virtual int GetL() = 0;
    virtual int GetH() = 0;

    virtual void Sound() = 0;
    virtual void PrintNote() = 0;
};

class Rest :public NOTE {
public:

    Rest();
    Rest(int type, int lenght);

    void SetL();
    void SetH();

    int GetH();
    int GetL();

    void PrintNote();
    void Sound();

};

class MusicNote :public NOTE {
protected:
    int Height;
public:
    MusicNote();
    void SetH();
    void SetL();

    int GetH();
    int GetL();

    void PrintNote();
    void Sound();

};

void NewSong(vector<NOTE*>& Song);
void SavedSong(vector<NOTE*>& Song);
void Menu(vector <NOTE*>& Song);
void MinMax(vector<NOTE*> Song);
void Count(vector<NOTE*>& Song);
int Lenght_(int i);
void Song1();
void Song2();