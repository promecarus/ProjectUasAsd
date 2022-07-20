// Buatlah suatu program antrean pasien pada suatu klinik ABC. Program dapat
// menerima inputan nama dan no ID pasien, kemudian program akan menentukan
// nomor urut pasien dan waktu kedatangan pasien. Silahkan tambahkan asumsi
// seperti perkiraan waktu periksa yang digunakan per pasien. Buatlah tampilan
// aplikasi semenarik mungkin

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

// struct pasien
struct Pasien {
    string nama;
    int id;
    int nomorUrut;
    string waktuKedatangan;

    Pasien *next;
};

// maksimal
int maksimal = 50;

// pointer
Pasien *head, *tail, *cur, *del, *newNode;

// nomor urut
int nomorUrutCounter = 0;

// rata-rata waktu pemeriksaan
int meanWaktuPemeriksaan = 20;

// border menu
void tampilanMenu() {
    int lebarTabel = 34;
    string menu[] = {
        "[1] Tambah Antrean",
        "[2] Panggil Pasien",
        "[3] Lihat List Antrean",
        "[4] Bersihkan List Antrean",
        "[5] Keluar",
    };
    cout << "\n"
         << setfill('-') << setw(lebarTabel) << left << "+-"
         << "+\n";
    cout << setfill(' ') << "| " << setw(lebarTabel - 2) << left
         << "Menu Kontrol Antrean Klinik ABC"
         << "|";
    cout << "\n"
         << setfill('-') << setw(lebarTabel) << left << "+-"
         << "+\n";
    for (int i = 0; i < sizeof(menu) / sizeof(string); i++) {
        cout << setfill(' ') << "| " << setw(lebarTabel - 2) << left << menu[i]
             << "|\n";
    }
    cout << setfill('-') << setw(lebarTabel) << left << "+-"
         << "+\n";
    cout << "Input Anda: ";
}

// konfirmasi
bool konfirmasiKeluar() {
    system("cls");
    
    bool hasil;
    string input;

    cout << "Apakah anda yakin ingin keluar? [y/n]: ";
    cin >> input;
    if (tolower(input[0]) == 'y') {
        system("cls");
        cout << "Terima kasih telah menggunakan aplikasi ini.";
        hasil = true;
    } else if (tolower(input[0]) == 'n') {
        cout << "Batal keluar dari aplikasi.";
    } else {
        cout << "Input tidak valid. Kembali ke menu.";
    }
    return !hasil;
}

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

// is full
bool isFull() { return (count() == maksimal); }

// is empty
bool isEmpty() { return (count() == 0); }

// enqueue
void enqueue() {
    cout << "Tambah Antrean" << endl;
    if (isFull()) {
        cout << "Antrean penuh." << endl;
    } else {
        newNode = new Pasien;

        // penginputan field nama dan id oleh user
        cin.ignore();
        cout << "Nama : ";
        getline(cin, newNode->nama);

        cout << "ID   : ";
        cin >> newNode->id;

        // penentuan field nomor urut dan waktu kedatangan oleh program
        nomorUrutCounter++;
        newNode->nomorUrut = nomorUrutCounter;

        auto t = time(nullptr);
        auto tm = *localtime(&t);
        ostringstream oss;
        oss << put_time(&tm, "%d-%m-%Y %H:%M:%S");
        newNode->waktuKedatangan = oss.str();

        // pengnullan field next
        newNode->next = NULL;

        // penentuan sebagai head atau tail
        if (isEmpty()) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        int ruasTabelEnqueue[] = {19, 28};

        // pencetakan kartu antrian
        system("cls");
        cout << setfill('-') << setw(ruasTabelEnqueue[0] + ruasTabelEnqueue[1])
             << left << "+-"
             << "+\n";
        cout << setfill(' ') << "| " << left << setw(ruasTabelEnqueue[0] - 12)
             << "Antrean"
             << " " << left << setw(ruasTabelEnqueue[1] + 9) << count()
             << "|\n";
        cout << setfill('-') << setw(ruasTabelEnqueue[0] + ruasTabelEnqueue[1])
             << left << "+-"
             << "+\n";
        cout << setfill(' ') << "| " << left << setw(ruasTabelEnqueue[0] - 2)
             << "Nama"
             << "| " << left << setw(ruasTabelEnqueue[1] - 2) << newNode->nama
             << "|\n";
        cout << setfill(' ') << "| " << left << setw(ruasTabelEnqueue[0] - 2)
             << "Nomor ID"
             << "| " << left << setw(ruasTabelEnqueue[1] - 2) << newNode->id
             << "|\n";
        cout << setfill(' ') << "| " << left << setw(ruasTabelEnqueue[0] - 2)
             << "Nomor Urut"
             << "| " << left << setw(ruasTabelEnqueue[1] - 2)
             << newNode->nomorUrut << "|\n";
        cout << setfill(' ') << "| " << left << setw(ruasTabelEnqueue[0] - 2)
             << "Waktu Kedatangan"
             << "| " << left << setw(ruasTabelEnqueue[1] - 2)
             << newNode->waktuKedatangan << "|\n";
        cout << setfill(' ') << "| " << left << setw(ruasTabelEnqueue[0] - 2)
             << "Estimasi Tunggu"
             << "| " << left << setw(ruasTabelEnqueue[1] - 2)
             << (count() * meanWaktuPemeriksaan) - meanWaktuPemeriksaan
             << "|\n";
        cout << setfill('-') << setw(ruasTabelEnqueue[0]) << left << "+-"
             << setw(ruasTabelEnqueue[1]) << left << "+-"
             << "+\n";
    }
}

// dequeue
void dequeue() {
    if (isEmpty()) {
        cout << "Antrean kosong." << endl;
    } else {
        int ruasTabelDequeue[] = {19, 28};
        del = head;
        head = head->next;
        del->next = NULL;

        system("cls");
        cout << setfill('-') << setw(ruasTabelDequeue[0] + ruasTabelDequeue[1])
             << left << "+-"
             << "+\n";
        cout << setfill(' ') << "| " << left
             << setw(ruasTabelDequeue[0] + ruasTabelDequeue[1] - 2)
             << "Pemanggilan Pasien"
             << "|\n";
        cout << setfill('-') << setw(ruasTabelDequeue[0]) << left << "+-"
             << setw(ruasTabelDequeue[1]) << left << "+-"
             << "+\n";
        cout << setfill(' ') << "| " << left << setw(ruasTabelDequeue[0] - 2)
             << "Nama"
             << "| " << left << setw(ruasTabelDequeue[1] - 2) << del->nama
             << "|\n";
        cout << setfill(' ') << "| " << left << setw(ruasTabelDequeue[0] - 2)
             << "Nomor ID"
             << "| " << left << setw(ruasTabelDequeue[1] - 2) << del->id
             << "|\n";
        cout << setfill(' ') << "| " << left << setw(ruasTabelDequeue[0] - 2)
             << "Nomor Urut"
             << "| " << left << setw(ruasTabelDequeue[1] - 2) << del->nomorUrut
             << "|\n";
        cout << setfill('-') << setw(ruasTabelDequeue[0]) << left << "+-"
             << setw(ruasTabelDequeue[1]) << left << "+-"
             << "+\n";

        delete del;
    }
}

// display
void display() {
    int ruasTabelDisplay[] = {6, 28, 19, 13, 22};
    if (isEmpty()) {
        cout << "Antrean kosong." << endl;
    } else {
        cur = head;
        int nomorBaris = 1;
        string kosong = "";
        cout << setfill('-') << setw(ruasTabelDisplay[0]) << left << "+-"
             << setw(ruasTabelDisplay[1]) << left << "+-"
             << setw(ruasTabelDisplay[2]) << left << "+-"
             << setw(ruasTabelDisplay[3]) << left << "+-"
             << setw(ruasTabelDisplay[4]) << left << "+-"
             << "+\n";
        cout << setfill(' ') << "| " << left << setw(ruasTabelDisplay[0] - 2)
             << "No."
             << "| " << left << setw(ruasTabelDisplay[1] - 2) << "Nama"
             << "| " << left << setw(ruasTabelDisplay[2] - 2) << "Nomor ID"
             << "| " << left << setw(ruasTabelDisplay[3] - 2) << "Nomor Urut"
             << "| " << left << setw(ruasTabelDisplay[4] - 2)
             << "Waktu Kedatangan"
             << "|\n";
        do {
            cout << setfill('-') << setw(ruasTabelDisplay[0]) << left << "+-"
                 << setw(ruasTabelDisplay[1]) << left << "+-"
                 << setw(ruasTabelDisplay[2]) << left << "+-"
                 << setw(ruasTabelDisplay[3]) << left << "+-"
                 << setw(ruasTabelDisplay[4]) << left << "+-"
                 << "+\n";
            if (cur != NULL) {
                cout << setfill(' ') << "| " << left
                     << setw(ruasTabelDisplay[0] - 2) << nomorBaris << "| "
                     << left << setw(ruasTabelDisplay[1] - 2) << cur->nama
                     << "| " << left << setw(ruasTabelDisplay[2] - 2) << cur->id
                     << "| " << left << setw(ruasTabelDisplay[3] - 2)
                     << cur->nomorUrut << "| " << left
                     << setw(ruasTabelDisplay[4] - 2) << cur->waktuKedatangan
                     << "|\n";
                cur = cur->next;
            } else {
                cout << setfill(' ') << "| " << left
                     << setw(ruasTabelDisplay[0] - 2) << nomorBaris << "| "
                     << left << setw(ruasTabelDisplay[1] - 2) << kosong << "| "
                     << left << setw(ruasTabelDisplay[2] - 2) << kosong << "| "
                     << left << setw(ruasTabelDisplay[3] - 2) << kosong << "| "
                     << left << setw(ruasTabelDisplay[4] - 2) << kosong
                     << "|\n";
            }
            nomorBaris++;
        } while (nomorBaris <= maksimal);
        cout << setfill('-') << setw(ruasTabelDisplay[0]) << left << "+-"
             << setw(ruasTabelDisplay[1]) << left << "+-"
             << setw(ruasTabelDisplay[2]) << left << "+-"
             << setw(ruasTabelDisplay[3]) << left << "+-"
             << setw(ruasTabelDisplay[4]) << left << "+-"
             << "+\n";
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
        cout << "Antrean berhasil dibersihkan." << endl;
    }
}

// operasi menu
void menu() {
    bool isStay = true;
    while (isStay) {
        int inputOpsi;
        tampilanMenu();
        cin >> inputOpsi;
        system("cls");

        switch (inputOpsi) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                clear();
                break;
            case 5:
                isStay = konfirmasiKeluar();
                break;
            default:
                cout << "Opsi yang anda masukkan tidak valid." << endl;
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}