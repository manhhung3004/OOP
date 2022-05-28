#include"Music_composser.h"

int main()
{
    //NOTE;
    vector <NOTE*> song;
    Menu(song);

    system("pause");
    return 0;
}

/*
* ---------------------------------------------------------------
                    Chương trình soạn nhạc

                 Nhấn 1 đển chọn: Chọn bài hát sẵn có
                 Nhấn 0 để thoát:
                 Nhấn 2 để tạo bài hát mới:

                1: /////////
                    1: hãy trao cho anh
                        nhấn 1 đển đếm số nốt lặng:
                        nhấn 2 tìm min và max của nốt:
                        nhấn 0 để về menu:
                    2: Con cò bé bé
                        nhấn 1 đển đếm số nốt lặng:
                        nhấn 2 tìm min và max của nốt:
                        nhấn 0 để về menu:
                0////
                        return 0;
                2///
                Trường độ:               Cao độ:
                C = Đô                  Semibreve = nốt tròn = 4
                D = Rê                  Minim = nốt trắng = 2
                E = Mi                  Crotchet = nốt đen = 1
                F = Pha                 Quaver = móc đơn = 1/2
                G = Sol                 Semiquaver = Semi = móc kép = 1/4
                A = La                  Demisemiquaver= Desemi = móc tam = 1/8
                B = Si                  Hemidemisemiquaver = Hemi = móc tứ = 1/16
                    Nhấn 1 để tiếp tục:
                    Nhấn 0 để quay về menu:
                    height : Cao độ
                    Lengh: Trường độ

*/
