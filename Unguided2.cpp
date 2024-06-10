#include <iostream>
#include <iomanip>
using namespace std;

class Node {
public:
    string namaProduk_2311110033;
    int harga;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(string namaProduk, int harga) {
        Node* newNode = new Node;
        newNode->namaProduk_2311110033 = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            cout << "Daftar sudah kosong, tidak ada yang bisa dihapus." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
            cout << "Daftar sekarang kosong setelah penghapusan." << endl;
        }
        delete temp;
        cout << "Elemen depan berhasil dihapus." << endl;
    }

    bool update(string oldNama, string newNama, int newHarga) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk_2311110033 == oldNama) {
                current->namaProduk_2311110033 = newNama;
                current->harga = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        cout << left << setw(20) << "Nama Produk" << "Harga" << endl;
        while (current != nullptr) {
            cout << left << setw(20) << current->namaProduk_2311110033 << current->harga << endl;
            current = current->next;
        }
    }

    void insertAt(string namaProduk, int harga, int posisi) {
        Node* newNode = new Node;
        newNode->namaProduk_2311110033 = namaProduk;
        newNode->harga = harga;
        if (posisi == 1) {
            push(namaProduk, harga);
            return;
        }
        Node* current = head;
        for (int i = 1; current != nullptr && i < posisi - 1; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi di luar batas." << endl;
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }

    void deleteAt(int posisi) {
        if (head == nullptr) {
            return;
        }
        Node* current = head;
        for (int i = 1; current != nullptr && i < posisi; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi di luar batas." << endl;
            return;
        }
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
        delete current;
    }

    bool remove(string namaProduk) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk_2311110033 == namaProduk) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    DoublyLinkedList list;
    list.push("Hanasui", 30000);
    list.push("Wardah", 50000);
    list.push("Skintific", 100000);
    list.push("Somethinc", 150000);
    list.push("Originote", 60000);

    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        int choice;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string namaProduk;
                int harga;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                list.push(namaProduk, harga);
                break;
            }
            case 2: {
                string namaProduk;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                if (!list.remove(namaProduk)) {
                    cout << "Produk tidak ditemukan." << endl;
                } else {
                    cout << "Produk berhasil dihapus." << endl;
                }
                break;
            }
            case 3: {
                string oldNama, newNama;
                int newHarga;
                cout << "Masukkan nama produk lama: ";
                cin >> oldNama;
                cout << "Masukkan nama produk baru: ";
                cin >> newNama;
                cout << "Masukkan harga baru: ";
                cin >> newHarga;
                bool updated = list.update(oldNama, newNama, newHarga);
                if (!updated) {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                string namaProduk;
                int harga, posisi;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                list.insertAt(namaProduk, harga, posisi);
                break;
            }
            case 5: {
                int posisi;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                list.deleteAt(posisi);
                break;
            }
            case 6: {
                list.deleteAll();
                break;
            }
            case 7: {
                list.display();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    }
    return 0;
}

// Mikhael Setia Budi
// 2311110033
// copyright@MikhaelS.B