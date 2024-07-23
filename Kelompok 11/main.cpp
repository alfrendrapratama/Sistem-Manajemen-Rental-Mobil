#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Pelanggan {
    int id;
    string nama;
    string no_telfon;
    Pelanggan* next;
};

struct Mobil {
    string tipe;
    string nama;
    string plat_nomor;
    int harga_sewa;
    bool tersedia;
    Mobil* next;
};

struct Transaksi {
    string nama_pelanggan;
    string tipe_kendaraan;
    string nama_kendaraan;
    int lama_sewa;
    int total_harga;
    Transaksi* next;
};

Pelanggan* headPelanggan = nullptr;
Mobil* headMobil = nullptr;
Transaksi* headTransaksi = nullptr;

void tambahPelanggan() {
    Pelanggan* baru = new Pelanggan();
    cout << "Masukkan ID Pelanggan: ";
    cin >> baru->id;
    cin.ignore();
    cout << "Masukkan Nama Pelanggan: ";
    getline(cin, baru->nama);
    cout << "Masukkan No Telfon: ";
    getline(cin, baru->no_telfon);
    baru->next = headPelanggan;
    headPelanggan = baru;
    cout << "Pelanggan berhasil ditambahkan.\n\n";
}

void editPelanggan() {
    int id;
    cout << "Masukkan ID Pelanggan yang ingin diedit: ";
    cin >> id;
    Pelanggan* current = headPelanggan;
    while (current != nullptr) {
        if (current->id == id) {
            cin.ignore();
            cout << "Masukkan Nama Baru: ";
            getline(cin, current->nama);
            cout << "Masukkan No Telfon Baru: ";
            getline(cin, current->no_telfon);
            cout << "Pelanggan berhasil diedit.\n\n";
            return;
        }
        current = current->next;
    }
    cout << "Pelanggan tidak ditemukan.\n\n";
}

void hapusPelanggan() {
    string nama;
    cin.ignore();
    cout << "Masukkan Nama Pelanggan yang ingin dihapus: ";
    getline(cin, nama);
    Pelanggan* current = headPelanggan;
    Pelanggan* prev = nullptr;
    while (current != nullptr) {
        if (current->nama == nama) {
            if (prev == nullptr) {
                headPelanggan = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "Pelanggan berhasil dihapus.\n\n";
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Pelanggan tidak ditemukan.\n\n";
}

void bubbleSortPelanggan() {
    if (headPelanggan == nullptr) return;
    bool swapped;
    Pelanggan* current;
    Pelanggan* lastPtr = nullptr;
    do {
        swapped = false;
        current = headPelanggan;
        while (current->next != lastPtr) {
            if (current->id > current->next->id) {
                swap(current->id, current->next->id);
                swap(current->nama, current->next->nama);
                swap(current->no_telfon, current->next->no_telfon);
                swapped = true;
            }
            current = current->next;
        }
        lastPtr = current;
    } while (swapped);
}

void tampilkanPelanggan() {
    bubbleSortPelanggan();
    Pelanggan* current = headPelanggan;
    cout << "Daftar Pelanggan:\n";
    cout << left << setw(10) << "No" << setw(20) << "Nama" << "No Telfon\n";
    while (current != nullptr) {
        cout << left << setw(10) << current->id << setw(20) << current->nama << setw(15) << current->no_telfon << endl;
        current = current->next;
    }
    cout << endl;
}

void tambahMobil() {
    Mobil* baru = new Mobil();
    cout << "Masukkan Tipe Mobil (sedan/suv/lcgc): ";
    cin >> baru->tipe;
    cin.ignore();
    cout << "Masukkan Nama Mobil: ";
    getline(cin, baru->nama);
    cout << "Masukkan Plat Nomor: ";
    getline(cin, baru->plat_nomor);
    if (baru->tipe == "lcgc") {
        baru->harga_sewa = 200000;
    }
    else if (baru->tipe == "suv") {
        baru->harga_sewa = 300000;
    }
    else if (baru->tipe == "sedan") {
        baru->harga_sewa = 450000;
    }
    baru->tersedia = true;
    baru->next = headMobil;
    headMobil = baru;
    cout << "Mobil berhasil ditambahkan.\n\n";
}

void editMobil() {
    string nama;
    cin.ignore();
    cout << "Masukkan Nama Mobil yang ingin diedit: ";
    getline(cin, nama);
    Mobil* current = headMobil;
    while (current != nullptr) {
        if (current->nama == nama) {
            cout << "Masukkan Tipe Mobil Baru (sedan/suv/lcgc): ";
            cin >> current->tipe;
            cin.ignore();
            cout << "Masukkan Nama Mobil Baru: ";
            getline(cin, current->nama);
            cout << "Masukkan Plat Nomor Baru: ";
            getline(cin, current->plat_nomor);
            if (current->tipe == "lcgc") {
                current->harga_sewa = 200000;
            }
            else if (current->tipe == "suv") {
                current->harga_sewa = 300000;
            }
            else if (current->tipe == "sedan") {
                current->harga_sewa = 450000;
            }
            cout << "Mobil berhasil diedit.\n\n";
            return;
        }
        current = current->next;
    }
    cout << "Mobil tidak ditemukan.\n\n";
}

void hapusMobil() {
    string nama;
    cin.ignore();
    cout << "Masukkan Nama Mobil yang ingin dihapus: ";
    getline(cin, nama);
    Mobil* current = headMobil;
    Mobil* prev = nullptr;
    while (current != nullptr) {
        if (current->nama == nama) {
            if (prev == nullptr) {
                headMobil = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "Mobil berhasil dihapus.\n\n";
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Mobil tidak ditemukan.\n\n";
}

void bubbleSortMobil() {
    if (headMobil == nullptr) return;
    bool swapped;
    Mobil* current;
    Mobil* lastPtr = nullptr;
    do {
        swapped = false;
        current = headMobil;
        while (current->next != lastPtr) {
            if (current->nama > current->next->nama) {
                swap(current->tipe, current->next->tipe);
                swap(current->nama, current->next->nama);
                swap(current->plat_nomor, current->next->plat_nomor);
                swap(current->harga_sewa, current->next->harga_sewa);
                swap(current->tersedia, current->next->tersedia);
                swapped = true;
            }
            current = current->next;
        }
        lastPtr = current;
    } while (swapped);
}

void tampilkanMobil() {
    bubbleSortMobil();
    Mobil* current = headMobil;
    cout << "Daftar Mobil:\n";
    cout << left << setw(15) << "Tipe" << setw(20) << "Nama" << setw(15) << "Plat Nomor" << setw(10) << "Harga Sewa" << "Status\n";
    while (current != nullptr) {
        cout << left << setw(15) << current->tipe << setw(20) << current->nama << setw(15) << current->plat_nomor << setw(10) << current->harga_sewa << (current->tersedia ? "Tersedia" : "Dipinjam") << endl;
        current = current->next;
    }
    cout << endl;
}

void sewaKendaraan() {
    Transaksi* baru = new Transaksi();
    cin.ignore();
    cout << "Masukkan Nama Pelanggan: ";
    getline(cin, baru->nama_pelanggan);
    cout << "Masukkan Tipe Kendaraan (sedan/suv/lcgc): ";
    cin >> baru->tipe_kendaraan;
    cin.ignore();
    cout << "Masukkan Nama Kendaraan: ";
    getline(cin, baru->nama_kendaraan);
    cout << "Masukkan Lama Sewa (dalam hari): ";
    cin >> baru->lama_sewa;

    Mobil* currentMobil = headMobil;
    while (currentMobil != nullptr) {
        if (currentMobil->nama == baru->nama_kendaraan && currentMobil->tipe == baru->tipe_kendaraan) {
            if (currentMobil->tersedia) {
                currentMobil->tersedia = false;
                baru->total_harga = currentMobil->harga_sewa * baru->lama_sewa;
                baru->next = headTransaksi;
                headTransaksi = baru;
                cout << "Transaksi berhasil.\n\n";
                return;
            }
            else {
                cout << "Mobil tidak tersedia.\n\n";
                return;
            }
        }
        currentMobil = currentMobil->next;
    }
    cout << "Mobil tidak ditemukan.\n\n";
}

void editSewaKendaraan() {
    string nama_pelanggan;
    cin.ignore();
    cout << "Masukkan Nama Pelanggan yang ingin diedit: ";
    getline(cin, nama_pelanggan);
    Transaksi* current = headTransaksi;
    while (current != nullptr) {
        if (current->nama_pelanggan == nama_pelanggan) {
            cout << "Masukkan Tipe Kendaraan Baru (sedan/suv/lcgc): ";
            cin >> current->tipe_kendaraan;
            cin.ignore();
            cout << "Masukkan Nama Kendaraan Baru: ";
            getline(cin, current->nama_kendaraan);
            cout << "Masukkan Lama Sewa Baru (dalam hari): ";
            cin >> current->lama_sewa;
            Mobil* currentMobil = headMobil;
            while (currentMobil != nullptr) {
                if (currentMobil->nama == current->nama_kendaraan && currentMobil->tipe == current->tipe_kendaraan) {
                    current->total_harga = currentMobil->harga_sewa * current->lama_sewa;
                    cout << "Transaksi berhasil diedit.\n\n";
                    return;
                }
                currentMobil = currentMobil->next;
            }
            cout << "Mobil tidak ditemukan.\n\n";
            return;
        }
        current = current->next;
    }
    cout << "Transaksi tidak ditemukan.\n\n";
}

void hapusSewaKendaraan() {
    string nama_pelanggan;
    cin.ignore();
    cout << "Masukkan Nama Pelanggan yang ingin dihapus: ";
    getline(cin, nama_pelanggan);
    Transaksi* current = headTransaksi;
    Transaksi* prev = nullptr;
    while (current != nullptr) {
        if (current->nama_pelanggan == nama_pelanggan) {
            if (prev == nullptr) {
                headTransaksi = current->next;
            }
            else {
                prev->next = current->next;
            }
            Mobil* currentMobil = headMobil;
            while (currentMobil != nullptr) {
                if (currentMobil->nama == current->nama_kendaraan && currentMobil->tipe == current->tipe_kendaraan) {
                    currentMobil->tersedia = true;
                    break;
                }
                currentMobil = currentMobil->next;
            }
            delete current;
            cout << "Transaksi berhasil dihapus.\n\n";
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Transaksi tidak ditemukan.\n\n";
}

void tampilkanTransaksi() {
    Transaksi* current = headTransaksi;
    cout << "Daftar Transaksi:\n";
    cout << left << setw(20) << "Nama Pelanggan" << setw(15) << "Tipe Kendaraan" << setw(20) << "Nama Kendaraan" << setw(15) << "Lama Sewa" << "Total Harga\n";
    while (current != nullptr) {
        cout << left << setw(20) << current->nama_pelanggan << setw(15) << current->tipe_kendaraan << setw(20) << current->nama_kendaraan << setw(15) << current->lama_sewa << current->total_harga << endl;
        current = current->next;
    }
    cout << endl;

    tampilkanMobil();
}

void menuPelanggan() {
    int pilihan;
    do {
        cout << endl;
        cout << "Menu Pelanggan:\n";
        cout << "1. Tambah Pelanggan\n";
        cout << "2. Edit Pelanggan\n";
        cout << "3. Hapus Pelanggan\n";
        cout << "4. Tampilkan Semua Pelanggan\n";
        cout << "5. Kembali ke Menu Utama\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan) {
        case 1: tambahPelanggan(); break;
        case 2: editPelanggan(); break;
        case 3: hapusPelanggan(); break;
        case 4: tampilkanPelanggan(); break;
        case 5: break;
        default: cout << "Pilihan tidak valid.\n\n"; break;
        }
    } while (pilihan != 5);
}

void menuMobil() {
    int pilihan;
    do {
        cout << endl;
        cout << "Menu Kendaraan:\n";
        cout << "1. Tambah Mobil\n";
        cout << "2. Edit Mobil\n";
        cout << "3. Hapus Mobil\n";
        cout << "4. Tampilkan Semua Mobil\n";
        cout << "5. Kembali ke Menu Utama\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan) {
        case 1: tambahMobil(); break;
        case 2: editMobil(); break;
        case 3: hapusMobil(); break;
        case 4: tampilkanMobil(); break;
        case 5: break;
        default: cout << "Pilihan tidak valid.\n\n"; break;
        }
    } while (pilihan != 5);
}

void menuTransaksi() {
    int pilihan;
    do {
        cout << endl;
        cout << "Menu Transaksi:\n";
        cout << "1. Sewa Kendaraan\n";
        cout << "2. Edit Transaksi\n";
        cout << "3. Hapus Transaksi\n";
        cout << "4. Tampilkan Semua Transaksi\n";
        cout << "5. Kembali ke Menu Utama\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan) {
        case 1: sewaKendaraan(); break;
        case 2: editSewaKendaraan(); break;
        case 3: hapusSewaKendaraan(); break;
        case 4: tampilkanTransaksi(); break;
        case 5: break;
        default: cout << "Pilihan tidak valid.\n\n"; break;
        }
    } while (pilihan != 5);
}

int main() {
    int pilihan;
    do {
        cout << "==============" << endl;
        cout << " Rental Mobil " << endl;
        cout << "==============\n" << endl;
        cout << "Menu Utama:\n";
        cout << "1. Data Pelanggan\n";
        cout << "2. Data Kendaraan\n";
        cout << "3. Menu Transaksi\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan) {
        case 1: menuPelanggan(); break;
        case 2: menuMobil(); break;
        case 3: menuTransaksi(); break;
        case 4: cout << "Terima kasih!\n"; break;
        default: cout << "Pilihan tidak valid.\n\n"; break;
        }
    } while (pilihan != 4);
    return 0;
}
