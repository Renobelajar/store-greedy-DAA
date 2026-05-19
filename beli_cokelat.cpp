#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struktur data untuk menyimpan info cokelat
struct Cokelat {
    long long harga;
    long long bebek;
};

// Fungsi bantuan untuk mengurutkan cokelat berdasarkan harga termurah
bool urutHarga(Cokelat a, Cokelat b) {
    return a.harga < b.harga;
}

int main() {
    int n;
    long long d;
    cin >> n >> d;

    vector<Cokelat> daftarCokelat(n);
    for (int i = 0; i < n; i++) {
        cin >> daftarCokelat[i].harga >> daftarCokelat[i].bebek;
    }

    // Langkah Greedy 1: Urutkan dari harga termurah
    sort(daftarCokelat.begin(), daftarCokelat.end(), urutHarga);

    long long totalBebekSenang = 0;

    // Langkah Greedy 2: Ambil sebanyak-banyaknya dari yang termurah
    for (int i = 0; i < n; i++) {
        long long totalHargaJenisIni = daftarCokelat[i].harga * daftarCokelat[i].bebek;

        if (d >= totalHargaJenisIni) {
            // Jika uang cukup untuk memborong tipe ini
            d -= totalHargaJenisIni;
            totalBebekSenang += daftarCokelat[i].bebek;
        } else {
            // Jika uang tidak cukup borong, beli semampunya uang yang tersisa
            long long yangBisaDibeli = d / daftarCokelat[i].harga;
            totalBebekSenang += yangBisaDibeli;
            break; // Uang sudah habis digunakan maksimal
        }
    }

    cout << totalBebekSenang << endl;
    return 0;
}