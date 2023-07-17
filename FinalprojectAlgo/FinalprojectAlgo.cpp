#include <iostream>
#include <string>
using namespace std;

const int MAX_MAHASISWA = 100;

int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];

int jumlahMahasiswa = 0;

void tambahMahasiswa() {
    if (jumlahMahasiswa < MAX_MAHASISWA) {
        cout << "========== TAMBAH MAHASISWA ==========" << endl;
        cout << "NIM        : ";
        cin >> NIM[jumlahMahasiswa];
        cin.ignore();
        cout << "Nama       : ";
        getline(cin, nama[jumlahMahasiswa]);
        cout << "Tahun Masuk: ";
        cin >> tahunMasuk[jumlahMahasiswa];
        cin.ignore();

        jumlahMahasiswa++;
        cout << "Mahasiswa berhasil ditambahkan!" << endl;
    }
    else {
        cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
    }
}

void tampilkanSemuaMahasiswa() {
    if (jumlahMahasiswa == 0) {
        cout << "Tidak ada data mahasiswa." << endl;
        return;
    }

    cout << "========== SEMUA MAHASISWA ==========" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Mahasiswa " << i + 1 << ":" << endl;
        cout << "NIM        : " << NIM[i] << endl;
        cout << "Nama       : " << nama[i] << endl;
        cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
        cout << endl;
    }
}

void algoritmacariMahasiswaByNIM() {
    int nimCari;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> nimCari;

    bool ditemukan = false;
    cout << "========== HASIL PENCARIAN ==========" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (NIM[i] == nimCari) {
            cout << "NIM        : " << NIM[i] << endl;
            cout << "Nama       : " << nama[i] << endl;
            cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
            cout << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan." << endl;
    }
}

void algoritmaSortByTahunMasuk() {
    for (int i = 0; i < jumlahMahasiswa - 1; i++) {
        for (int j = 0; j < jumlahMahasiswa - i - 1; j++) {
            if (tahunMasuk[j] > tahunMasuk[j + 1]) {
                swap(NIM[j], NIM[j + 1]);
                swap(nama[j], nama[j + 1]);
                swap(tahunMasuk[j], tahunMasuk[j + 1]);
            }
        }
    }

    cout << "========== MAHASISWA BERDASARKAN TAHUN MASUK ==========" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Mahasiswa " << i + 1 << ":" << endl;
        cout << "NIM        : " << NIM[i] << endl;
        cout << "Nama       : " << nama[i] << endl;
        cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
        cout << endl;
    }
}

int main() {
    int pilihan;
    do {
        cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Mahasiswa" << endl;
        cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
        cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            tambahMahasiswa();
            break;
        case 2:
            tampilkanSemuaMahasiswa();
            break;
        case 3:
            algoritmacariMahasiswaByNIM();
            break;
        case 4:
            algoritmaSortByTahunMasuk();
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        cout << endl;
    } while (pilihan != 5);

    return 0;
}



/*2.Berdasarkan studi kasus diatas, algoritma apa saja yang anda gunakan?

BubbleSort
Insertion Sort


/*3. Jelaskan perbedaan mendasar antara algorithma stack dan queue?

Stack adalah struktur data linear yang mengikuti konsep Last - In - First - Out(LIFO), yang berarti elemen terakhir yang dimasukkan ke dalam stack akan menjadi elemen pertama yang dihapus dari stack.
Queue adalah struktur data linear yang mengikuti konsep First - In - First - Out(FIFO), yang berarti elemen pertama yang dimasukkan ke dalam queue akan menjadi elemen pertama yang dihapus dari queue.
Dalam stack, operasi penambahan elemen disebut "push", dan operasi penghapusan elemen disebut "pop".Elemen yang terakhir ditambahkan ke dalam stack akan menjadi elemen yang pertama dihapus.
Dalam queue, operasi penambahan elemen disebut "enqueue", dan operasi penghapusan elemen disebut "dequeue".Elemen yang pertama ditambahkan ke dalam queue akan menjadi elemen yang pertama dihapus.



/*4. Jelaskan pada saat bagaimana harus menggunakan algoritma stack?

Algoritma stack digunakan ketika kita ingin mengelola data dengan konsep Last - In - First - Out(LIFO).Berikut adalah beberapa situasi di mana algoritma stack cocok digunakan :

Reversal: Ketika kita perlu membalik urutan elemen dalam suatu struktur data.Misalnya, kita ingin membalik urutan karakter dalam suatu kata atau membalik urutan elemen dalam suatu array.
Pemanggilan fungsi : Ketika kita menggunakan rekursi atau pemanggilan fungsi secara berlapis.Setiap kali fungsi dipanggil, konteksnya disimpan dalam stack.Ketika fungsi selesai dieksekusi, konteksnya dihapus dari stack dan kembali ke fungsi sebelumnya.
Evaluasi ekspresi : Ketika kita perlu mengevaluasi ekspresi matematika yang menggunakan notasi postfix atau infix.Dalam hal ini, stack digunakan untuk menyimpan operator dan operand sementara selama evaluasi.
Manajemen memori : Ketika kita perlu mengalokasikan dan menghapus memori dalam urutan yang terbalik.Misalnya, ketika kita menggunakan alokasi memori dinamis, data yang dialokasikan akan disimpan dalam stack.Ketika memori tersebut tidak lagi diperlukan, data akan dihapus dari stack.
Pencarian backtracking : Ketika kita melakukan pencarian dengan strategi backtracking, stack digunakan untuk menyimpan status saat ini atau langkah - langkah yang diambil, sehingga kita dapat kembali ke langkah sebelumnya jika diperlukan.*/

