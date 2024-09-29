#include <iostream>
using namespace std;

    //menghitung biaya jabatan
    void biaya_jabatan(int penghasilan){
        int hasil = (5/100) * penghasilan;
        cout << "Biaya jabatan : " << hasil;
    }
    //menghitung penghasilan tidak kena pajak(PTKP)
    void hitung_PTKP(int status, int tanggungan) { 
        float PTKP;
        switch (status){ 
            case 0: // TK/0 : Tidak Kawin/tanggungan 0
                PTKP = 54000000;
                break;
            case 1: // TK/1 : Tidak Kawin/tanggungan 1
                PTKP = 58500000;
                break;
            case 2: // TK/2 : Tidak Kawin/tanggungan 2
                PTKP = 63000000;
                break;
            case 3: // TK/3 : Tidak Kawin/tanggungan 3
                PTKP = 67500000;
                break;
            case 4: // K/0 : Kawin/tanggungan 0
                PTKP = 58500000;
                break;
            case 5: // K/1 : Kawin/tanggungan 1
                PTKP = 63000000;
                break;
            case 6: // K/2 : Kawin/tanggungan 2
                PTKP = 67500000;
                break;
            case 7: // K/3 : Kawin/tanggungan 3
                PTKP = 72000000;
                break;
            case 8: // K/I/0 : Kawin/penghasilan suami isri digabung/tanggungan 0   
                PTKP = 112500000;
                break;
            case 9: // K/I/1 :  Kawin/penghasilan suami isri digabung/tanggungan 1    
                PTKP = 117000000;
                break;
            case 10: // K/I/2 :  Kawin/penghasilan suami isri digabung/tanggungan 2 
                PTKP = 121500000;
                break;
            case 11: // K/I/3 :  Kawin/penghasilan suami isri digabung/tanggungan 3
                PTKP = 126000000;
                break;
            default : cout << "Status Salah";
                break;
        }
        // ada tambahan PTKP untuk setiap tanggungan 
        PTKP += (tanggungan * 4500000); 
    }
    


int main () {
    cout << "Penghitung Pajak Penghasilan" << endl;
    int Nama, penghasilan, jenis_kelamin, PPh;
    cout << "Nama : "; 
    cin >> Nama;
    cout << "Penghasilan per tahun : ";
    cin >> penghasilan;
    cout << "Jenis kelamin : "; // pria atau wanita
    cin >> jenis_kelamin;

    // menghitung PPh (Pajak Penghasilan)
    if (penghasilan == 0 && penghasilan <= 50000000){
            PPh = (5/100) * penghasilan;
        }
        else if (penghasilan == 50000000 && penghasilan <= 250000000){
            PPh = (15/100) * penghasilan;
        }
        else if (penghasilan == 250000000 && penghasilan <= 500000000){
            PPh = (25/100) * penghasilan;
        }
        else if (penghasilan == 500000000 && penghasilan <= 5000000000){
            PPh = (30/100) * penghasilan;
        }
        else if (penghasilan > 5000000000){
            PPh = (35/100) * penghasilan;
        }
        else {
            
        }
} 