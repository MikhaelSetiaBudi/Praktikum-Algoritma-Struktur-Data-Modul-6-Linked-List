#include <iostream>
#include <iomanip> // Menambahkan library untuk manipulasi output
#include <string>

using namespace std;

struct Node 
{
    string nama;
    int usia;
    Node* next;
};

class LinkedList 
{
public:
    Node* head_2311110033;

    LinkedList() 
    {
        head_2311110033 = nullptr;
        // Menambahkan data pertama ke dalam linked list
        insertDepan("Karin", 18);
        insertDepan("Hoshino", 18);
        insertDepan("Akechi", 20);
        insertDepan("Yusuke", 19);
        insertDepan("Michael", 18);
        insertDepan("Jane", 20);
        insertDepan("John", 19);
    }

    void insertDepan(string nama, int usia) 
    {
        Node* newnode = new Node{nama, usia, nullptr};
        if (head_2311110033 == nullptr) 
        {
            head_2311110033 = newnode;
        } else 
        {
            newnode->next = head_2311110033;
            head_2311110033 = newnode;
        }
    }

    void insertBelakang(string nama, int usia) 
    {
        Node* newnode = new Node{nama, usia, nullptr};
        if (head_2311110033 == nullptr) 
        {
            head_2311110033 = newnode;
        } else 
        {
            Node* temp = head_2311110033;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void insertTengah(string nama, int usia, int posisi) 
    {
        if (posisi == 1) 
        {
            insertDepan(nama, usia);
            return;
        }
        Node* newnode = new Node{nama, usia, nullptr};
        Node* temp = head_2311110033;
        for (int i = 1; temp != nullptr && i < posisi - 1; i++) 
        {
            temp = temp->next;
        }
        if (temp == nullptr) 
        {
            cout << "Posisi di luar batas." << endl;
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void updateData(string namalama, string namabaru, int usiabaru) 
    {
        Node* temp = head_2311110033;
        while (temp != nullptr) {
            if (temp->nama == namalama) 
            {
                temp->nama = namabaru;
                temp->usia = usiabaru;
                return;
            }
            temp = temp->next;
        }
        cout << "Data tidak ditemukan." << endl;
    }

    void hapusData(string nama) 
    {
        Node* temp = head_2311110033;
        Node* prev = nullptr;
        while (temp != nullptr) 
        {
            if (temp->nama == nama) 
            {
                if (prev == nullptr) 
                {
                    head_2311110033 = temp->next;
                } else 
                {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Data berhasil dihapus." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Data tidak ditemukan." << endl;
    }

    void display() 
    {
        Node* temp = head_2311110033;
        cout << left << setw(20) << "Nama" << "Usia" << endl; // Menampilkan header tabel
        while (temp != nullptr) 
        {
            cout << left << setw(20) << temp->nama << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main() 
{
    LinkedList list;
    string namalama, namabaru, namahapus;
    int usiabaru;
    int pilihan;
    bool lanjut = true;

    while (lanjut) 
    {
        cout << "Pilih operasi:" << endl; 
        cout << "1. Insert Depan" << endl; 
        cout << "2. Insert Belakang" << endl;
        cout << "3. Insert Tengah" << endl;
        cout << "4. Update Data" << endl;
        cout << "5. Hapus Data" << endl;
        cout << "6. Tampilkan Data" << endl;
        cout << "7. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        cin.ignore(); // Untuk mengabaikan newline yang tersisa di input buffer

        switch (pilihan) 
        {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, namabaru);
                cout << "Masukkan usia: ";
                cin >> usiabaru;
                list.insertDepan(namabaru, usiabaru);
                break;
            case 2:
                cout << "Masukkan nama: ";
                getline(cin, namabaru);
                cout << "Masukkan usia: ";
                cin >> usiabaru;
                list.insertBelakang(namabaru, usiabaru);
                break;
            case 3:
                int posisi;
                cout << "Masukkan nama: ";
                getline(cin, namabaru);
                cout << "Masukkan usia: ";
                cin >> usiabaru;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                list.insertTengah(namabaru, usiabaru, posisi);
                break;
            case 4:
                cout << "Masukkan nama lama: ";
                getline(cin, namalama);
                cout << "Masukkan nama baru: ";
                getline(cin, namabaru);
                cout << "Masukkan usia baru: ";
                cin >> usiabaru;
                list.updateData(namalama, namabaru, usiabaru);
                break;
            case 5:
                cout << "Masukkan data yang ingin dihapus: ";
                getline(cin, namahapus);
                list.hapusData(namahapus);
                break;  
            case 6:
                list.display();
                break;
            case 7:
                lanjut = false;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    }
    return 0;
}


// Mikhael Setia Budi
// 2311110033
// copyright@MikhaelS.B