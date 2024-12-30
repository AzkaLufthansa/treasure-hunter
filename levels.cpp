#pragma once

#include "constants.cpp"
#include "objects.cpp"

// Daftar level yang nantinya akan diacak setiap sesi permainan.
Level SEMUA_LEVEL[TOTAL_LEVEL] = {
    {1, "Di suatu negara yang memiliki tempat terdalam di dunia, hanya suara laut yang terdengar di tempat itu.", "Filipina", "Sistem Keamanan Canggih", "Perangkat keamanan tercanggih yang mampu mendeteksi dan mencegah ancaman dunia maya secara real-time.", 1000},
    {2, "Negara ini memiliki puncak tertinggi di dunia, sering disebut sebagai 'Atap Dunia'.", "Nepal", "Alat Komunikasi Satelit", "Alat canggih untuk komunikasi tanpa hambatan di daerah terpencil dan ekstrem.", 1050},
    {3, "Negara dengan salah satu keajaiban dunia kuno, piramida megah yang menyimpan sejarah besar.", "Mesir", "Kunci Enkripsi Kuno", "Kunci berbasis hieroglif yang dipercaya menyimpan rahasia peradaban kuno.", 2000},
    {4, "Samudra yang berbatasan dengan negara ini menyimpan kapal legendaris yang tenggelam di dasarnya.", "Amerika Serikat", "Jaringan Komunikasi Bawah Laut", "Sebuah sistem kabel bawah laut untuk transfer data ultra-cepat.", 1140},
    {5, "Hutan terbesar di dunia berada di negara ini, kaya akan misteri dan flora eksotis.", "Brasil", "Sensor Keamanan Luar Angkasa", "Sensor yang dirancang untuk melacak pergerakan satelit dan ancaman luar angkasa.", 1200},
    {6, "Di dekat Kutub Utara, negara ini memiliki wilayah es abadi yang menyimpan banyak rahasia.", "Rusia", "Sistem Komunikasi Ultra-Rahasia", "Perangkat komunikasi dengan enkripsi tingkat tinggi untuk keamanan penuh.", 1180},
    {7, "Negara ini dikenal dengan gunung suci yang menjadi simbol budaya dan alam selama berabad-abad.", "Jepang", "Algoritma Kecerdasan Buatan", "Program AI revolusioner yang dapat memproses data dalam waktu singkat.", 1225},
    {8, "Di Afrika Tengah, negara ini memiliki hutan rimbun dengan cerita tentang kerajaan kuno yang hilang.", "Republik Demokratik Kongo", "Teknologi Blockchain Tersembunyi", "Sistem blockchain rahasia untuk melindungi data transaksi global.", 1300},
    {9, "Negara ini memiliki hutan Siberia yang luas dan gelap, tempat yang penuh misteri.", "Rusia", "Sistem Pengaman Jaringan Terisolasi", "Teknologi jaringan yang tidak bisa ditembus oleh serangan cyber apapun.", 1350},
    {10, "Lembah Sungai Nil yang subur di negara ini menjadi saksi sejarah peradaban besar dunia.", "Mesir", "Perangkat Penyimpanan Data Terenkripsi", "Perangkat penyimpanan data ultra-aman yang dapat bertahan ribuan tahun.", 1400},
    {11, "Negara di Timur Tengah ini memiliki gurun terbesar, tempat penyimpanan energi masa depan.", "Arab Saudi", "Teknologi Panel Surya", "Panel surya inovatif dengan efisiensi energi yang sangat tinggi.", 14500},
    {12, "Di negara ini, terdapat kota kuno Machu Picchu yang menjadi simbol peradaban Inca.", "Peru", "Teknologi Navigasi Kuno", "Alat navigasi kuno yang tetap relevan untuk eksplorasi modern.", 1500},
    {13, "Negara ini memiliki keindahan Great Barrier Reef, rumah bagi ribuan spesies laut.", "Australia", "Teknologi Pemantauan Laut", "Sistem canggih untuk melindungi dan memantau ekosistem laut.", 1550},
    {14, "Negara ini memiliki pulau kecil di Samudra Hindia dengan pantai terindah di dunia.", "Maladewa", "Teknologi Pembersihan Laut", "Perangkat inovatif untuk membersihkan sampah plastik dari lautan.", 1600},
    {15, "Negara di Afrika ini memiliki piramida lebih banyak daripada Mesir.", "Sudan", "Sistem Enkripsi Sejarah", "Teknologi yang dapat mendekripsi tulisan dan simbol kuno.", 16500},
    {16, "Di negara ini terdapat Colosseum, simbol kejayaan Kekaisaran Romawi.", "Italia", "Teknologi Restorasi Sejarah", "Alat presisi tinggi untuk memulihkan bangunan bersejarah.", 1700},
    {17, "Negara ini terkenal dengan Aurora Borealis yang menghiasi langit malamnya.", "Norwegia", "Sistem Navigasi Bintang", "Alat navigasi canggih berbasis posisi bintang.", 17500},
    {18, "Negara ini memiliki gunung berapi aktif yang terkenal, Etna.", "Italia", "Pemantauan Aktivitas Vulkanik", "Sensor canggih untuk mendeteksi aktivitas vulkanik sebelum letusan.", 18000},
    {19, "Negara ini memiliki padang rumput luas yang menjadi rumah bagi satwa liar eksotis.", "Kenya", "Teknologi Pelestarian Satwa", "Sistem pelacakan untuk melindungi hewan langka dari kepunahan.", 1850},
    {20, "Di negara ini terdapat Stonehenge, sebuah monumen misterius yang terkenal.", "Inggris", "Sistem Deteksi Gelombang Magnetik", "Alat untuk mendeteksi energi magnetik yang tersembunyi di bumi.", 1900},
    {21, "Negara ini memiliki terumbu karang terbesar kedua di dunia setelah Australia.", "Belize", "Teknologi Konservasi Laut", "Sistem yang mendukung regenerasi terumbu karang dengan efisiensi tinggi.", 1950},
    {22, "Di negara ini terdapat saluran air kuno bernama Aqueducts, bukti peradaban canggih masa lalu.", "Spanyol", "Teknologi Rekayasa Hidraulik", "Sistem pengairan inovatif untuk pemanfaatan air yang lebih baik.", 20000},
    {23, "Negara ini memiliki Pulau Komodo, tempat tinggal kadal terbesar di dunia.", "Indonesia", "Teknologi Pemantauan Satwa Langka", "Sistem pelacakan satwa langka untuk mencegah perburuan liar.", 20500},
    {24, "Di negara ini ada Danau Baikal, danau terdalam dan tertua di dunia.", "Rusia", "Teknologi Penelitian Laut Dalam", "Peralatan penelitian yang dapat menjangkau kedalaman ekstrem.", 21000},
    {25, "Negara ini memiliki Pegunungan Rocky yang membentang panjang di benua Amerika Utara.", "Kanada", "Teknologi Pemantauan Geologi", "Alat untuk memantau pergeseran tanah dan aktivitas geologi lainnya.", 21500},
    {26, "Negara ini memiliki kastil kuno yang terkenal, Edinburgh Castle.", "Skotlandia", "Teknologi Pengamanan Digital", "Sistem keamanan berbasis digital yang tidak bisa diretas.", 22000},
    {27, "Negara ini adalah rumah bagi Pegunungan Alpen yang megah.", "Swiss", "Teknologi Pengawasan Cuaca", "Alat pemantau cuaca dengan akurasi yang sangat tinggi.", 2250},
    {28, "Negara ini memiliki Pegunungan Andes yang membentang di benua Amerika Selatan.", "Argentina", "Teknologi Perlindungan Lingkungan", "Sistem inovatif untuk mencegah kerusakan ekosistem pegunungan.", 23000},
    {29, "Negara ini memiliki Sungai Amazon, salah satu sungai terpanjang di dunia.", "Brasil", "Teknologi Pemantauan Ekosistem", "Sistem yang dirancang untuk menjaga keanekaragaman hayati Amazon.", 23500},
    {30, "Negara ini terkenal dengan tembok raksasa yang menjadi keajaiban dunia.", "Cina", "Teknologi Pengamanan Perbatasan", "Sistem keamanan mutakhir untuk perlindungan wilayah.", 24000}
};