#include <iostream>
#include <limits>
#include <stdlib.h>
#include <conio.h>

#include "levels.cpp"
#include "objects.cpp"
#include "constants.cpp"
#include "helper_functions.cpp"

using namespace std;

void mulaiPetualangan(StatistikPermainan* statistik) {
    srand(time(0));
    
    // ID level yang akan dimainkan
    int generatedLevel[LEVEL_YANG_AKAN_DIMAINKAN];

    // Generate lima level random
    for (int i = 0; i < LEVEL_YANG_AKAN_DIMAINKAN; i++) {
        int randomLevelId = rand() % TOTAL_LEVEL + 1;

        // Cek apakah level sudah terdapat didalam list
        if (!levelSudahAda(randomLevelId, generatedLevel)) {
            generatedLevel[i] = randomLevelId;
        } else {
            i--;
        }
    }

    cout << endl;
    cout << "||=================================================================================================||" << endl;
    cout << "||                                                                                                 ||" << endl;
    cout << "||                                     PETUALANGAN DIMULAI                                        ||" << endl;
    cout << "||                                                                                                 ||" << endl;
    cout << "||=================================================================================================||" << endl;
    cout << endl << "Tebak lokasinya dengan tepat! Gunakan petunjuk yang diberikan untuk menemukan tempat tersembunyi di" << endl;
    cout << "dunia dan buktikan bahwa kamu adalah pemburu harta karun sejati!" << endl << endl;

    // Perulangan untuk menampilkan level.
    for (int i = 0; i < LEVEL_YANG_AKAN_DIMAINKAN; i++) {
        // Bersihkan buffer.
        if (i == 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            system("cls");
        }

        // Cari data level berdasarkan id.
        Level dataLevel = cariDataLevel(generatedLevel[i], SEMUA_LEVEL);
        string inputJawaban;
        int sisaPercobaan = 3;
        bool intensityUp = false;

        // Tampilkan level, petunjuk, dan input jawaban.
        cout << "[Level " << i + 1 << "]" << endl;
        cout << "Petunjuk: " << "\"" << dataLevel.petunjuk << "\"" << endl;
        cout << "Masukkan lokasi yang ingin kamu telusuri: ";
        getline(cin, inputJawaban);

        // Jika sudah mencapai level 3, maka kesempatan hanya sekali 
        if ((i + 1) >= (LEVEL_YANG_AKAN_DIMAINKAN - 2)) {
            intensityUp = true;
            sisaPercobaan = 1;
        }

        // Cek jawaban.
        while (!jawabanValid(inputJawaban, dataLevel.jawaban)) {
            sisaPercobaan--;

            if (sisaPercobaan == 0) {
                // Jika intensity up, maka langsung selesai
                if (intensityUp) {
                    i = LEVEL_YANG_AKAN_DIMAINKAN;
                    break;
                }
                
                break;
            }

            if (sisaPercobaan == 2) {
                cout << endl << "Kamu pergi ke " << inputJawaban << ", namun kamu tidak menemukan apa-apa." << endl;
                cout << "Kamu masih memiliki " << sisaPercobaan << " kesempatan lagi." << endl;
            } else if (sisaPercobaan == 1) {
                cout << endl << "Kamu pergi ke " << inputJawaban << ", namun kamu masih tidak menemukan apa-apa." << endl;
                cout << "Ini percobaan terakhir kamu. Jika kamu masih belum menemukan hartamu, maka kamu akan gagal." << endl;
            } else {
                cout << endl << "Kamu pergi ke " << inputJawaban << ", namun kamu tidak menemukan apa-apa." << endl;
                cout << "Nampaknya kamu kurang tepat dalam menentukan lokasi." << endl;
            }

            cout << endl;
            
            cout << "Masukkan lokasi yang ingin kamu telusuri: ";
            getline(cin, inputJawaban);
        }

        // Jika gagal pada stage ini.
        if (sisaPercobaan == 0) {
            cout << endl << "Kamu gagal untuk mendapat harta ini." << endl;
        } else {
            // Jika berhasil menjawab.
            cout << endl << "Selamat! Usahamu tidak sia-sia. Kamu menemukan harta karun di " << inputJawaban << "!" << endl;
            cout << dataLevel.harta << ": " << dataLevel.deskripsiHarta << endl;

            // Tambahkan harta yang didapat ke dalam statistik permainan.
            statistik->hartaDidapat.push_back(dataLevel.id);
            statistik->koleksiHarta.push_back(dataLevel.id);
        }

        cout << endl;

        if (i != LEVEL_YANG_AKAN_DIMAINKAN - 1) {
            cout << "Lanjutkan pencarian harta lainnya..";
            getch();
            system("cls");
        }
    }

    // Petualangan berakhir setalah 5 level sudah ditampilkan.
    cout << "Kamu kelelahan dan memutuskan untuk menghentikan perburuan harta karun." << endl;
    cout << "Tekan apa saja untuk melihat hasil perburuanmu..";
    getch();
    system("cls");

    // ~ PETUALANGAN SELESAI ~
    cout << "||=================================================================================================||" << endl;
    cout << "||                                                                                                 ||" << endl;
    cout << "||                                      PETUALANGAN SELESAI                                        ||" << endl;
    cout << "||                                                                                                 ||" << endl;
    cout << "||=================================================================================================||" << endl << endl;
    cout << "Setelah melewati berbagai tantangan, teka-teki, dan misteri dari penjuru " << endl;
    cout << "dunia, kamu berhasil mengumpulkan harta-harta berharga berikut ini:" << endl;

    for (int i = 0; i < statistik->hartaDidapat.size(); i++) {
        Level dataLevel = cariDataLevel(statistik->hartaDidapat[i], SEMUA_LEVEL);
        cout << i + 1 << ". " << dataLevel.harta << ": " << dataLevel.deskripsiHarta << " - $" << dataLevel.nilaiHarta << endl;
    }

    cout << endl << "Kamu dapat melihat koleksi harta karun yang pernah kamu dapatkan dengan pergi ke menu 'Lihat Koleksi'." << endl << endl;
}

void lihatKoleksiHartaKarun(StatistikPermainan statistik) {
    cout << "Kamu memiliki " << statistik.koleksiHarta.size() << " harta karun." << endl;

    for (int i = 0; i < statistik.koleksiHarta.size(); i++) {
        Level dataLevel = cariDataLevel(statistik.koleksiHarta[i], SEMUA_LEVEL);
        cout << i + 1 << ". " << dataLevel.harta << ": " << dataLevel.deskripsiHarta << " - $" << dataLevel.nilaiHarta << endl;
    }
}

void akhiriPetualangan() {
    cout << "Terima kasih sudah bermain!" << endl;
    cout << "Selamat bertemu di petualangan yang selanjutnya." << endl;
    cout << "Jangan lupa untuk membawa keberanian dan semangatmu lagi!" << endl;
}
