#pragma once

#include <vector>
#include <string>
using namespace std;

// Data permainan.
struct StatistikPermainan {
    vector<int> koleksiHarta;
    vector<int> hartaDidapat;
};

// Data level
struct Level {
    int id;
    string petunjuk;
    string jawaban;
    string harta;
    string deskripsiHarta;
    double nilaiHarta;
};