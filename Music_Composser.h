#pragma once
#include<iostream>
#include<fstream>
#include<windows.h> // WinApi header 
#include<vector>
#include<string>
#include<cstring>

using namespace std;

/*

Các thuộc tính cơ bản của 1 nốt

Trường độ:               Cao độ:
  C = Đô                  Semibreve = nốt tròn = 4
  D = Rê                  Minim = nốt trắng = 2
  E = Mi                  Crotchet = nốt đen = 1
  F = Pha                 Quaver = móc đơn = 1/2
  G = Sol                 Semiquaver = Semi = móc kép = 1/4
  A = La                  Demisemiquaver= Desemi = móc tam = 1/8
  B = Si                  Hemidemisemiquaver = Hemi = móc tứ = 1/16




   Song( bài hát): tập hợp các nốt
   -> vector V  mảng V linked list
   -> vector <NOTE*> Song

   Nốt:
    + Nốt nhạc(các nốt phát ra tiếng): cao độ, trường độ.
    + Dấu lặng(các nốt ko phát ra tiếng): chỉ có trường độ.

   ->
   class NOTE{
        + Các thuộc tính chung
        + Các hàm khởi tạo (dạng virtual)
        + Các hàm chức năng ( dạng virtual / dạng bt)
   };

   class MusicNote : public NOTE{
        protected:
             trường độ;
        public:
             các hàm dạng ảo nêu trên;
   };

   class REST : public NOTE{
        protected:
            trên lý thuyết là del có bỏ trống
        public:
            các hàm dạng ảo ở trên;
   };

*/




// NOTE
class NOTE {
protected:
    int Type; 
    int Lenght;
public:
  
    NOTE();
    NOTE(int lenght);
    virtual ~NOTE();

    
    int GetType() {
        return Type;
    }
  
    virtual void SetL();
    virtual void SetH();

    virtual int GetL();
    virtual int GetH();
  
    virtual void Sound();
    virtual void PrintNote();
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
    void SetH();
    void SetL();

    int GetH();
    int GetL();

    void PrintNote();
    void Sound();

};

void NewSong(vector<NOTE*>& Song);
void SavedSong(vector<NOTE*>& Song);
