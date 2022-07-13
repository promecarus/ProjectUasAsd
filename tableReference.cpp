#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct kata {
    char kata[10];
};

struct dataNama {
    kata namaDepan;
    kata namaTengah;
    kata namaBelakang;
};

struct Anggota {
    int id;
    dataNama namaAnggota;
    string namaLengkapAnggota;
    string hobiAnggota;
    string divisi;
    int tahunLahir;
    int tahunMasuk;
    Anggota *next;
};

Anggota *head, *tail, *cur, *newNode, *del, *aft, *bef;
int counter = 0;

void IsiData(Anggota *newNode) {
    newNode->id = ++counter;
    cout << "Nama Depan\t: ";
    cin >> newNode->namaAnggota.namaDepan.kata;
    cout << "Nama Tengah\t: ";
    cin >> newNode->namaAnggota.namaTengah.kata;
    cout << "Nama Belakang\t: ";
    cin >> newNode->namaAnggota.namaBelakang.kata;
    cout << "Hobi\t\t: ";
    cin >> newNode->hobiAnggota;
    cout << "Divisi\t\t: ";
    cin >> newNode->divisi;
    cout << "Tahun Lahir\t: ";
    cin >> newNode->tahunLahir;
    cout << "Tahun Masuk\t: ";
    cin >> newNode->tahunMasuk;
}

void CetakCircularSingleLinkedList() {
    cur = head;
    if (head == NULL) {  // jika list kosong, maka buat node pertama
        cout << "List kosong, isi terlebih dahulu:"
             << "\n";
        newNode = new Anggota;
        IsiData(newNode);
        head = newNode;
        tail = head;
        tail->next = head;
    } else {  // jika list tidak kosong, maka cetak semua data yang ada
        cout << setfill('-') << setw(7) << left << "+-" << setw(32) << left
             << "+-" << setw(17) << left << "+-" << setw(17) << left << "+-"
             << setw(17) << left << "+-" << setw(17) << left << "+-"
             << "+\n";
        cout << setfill(' ') << "| " << left << setw(5) << "ID"
             << "| " << left << setw(30) << "Nama"
             << "| " << left << setw(15) << "Hobi"
             << "| " << left << setw(15) << "Divisi"
             << "| " << left << setw(15) << "Tahun Lahir"
             << "| " << left << setw(15) << "Tahun Masuk"
             << "|\n";
        do {
            cout << setfill('-') << setw(7) << left << "+-" << setw(32) << left
                 << "+-" << setw(17) << left << "+-" << setw(17) << left << "+-"
                 << setw(17) << left << "+-" << setw(17) << left << "+-"
                 << "+\n";
            string namaDepanTemp = "", namaTengahTemp = " ",
                   namaBelakangTemp = " ", namaLengkap;
            namaDepanTemp += cur->namaAnggota.namaDepan.kata;
            namaTengahTemp += cur->namaAnggota.namaTengah.kata;
            namaBelakangTemp += cur->namaAnggota.namaBelakang.kata;

            if (namaTengahTemp == " -") {
                namaTengahTemp = "\0";
                if (namaBelakangTemp == " -") {
                    namaBelakangTemp = "\0";
                }
            }

            namaLengkap += namaDepanTemp + namaTengahTemp + namaBelakangTemp;

            cout << setfill(' ') << "| " << left << setw(5) << cur->id << "| "
                 << left << setw(30) << namaLengkap << "| " << left << setw(15)
                 << cur->hobiAnggota << "| " << left << setw(15) << cur->divisi
                 << "| " << left << setw(15) << cur->tahunLahir << "| " << left
                 << setw(15) << cur->tahunMasuk << "|\n";

            cur = cur->next;
        } while (cur != head);

        cout << setfill('-') << setw(7) << left << "+-" << setw(32) << left
             << "+-" << setw(17) << left << "+-" << setw(17) << left << "+-"
             << setw(17) << left << "+-" << setw(17) << left << "+-"
             << "+\n";
    }
}

void TambahDepan() {
    newNode = new Anggota;
    IsiData(newNode);

    if (head == NULL) {  // jika list kosong, maka buat node pertama
        head = newNode;
        tail = head;
        tail->next = head;
    } else {  // jika list tidak kosong, maka tambahkan node di awal
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

void TambahBelakang() {
    newNode = new Anggota;
    IsiData(newNode);

    if (head == NULL) {  // jika list kosong, maka buat node pertama
        head = newNode;
        tail = head;
        tail->next = head;
    } else {  // jika list tidak kosong, maka tambahkan node di akhir
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void HapusDepan() {
    if (head == NULL) {
        cout << "List kosong."
             << "\n";
    } else {
        del = head;
        head = head->next;
        tail->next = head;
        delete del;
        CetakCircularSingleLinkedList();
    }
}

void HapusBelakang() {
    if (head == NULL) {
        cout << "List kosong."
             << "\n";
    } else {
        del = tail;
        cur = head;
        while (cur->next != tail) {
            cur = cur->next;
        }
        tail = cur;
        tail->next = head;
        delete del;
        CetakCircularSingleLinkedList();
    }
}

int main() {
    int pilihan;
    while (pilihan != 0) {
        string menu[] = {"[0] Keluar",
                         "[1] Tambah node di depan",
                         "[2] Tambah node di belakang",
                         "[3] Hapus node di depan",
                         "[4] Hapus node di belakang",
                         "[5] Tampilkan data"};
        cout << "\n"
             << setfill('-') << setw(30) << left << "+-"
             << "+\n";
        for (int i = 0; i < sizeof(menu) / sizeof(string); i++) {
            cout << setfill(' ') << "| " << setw(28) << left << menu[i]
                 << "|\n";
        }
        cout << setfill('-') << setw(30) << left << "+-"
             << "+\n";

        cout << "Pilihan: ";
        cin >> pilihan;
        system("cls");

        switch (pilihan) {
            case 0:
                cout << "Keluar"
                     << "\n";
                break;
            case 1:
                TambahDepan();
                break;
            case 2:
                TambahBelakang();
                break;
            case 3:
                HapusDepan();
                break;
            case 4:
                HapusBelakang();
                break;
            case 5:
                CetakCircularSingleLinkedList();
                break;
            default:
                cout << "Pilihan tidak ada"
                     << "\n";
                break;
        }
    }

    system("pause");
    return 0;
}