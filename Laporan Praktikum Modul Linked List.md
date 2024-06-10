# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Mikhael Setia Budi</p>

## Dasar Teori

### Single Linked List
Linked List merupakan suatu bentuk struktur data yang berisi kumpulan data yang disebut sebagai node yang tersusun secara sekuensial, saling sambung menyambung, dinamis, dan terbatas. 
Setiap elemen dalam linked list dihubungkan ke elemen lain melalui pointer. Masing-masing komponen sering disebut dengan simpul atau node atau verteks. Pointer adalah alamat elemen. 
Simpul dibagi menjadi dua bagian, bagian pertama disebut sebagai isi atau informasi atau data yang berisi nilai yang disimpan oleh simpul.
Bagian kedua disebut bagian pointer yang berisi alamat dari node berikutnya atau sebelumnya.
linked list dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya. 
Pointer next pada elemen terakhir merupakan NULL, yang menunjukkan akhir dari suatu list. Elemen pada awal suatu list disebut head dan elemen terakhir dari suatu list disebut tail.

#### Linked List Circular
Linked list circular merupakan linked list yang tidak memiliki akhiran karena node terakhir (tail) tidak bernilai NULL,
tetapi terhubung dengan node pertama (Head). Saat menggunakan linked list circular kita membutuhkan dummy node atau node  pengecoh yang biasanya dinamakan dengan node current supaya program dapat  berhenti menghitung data ketika node current mencapai node pertama (head). 
Linked list circular dapat digunakan untuk menyimpan data yang perlu diakses  secara berulang, seperti daftar putar lagu, daftar pesan dalam antrian, atau  penggunaan memori berulang dalam suatu aplikasi.

### Double Linked List
Double Linked List adalah struktur data Linked List yang mirip dengan Single Linked List, namun dengan tambahan satu pointer tambahan pada setiap simpul yaitu pointer prev yang menunjuk ke simpul sebelumnya. Dengan adanya pointer prev, Double Linked List memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul mana saja secara efisien. Setiap simpul pada Double Linked List memiliki tiga elemen penting, yaitu elemen data (biasanya berupa nilai), pointer next yang menunjuk ke simpul
berikutnya, dan pointer prev yang menunjuk ke simpul sebelumnya. Keuntungan dari Double Linked List adalah memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul dimana saja dengan efisien, sehingga sangat berguna dalam implementasi beberapa algoritma yang membutuhkan operasi tersebut. Selain itu, Double Linked List juga memungkinkan kita untuk melakukan traversal pada list baik dari depan (head) maupun dari belakang (tail) dengan mudah. 
kekurangan dari Double Linked List adalah penggunaan memori yang lebih besar dibandingkan dengan Single Linked List, karena setiap simpul membutuhkan satu pointer tambahan. Selain itu, Double Linked List juga membutuhkan waktu eksekusi yang lebih lama dalam operasi penambahan dan penghapusan jika dibandingkan dengan Single Linked List.

## Guided 

### 1. Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    insertTengah(7,1);
    tampil();
    return 0;
}
```

**Code 1**
```C++
#include <iostream>
using namespace std;
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. 
using namespace std digunakan untuk menggunakan namespace std.

**Code 2**
```C++
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
```
Kode diatas adalah mendeklarasikan node sebagai struktur dasar dari linked list yang akan menyimpan data dan pointer ke node berikutnya
head merupakan pointer node pertama dalam linked list dan tail merupakan pointer node terakhir dalam linked list

**Code 3**
```C++
void init(){
    head = NULL;
    tail = NULL;
}
```
Kode diatas merupakan fungsi untuk menginisialisasi linked list dengan mengatur head dan tail menjadi NULL, menandakan bahwa list kosong.

**Code 4**
```C++
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
```
Kode diatas merupakan fungsi mengembalikan true jika linked list kodong atau head adalah NULL, dan sebaliknya mengembalikan false.

**Code 5**
```C++
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
```
Kode diatas adalah fungsi menambahkan node baru di depan linked list. jika linked list kosong maka head dan tail diatur ke node baru.
tetapi jika tidak maka node baru akan menjadi head.

**Code 6**
```C++
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
```
Kode diatas merupakan fungsi untuk menambahkan node baru di belakang linked list.
Jika linked list kosong maka head dan tail diatur ke node baru, tetapi jika tidak maka node baru menjadi tail.

**Code 7**
```C++
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
```
Fungsi untuk menghitung node dalam linked list dengan iterasi dari head atau node pertama sampai tail atau node terakhir.

**Code 8**
```C++
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
```
Fungsi untuk menambahkan node baru di posisi tertentu dalam linked list. jika posisi tidak valid maka fungsi akan menampilkan pesan kesalahan.
tetapi jika posisi adalah posisi pertama maka fungsi akan menampilkan pesan bahwa posisi bukan posisi tengah.
node baru ditambahkan setelah node pasa posisi (posisi-1).

**Code 9**
```C++
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
```
kode diatas merupakan fungsi yang digunakan untuk menghapus node di depan linked list. jika linked list kosong maka fungsi akan menampilkan kesalahan.
tetapi jika hanya ada satu node maka head dan tail akan diatur ke NULL.

**Code 10**
```C++
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
```
kode diatas merupakan fungsi yang digunakan untuk menghapus node di belakang linked list.
Jika linked list kosong maka fungsi akan menampilkan pesan kesalahan. jika hanya terdapat satu node maka head dan tail akan diatur ke NULL.

**Code 11**
``C++
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
```
kode diatas merupakan fungsi yang digunakan untuk menghapus node di posisi tertentu dalam linked list.
jika posisi tidak valid maka fungsi akan menampilkan kesalahan. node posisi dihapus dan pointer next dari node sebelumnya (posisi-1) diatur ke node setelah node yang dihapus.

**Code 12**
```C++
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
```
Kode diatas merupakan fungsi yang digunakan untuk mengubah data node di depan linked list.

**Code 13**
```C++
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
```
Kode diatas merupakan fungsi yang digunakan untuk mengubah data node pada posisi tertentu dalam linked list.

**Code 14**
```C++
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
```
Kode diatas adalah fungsi yang digunakan untuk mengubah data node di belakang linked list

**Code 15**
```C++
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
```
fungsi diatas digunakan untuk menghapus semua node dalam linked list dan mengatur head dan tail ke NULL.

**Code 16**
```C++
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
```
fungsi diatas digunakan untuk menampilkan semua data dalan linked list.

**Code 17**
```C++
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    insertTengah(7,1);
    tampil();
    return 0;
}
```
int main() merupakan fungsi utama yang akan dijalankan dalam program. 
diawali dengan menginisialisasi linked list, lalu menambahkan node di depan linked list dengan fungsi insert depan dan menampilkannya.
menambahkan node di belakang linked list dengan menggunakan fungsi insert belakang, dan menampilkannya.
menghapus node di depan, belakang dan tengah dengan menggunakan fungsi hapus belakang, depan, dan tengah.
menambahkan node di posisi tertentu dan menampilkannya. mengubah data depan, belakang dan tengah dengan menggunakan fungsi ubah depan, belakang, dan tengah dan menampilkannya.



#### Output
```C++
3
35
235
1235
235
23
273
23
13
18
111
Posisi bukan posisi tengah
111
```
output diatas menampilkan node pada linked list.

#### Full Code Screenshoot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-6-Linked-List/blob/master/Modul%206%20Alstrukdat/Code%20Guided%201%20Linked%20List.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-6-Linked-List/blob/master/Output%20Modul%206%20Alstrukdat/Output%20Guided%201%20Linked%20List.png?raw=true)

### 2. Latihan Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
public:
    string data;
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

    void push(string data) {
        Node* newNode = new Node;
        newNode->data = data;
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
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(string oldData, string newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
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
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                string oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```

**Code 1**
```C++
#include <iostream>
using namespace std;
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout.
using namespace std digunakan untuk menggunakan namespace std.

**Code 2**
```C++
struct hewan {
    string nama_hewan;
    string jenis_kelamin;
    string kembangbiak;
    string pernafasan;
    string tempat_hidup;
    bool karnivora;
}; 
```
kode diatas digunakan untuk mendefinisikan struct hewan yang memiliki beberapa atribut seperti nama_hewan, jenis_kelamin, kembangbiak, pernafasan, tempat_hidup, dan karnivora. struct ini merepresentasikan informasi umum tentang hewan.

**Code 3**
```C++
struct hewan_darat{
    hewan info_hewan;
    int jumlah_kaki;
    bool apakah_menyusui;
    string suara;
};
hewan_darat hewan1;
```
struct hewan darat didefinisikan yang menempatkan struct hewan sebagai salah satu anggotanya. dimana dalam struct hewan darat terdapat beberapa atribut yaitu jumlah_kaki, apakah_menyusui,dan suara. lalu mendeklarasikan hewan1 dengan tipe hewan_darat.

**Code 4**
```C++
struct hewan_laut{
    hewan info_hewan;
    string bentuk_sirip;
    string pertahanan_diri;
};
hewan_laut hewan2;
```
struct hewan laut didefinisikan yang menempatkan struct hewan sebagai salah satu anggotanya. dimana dalam struct hewan laut terdapat beberapa atribut yaitu bentuk_sirip dan pertahanan_diri. lalu mendeklarasikan hewan2 dengan tipe hewan_laut.

**Code 5**
```C++
int main() {
    hewan1.info_hewan.nama_hewan = "Anjing";
    hewan1.info_hewan.jenis_kelamin = "Laki-laki";
    hewan1.info_hewan.kembangbiak = "Melahirkan";
    hewan1.info_hewan.pernafasan = "Paru paru";
    hewan1.info_hewan.tempat_hidup = "Darat";
    hewan1.info_hewan.karnivora = true;
    hewan1.jumlah_kaki = 4;
    hewan1.apakah_menyusui = true;   
    hewan1.suara = "guk, guk, guk";
    
    hewan2.info_hewan.nama_hewan = "Hiu";
    hewan2.info_hewan.jenis_kelamin = "Perempuan";
    hewan2.info_hewan.kembangbiak = "Bertelur dan Beranak";
    hewan2.info_hewan.pernafasan = "Insang";
    hewan2.info_hewan.tempat_hidup = "Perairan (Laut)";
    hewan2.info_hewan.karnivora = true;
    hewan2.bentuk_sirip = "dosal, sabit, dan gumpalan";
    hewan2.pertahanan_diri = "Memakan Mangsa";   
```
int main() merupakan fungsi utama program. hewan1 dan hewan2 diisi dengan data sesuai atribut pada setia struct hewan dan hewan darat pada hewan1, lalu atribut hewan dan hewan laut pada hewan2 dengan menggunakan operator titik untuk mengakses dan mengatur nilai masing-masing atribut.

**Code 6**
```C++
//menampilkan data 
	cout << "\t Hewan Darat" << endl;
	cout << "Nama Hewan :" <<hewan1.info_hewan.nama_hewan << endl;
	cout << "Jenis Kelamin : "<<hewan1.info_hewan.jenis_kelamin << endl;
	cout << "Kembangbiak : "<< hewan1.info_hewan.kembangbiak << endl;
	cout << "Pernapasan : "<< hewan1.info_hewan.pernafasan << endl;
	cout << "Tempat Hidup : "<< hewan1.info_hewan.tempat_hidup << endl;
	cout << "karnivora : "<< hewan1.info_hewan.karnivora << endl;
	cout << "jumlah kaki : "<< hewan1.jumlah_kaki << endl;
	cout << "apakah menyusui?  : "<< hewan1.apakah_menyusui << endl;
	cout << "suara : "<< hewan1.suara << "\n" << endl ;

	//menampilkan data 
	cout << "\t Hewan Laut" << endl;
	cout << "Nama Hewan :" <<hewan2.info_hewan.nama_hewan << endl;
	cout << "Jenis Kelamin : "<<hewan2.info_hewan.jenis_kelamin << endl;
	cout << "Kembangbiak : "<< hewan2.info_hewan.kembangbiak << endl;
	cout << "Pernapasan : "<< hewan2.info_hewan.pernafasan << endl;
	cout << "Tempat Hidup : "<< hewan2.info_hewan.tempat_hidup << endl;
	cout << "apakah karnivora? "<< hewan2.info_hewan.karnivora << endl;
	cout << "bentuk sirip : "<< hewan2.bentuk_sirip << endl;
	cout << "pertahanan diri : "<< hewan2.pertahanan_diri << endl;
```
kode diatas digunakan untuk menampilkan informasi mengenai hewan1 dan hewan2 dengan menggunakan cout. atribut hewan diakses dengan menggunakan operator titik setelah nama objek.

**Code 7**
```C++
	return 0;
  }
```
Mengembalikan nilai 0 yang menandakan bahwa program telah selesai dijalankan.

#### Output
```C++
         Hewan Darat
Nama Hewan :Anjing
Jenis Kelamin : Laki-laki
Kembangbiak : Melahirkan
Pernapasan : Paru paru
Tempat Hidup : Darat
karnivora : 1
jumlah kaki : 4
apakah menyusui?  : 1
suara : guk, guk, guk

         Hewan Laut
Nama Hewan :Hiu
Jenis Kelamin : Perempuan
Kembangbiak : Bertelur dan Beranak
Pernapasan : Insang
Tempat Hidup : Perairan (Laut)
apakah karnivora? 1
bentuk sirip : dosal, sabit, dan gumpalan
pertahanan diri : Memakan Mangsa
```
Menampilkan informasi hewan darat yaitu nama hewan, jenis kelamin, kembangbiak, pernapasan, tempat hidup, karivora, jumlah kaki, apakah menyusui?, dan suara. pada bagian karnivora dan apakah menyusui 1 yang artinya true. menampilkan informasi hewan laut yaitu nama hewan, jenis kelamin, kembangbiak, pernapasan, tempat hidup, apakah karnivora?, bentuk sirip, dan pertahanan diri. pada bagian apakah karnivora? 1 yang artinya true.

#### Full Code Screenshoot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-5-Struct/blob/master/Modul%205%20Alstrukdat/code%20Guided%202%20Struct.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-5-Struct/blob/master/Output%20Modul%205%20Alstrukdat/Output%20Guided%202%20Struct.png?raw=true)

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan. 

```C++
#include <iostream>
using namespace std;

const int array_buku = 5; 

struct buku
{
    string judul_buku[array_buku];
    string pengarang[array_buku];
    string penerbit[array_buku];
    int tebal_buku[array_buku];
    double harga_buku[array_buku];
};

int main()
{
    buku data_buku;

    cout << "Masukkan data buku: " << endl;
    for (int i = 0; i < array_buku; ++i)
    {
        cout << "Buku ke-" << i + 1 << ":" << endl;
        cout << "Judul Buku: ";
        getline(cin, data_buku.judul_buku[i]);
        cout << "Pengarang Buku: ";
        getline(cin, data_buku.pengarang[i]);
        cout << "Penerbit Buku: ";
        getline(cin, data_buku.penerbit[i]);
        cout << "Tebal Buku: ";
        cin >> data_buku.tebal_buku[i];
        cout << "Harga Buku: ";
        cin >> data_buku.harga_buku[i];
        cin.ignore(); 
    }

    cout << "\nInformasi Buku: " << endl;
    for (int i = 0; i < array_buku; ++i)
    {
        cout << "\nBuku ke-" << i + 1 << ":" << endl;
        cout << "Judul Buku: " << data_buku.judul_buku[i] << endl;
        cout << "Pengarang Buku: " << data_buku.pengarang[i] << endl;
        cout << "Penerbit Buku: " << data_buku.penerbit[i] << endl;
        cout << "Tebal Buku: " << data_buku.tebal_buku[i] << endl;
        cout << "Harga Buku: " << data_buku.harga_buku[i] << endl;
    }

    return 0;
}


// Mikhael Setia Budi
// 2311110033
// copyright@MikhaelS.B
```

**Code 1**
```C++
#include <iostream>
using namespace std;
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. 
using namespace std digunakan untuk menggunakan namespace std. 

**Code 2**
```C++
const int array_buku = 5; 
```
kode diatas digunakan untuk mendeklarasikan sebuah konstanta array_buku yang memiliki nilai 5. konstanta ini digunakan untuk menentukan jumlah buku yang akan dimasukkan.

**Code 3**
```C++
struct buku
{
    string judul_buku[array_buku];
    string pengarang[array_buku];
    string penerbit[array_buku];
    int tebal_buku[array_buku];
    double harga_buku[array_buku];
};
```
kode diatas digunakan untuk mendefinisikan struct buku yang memiliki beberapa array untuk menyimpan informasi tentang judul buku, pengarang, penerbit, tebal buku, dan harga buku.

**Code 4**
```C++
int main()
{
    buku data_buku;

    cout << "Masukkan data buku: " << endl;
    for (int i = 0; i < array_buku; ++i)
    {
        cout << "Buku ke-" << i + 1 << ":" << endl;
        cout << "Judul Buku: ";
        getline(cin, data_buku.judul_buku[i]);
        cout << "Pengarang Buku: ";
        getline(cin, data_buku.pengarang[i]);
        cout << "Penerbit Buku: ";
        getline(cin, data_buku.penerbit[i]);
        cout << "Tebal Buku: ";
        cin >> data_buku.tebal_buku[i];
        cout << "Harga Buku: ";
        cin >> data_buku.harga_buku[i];
        cin.ignore(); 
    }
  ```
int main() merupakan fungsi program utama. variabel data_buku dari tipe buku dideklarasikan untuk menyimpan data buku yang dimasukkan oleh pengguna. perulagan for yang memungkinkan pengguna untuk memasukkan informasi tentang setiap buku. setiap atribut buku yang dimasukkan ke dalam array yang sesuai. 

**Code 5**
```C++
 cout << "\nInformasi Buku: " << endl;
    for (int i = 0; i < array_buku; ++i)
    {
        cout << "\nBuku ke-" << i + 1 << ":" << endl;
        cout << "Judul Buku: " << data_buku.judul_buku[i] << endl;
        cout << "Pengarang Buku: " << data_buku.pengarang[i] << endl;
        cout << "Penerbit Buku: " << data_buku.penerbit[i] << endl;
        cout << "Tebal Buku: " << data_buku.tebal_buku[i] << endl;
        cout << "Harga Buku: " << data_buku.harga_buku[i] << endl;
    }
```
kode diatas digunakan untuk menampilkan informasi buku yang dimasukkan oleh pengguna.

**Code 6**
```C++
    return 0;
}
```
Mengembalikan nilai 0 yang menandakan bahwa program telah selesai dijalankan.

#### Output:
```C++
Masukkan data buku: 
Buku ke-1:
Judul Buku: Algoritma Pemrograman
Pengarang Buku: Yunus Prademon
Penerbit Buku: Gramedia Pustaka Utama
Tebal Buku: 300
Harga Buku: 120000
Buku ke-2:
Judul Buku: Metode Statistika
Pengarang Buku: Atika Ratna Dewi
Penerbit Buku: Gramedia Pustaka Utama
Tebal Buku: 250
Harga Buku: 110000
Buku ke-3:
Judul Buku: Kewarganegaraan
Pengarang Buku: Rakhma Nurrozalina
Penerbit Buku: Gramedia Pustaka Utama
Tebal Buku: 350
Harga Buku: 150000
Buku ke-4:
Judul Buku: Matematika Diskrit
Pengarang Buku: Ummi Athiya
Penerbit Buku: Gramedia Pustaka Utama
Tebal Buku: 200
Harga Buku: 130000
Buku ke-5:
Judul Buku: 1001 Modus
Pengarang Buku: Rizal Wahyu Pratama
Penerbit Buku: Gramedia Pustaka Utama
Tebal Buku: 200
Harga Buku: 100000
```
Pengguna memasukkan data buku 1 sampai 5.

```C++
Informasi Buku:

Buku ke-1:
Judul Buku: Algoritma Pemrograman       
Pengarang Buku: Yunus Prademon
Penerbit Buku: Gramedia Pustaka Utama   
Tebal Buku: 300
Harga Buku: 120000

Buku ke-2:
Judul Buku: Metode Statistika
Pengarang Buku: Atika Ratna Dewi        
Penerbit Buku: Gramedia Pustaka Utama   
Tebal Buku: 250
Harga Buku: 110000

Buku ke-3:
Judul Buku: Kewarganegaraan
Pengarang Buku: Rakhma Nurrozalina      
Penerbit Buku: Gramedia Pustaka Utama   
Tebal Buku: 350
Harga Buku: 150000

Buku ke-4:
Judul Buku: Matematika Diskrit
Pengarang Buku: Ummi Athiya
Penerbit Buku: Gramedia Pustaka Utama   
Tebal Buku: 200
Harga Buku: 130000

Buku ke-5:
Judul Buku: 1001 Modus
Pengarang Buku: Rizal Wahyu Pratama
Penerbit Buku: Gramedia Pustaka Utama
Tebal Buku: 200
Harga Buku: 100000
```
menampilkan Infromasi buku 1 sampai 5 yang telah diinputkan oleh pengguna.

#### Full code Screenshot:
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-5-Struct/blob/master/Modul%205%20Alstrukdat/code%20Unguided%201%20Struct.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-5-Struct/blob/master/Output%20Modul%205%20Alstrukdat/Output%20Unguided%201%20Struct%20(Input%20Data).png?raw=true)

![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-5-Struct/blob/master/Output%20Modul%205%20Alstrukdat/Output%20Unguided%201%20Struct.png?raw=true)

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?
Jika deklarasi variabel struct guided 1 dengan jenis array dengan mendeklarasikan buku data_buku dimana di dalam kode tersebut terdapat array_buku yang telah diberi nilai 5, sehingga array_buku akan menyimpan data buku sebanyak 5. Cara mengisi data terdapat pada variabel data_buku dari tipe buku dideklarasikan untuk menyimpan data buku yang dimasukkan oleh pengguna. dengan menggunakan perulagan for yang memungkinkan pengguna untuk memasukkan informasi tentang setiap buku mengenai judul buku, pengarang, penerbit, tebal buku, dan harga buku. untuk menampilkan data buku menggunakan perulangan for yang melakukan perulangan dalam array array_buku, dan menggunakan cout untuk menampilkan informasi buku yang telah diinputkan oleh pengguna

## Kesimpulan
Variabel merupakan tempat untuk menyimpan data dengan tipe data tertentu. variabel tidak dapat menyimpan lebih dari 1 nilai, jika ingin menyimpan lebih dari 1 nilai maka perlu mendeklarasikan variabel sebagai array. variabel terbagi menjadi dua yaitu variabel lokal dan variabel global. struct terdiri dari tipe data standar maupun tipe data bentukan lainnya yang telah didefinisikan. terdapat 3 format dalam struct.

## Referensi
[1]	Q. Muhammad et al., “Penggunaan Bahasa C++ dalam Perkuliahan Jurusan Teknik Elektro Fakultas Teknik,” vol. 3, no. 1, pp. 143–151, 2024, [Online]. Available: http://jurnalilmiah.org/journal/index.php/majemuk
