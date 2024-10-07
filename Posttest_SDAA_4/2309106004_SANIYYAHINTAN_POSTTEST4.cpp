#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <string>

using namespace std;

struct Suratmsk {
    string tanggal_masuk;
    string tanggal_surat;
    string nomor_surat;
    string asal_surat;
    string perihal;
    string keterangan;
    Suratmsk* next;
    Suratmsk* prev;
};

struct Suratklr {
    string tanggal_keluar;
    string tanggal_surat;
    string nomor_surat;
    string tujuan_surat;
    string perihal;
    string keterangan;
    Suratklr* next;
};

Suratmsk* head_masuk = nullptr;
// Suratmsk* last_masuk = nullptr;

void push(Suratmsk*& head) {

    string ulang;
    do{
        system("cls");
        Suratmsk* newNode = new Suratmsk();
        cin.ignore();
        cout << "Tanggal (YYYY-MM-DD): ";
        cin >> newNode->tanggal_masuk;
        cin.ignore();
        cout << "Tanggal pelaksanaan : ";
        getline(cin, newNode->tanggal_surat);
        cout << "Nomor surat         : ";
        getline(cin, newNode->nomor_surat);
        cout << "Pengirim/asal surat : ";
        getline(cin, newNode->asal_surat);
        cout << "Perihal             : ";
        getline(cin, newNode->perihal);
        cout << "Lampiran            : ";
        getline(cin, newNode->keterangan);
        
        newNode->next = head;
        newNode->prev = nullptr; 
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode; 

        cout << endl;
        cout << "Ulangi (y/t) : ";
        cin >> ulang;

    } while (ulang == "y");

    
}

void peek(Suratmsk*& head) { 

    system("cls");
    if (head == nullptr) {
        cout << endl;
        cout << "Stack kosong, tidak ada elemen untuk ditampilkan." << endl;
        cout << "Tekan ENTER untuk kembali...";
        cin.ignore();
        cin.get();
    } else {
        cout << "------ Surat Terakhir ------ " << endl << endl;
        cout << "Tanggal Masuk  : " << head->tanggal_masuk << endl;
        cout << "Tanggal Surat  : " << head->tanggal_surat << endl;
        cout << "Nomor Surat    : " << head->nomor_surat << endl;
        cout << "Pengirim       : " << head->asal_surat << endl;
        cout << "Perihal        : " << head->perihal << endl;
        cout << "Lampiran       : " << head->keterangan << endl;
        cout << endl;
        cout << "Tekan ENTER untuk kembali...";
        cin.ignore();
        cin.get();
    }
}

void pop(Suratmsk*& head) {
    if (head = nullptr) {
        cout << endl;
        cout << "Stack kosong. Tekan ENTER untuk kembali...";
        cin.ignore();
        cin.get();
        return;
    } 

    Suratmsk* temp = head; 
    head = head->next; 
    
    delete temp; 
    cout << "Surat teratas berhasil dihapus dari stack." << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}

void tampilkan_stack(Suratmsk* head) {
    Suratmsk* temp = head;
    int nomor = 1;

    system("cls");
    
    if (temp == nullptr) {
        cout << "Data masih kosong" << endl;
        return;
    }

    while (temp != nullptr) {
        cout << "Surat ke- " << nomor++ << endl << endl;
        cout << "Tanggal Masuk  : " << temp->tanggal_masuk << endl;
        cout << "Tanggal Surat  : " << temp->tanggal_surat << endl;
        cout << "Nomor Surat    : " << temp->nomor_surat << endl;
        cout << "Pengirim/Asal  : " << temp->asal_surat << endl;
        cout << "Perihal        : " << temp->perihal << endl;
        cout << "Lampiran       : " << temp->keterangan << endl;
        cout << "-------------------------------------------------" << endl;
        temp = temp->next;
    }
}

void update_surat_masuk(Suratmsk* head) {
    Suratmsk* temp = head;
    int i = 1;
    bool found = false;
    int nomor;
    
    // system("cls");
    if (temp == nullptr) {
        cout << endl;
        cout << "Tekan ENTER untuk kembali...";
        cin.ignore();
        cin.get();
        return;
    }

    cout << endl;
    cout << "Masukkan nomor surat yang ingin diupdate : ";
    cin >> nomor;
    cout << endl;

    while (temp != nullptr) {
        if (i == nomor) {
            found = true;
            Suratmsk newNode;
            cin.ignore();
            cout << "Tanggal masuk surat : ";
            getline(cin, newNode.tanggal_masuk);
            if (newNode.tanggal_masuk.empty()) {
                newNode.tanggal_masuk = temp->tanggal_masuk;
            }
            cout << "Tanggal pelaksanaan : ";
            getline(cin, newNode.tanggal_surat);
            if (newNode.tanggal_surat.empty()) {
                newNode.tanggal_surat = temp->tanggal_surat;
            }
            cout << "Nomor surat         : ";
            getline(cin, newNode.nomor_surat);
            if (newNode.nomor_surat.empty()) {
                newNode.nomor_surat = temp->nomor_surat;
            }
            cout << "Asal surat          : ";
            getline(cin, newNode.asal_surat);
            if (newNode.asal_surat.empty()) {
                newNode.asal_surat = temp->asal_surat;
            }
            cout << "Perihal             : ";
            getline(cin, newNode.perihal);
            if (newNode.perihal.empty()) {
                newNode.perihal = temp->perihal;
            }
            cout << "Lampiran            : ";
            getline(cin, newNode.keterangan);
            if (newNode.keterangan.empty()) {
                newNode.keterangan = temp->keterangan;
            }
            temp->tanggal_masuk = newNode.tanggal_masuk;
            temp->tanggal_surat = newNode.tanggal_surat;
            temp->nomor_surat = newNode.nomor_surat;
            temp->asal_surat = newNode.asal_surat;
            temp->perihal = newNode.perihal;
            temp->keterangan = newNode.keterangan;
            cout << endl << "Data surat berhasil diupdate." << endl;
            break;
        }
        temp = temp->next;
        i++;
    }
    if (!found) { 
        cout << "Surat dengan nomor " << nomor << " tidak ditemukan." << endl;
    }

    cout << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}


void enqueue(Suratklr*& head, Suratklr*& tail) {
    string ulang;
    do{
        system("cls");
        Suratklr* newNode = new Suratklr();
        cin.ignore();
        cout << "Tanggal (YYYY-MM-DD): ";
        cin >> newNode->tanggal_keluar;
        cin.ignore();
        cout << "Tanggal pelaksanaan : ";
        getline(cin, newNode->tanggal_surat);
        cout << "Nomor surat         : ";
        getline(cin, newNode->nomor_surat);
        cout << "Tujuan surat        : ";
        getline(cin, newNode->tujuan_surat);
        cout << "Perihal             : ";
        getline(cin, newNode->perihal);
        cout << "Lampiran            : ";
        getline(cin, newNode->keterangan);
        
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        cout << endl;
        cout << "Ulangi (y/t) : ";
        cin >> ulang; 

    } while (ulang == "y");
}

void dequeue(Suratklr*& head) {
    system("cls");
    if (head == nullptr) {
        cout << endl;
        cout << "Queue kosong. Tekan ENTER untuk kembali..." << endl;
        cin.ignore();
        cin.get();
        return;
        return;
    }
    Suratklr* temp = head;
    head = head->next;
    delete temp;

    cout << "Surat teratas berhasil dihapus dari antrian." << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}

void tampilkan_queue(Suratklr* head) {
    Suratklr* temp = head;
    int nomor = 1;

    system("cls");

    if (temp == nullptr) {
        cout << "Data masih kosong" << endl;
        return;
    }

    while (temp != nullptr) {
        cout << "Surat ke- " << nomor++ << endl << endl;
        cout << "Tanggal Keluar : " << temp->tanggal_keluar << endl;
        cout << "Tanggal Surat  : " << temp->tanggal_surat << endl;
        cout << "Nomor Surat    : " << temp->nomor_surat << endl;
        cout << "Tujuan         : " << temp->tujuan_surat << endl;
        cout << "Perihal        : " << temp->perihal << endl;
        cout << "Lampiran       : " << temp->keterangan << endl;
        cout << "-------------------------------------------------" << endl;
        temp = temp->next;
    }
}

void update_surat_keluar(Suratklr* head) {
    Suratklr* temp = head;
    int i = 1;
    bool found = false;
    int nomor;

    // system("cls");
    if (temp == nullptr) {
        cout << endl;
        cout << "Tekan ENTER untuk kembali...";
        cin.ignore();
        cin.get();
        return;
    }

    cout << endl;
    cout << "Masukkan nomor surat yang ingin diupdate : ";
    cin >> nomor;
    cout << endl;
    
    while (temp != nullptr) {
        if (i == nomor) {
            found = true;
            Suratklr baru;
            cin.ignore();
            cout << "Tanggal keluar surat : ";
            getline(cin, baru.tanggal_keluar);
            if (baru.tanggal_keluar.empty()) {
                baru.tanggal_keluar = temp->tanggal_keluar;
            }
            cout << "Tanggal pelaksanaan  : ";
            getline(cin, baru.tanggal_surat);
            if (baru.tanggal_surat.empty()) {
                baru.tanggal_surat = temp->tanggal_surat;
            }
            cout << "Nomor surat          : ";
            getline(cin, baru.nomor_surat);
            if (baru.nomor_surat.empty()) {
                baru.nomor_surat = temp->nomor_surat;
            }
            cout << "Tujuan surat         : ";
            getline(cin, baru.tujuan_surat);
            if (baru.tujuan_surat.empty()) {
                baru.tujuan_surat = temp->tujuan_surat;
            }
            cout << "Perihal              : ";
            getline(cin, baru.perihal);
            if (baru.perihal.empty()) {
                baru.perihal = temp->perihal;
            }
            cout << "Lampiran             : ";
            getline(cin, baru.keterangan);
            if (baru.keterangan.empty()) {
                baru.keterangan = temp->keterangan;
            }
            temp->tanggal_keluar = baru.tanggal_keluar;
            temp->tanggal_surat = baru.tanggal_surat;
            temp->nomor_surat = baru.nomor_surat;
            temp->tujuan_surat = baru.tujuan_surat;
            temp->perihal = baru.perihal;
            temp->keterangan = baru.keterangan;
            cout << "Data surat berhasil diupdate." << endl;
            break;
        }
        temp = temp->next;
        i++;
    }
    if (!found) { 
        cout << "Surat dengan nomor " << nomor << " tidak ditemukan." << endl;
    }

    cout << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}

void menu() {
    int pilih;
    Suratmsk* head_masuk = nullptr;
    Suratmsk* last_masuk = nullptr;
    Suratmsk* tail_masuk = nullptr;
    Suratklr* head_keluar = nullptr;
    Suratklr* last_keluar = nullptr;
    Suratklr* tail_keluar = nullptr;

    do {
        system("cls");
        cout << "----------------------------------" << endl;
        cout << "           Pilihan Menu            " << endl;
        cout << "----------------------------------" << endl;
        cout << "      1. Surat Masuk (stack)        " << endl;
        cout << "      2. Surat Keluar (Queue)            " << endl;
        cout << "      3. Exit                      " << endl;
        cout << "----------------------------------" << endl;
        cout << endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                int pilihan;
                do {
                    system("cls");
                    cout << "---------------------------------" << endl;
                    cout << "         Menu Surat Masuk        " << endl;
                    cout << "---------------------------------" << endl;
                    cout << "      1. Push Surat Masuk    " << endl;
                    cout << "      2. Show Surat Masuk     " << endl;
                    cout << "      3. Update Surat Masuk    " << endl;
                    cout << "      4. pop Surat Masuk     " << endl;
                    cout << "      5. Peek Surat Masuk     " << endl;
                    cout << "      6. Keluar                " << endl;
                    cout << "---------------------------------" << endl;
                    cout << "\nPilih : ";
                    cin >> pilihan;
                    
                    Suratmsk* newNode = new Suratmsk();

                    switch (pilihan) {
                        case 1:
                            push(head_masuk);
                            break;
                        case 2:
                            tampilkan_stack(head_masuk);
                            cout << endl;
                            cout << "Tekan ENTER untuk kembali...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 3: 
                            tampilkan_stack(head_masuk);
                            update_surat_masuk(head_masuk);
                            break;
                        case 4: 
                            pop(head_masuk);
                            break;
                        case 5:
                            peek(head_masuk);
                            break;
                        case 6:
                            break;
                        default:
                            cout << "Pilihan tidak valid." << endl;
                            sleep(1);
                            break;
                    }
                } while (pilihan != 6);
                break;
            }
            case 2: {
                int pilihan;
                do {
                    system("cls");
                    cout << "-----------------------------------" << endl;
                    cout << "          Menu Surat Keluar        " << endl;
                    cout << "-----------------------------------" << endl;
                    cout << "      1. Enqueue Surat Keluar   " << endl;
                    cout << "      2. Queue Surat Keluar    " << endl;
                    cout << "      3. Update Surat Keluar   " << endl;
                    cout << "      4. Dequeue Surat Keluar    " << endl;
                    cout << "      5. Keluar                " << endl;
                    cout << "-----------------------------------" << endl;
                    cout << "\nPilih : ";
                    cin >> pilihan;

                    switch (pilihan) {
                        case 1:
                            enqueue(head_keluar, tail_keluar);
                            break;
                        case 2:
                            tampilkan_queue(head_keluar);
                            cout << endl;
                            cout << "Tekan ENTER untuk kembali...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 3: 
                            int nomor;
                            tampilkan_queue(head_keluar);
                            update_surat_keluar(head_keluar);
                            break;
                        case 4: 
                            dequeue(head_keluar);
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Pilihan tidak valid." << endl;
                            sleep(1);
                            break;
                    }
                } while (pilihan != 5);
                break;
            }
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