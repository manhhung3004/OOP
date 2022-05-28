#include"Music_composser.h"

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
            cout << "Nhap vao truong do:\n";
            Song[Song.size() - 1]->SetL();
            break;
        case 2:
            cout << "NOT NHAC\n";
            Song.push_back(new MusicNote());
            cout << "Nhap vao cao do:\n";
            Song[Song.size() - 1]->SetH();
            cout << "Nhap vao truong do:\n";
            Song[Song.size() - 1]->SetL();
            break;
        case 3:
            break;
        }
        //for (int i = 0; i < Song.max_size() - 1; i++) {
            //Song[i]->Sound();
            //Song[i]->PrintNote();
        //}
    } while (choice != 3);
}