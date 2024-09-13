#include <iostream>
using namespace std;

int pascal(int baris, int kolom) {
    if (kolom == 0 || kolom == baris) {
        return 1;
    }
    return pascal(baris - 1, kolom - 1) + pascal(baris - 1, kolom);
}

void segitigaPascal(int tingkat_awal, int tingkat_mask) {
    if (tingkat_awal > tingkat_mask) {
        return;
    }

    for (int i = 0; i < tingkat_awal; i++) {
        cout << pascal(tingkat_awal - 1, i) << " ";
    }
    cout << endl;
    segitigaPascal(tingkat_awal + 1, tingkat_mask);
}

int main() {
    system("cls");
    cout << "SANIYYAH INTAN SALSABIILA 2309106004\n" << endl;
    cout << "Fungsi rekursif pada Segitiga Pascal" << endl;
    cout << "(format segitiga siku-siku)\n" << endl;
    segitigaPascal(1, 3);
    cout << endl;
    return 0;
}


