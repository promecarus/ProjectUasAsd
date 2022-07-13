#include <iostream>
#include <string>

using namespace std;
// Buatlah sebuah double linked list, yang didalamnya terdapat nested struct dengan atribut yang menggunakan type data array

struct kata{
	char kata[20];
};

struct dataNama{
	kata namaDepan;
	kata namaTengah;
	kata namaBelakang;
};

struct hobi{
	kata hobi1;
	kata hobi2;
	kata hobi3;
};

struct tanggal{
	int tanggal;
	int bulan;
	int tahun;
};

struct Anggota{
	int id;
	dataNama namaAnggota;
	hobi hobiAnggota;
	string divisi;
	tanggal tanggalLahir;
	tanggal tanggalMasuk;
	Anggota *next;
	Anggota *prev;
};

Anggota *head, *tail, *cur, *newNode, *del;
int counter = 0;

void IsiData(Anggota *newNode){
	newNode->id = ++counter;
	cout << "Masukkan Nama Depan\t: ";
	cin >> newNode->namaAnggota.namaDepan.kata;
	cout << "Masukkan Nama Tengah\t: ";
	cin >> newNode->namaAnggota.namaTengah.kata;
	cout << "Masukkan Nama Belakang\t: ";
	cin >> newNode->namaAnggota.namaBelakang.kata;
	cout << "Masukkan Hobi 1\t\t: ";
	cin >> newNode->hobiAnggota.hobi1.kata;
	cout << "Masukkan Hobi 2\t\t: ";
	cin >> newNode->hobiAnggota.hobi2.kata;
	cout << "Masukkan Hobi 3\t\t: ";
	cin >> newNode->hobiAnggota.hobi3.kata;
	cout << "Masukkan Divisi\t\t: ";
	cin >> newNode->divisi;
	cout << "Masukkan Tanggal Lahir\t: ";
	cin >> newNode->tanggalLahir.tanggal;
	cout << "Masukkan Bulan Lahir\t: ";
	cin >> newNode->tanggalLahir.bulan;
	cout << "Masukkan Tahun Lahir\t: ";
	cin >> newNode->tanggalLahir.tahun;
	cout << "Masukkan Tanggal Masuk\t: ";
	cin >> newNode->tanggalMasuk.tanggal;
	cout << "Masukkan Bulan Masuk\t: ";
	cin >> newNode->tanggalMasuk.bulan;
	cout << "Masukkan Tahun Masuk\t: ";
	cin >> newNode->tanggalMasuk.tahun;
}

void BuatDoubleLinkedList(){
	cout << "Buat Double Linked List" << "\n";
	head = new Anggota;
	IsiData(head);
	
	head->next = NULL;
	head->prev = NULL;
	tail = head;
}

void CetakDoubleLinkedList(){
	cout << "\nCetak Double Linked List" << "\n";
	cur = head;
	while(cur != NULL){
		cout << "ID : " << cur->id << "\n";
		cout << "Nama Depan\t: " << cur->namaAnggota.namaDepan.kata << "\n";
		cout << "Nama Tengah\t: " << cur->namaAnggota.namaTengah.kata << "\n";
		cout << "Nama Belakang\t: " << cur->namaAnggota.namaBelakang.kata << "\n";
		cout << "Hobi\t\t: " << cur->hobiAnggota.hobi1.kata << " " << cur->hobiAnggota.hobi2.kata << " " << cur->hobiAnggota.hobi3.kata << "\n";
		cout << "Divisi\t\t: " << cur->divisi << "\n";
		cout << "Tanggal Lahir\t: " << cur->tanggalLahir.tanggal << " " << cur->tanggalLahir.bulan << " " << cur->tanggalLahir.tahun << "\n";
		cout << "Tanggal Masuk\t: " << cur->tanggalMasuk.tanggal << " " << cur->tanggalMasuk.bulan << " " << cur->tanggalMasuk.tahun << "\n";
		cout << "\n";
		cur = cur->next;
	}
}

void TambahDepan(){
	cout << "Tambah Depan" << "\n";
	newNode = new Anggota;
	IsiData(newNode);

	newNode->next = head;
	newNode->prev = NULL;
	head->prev = newNode;
	head = newNode;
}

void TambahBelakang(){
	cout << "Tambah Belakang" << "\n";
	newNode = new Anggota;
	IsiData(newNode);

	newNode->next = NULL;
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
}

void HapusDepan(){
	cout << "Hapus Depan" << "\n";
	del = head;
	head = head->next;
	head->prev = NULL;
	delete del;
}

void HapusBelakang(){
	cout << "Hapus Belakang" << "\n";
	del = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete del;
}

int main(){
	BuatDoubleLinkedList();
	
	int pilihan;
	while(pilihan != 9){
		CetakDoubleLinkedList();
		cout << "+--------------------------------------------------------------------------------------------------------+" << "\n";
		cout << "| [1] Tambah Depan | [2] Tambah Belakang | [3] Hapus Depan | [4] Hapus Belakang | [5] Cetak | [9] Keluar |" << "\n";
		cout << "Pilihan: ";
		cin >> pilihan;

		switch(pilihan){
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
			case 9:
				cout << "Keluar" << "\n";
				break;
			default:
				cout << "Pilihan tidak ada" << "\n";
				break;
		}
	}

	system("pause");
	return 0;
}