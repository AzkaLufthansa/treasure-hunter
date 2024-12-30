#pragma once

#include <iostream>
#include <limits>
#include <algorithm>

#include "constants.cpp"
#include "objects.cpp"

using namespace std;

// Cetak box, bertuliskan judul dan deskripsi permainan.
void cetakBoxJudul() {
    cout << "||=================================================================================================||" << endl;
    cout << "||                                                                                                 ||" << endl;
    cout << "||                                          TREASURE TECH:                                         ||" << endl;
    cout << "||                             Petualangan Menentukan Harta Teknologi                              ||" << endl;
    cout << "||                                                                                                 ||" << endl;
    cout << "||=================================================================================================||" << endl;
    cout << "||                                                                                                 ||" << endl;
    cout << "||                              Sebuah game petualangan berbasis teks                              ||" << endl;
    cout << "||                               Jelajahi dunia teknologi yang penuh                               ||" << endl;
    cout << "||                                 misteri, teka-teki, dan harta                                   ||" << endl;
    cout << "||                                                                                                 ||" << endl;
    cout << "||=================================================================================================||" << endl;

    cout << endl << "Selamat datang, Pemburu Harta Karun!" << endl;  
    cout << "Tugasmu adalah menemukan harta karun tersembunyi di lokasi-lokasi terkenal di dunia." << endl;
    cout << "Petualangan ini penuh tantangan, jadi pastikan kamu menjawab dengan benar!" << endl << endl;
}

// Mencari data level berdasarkan id level.
Level cariDataLevel(int levelId, Level semuaLevel[TOTAL_LEVEL]) {
    for (int i = 0; i < TOTAL_LEVEL; ++i) {
        if (semuaLevel[i].id == levelId) {
            return semuaLevel[i];
        }
    }

    return Level{-1, "", "", "", "", 0.0};
}

// Mengecek apakah jawaban yang diberikan sudah benar dan valid.
bool jawabanValid(string inputUser, string jawaban) {
    // Ubah menjadi lower case.
    transform(inputUser.begin(), inputUser.end(), inputUser.begin(), ::tolower);
    transform(jawaban.begin(), jawaban.end(), jawaban.begin(), ::tolower);

    // Jika jawaban salah.
    if (cin.fail() || (inputUser != jawaban)) {
        return false;
    }

    return true;
}

// Validasi input. Mengembalikan `true` jika input valid
bool inputValid() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input yang kamu masukkan tidak valid!" << endl;
        
        // Input tidak valid.
        return false;
    }

    // Input valid.
    return true;
}

// Mengecek apakah level sudah terdapat dalam array.
// Agar satu sesi permainan tidak ada level yang sama.
bool levelSudahAda(int randomLevelId, int* generatedLevel) {
     for (int i = 0; i < LEVEL_YANG_AKAN_DIMAINKAN; ++i) {
         if (generatedLevel[i] == -1) {
            continue;
        }

        if (randomLevelId == generatedLevel[i]) {
            return true;
        }
    }

    return false;
}