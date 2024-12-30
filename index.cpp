#include <iostream>
#include <limits>
#include <conio.h>

#include "game_functions.cpp"
#include "helper_functions.cpp"
#include "constants.cpp"
#include "objects.cpp"
#include "levels.cpp"

using namespace std;

int main() {
    StatistikPermainan statistik;

    menu_utama:
    // Cetak header permainan.
    cetakBoxJudul();

    // Pilih menu.
    int pilihan;
    cout << "MENU PERBURUAN HARTA KARUN" << endl;
    cout << "1. Mulai Petualangan Mencari Harta" << endl;
    cout << "2. Lihat Koleksi Harta Karunmu" << endl;
    cout << "3. Akhiri Petualangan" << endl;
    
    // Validasi input.
    pilih_mode:
    do {
        cout << "Masukkan Pilihanmu (1/2/3): ";
        cin >> pilihan;
    } while (!inputValid());

    switch (pilihan) {
        case 1:
            // Mulai permainan.
            system("cls");
            statistik.hartaDidapat.clear();
            mulaiPetualangan(&statistik);

            // Kembali ke menu utama ketika selesai bermain.
            cout << "Tekan apa saja untuk kembali ke menu utama..";
            getch();
            system("cls");
            goto menu_utama;

            break;
        case 2:
            // Lihat koleksi harta karun.
            system("cls");
            lihatKoleksiHartaKarun(statistik);

            // Kembali ke menu utama.
            cout << endl << "Tekan apa saja untuk kembali ke menu utama..";
            getch();
            system("cls");
            goto menu_utama;
            
            break;
        case 3:
            // Akhiri petualangan.
            system("cls");
            akhiriPetualangan();
            return 0;
        default:
            cout << "Input yang Kamu masukkan tidak valid!" << endl;
            goto pilih_mode;
    }

    getch();

    return 0;
}