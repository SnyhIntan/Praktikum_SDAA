#include <iostream>
#include <iomanip> 
#include <unistd.h>
#include <algorithm>

using namespace std;

struct Suratmsk
{
    string tanggal_masuk;
    string tanggal_surat;
    string nomor_surat;
    string asal_surat;
    string perihal;
    string keterangan;
};

struct Suratklr
{
    string tanggal_keluar;
    string tanggal_surat;
    string nomor_surat;
    string tujuan_surat;
    string perihal;
    string keterangan;
};

Suratmsk suratMasuk[100];
Suratklr suratKeluar[100];

int jumlahSuratMasuk = 0;
int jumlahSuratKeluar = 0;
int max_masuk[100];
int max_keluar[100];

void surat_masuk(Suratmsk *suratMasuk, int &jumlahSuratMasuk)
{
    string ulang;
    int nomorUrutan = 1; 
    cin.ignore();
    do
    {
        if (jumlahSuratMasuk < 100)
        {
            system("cls");
            cout << "Tanggal (YYYY-MM-DD): ";
            cin >> suratMasuk[jumlahSuratMasuk].tanggal_masuk;
            cin.ignore();
            cout << "Tanggal pelaksanaan : ";
            fflush(stdin); 
            getline(cin, suratMasuk[jumlahSuratMasuk].tanggal_surat);
            cout << "Nomor surat         : ";
            fflush(stdin);
            getline(cin, suratMasuk[jumlahSuratMasuk].nomor_surat);
            cout << "Pengirim/asal surat : ";
            fflush(stdin);
            getline(cin, suratMasuk[jumlahSuratMasuk].asal_surat);
            cout << "Perihal             : ";
            fflush(stdin);
            getline(cin, suratMasuk[jumlahSuratMasuk].perihal);
            cout << "Lampiran            : ";
            fflush(stdin);
            getline(cin, suratMasuk[jumlahSuratMasuk].keterangan);

            jumlahSuratMasuk++;
            nomorUrutan++; 
            cout << "\nSurat berhasil ditambahkan." << endl;
        }
        else
        {
            cout << "Batas maksimum surat masuk telah tercapai." << endl;
        }

        cout << endl;
        cout << "Ulangi (y/t) : ";
        cin >> ulang;
        cin.ignore(); 

    } while (ulang == "y");
}

void lihat_surat_masuk(Suratmsk *suratMasuk, int jumlahSuratMasuk)
{
    system("cls");
    if (jumlahSuratMasuk > 0)
    {
        cout << "Daftar Surat Masuk" << endl;
        for (int i = 0; i < jumlahSuratMasuk; ++i)
        {
            cout << endl;
            cout << "Surat ke-     : " << i + 1 << endl; 
            cout << endl;
            cout << "Tanggal Masuk : " << suratMasuk[i].tanggal_masuk << endl;
            cout << "Tanggal Surat : " << suratMasuk[i].tanggal_surat << endl;
            cout << "Nomor Surat   : " << suratMasuk[i].nomor_surat << endl;
            cout << "Asal Surat    : " << suratMasuk[i].asal_surat << endl;
            cout << "Perihal       : " << suratMasuk[i].perihal << endl;
            cout << "Lampiran      : " << suratMasuk[i].keterangan << endl;
            cout << "-------------------------------------------------" << endl;
        }
    }
    else
    {
        cout << "Daftar Surat Masuk Kosong." << endl;
    }
    cout << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}

void update_surat_masuk(Suratmsk *suratMasuk, int jumlahSuratMasuk)
{
    system("cls");
    if (jumlahSuratMasuk > 0)
    {
        int nomorUrut;
        bool found = false;

        cout << "Masukkan indeks surat yang ingin diupdate : ";
        cin.ignore();
        cin >> nomorUrut;

        for (int i = 0; i < jumlahSuratMasuk; ++i)
        {
            if (nomorUrut >= 1 && nomorUrut <= jumlahSuratMasuk)
            {
                int index = nomorUrut - 1;
                Suratmsk temp;

                cout << "\n -- Masukkan data baru untuk surat masuk pada surat ke- " << nomorUrut << " --\n" << endl;
                cout << endl;
                cout << "Tanggal masuk surat : ";
                cin.ignore();
                getline(cin, temp.tanggal_masuk);
                if (temp.tanggal_masuk.empty()) {
                    temp.tanggal_masuk = suratMasuk[i].tanggal_masuk;
                }
                cout << "Tanggal pelaksanaan : ";
                cin.ignore();
                getline(cin, temp.tanggal_surat);
                if (temp.tanggal_surat.empty()) {
                    temp.tanggal_surat = suratMasuk[i].tanggal_surat; 
                }
                cout << "Nomor surat         : ";
                cin.ignore();
                getline(cin, temp.nomor_surat);
                if (temp.nomor_surat.empty()) {
                    temp.nomor_surat = suratMasuk[i].nomor_surat; 
                }
                cout << "Asal surat          : ";
                getline(cin, temp.asal_surat);
                cin.ignore();
                if (temp.asal_surat.empty()) {
                    temp.asal_surat = suratMasuk[i].asal_surat; 
                }
                cout << "Perihal             : ";
                cin.ignore();
                getline(cin, temp.perihal);
                if (temp.perihal.empty()) {
                    temp.perihal = suratMasuk[i].perihal; 
                }
                cout << "Lampiran            : ";
                cin.ignore();
                getline(cin, temp.keterangan);
                if (temp.keterangan.empty()) {
                    temp.keterangan = suratMasuk[i].keterangan; 
                }
                suratMasuk[i] = temp;
                found = true;
                cout << "Data surat berhasil diupdate." << endl;
                break;
            }
        }

        if (!found)
        {
            cout << "Indeks surat tidak ditemukan." << endl;
        }
    }
    else
    {
        cout << "Daftar Surat Masuk Kosong." << endl;
    }

    cout << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}

void delete_surat_masuk(Suratmsk *suratMasuk, int &jumlahSuratMasuk)
{
    system("cls");
    if (jumlahSuratMasuk > 0)
    {
        int nomorUrut;
        bool found = false;

        cout << "Masukkan indeks surat yang ingin dihapus: ";
        cin >> nomorUrut;

        for (int i = 0; i < jumlahSuratMasuk; ++i)
        {
            if (nomorUrut >= 1 && nomorUrut <= jumlahSuratMasuk)
            {
                int index = nomorUrut - 1;

                for (int j = i; j < jumlahSuratMasuk - 1; ++j)
                {
                    suratMasuk[j] = suratMasuk[j + 1];
                }
                jumlahSuratMasuk--;

                found = true;
                cout << "Surat ke- " << nomorUrut << " berhasil dihapus." << endl;
                break;
            }
        }

        if (!found)
        {
            cout << "Indeks surat tidak ditemukan." << endl;
        }
    }
    else
    {
        cout << "Daftar Surat Masuk Kosong." << endl;
    }

    cout << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}

void insertion_sort_masuk(Suratmsk *suratMasuk, int jumlahSuratMasuk)
{
    int i, j;
    Suratmsk key;
    for (i = 1; i < jumlahSuratMasuk; ++i)
    {
        key = suratMasuk[i];
        j = i - 1;

        while (j >= 0 && suratMasuk[j].tanggal_masuk > key.tanggal_masuk)
        {
            suratMasuk[j + 1] = suratMasuk[j];
            j = j - 1;
        }
        suratMasuk[j + 1] = key;
    }
}

int crudmasuk()
{
    int pilihan;

    do
    {
        system("cls");
        cout << "---------------------------------" << endl;
        cout << "            Menu Utama        " << endl;
        cout << "---------------------------------" << endl;
        cout << "      1. Tambah Surat Masuk    " << endl;
        cout << "      2. Lihat Surat Masuk     " << endl;
        cout << "      3. Update Surat Masuk    " << endl;
        cout << "      4. Hapus Surat Masuk     " << endl;
        cout << "      5. Keluar                " << endl;
        cout << "---------------------------------" << endl;
        cout << "\nPilih : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            surat_masuk(suratMasuk, jumlahSuratMasuk);
            break;
        case 2:
            insertion_sort_masuk(suratMasuk, jumlahSuratMasuk);
            lihat_surat_masuk(suratMasuk, jumlahSuratMasuk);
            break;
        case 3:
            update_surat_masuk(suratMasuk, jumlahSuratMasuk);
            break;
        case 4:
            delete_surat_masuk(suratMasuk, jumlahSuratMasuk);
            break;
        case 5:
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (pilihan != 5);

    return 0;
}

void surat_keluar(Suratklr *suratKeluar, int &jumlahSuratKeluar)
{
    string ulang;
    int nomorUrutan = 1; 
    cin.ignore();
    do
    {
        if (jumlahSuratKeluar < 100)
        {
            system("cls");
            cout << "Tanggal (YYYY-MM-DD): ";
            cin >> suratKeluar[jumlahSuratKeluar].tanggal_keluar;
            cin.ignore();
            cout << "Tanggal pelaksanaan : ";
            cin.ignore(); 
            getline(cin, suratKeluar[jumlahSuratKeluar].tanggal_surat);
            cout << "Nomor surat         : ";
            cin.ignore();
            getline(cin, suratKeluar[jumlahSuratKeluar].nomor_surat);
            cout << "Tujuan surat        : ";
            cin.ignore();
            getline(cin, suratKeluar[jumlahSuratKeluar].tujuan_surat);
            cout << "Perihal             : ";
            cin.ignore();
            getline(cin, suratKeluar[jumlahSuratKeluar].perihal);
            cout << "Lampiran            : ";
            cin.ignore();
            getline(cin, suratKeluar[jumlahSuratKeluar].keterangan);

            jumlahSuratKeluar++;
            nomorUrutan++; 
            cout << "\nSurat berhasil ditambahkan." << endl;
        }
        else
        {
            cout << "Batas maksimum surat masuk telah tercapai." << endl;
        }

        cout << endl;
        cout << "Ulangi (y/t) : ";
        cin >> ulang;
        cin.ignore(); 

    } while (ulang == "y");
}

void lihat_surat_keluar(Suratklr *suratKeluar, int jumlahSuratKeluar)
{
    system("cls");
    if (jumlahSuratKeluar > 0)
    {
        cout << "Daftar Surat Keluar" << endl;
        for (int i = 0; i < jumlahSuratKeluar; ++i)
        {
            cout << endl;
            cout << "Surat ke-     : " << i + 1 << endl; 
            cout << endl;
            cout << "Tanggal Masuk : " << suratKeluar[i].tanggal_keluar << endl;
            cout << "Tanggal Surat : " << suratKeluar[i].tanggal_surat << endl;
            cout << "Nomor Surat   : " << suratKeluar[i].nomor_surat << endl;
            cout << "Tujuan Surat  : " << suratKeluar[i].tujuan_surat << endl;
            cout << "Perihal       : " << suratKeluar[i].perihal << endl;
            cout << "Lampiran      : " << suratKeluar[i].keterangan << endl;
            cout << "-------------------------------------------------" << endl;
        }
    }
    else
    {
        cout << "Daftar Surat Masuk Kosong." << endl;
    }
    cout << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}

void update_surat_keluar(Suratklr *suratKeluar, int jumlahSuratKeluar)
{
    system("cls");
    if (jumlahSuratKeluar > 0)
    {
        int nomorUrut;
        bool found = false;

        cout << "Masukkan indeks surat yang akan diupdate : ";
        cin.ignore();
        cin >> nomorUrut;

        for (int i = 0; i < jumlahSuratKeluar; ++i)
        {
            if (nomorUrut >= 1 && nomorUrut <= jumlahSuratKeluar)
            {
                int index = nomorUrut - 1;
                Suratklr temp;

                cout << "\n -- Masukkan data baru untuk surat keluar pada surat ke- " << nomorUrut << " --\n" << endl;
                cout << "Tanggal keluar surat : ";
                cin.ignore();
                getline(cin, temp.tanggal_keluar);
                if (temp.tanggal_keluar.empty()) {
                    temp.tanggal_keluar = suratKeluar[i].tanggal_keluar;
                }
                cout << "Tanggal pelaksanaan  : ";
                cin.ignore();
                getline(cin, temp.tanggal_surat);
                if (temp.tanggal_surat.empty()) {
                    temp.tanggal_surat = suratKeluar[i].tanggal_surat;
                }
                cout << "Nomor surat          : ";
                cin.ignore();
                getline(cin, temp.nomor_surat);
                if (temp.nomor_surat.empty()) {
                    temp.nomor_surat = suratKeluar[i].nomor_surat;
                }
                cout << "tujuan surat         : ";
                getline(cin, temp.tujuan_surat);
                cin.ignore();
                if (temp.tujuan_surat.empty()) {
                    temp.tujuan_surat = suratKeluar[i].tujuan_surat;
                }
                cout << "Perihal              : ";
                cin.ignore();
                getline(cin, temp.perihal);
                if (temp.perihal.empty()) {
                    temp.perihal = suratKeluar[i].perihal;
                }
                cout << "Lampiran             : ";
                cin.ignore();
                getline(cin, temp.keterangan);
                if (temp.keterangan.empty()) {
                    temp.keterangan = suratKeluar[i].keterangan;
                }

                suratKeluar[i] = temp;
                found = true;
                cout << "Data surat berhasil diupdate." << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Nomor surat tidak ditemukan." << endl;
        }
    }
    else
    {
        cout << "Daftar Surat Masuk Kosong." << endl;
    }

    cout << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}

void delete_surat_keluar(Suratklr *suratKeluar, int &jumlahSuratKeluar)
{
    system("cls");
    if (jumlahSuratKeluar > 0)
    {
        int nomorUrut;
        bool found = false;

        cout << "Masukkan indeks surat yang ingin dihapus: ";
        cin >> nomorUrut;

        for (int i = 0; i < jumlahSuratKeluar; ++i)
        {
            if (nomorUrut >= 1 && nomorUrut <= jumlahSuratKeluar)
            {
                int index = nomorUrut - 1;

                for (int j = i; j < jumlahSuratKeluar - 1; ++j)
                {
                    suratKeluar[j] = suratKeluar[j + 1];
                }
                jumlahSuratKeluar--;

                found = true;
                cout << "\nSurat ke- " << nomorUrut << " berhasil dihapus." << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Nomor surat tidak ditemukan." << endl;
        }
    }
    else
    {
        cout << "Daftar Surat Masuk Kosong." << endl;
    }

    cout << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}

void insertion_sort_keluar(Suratklr suratKeluar[], int jumlahSuratKeluar)
{
    int i, j;
    Suratklr key;
    for (i = 1; i < jumlahSuratKeluar; ++i)
    {
        key = suratKeluar[i];
        j = i - 1;

        while (j >= 0 && suratKeluar[j].tanggal_keluar > key.tanggal_keluar)
        {
            suratKeluar[j + 1] = suratKeluar[j];
            j = j - 1;
        }
        suratKeluar[j + 1] = key;
    }
}

int crudkeluar()
{
    int pilihan;

    do
    {
        system("cls");
        cout << "----------------------------------" << endl;
        cout << "            Menu Utama        " << endl;
        cout << "----------------------------------" << endl;
        cout << "      1. Tambah Surat Keluar   " << endl;
        cout << "      2. Lihat Surat Keluar    " << endl;
        cout << "      3. Update Surat Keluar   " << endl;
        cout << "      4. Hapus Surat Keluar    " << endl;
        cout << "      5. Keluar                " << endl;
        cout << "----------------------------------" << endl;
        cout << "\nPilih : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            surat_keluar(suratKeluar, jumlahSuratKeluar);
            break;
        case 2:
            insertion_sort_keluar(suratKeluar, jumlahSuratKeluar);
            lihat_surat_keluar(suratKeluar, jumlahSuratKeluar);
            break;
        case 3:
            update_surat_keluar(suratKeluar, jumlahSuratKeluar);
            break;
        case 4:
            delete_surat_keluar(suratKeluar, jumlahSuratKeluar);
            break;
        case 5:
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (pilihan != 5);

    return 0;
}

void menu() {
    int pilih;
    do {
        system("cls");
        cout << "---------------------------" << endl;
        cout << "        Pilihan Menu " << endl;
        cout << "---------------------------" << endl;
        cout << "      1. Surat Masuk         " << endl;
        cout << "      2. Surat Keluar       " << endl;
        cout << "      3. Exit          " << endl;
        cout << "---------------------------" << endl;
        cout << endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                crudmasuk();
                break;
            case 2:
               crudkeluar();
                break;
            case 3:
                system("cls");
                cout << endl;
                cout << "BYE BYE...\n";
                cout << endl;
                break;
            default:
                cout << "Pilihan tidak valid. ENTER untuk lanjut...\n";
                cin.ignore();
                cin.get();
        }
    } while (pilih != 3);
}

int main() {
    system("cls");
    cout << endl;
    cout << "SELAMAT DATANG....\n";
    sleep(1);
    menu();
    return 0;
}