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
berikutnya, dan pointer prev yang menunjuk ke simpul sebelumnya. double linked list, di mana setiap node dapat ditunjuk oleh dua tetangganya [1]. Keuntungan dari Double Linked List adalah memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul dimana saja dengan efisien, sehingga sangat berguna dalam implementasi beberapa algoritma yang membutuhkan operasi tersebut. Selain itu, Double Linked List juga memungkinkan kita untuk melakukan traversal pada list baik dari depan (head) maupun dari belakang (tail) dengan mudah. 
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
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. using namespace std digunakan untuk menggunakan namespace std.

**Code 2**
```C++
class Node {
public:
    string data;
    Node* prev;
    Node* next;
};
```
kode diatas mendeklarasikan kelas node yang mendefinisikan struktur node dalam linked list berantai ganda. untuk variabel data digunakan untuk menyimpan nilai atau data dari node. prev merupakan pointer yang menunjuk ke node sebelumnya dalam list. variabel next merupakan pointer yang menunjuk ke node berikutnya dalam list.

**Code 3**
```C++
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
```
kelas DoublyLinkedList mendefinisikan linked list berantai ganda. head merupakan pointer node pertama dalam linked list dan tail merupakan pointer node terakhir dalam linked list.

**Code 4**
```C++
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

```
kode diatas merupakan fungsi push. kode diatas juga menambahkan node baru di depan linked list. membuat node baru, mengatur data, dan memperbarui pointer prev dan next. jika list tidak kosong maka memperbarui prev dari node pertama, tetapi jika list kosong maka memperbarui tail dan mengatur node baru sebagai head.

**Code 5**
```C++
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
```
kode diatas digunakan untuk menghapus node pertama dari list. jika list kosong maka tidak melakukan apa apa, dan set node kedua sebagai head yang baru. tetapi jika daftar masih ada node maka putuskan node kedua dengan node pertama yang sebelumnya. lalu jika hanya ada satu node maka set tail ke nullptr, dan menghapus node pertama yang sebelumnya. 

**Code 6**
```C++
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
```
kode diatas menggunakan fungsi update untuk mengubdate data yang telah ada dimana mengubah data dalam node yang cocok dengan oldData menjadi newData. kode diatas juga melakukan pencarian node dengan data oldData, jika ditemukan maka memperbarui data dan mengembalikan true tetapi jika tidak ditemukan maka akan mengembalikan false.

**Code 7**
```C++
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
```
kode diatas menggunakan fungsi deletAll untuk menghapus semua node dari daftar. kode diatas juga melakukan iterasi melalui list dan menghapus setiap nodenya. setelah semua dihapus makan head dan tail diatur ke nullptr.

**Code 8**
```C++
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
```
Fungsi display digunakan untuk menampilkan data dari semua node dalam daftar. kode diatas juga melakukan iterasi melalui list dan mencetak data setiap nodenya.

**Code 9**
```C++
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
int main() merupakan fungsi utama berinteraksi dengan daftar berantai ganda melalui antarmuka pengguna berbasis teks. dimana dalam fungsi utama terdapat menu dengan 6 pilihan yaitu menambahkan data dengan fungsi push, menghapus data dengan fungsi pop, memperbarui data dengan fungsi update, menghapus semua data dengan fungsi deleteAll, menampilkan data dengan fungsi display, dan yang terakhir yaitu untuk keluar dari program. program mengambil pilihan pengguna dan memanggil metode yang sesuai dari objek DoublyLinkedList.

#### Output
```C++
1. Add data
2. Delete data
3. Update data
4. Clear data
5. Display data
6. Exit
Enter your choice: 1
Enter data to add: 11
1. Add data
2. Delete data
3. Update data
4. Clear data
5. Display data
6. Exit
Enter your choice: 1
Enter data to add: 20
1. Add data
2. Delete data
3. Update data
4. Clear data
5. Display data
6. Exit
Enter your choice: 1
Enter data to add: 21
1. Add data
2. Delete data
3. Update data
4. Clear data
5. Display data
6. Exit
Enter your choice: 1
Enter data to add: 30
1. Add data
2. Delete data
3. Update data
4. Clear data
5. Display data
6. Exit
Enter your choice: 5
30 21 20 11
1. Add data
2. Delete data
3. Update data
4. Clear data
5. Display data
6. Exit
Enter your choice: 4
1. Add data
2. Delete data
3. Update data
4. Clear data
5. Display data
6. Exit
Enter your choice: 5

1. Add data
2. Delete data
3. Update data
4. Clear data
5. Display data
6. Exit
Enter your choice: 6
```
Output diatas menampilkan menu dengan 6 pilihan. memilih nomor 1 untuk menginputkan data baru, inputkan data baru 11, 20, 21, dan 30. lalu pilih nomor 5 untuk menampilkan seluruh linked list. pilih nomor 4 untuk menghapus seluruh data dan pilih nomor 6 untuk keluar dari program.

#### Full Code Screenshoot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-6-Linked-List/blob/master/Modul%206%20Alstrukdat/Code%20Guided%202%20Linked%20List.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-6-Linked-List/blob/master/Output%20Modul%206%20Alstrukdat/Output%20Guided%202%20Linked%20List.png?raw=true)

## Unguided 

### 1. Soal mengenai Single Linked List
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
a.	Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.

[Nama_anda]	[Usia_anda]
John		     19
Jane		     20
Michael		     18
Yusuke		     19
Akechi		     20
Hoshino		     18
Karin		     18
b.	Hapus data Akechi
c.	Tambahkan data berikut diantara John dan Jane : Futaba	18
d.	Tambahkan data berikut diawal : Igor	20
e.	Ubah data Michael menjadi : Reyn	18
f.	Tampilkan seluruh data

```C++
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
```

**Code 1**
```C++
#include <iostream>
#include <iomanip> // Menambahkan library untuk manipulasi output
#include <string>

using namespace std;
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. include <iomanip> digunakan untuk manipulasi output seperti pengaturan lebar kolom dan penyelarasan teks. include string digunakan untuk manipulasi string yang lebih mudah dan efisien.
using namespace std digunakan untuk menggunakan namespace std. 

**Code 2**
```C++
struct Node 
{
    string nama;
    int usia;
    Node* next;
};
```
Node merupakan struktur data yang mewakili satu elemen dalam linked list. variabel nama digunakan untuk menyimpan nama, variabel usia digunakan untuk menyimpan usia. untuk next adalah pointer yang menunjuk ke node berikutnya dalam linked list.

**Code 3**
```C++
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
```
LinkedList adalah kelas yang akan mengatur operasi pada linked list. lalu untuk head merupakan pointer node pertama dalam linked list. LinkedList menginisialisasi head_2311110033 dengan nullptr dan mengisi linked list dengan beberapa data awal menggunakan insertDepan.

**Code 4**
```C++
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
  ```
kode diatas merupakan fungsi insertDepan dimana fungsi ini digunakan untuk menambahkan node baru di awal linked list. membuat node baru dengan data nama dan usia. jika linked list kosong maka head_2311110033 == nullptr, dan node baru akan menjadi head. jika tidak kosong maka node baru menunjuk ke head saat ini dan menjadi head yang baru. 

**Code 5**
```C++
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
```
fungsi insertBelakang digunakan untuk menambahkan node baru di akhir linked list. membuat node baru dengan data nama dan usia. jika linked list kosong maka node baru menjadi head, tetapi jika tidak kosong maka akan berjalan hingga node terakhir dan menambahkan node baru di akhir.

**Code 6**
```C++
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
```
fungsi insertTengah digunakan untuk menambahkan node baru di posisi tertentu dalam linked list. jika posisinya adalah 1 maka node baru akan ditambahkan di depan menggunakan fungsi insertDepan. tetapi jika tidak maka mencari node di posisi sebelum posisi yang diinginkan dan menyisipkan node baru di sana. apabila posisi melebihi panjang linked list maka akan menampilkan pesan "Posisi di luar batas."

**Code 7**
```C++
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
```
fungsi updateDepan digunakan untuk memperbarui data pada node yang memiliki nama tertentu. mencari node dengan nama yang sesuai. jika nama ditemukan maka akan mengubah nama dan usia node tersebut menjadi namabaru dan usiabaru, tetapi jika tidak ditemukan mana akan menampilkan pesan "Data tidak ditemukan."

**Code 8**
```C++
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
```
Fungsi hapusData digunakan untuk menghapus node yang memiliki nama tertentu. mencari node dengan nama yang sesuai. jika node yang dicari adalah head maka akan mengubah head menjadi node berikutnya. jika node yang dicari bukan head maka akan memperbarui pointer next dari node sebelumnya. ketika menghapus node maka akan menampilkan pesan "Data berhasil dihapis." jika tidak ditemukan maka akan menampilkan pesan "Data tidak ditemukan."

**Code 9**
```C++
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
```
fungsi display digunakan untuk menampilkan seluruh data dalam linked list. dengan menampilkan header tabel nama dan usia, mengiterasi seluruh node dalam linked list, dan menampilkan nama dan usia pada setiap nodenya.

**Code 10**
```C++
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
```
fungsi main merupakan fungsi utama dalam program. membuat objek LinkedList dan meyediakan input untuk pengguna memasukkan operasi pada linked list. pengguna dapat memilih operasi seperti menambahkan node di awal, akhir, dan tengah, mengupdate data, menghapus data, menampilkan data, dan keluar dari program.

#### Output:
```C++
Pilih operasi:
1. Insert Depan
2. Insert Belakang
3. Insert Tengah
4. Update Data
5. Hapus Data
6. Tampilkan Data
7. Keluar
Masukkan pilihan Anda: 5
Masukkan data yang ingin dihapus: Akechi
Data berhasil dihapus.
Pilih operasi:
1. Insert Depan
2. Insert Belakang
3. Insert Tengah
4. Update Data
5. Hapus Data
6. Tampilkan Data
7. Keluar
Masukkan pilihan Anda: 3
Masukkan nama: Futaba 
Masukkan usia: 18
Masukkan posisi: 2
Pilih operasi:
1. Insert Depan
2. Insert Belakang
3. Insert Tengah
4. Update Data
5. Hapus Data
6. Tampilkan Data
7. Keluar
Masukkan pilihan Anda: 1
Masukkan nama: Igor
Masukkan usia: 20
Pilih operasi:
1. Insert Depan
2. Insert Belakang
3. Insert Tengah
4. Update Data
5. Hapus Data
6. Tampilkan Data
7. Keluar
Masukkan pilihan Anda: 4
Masukkan nama lama: Michael
Masukkan nama baru: Reyn
Masukkan usia baru: 18
Pilih operasi:
1. Insert Depan
2. Insert Belakang
3. Insert Tengah
4. Update Data
5. Hapus Data
6. Tampilkan Data
7. Keluar
Masukkan pilihan Anda: 6
Nama                Usia
Igor                20
John                19
Futaba              18
Jane                20
Reyn                18
Yusuke              19
Hoshino             18
Karin               18
Pilih operasi:
1. Insert Depan
2. Insert Belakang
3. Insert Tengah
4. Update Data
5. Hapus Data
6. Tampilkan Data
7. Keluar
Masukkan pilihan Anda: 7
```
output diatas adalah menampilkan pilihan yang akan dipilih oleh pengguna untuk menambahkan nama di depan, belakang atau di posisi tertentu, menghapus data, mengupdate data, dan menampilkan data yang telah diinputkan oleh pengguna.

#### Full code Screenshot:
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-6-Linked-List/blob/master/Modul%206%20Alstrukdat/Code%20Unguided%201%20Linked%20List.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-6-Linked-List/blob/master/Output%20Modul%206%20Alstrukdat/Output%20Unguided%201%20Linked%20List%20(1).png?raw=true)

![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-6-Linked-List/blob/master/Output%20Modul%206%20Alstrukdat/Output%20Unguided%201%20Linked%20List%20(2).png?raw=true)

![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-6-Linked-List/blob/master/Output%20Modul%206%20Alstrukdat/Output%20Unguided%201%20Linked%20List%20(3).png?raw=true)

### 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
Nama Produk	Harga
Originote	60.000
Somethinc	150.000
Skintific	100.000
Wardah	50.000
Hanasui	30.000

Case:
1.	Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
2.	Hapus produk wardah
3.	Update produk Hanasui menjadi Cleora dengan harga 55.000
4.	Tampilkan menu seperti dibawah ini
Toko Skincare Purwokerto
1.	Tambah Data
2.	Hapus Data
3.	Update Data
4.	Tambah Data Urutan Tertentu
5.	Hapus Data Urutan Tertentu
6.	Hapus Seluruh Data
7.	Tampilkan Data
8.	Exit
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :

Nama Produk	Harga
Originote	60.000
Somethinc	150.000
Azarine	65.000
Skintific	100.000
Cleora	55.000

```C++
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
```

**Code 1**
```C++
#include <iostream>
#include <iomanip>
using namespace std;
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. include <iomanip> digunakan untuk manipulasi output seperti pengaturan lebar kolom dan penyelarasan teks.
using namespace std digunakan untuk menggunakan namespace std. 

**Code 2**
```C++
class Node {
public:
    string namaProduk_2311110033;
    int harga;
    Node* prev;
    Node* next;
};
```
kelas node merepresentasikan satu elemen dalam doubly linked list. setiap node memiliki atribut namaProduk_2311110033 untuk menyimpan nama produk, variabel harga digunakan untuk menyimpan harga produk, dan pointer prev dan next digunakan untuk menunjuk ke node sebelumnya dan node berikutnya.

**Code 3**
```C++
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
```
kelas DoublyLinkedList merepresentasikan seluruh linked list. head merupakan node pertama dalam list, sedangkan tail merupakan node terakhir dalam list. head dan tail diinisialisasi dengan nullptr.

**Code 4**
```C++
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
```
fungsi push digunakan untuk menambahkan node baru di depan linked list. node baru yang ditambahkan akan menjadi head baru. jika list awalnya kosong maka tail juga diatur ke node baru yang ditambahkan.

**Code 5**
```C++
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
```
fungsi pop digunakan untuk menghapus node pertama dalam linked list (head). jika list kosong maka akan menampilkan pesan bahwa tidak ada yang bisa dihapus.

**Code 6**
```C++
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
```
fungsi update digunakan untuk memperbarui data produk yang sesuai dengan oldNama dengan nama dan harga yang baru (newNama dan newHarga). mengembalikan true jika berhasil, dan mengembalikan false jika data tidak ditemukan.

**Code 7**
```C++
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
```
fungsi deleteAll digunakan untuk menghapus seluruh node dalam linked list, mengosongkan list sepenuhnya.

**Code 8**
```C++
    void display() {
        Node* current = head;
        cout << left << setw(20) << "Nama Produk" << "Harga" << endl;
        while (current != nullptr) {
            cout << left << setw(20) << current->namaProduk_2311110033 << current->harga << endl;
            current = current->next;
        }
    }
```
Fungsi display digunakan untuk menampilkan semua data produk dalam linked list dalam format tabel.

**Code 9**
```C++
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
```
fungsi insertAt digunakan untuk menambahkan node baru di posisi tertentu dalam linked list. jika posisi adalah 1 maka node baru ditambahkan di depan menggunakan push.

**Code 10**
```C++
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
```
fungsi deleteAt digunakan untuk menghapus node pada posisi tertentu dalam linked list.

**Code 11**
```C++
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
```
fungsi remove digunakan untuk menghapus node dengan nama produk tertentu dalam linked list.

**Code 12**
```C++
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
```
fungsi main merupakan fungsi utama yang dimana mengelola interaksi dengan pengguna melalui menu untuk menambah, menghapus, memperbarui, dan menampilkan data produk. dalam program memasukkan data pertama pada DoublyLinkedList list. membuat menu dimana case 1 adalah memasukkan produk baru diawal linked list menggunakan fungsi push, case 2 adalah menghapus produk berdasarkan nama produk dengan fungsi remove, case 3 adalah memperbarui nama dan harga produk berdasarkan nama produk lama dengan fungsi update, case 4 adalah  menambahkan produk baru pada posisi tertentu dalam linked list dengan menggunakan fungsi insertAt, case 5 adalah menampilkan semua prouk yang ada dalam linked list dengan menggunakan fungsi display menghapus produk pada posisi tertentu dalam linked list dengan menggunakan fungsi deleteAt, case 6 adalah menghapus seluruh node dari linked list dengan menggunakan fungsi deleteAll, case 7 menampilkan semua prouk yang ada dalam linked list dengan menggunakan fungsi display, dan case 8 untuk keluar dari program. 

#### Output:
```C++
Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
Masukkan pilihan Anda: 4
Masukkan nama produk: Azarine
Masukkan harga: 65000
Masukkan posisi: 3
Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
Masukkan pilihan Anda: 2
Masukkan nama produk: Wardah
Produk berhasil dihapus.
Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
Masukkan pilihan Anda: 3
Masukkan nama produk lama: Hanasui
Masukkan nama produk baru: Cleora
Masukkan harga baru: 55000
Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
Masukkan pilihan Anda: 7
Nama Produk         Harga
Originote           60000
Somethinc           150000
Azarine             65000
Skintific           100000
Cleora              55000
Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
Masukkan pilihan Anda: 8
```
output diatas adalah menampilkan pilihan yang akan dipilih oleh pengguna untuk menambahkan data produk, menghapus data produk, mengupdate data produk, menambahkan produk di urutan tertentu, menghapus produk di urutan tertentu, menghapus seluruh data, dan menampilkan data.

#### Full code Screenshot:
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-6-Linked-List/blob/master/Modul%206%20Alstrukdat/Code%20Unguided%202%20Linked%20List.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-6-Linked-List/blob/master/Output%20Modul%206%20Alstrukdat/Output%20Unguided%202%20Linked%20List%20(1).png?raw=true)

![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-6-Linked-List/blob/master/Output%20Modul%206%20Alstrukdat/Output%20Unguided%202%20Linked%20List%20(2).png?raw=true)

![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-6-Linked-List/blob/master/Output%20Modul%206%20Alstrukdat/Output%20Unguided%202%20Linked%20List%20(3).png?raw=true)

## Kesimpulan
Linked list adalah bentuk struktur yang berisi kumpulan data yang disebut sebagai node. linked list terbagi menjadi dua yaitu single linked list dan double linked list. linked list dapat digunakan untuk membuat program seperti program daftar nama dan usia, dan program daftar produk dan harganya. dalam linked list terdapat head dan tail, head adalah pointer yang menunjuk pada node pertama dalam linked list sedangkan tail adalah pinter yang menunjuk pada node paling akhir dalam linked list.

## Referensi
[1]	A. Lattuada et al., “Verus: Verifying Rust Programs using Linear Ghost Types,” Proc. ACM Program. Lang., vol. 7, no. OOPSLA1, 2023, doi: 10.1145/3586037.
