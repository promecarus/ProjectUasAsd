// Diberikan sebuah kasus untuk enkripsi password yang memanfaatkan Linked List,
// dengan spesifikasi : Panjang password 6 digit, Isi password terserah dari
// user dan password diinputkan terlebih dahulu. Enkripsi dilakukan dengan
// menukarkan n node terakhir, menjadi node terdepan. Kemudian sisipkan karakter
// baru sebagai kunci (misal karakter @) setelah n node dari yang dipindahkan
// tersebut. Silahkan tentukan nilai n, dan boleh menambahkan asumsi pribadi.
// Buatlah tampilan aplikasi semenarik mungkin

#include <iostream>

using namespace std;

// struct node
struct Node {
    char data;

    Node *next;
};

Node *head, *tail, *cur, *newNode, *del, *temp;

// digit password
int digitPassword = 6;

// password sebelum dan sesudah
string passwordSebelum, passwordSesudah;

// push
void push(char data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    // penentuan sebagai head atau tail
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// remove
void remove() {
    for (int i = 0; i < 7; i++) {
        del = head;
        head = head->next;
        del->next = NULL;
        delete del;
    }
}

// print
void print(string pesan) {
    cout << pesan << endl;

    // traversing
    cur = head;
    while (cur != NULL) {
        cout << cur->data;
        cur = cur->next;
        if (cur != NULL) {
            cout << " >> ";
        }
    }
    cout << endl << endl;
}

// input
string input() {
    bool valid = false;
    string hasil;
    passwordSebelum = "";

    while (!valid) {
        cout << "Masukkan password yang ingin dienkripsi [" << digitPassword
             << " digit karakter]: ";
        cin >> hasil;
        if (hasil.length() == digitPassword) {
            valid = true;
        } else {
            system("cls");
            cout << "Password yang Anda masukkan terlalu";
            if (hasil.length() < digitPassword) {
                cout << " [pendek].";
            } else {
                cout << " [panjang].";
            }
            cout << endl << endl;
        }
        cout << endl;
    }

    // pembentukan single linked list & menyimpan password sebelum terenkripsi
    for (int i = 0; i < digitPassword; i++) {
        push(hasil[i]);

        // penyimpanan password sebelum
        passwordSebelum += hasil[i];
    }

    // menampilkan password
    print("Password sebelum dienkripsi: ");
    return hasil;
}

// enkripsi
void enkripsi(string data) {
    bool check = false;
    int counter = 1;
    passwordSesudah = "";

    int nilaiN = 4;
    // int nilaiN;
    // while (!check) {
    //     cout << "Nilai n [ 0 < digit < " << digitPassword << " ] : ";
    //     cin >> nilaiN;
    //     if (nilaiN > 0 && nilaiN < digitPassword) {
    //         check = true;
    //     } else {
    //         system("cls");
    //         cout << "Tidak valid." << endl;
    //     }
    // }

    char kunci = '#';
    // char kunci;
    // cout << "Karakter kunci            : ";
    // cin >> kunci;
    
    push(kunci);

    // traversing menetapkan sejumlah n node yang nantinya akan disisipkan ke depan
    cur = head;
    while (counter != abs(digitPassword - nilaiN)) {
        cur = cur->next;
        counter++;
    }

    // proses pengenkripsian
    temp = head;
    head = cur->next;
    tail->next = temp;
    cur->next = NULL;
    tail = cur;
    print("\nPassword sesudah dienkripsi: ");

    // traversing
    cur = head;
    while (cur != NULL) {
        passwordSesudah += cur->data;
        cur = cur->next;
    }
}

int main() {
    bool lagi = true;
    bool valid = false;
    string konfirmasi;

    while (lagi) {
        enkripsi(input());
        while (!valid) {
            cout << "Enkripsi password lainnya? [y/n]: ";
            cin >> konfirmasi;
            if (tolower(konfirmasi[0]) == 'y') {
                system("cls");
                remove();
                lagi = true;
                valid = true;
            } else if (tolower(konfirmasi[0]) == 'n') {
                cout << "Terima kasih telah menggunakan aplikasi ini." << endl;
                lagi = false;
                valid = true;
            } else {
                system("cls");
                cout << "Input tidak valid." << endl;
                valid = false;
            }
        }
        valid = false;
    }

    // cout << "Sebelum enkripsi: " << passwordSebelum << endl;
    // cout << "Sesudah enkripsi: " << passwordSesudah << endl;

    return 0;
}