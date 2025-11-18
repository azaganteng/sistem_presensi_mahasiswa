#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

struct Data {
    string nim;
    string nama;
    char status[5];
    int hadir;
    int izin;
    int sakit;
    int alpa;
};

Data mahasiswa[10] = {
    {"24051130001", "Neshia",      {'\0','\0','\0','\0','\0'}},
    {"24051130002", "Luthfian",    {'\0','\0','\0','\0','\0'}},
    {"24051130003", "Angger",      {'\0','\0','\0','\0','\0'}},
    {"24051130004", "Haidar",      {'\0','\0','\0','\0','\0'}},
    {"24051130005", "Glen",        {'\0','\0','\0','\0','\0'}},
    {"24051130006", "Mulisa",      {'\0','\0','\0','\0','\0'}},
    {"24051130007", "Kartika",     {'\0','\0','\0','\0','\0'}},
    {"24051130008", "La D'raz",    {'\0','\0','\0','\0','\0'}},
    {"24051130009", "Elfrina",     {'\0','\0','\0','\0','\0'}},
    {"24051130010", "Bayu",        {'\0','\0','\0','\0','\0'}}
};

int jumlahMhs = 10;

int cariMahasiswa(string nim) {
    for (int i = 0; i < jumlahMhs; i++) {
        if (mahasiswa[i].nim == nim)
            return i;
    }
    return -1;
}

void inputPresensi() {
    string nim;
    cout << "\nMasukkan NIM: ";
    cin >> nim;

    int idx = cariMahasiswa(nim);
    if (idx == -1) {
        cout << "NIM tidak ditemukan!\n";
        return;
    }

    cout << "Nama : " << mahasiswa[idx].nama << endl;

    int hari = -1;
    for (int i = 0; i < 5; i++) {
        if (mahasiswa[idx].status[i] == '\0') {
            hari = i;
            break;
        }
    }

    if (hari == -1) {
        cout << "Presensi sudah penuh 5 pertemuan!\n";
        return;
    }

    cout << "Mengisi presensi pertemuan ke-" << hari + 1 << endl;
    cout << "Masukkan status (H/I/S/A): ";
    char s;
    cin >> s;
    mahasiswa[idx].status[hari] = toupper(s);

    cout << "Presensi pertemuan ke-" << hari + 1 << " tersimpan!\n";
}

void hitungRekap(Data mahasiswa[], int n) {
    for (int i = 0; i < n; i++) {
        mahasiswa[i].hadir = 0;
        mahasiswa[i].izin = 0;
        mahasiswa[i].sakit = 0;
        mahasiswa[i].alpa = 0;

        for (int j = 0; j < 5; j++) {
            switch (mahasiswa[i].status[j]) {
                case 'H': mahasiswa[i].hadir++; break;
                case 'I': mahasiswa[i].izin++; break;
                case 'S': mahasiswa[i].sakit++; break;
                case 'A': mahasiswa[i].alpa++; break;
            }
        }
    }
}

void bubbleSortAlpa(Data mahasiswa[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mahasiswa[j].alpa < mahasiswa[j + 1].alpa) {
                swap(mahasiswa[j], mahasiswa[j + 1]);
            }
        }
    }
}

void tampilkanRekap(Data mahasiswa[], int n) {
    hitungRekap(mahasiswa, n);

    cout << "\n=== REKAP PRESENSI MAHASISWA ===\n\n";

    cout << left
         << setw(12) << "NIM"
         << setw(15) << "Nama"
         << setw(7)  << "Hadir"
         << setw(7)  << "Sakit"
         << setw(7)  << "Izin"
         << setw(7)  << "Alpa"
         << endl;

    for (int i = 0; i < n; i++) {
        cout << left
             << setw(12) << mahasiswa[i].nim
             << setw(15) << mahasiswa[i].nama
             << setw(7)  << mahasiswa[i].hadir
             << setw(7)  << mahasiswa[i].sakit
             << setw(7)  << mahasiswa[i].izin
             << setw(7)  << mahasiswa[i].alpa
             << endl;
    }

    bubbleSortAlpa(mahasiswa, n);

    cout << "\n=== MAHASISWA DENGAN ALPA TERTINGGI ===\n";
    cout << "Nama : " << mahasiswa[0].nama << endl;
    cout << "NIM  : " << mahasiswa[0].nim  << endl;
    cout << "Alpa : " << mahasiswa[0].alpa << endl;
}

void cariData() {
    string nim;
    cout << "\nMasukkan NIM: ";
    cin >> nim;

    int idx = cariMahasiswa(nim);

    if (idx == -1) {
        cout << "Mahasiswa tidak ditemukan!\n";
        return;
    }

    hitungRekap(mahasiswa, jumlahMhs);

    cout << "\nData ditemukan!\n";
    cout << "Nama  : " << mahasiswa[idx].nama << endl;
    cout << "Hadir : " << mahasiswa[idx].hadir << endl;
    cout << "Sakit : " << mahasiswa[idx].sakit << endl;
    cout << "Izin  : " << mahasiswa[idx].izin << endl;
    cout << "Alpa  : " << mahasiswa[idx].alpa << endl;
}

int main() {
    int pilih;

    do {
        cout << "\n=== MENU PRESENSI MAHASISWA ===\n";
        cout << "1. Input Presensi\n";
        cout << "2. Tampilkan Rekap\n";
        cout << "3. Cari Mahasiswa\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: inputPresensi(); break;
            case 2: tampilkanRekap(mahasiswa, jumlahMhs); break;
            case 3: cariData(); break;
            case 4: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 4);

    return 0;
}
