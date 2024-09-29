#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// fungsi untuk menghitung PTKP(Penghasilan Tidak Kena Pajak)
int hitungPTKP(bool single, int jumlahAnak) {
    int ptkp = 0;

    if (single == false) {
        ptkp = 54000000;
    } 
    else if (single == true) {
        ptkp = 58500000;
    }

    // Batasi jumlah, anak maksimal 3
    if (jumlahAnak > 3) {
        jumlahAnak = 3;
    }
    if (jumlahAnak > 0) {
        ptkp += 4500000 * jumlahAnak;
    } else {
        ptkp += 0;
    }
    return ptkp;
}

// fungsi untuk menghitung biaya jabatan 
int biayaJabatan (int gajiPertahun){
    int biayaJabatan = 0.05 * gajiPertahun;
    if (biayaJabatan >= 6000000){
        biayaJabatan = 6000000;
    }
    return biayaJabatan;

}
// fungsi untuk menghitung pajak
float hitungPajak(int gajiPertahun, int pkp) {
    float pajak = 0;
    if (pkp >= 0 && pkp<= 50000000) {
        pajak = pkp * 0.05;
    }  
    else if (pkp > 50000000 && pkp <= 250000000) {
        pajak = pkp * 0.15;
    } 
    else if (pkp > 250000000 && pkp <= 500000000) {
        pajak = pkp * 0.25;
    } 
    else if (pkp > 500000000 && pkp <= 5000000000) {
        pajak = pkp * 0.30;
    } 
    else if (pkp > 5000000000) {
        pajak = pkp * 0.35;
    }

    return pajak;
}

// fungsi untuk menghitung kalkulator PPh (Pajak Penghasilan)
float kalkulatorPPh(int gajiPertahun, bool single, int jumlahAnak) {
    int ptkp = hitungPTKP(single, jumlahAnak);
    int bJabatan = biayaJabatan(gajiPertahun);
    int pkp = gajiPertahun - bJabatan - ptkp; // PKP (Penghasilan Kena Pajak) 

    // Jika PKP negatif, buat PKP menjadi 0
    if (pkp < 0) {
        pkp = 0;
    }

    float pajak = hitungPajak(gajiPertahun, pkp);
    return pajak;
}

// fungsi utama 
int main() {
    int gajiPertahun;
    bool single;
    int jumlahAnak;
    int pengulangan = 1;

    while (pengulangan == 1){
        cout << "Masukkan gaji pertahun: ";
        cin >> gajiPertahun;

        cout << "Apakah Anda sudah menikah? (ketik 1 jika sudah menikah, ketik 0 jika belum): ";
        cin >> single;

        cout << "Masukkan jumlah tanggungan (0-3): ";
        cin >> jumlahAnak;

        float pajak = kalkulatorPPh(gajiPertahun, single, jumlahAnak);
        cout << fixed << setprecision(0);
        cout << "Pajak yang harus dibayarkan pertahun: " << pajak << endl;

        cout << "Apakah Anda ingin mengulang program ini? (ketik 1 untuk ya, ketik 0 untuk tidak): ";
        cin >> pengulangan;
        cout << endl;
        
    }
    return 0;
}