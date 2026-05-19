#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struktur data untuk menyimpan info jamuan teman
struct Teman {
    long long awal;
    long long durasi;
    long long selesai;
};

// Fungsi bantuan untuk mengurutkan teman berdasarkan waktu selesai paling cepat
bool urutSelesai(Teman a, Teman b) {
    return a.selesai < b.selesai;
}

int main() {
    int n;
    cin >> n;

    vector<Teman> daftarTeman(n);
    for (int i = 0; i < n; i++) {
        cin >> daftarTeman[i].awal >> daftarTeman[i].durasi;
        // Waktu selesai = Waktu Awal + Durasi
        daftarTeman[i].selesai = daftarTeman[i].awal + daftarTeman[i].durasi;
    }

    // Langkah Greedy 1: Urutkan berdasarkan waktu selesai tercepat
    sort(daftarTeman.begin(), daftarTeman.end(), urutSelesai);

    int totalTemanDiundang = 0;
    long long waktuSelesaiTerakhir = -1;

    // Langkah Greedy 2: Pilih jamuan yang tidak bentrok
    for (int i = 0; i < n; i++) {
        if (daftarTeman[i].awal >= waktuSelesaiTerakhir) {
            // Jadwal tidak bentrok, teman bisa diundang
            totalTemanDiundang++;
            waktuSelesaiTerakhir = daftarTeman[i].selesai; // Update batas waktu selesai
        }
    }

    cout << totalTemanDiundang << endl;
    return 0;
}