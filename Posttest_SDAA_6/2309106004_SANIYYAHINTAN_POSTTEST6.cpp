#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <string>
#include <limits>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

struct Suratmsk {
    string tanggal_masuk;
    string tanggal_surat;
    int nomor_surat;
    string asal_surat;
    string perihal;
    string keterangan;
    Suratmsk* next;
    Suratmsk* prev;
};

struct Suratklr {
    string tanggal_keluar;
    string tanggal_surat;
    int nomor_surat;
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
        while (true) {
            cin >> newNode->nomor_surat; 
            if (cin.fail()) { 
                cout << "Input tidak valid." << endl << "Harap masukkan nomor surat integer (angka): ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        } 
        cin.ignore();
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
    cout << "Masukkan surat yang ingin diupdate : ";
    while (!(cin >> nomor)) {
        cout << "Input tidak valid." << endl << "Harap masukkan nomor surat integer (angka): ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl;

    while (temp != nullptr) {
        if (i == nomor) {
            found = true;
            Suratmsk newNode;
            int newNomor;
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
            cout << "Nomor surat (ketik 0 jika NULL): ";
            while (true) {
            cin >> newNode.nomor_surat; 
                if (cin.fail()) { 
                    cout << "Input tidak valid." << endl << "Harap masukkan nomor surat integer (angka): ";
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                } else {
                    break; 
                }
                if (newNode.nomor_surat != 0) {
                    temp->nomor_surat = newNode.nomor_surat; 
                }
            } 
            cin.ignore();
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

void swap(Suratmsk* a, Suratmsk* b) {
    string tempTanggalMasuk = a->tanggal_masuk;
    string tempTanggalSurat = a->tanggal_surat;
    int tempNomorSurat = a->nomor_surat;
    string tempAsalSurat = a->asal_surat;
    string tempPerihal = a->perihal;
    string tempKeterangan = a->keterangan;

    a->tanggal_masuk = b->tanggal_masuk;
    a->tanggal_surat = b->tanggal_surat;
    a->nomor_surat = b->nomor_surat;
    a->asal_surat = b->asal_surat;
    a->perihal = b->perihal;
    a->keterangan = b->keterangan;

    b->tanggal_masuk = tempTanggalMasuk;
    b->tanggal_surat = tempTanggalSurat;
    b->nomor_surat = tempNomorSurat;
    b->asal_surat = tempAsalSurat;
    b->perihal = tempPerihal;
    b->keterangan = tempKeterangan;
}

Suratmsk* partition(Suratmsk*& head, Suratmsk* tail) {
    Suratmsk* pivot = head;
    Suratmsk* i = head;
    Suratmsk* j = head->next;

    while (j != tail) {
        if (j->tanggal_masuk > pivot->tanggal_masuk) {
            i = i->next;
            swap(i, j);
        }
        j = j->next;
    }

    swap(i, pivot);
    return i;
}

void quickSortRecursive(Suratmsk*& head, Suratmsk* tail) {
    if (head == nullptr || head == tail || head->next == tail) {
        return;
    }

    Suratmsk* pivot = partition(head, tail);
    quickSortRecursive(head, pivot);
    quickSortRecursive(pivot->next, tail);
}

void quickSort(Suratmsk*& head) {
    quickSortRecursive(head, nullptr);
}

void tampilkan_quick(Suratmsk* head) {
    quickSort(head);
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

int fibonacciSearch(Suratmsk* head, int target) {
    int fibM2 = 0; 
    int fibM1 = 1;
    int fibM = fibM1 + fibM2; 

    int n = 0;
    Suratmsk* temp = head;
    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }

    while (fibM < n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM1 + fibM2;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibM2, n - 1);

        temp = head;
        for (int j = 0; j < i; j++) {
            temp = temp->next;
        }

        if (temp->nomor_surat == target) {
            return i; 
        } else if (temp->nomor_surat < target) {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i; 
        } else {
            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        }
    }

    if (fibM1 && head->nomor_surat == target) {
        return offset + 1; 
    }

    return -1;
}

void searchSuratMasuk(Suratmsk* head) {
    system("cls");
    int target;
    cout << "Masukkan nomor surat yang ingin dicari: ";
    cin >> target;
    cout << endl;

    int index = fibonacciSearch(head, target);
    
    if (index != -1) {
        Suratmsk* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        cout << "------Surat ditemukan------ " << endl << endl;
        cout << "Tanggal Masuk  : " << temp->tanggal_masuk << endl;
        cout << "Tanggal Surat  : " << temp->tanggal_surat << endl;
        cout << "Nomor Surat    : " << temp->nomor_surat << endl;
        cout << "Pengirim/Asal  : " << temp->asal_surat << endl;
        cout << "Perihal        : " << temp->perihal << endl;
        cout << "Lampiran       : " << temp->keterangan << endl;
    } else {
        cout << "Surat dengan nomor " << target << " tidak ditemukan." << endl;
    }

    cout << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}

const int NO_OF_CHARS = 256;
void badCharHeuristic(const string& str, int size, int badChar[NO_OF_CHARS]) {
    for (int i = 0; i < NO_OF_CHARS; i++) {
        badChar[i] = -1; 
    }
    for (int i = 0; i < size; i++) {
        badChar[(int)str[i]] = i;
    }
}

void BoyerMoore(Suratmsk* head, const string& pat) {
    int m = pat.size();
    Suratmsk* temp = head;

    while (temp != nullptr) {
        int n = temp->tanggal_masuk.size();
        int badChar[NO_OF_CHARS];
        badCharHeuristic(pat, m, badChar);
        int s = 0;

        while (s <= (n - m)) {
            int j = m - 1;

            while (j >= 0 && pat[j] == temp->tanggal_masuk[s + j]) {
                j--;
            }

            if (j < 0) {
                cout << "-------Surat ditemukan------- " << endl;
                cout << "Tanggal Masuk  : " << temp->tanggal_masuk << endl;
                cout << "Tanggal Surat  : " << temp->tanggal_surat << endl;
                cout << "Nomor Surat    : " << temp->nomor_surat << endl;
                cout << "Pengirim/Asal  : " << temp->asal_surat << endl;
                cout << "Perihal        : " << temp->perihal << endl;
                cout << "Lampiran       : " << temp->keterangan << endl;
                break; 
            } else {
                s += max(1, j - badChar[temp->tanggal_masuk[s + j]]);
            }
        }
        temp = temp->next;
    }
}

void searchSuratMasukByTanggal(Suratmsk* head) {
    system("cls");
    string target;
    cout << "Masukkan tanggal masuk yang ingin dicari (YYYY-MM-DD): ";
    cin >> target;
    cout << endl;

    BoyerMoore(head, target);
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
        while (true) {
            cin >> newNode->nomor_surat; 
            if (cin.fail()) { 
                cout << "Input tidak valid." << endl << "Harap masukkan nomor surat integer (angka): ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        } 
        cin.ignore();
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
    cout << "Masukkan surat yang ingin diupdate : ";
    while (!(cin >> nomor)) {
        cout << "Input tidak valid." << endl << "Harap masukkan nomor surat integer (angka): ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
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
            cout << "Nomor surat (ketik 0 jika NULL): ";
            while (true) {
            cin >> baru.nomor_surat; 
                if (cin.fail()) { 
                    cout << "Input tidak valid." << endl << "Harap masukkan nomor surat integer (angka): " ;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                } else {
                    break; 
                }
                if (baru.nomor_surat != 0) {
                    temp->nomor_surat = baru.nomor_surat; 
                }
            } 
            cin.ignore();
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

void swapData(Suratklr* node1, Suratklr* node2) {
    string tempTanggalKeluar = node1->tanggal_keluar;
    string tempTanggalSurat = node1->tanggal_surat;
    int tempNomorSurat = node1->nomor_surat;
    string tempTujuanSurat = node1->tujuan_surat;
    string tempPerihal = node1->perihal;
    string tempLampiran = node1->keterangan;

    node1->tanggal_keluar = node2->tanggal_keluar;
    node1->tanggal_surat = node2->tanggal_surat;
    node1->nomor_surat = node2->nomor_surat;
    node1->tujuan_surat = node2->tujuan_surat;
    node1->perihal = node2->perihal;
    node1->keterangan = node2->keterangan;

    node2->tanggal_keluar = tempTanggalKeluar;
    node2->tanggal_surat = tempTanggalSurat;
    node2->nomor_surat = tempNomorSurat;
    node2->tujuan_surat = tempTujuanSurat;
    node2->perihal = tempPerihal;
    node2->keterangan = tempLampiran;
}

int getLength(Suratklr* head) {
    int length = 0;
    Suratklr* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

Suratklr* getNodeAt(Suratklr* head, int index) {
    Suratklr* temp = head;
    for (int i = 0; i < index && temp != nullptr; i++) {
        temp = temp->next;
    }
    return temp;
}

void shellSort(Suratklr*& head) {
    int length = getLength(head);
    for (int gap = length / 2; gap > 0; gap /= 2) {  
        for (int i = gap; i < length; i++) {
            Suratklr* temp = getNodeAt(head, i);
            Suratklr* jNode = temp;
            int j = i;
            
            while (j >= gap && getNodeAt(head, j - gap)->tanggal_keluar > temp->tanggal_keluar) {
                swapData(jNode, getNodeAt(head, j - gap));
                jNode = getNodeAt(head, j - gap);
                j -= gap;
            }
        }
    }
}

void tampilkan_shell(Suratklr* head) {
    shellSort(head);
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

int jumpSearch(Suratklr* head, int target) {
    int n = getLength(head);
    int step = sqrt(n);
    int prev = 0;

    Suratklr* current = head;

    while (current != nullptr && current->nomor_surat < target) {
        prev = current->nomor_surat;
        for (int i = 0; i < step && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr || current->nomor_surat > target) {
            current = head;
            while (current != nullptr && current->nomor_surat < target) {
                current = current->next;
            }
            return (current != nullptr && current->nomor_surat == target) ? current->nomor_surat : -1;
        }
    }

    if (current == nullptr || current->nomor_surat > target) {
        return -1;
    }

    while (current != nullptr && current->nomor_surat <= target) {
        if (current->nomor_surat == target) {
            return current->nomor_surat;
        }
        current = current->next;
    }
    return -1; 
}

void searchSuratKeluar(Suratklr* head) {
    system("cls");
    int target;
    cout << "Masukkan nomor surat yang ingin dicari: ";
    cin >> target;
    cout << endl;

    int result = jumpSearch(head, target); 

    if (result != -1) {
        Suratklr* temp = head;
        while (temp != nullptr) {
            if (temp->nomor_surat == result) {
                cout << "------Surat ditemukan------ " << endl << endl;
                cout << "Tanggal Keluar  : " << temp->tanggal_keluar << endl;
                cout << "Tanggal Surat   : " << temp->tanggal_surat << endl;
                cout << "Nomor Surat     : " << temp->nomor_surat << endl;
                cout << "Tujuan          : " << temp->tujuan_surat << endl;
                cout << "Perihal         : " << temp->perihal << endl;
                cout << "Lampiran        : " << temp->keterangan << endl;
                break;
            }
            temp = temp->next;
        }
    } else {
        cout << "Surat dengan nomor " << target << " tidak ditemukan." << endl;
    }

    cout << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}

void BoyerMoore1(Suratklr* head, const string& pat) {
    int m = pat.size();
    Suratklr* temp = head;

    while (temp != nullptr) {
        int n = temp->tanggal_keluar.size();
        int badChar[NO_OF_CHARS];
        badCharHeuristic(pat, m, badChar);
        int s = 0;

        while (s <= (n - m)) {
            int j = m - 1;

            while (j >= 0 && pat[j] == temp->tanggal_keluar[s + j]) {
                j--;
            }

            if (j < 0) {
                cout << "-------Surat ditemukan------- " << endl;
                cout << "Tanggal Keluar  : " << temp->tanggal_keluar << endl;
                cout << "Tanggal Surat   : " << temp->tanggal_surat << endl;
                cout << "Nomor Surat     : " << temp->nomor_surat << endl;
                cout << "Tujuan          : " << temp->tujuan_surat << endl;
                cout << "Perihal         : " << temp->perihal << endl;
                cout << "Lampiran        : " << temp->keterangan << endl;
                break; 
            } else {
                s += max(1, j - badChar[temp->tanggal_keluar[s + j]]);
            }
        }
        temp = temp->next;
    }
}

void searchSuratKeluarByTanggal(Suratklr* head) {
    system("cls");
    string target;
    cout << "Masukkan tanggal masuk yang ingin dicari (YYYY-MM-DD): ";
    cin >> target;
    cout << endl;

    BoyerMoore1(head, target);
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
                    cout << "      6. Quick Sort Desc     " << endl;
                    cout << "      7. Fibonacci Search     " << endl;
                    cout << "      8. Boyer-Moore Search   " << endl;
                    cout << "      9. Keluar                " << endl;
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
                            tampilkan_quick(head_masuk);
                            cout << endl;
                            cout << "Tekan ENTER untuk kembali...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 7:
                            searchSuratMasuk(head_masuk);
                            break;
                        case 8:
                            searchSuratMasukByTanggal(head_masuk);
                            break;
                        case 9:
                            break;
                        default:
                            cout << "Pilihan tidak valid." << endl;
                            sleep(1);
                            break;
                    }
                } while (pilihan != 9);
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
                    cout << "      5. Shell Sort Ascending    " << endl;
                    cout << "      6. Jump Search           " << endl;
                    cout << "      7. Boyer-Moore Search    " << endl;
                    cout << "      8. Keluar                " << endl;
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
                            tampilkan_shell(head_keluar);
                            cout << endl;
                            cout << "Tekan ENTER untuk kembali...";
                            cin.ignore();
                            cin.get();
                            break;
                        case 6:
                            searchSuratKeluar(head_keluar);
                            break;
                        case 7:
                            searchSuratKeluarByTanggal(head_keluar);
                            break;
                        case 8:
                            break;
                        default:
                            cout << "Pilihan tidak valid." << endl;
                            sleep(1);
                            break;
                    }
                } while (pilihan != 8);
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