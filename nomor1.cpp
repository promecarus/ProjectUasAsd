// Buatlah suatu program antrean pasien pada suatu klinik ABC. Program dapat
// menerima inputan nama dan no ID pasien, kemudian program akan menentukan
// nomor urut pasien dan waktu kedatangan pasien. Silahkan tambahkan asumsi
// seperti perkiraan waktu periksa yang digunakan per pasien. Buatlah tampilan
// aplikasi semenarik mungkin

#include <iomanip>
#include <iostream>

using namespace std;

// struct pasien
struct Pasien {
    string nama;
    int id;
    int nomorUrut;
    int waktuKedatangan;

    Pasien *next;
};

// maksimal
int maksimal = 5;

// pointer
Pasien *head, *tail, *cur, *del, *newNode;

// count
int count() {
    int counter = 0;

    // traversing
    cur = head;
    while (cur != NULL) {
        cur = cur->next;
        counter++;
    }

    return counter;
}

// waktu kedatangan
int waktuKedatanganCounter = 1;

// is full
bool isFull() { return (count() == maksimal); }

// is empty
bool isEmpty() { return (count() == 0); }

// enqueue
void enqueue() {
    // system("cls");
    if (isFull()) {
        cout << "Antrean penuh." << endl;
    } else {
        newNode = new Pasien();

        // penginputan field nama dan id oleh user
        cout << "Nama : ";
        cin >> newNode->nama;
        cout << "ID   : ";
        cin >> newNode->id;

        // penentuan field nomor urut dan waktu kedatangan oleh program
        newNode->nomorUrut = count() + 1;
        newNode->waktuKedatangan = waktuKedatanganCounter;
        waktuKedatanganCounter++;

        // pengnullan field next
        newNode->next = NULL;

        // penentuan head atau tail
        if (isEmpty()) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

// dequeue
void dequeue() {
    if (isEmpty()) {
        cout << "Antrean kosong." << endl;
    } else {
        del = head;
        head = head->next;
        del->next = NULL;
        delete del;
    }
}

// display
void display() {
    if (isEmpty()) {
        cout << "Antrean kosong." << endl;
    } else {
        cur = head;
        int nomorBaris = 1;

        while (nomorBaris <= maksimal) {
            if (cur != NULL) {
                cout << nomorBaris << " " << cur->id << " " << cur->nama << " "
                     << cur->nomorUrut << " " << cur->waktuKedatangan << endl;
                cur = cur->next;
            } else {
                cout << nomorBaris << " "
                     << "cur->id"
                     << " "
                     << "cur->nama"
                     << " "
                     << "cur->nomorUrut"
                     << " "
                     << "cur->waktuKedatangan" << endl;
            }
            nomorBaris++;
        }
    }
}

// clear
void clear() {
    if (isEmpty()) {
        cout << "Antrean kosong." << endl;
    } else {
        cur = head;
        // traversing
        while (cur != NULL) {
            del = cur;
            cur = cur->next;
            del->next = NULL;
            delete del;
        }
        head = NULL;
        tail = NULL;
    }
}

// operasi menu
void menu() {
    bool isStay = true;
    // while (isStay) {
    //     system("cls");
    //     int inputOpsi;
    //     display();
    //     cout << "Menu: ";
    //     cin >> inputOpsi;

    //     switch (inputOpsi) {
    //         case 1:
    //             enqueue();
    //             break;
    //         case 2:
    //             display();
    //             break;
    //         case 3:
    //             dequeue();
    //             break;
    //         case 4:
    //             clear();
    //             break;
    //         default:
    //             cout << "Opsi yang anda masukkan tidak valid." << endl;
    //             break;
    //     }
    // }
    do {
        system("cls");
        int inputOpsi;
        display();
        cout << "Menu: ";
        cin >> inputOpsi;

        switch (inputOpsi) {
            case 0:
                isStay = false;
                break;
            case 1:
                enqueue();
                break;
            case 2:
                display();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                clear();
                break;
            default:
                cout << "Opsi yang anda masukkan tidak valid." << endl;
                break;
        }
    } while (isStay);
}

int main() {
    menu();
    return 0;
}