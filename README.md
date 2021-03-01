# Tugas Kecil 2 IF 2211 Strategi Algoritma 2021


## Algortima Decrease and Concquer
Pada program ini, algoritma decrease and conquer yang digunakan sebagai berikut.
* Pembacaan file input
1. Membaca nama matakuliah utama, yaitu matakuliah yang membutuhkan prerequisite, kemudian disimpan dalam suatu variabel dan disimpan dalam list matakuliah
2. Membaca nama matakuliah prerequisite, kemudian jika matakuliah tersebut belum terdapat dalam list matakuliah, disimpan di dalam list matakuliah
3. Matakuliah utama dengan matakuliah prerequisite akan dimasukkan ke dalam list prerequisite sebagai pasangan matakuliah utama dengan prerequisitenya
4. Ulangi no 2 dan 3 sehingga prerequisite untuk matakuliah utama tersebut sudah terdaftar di dalam list prerequisite
5. Ulaingi no 1 hingga no 4 sehingga semua matakuliah dengan prerequisitenya sudah terdaftar di dalam list matakuliah dan prerequisite

* Penentuan matakuliah
1. Program akan mencari matakuliah yang tidak memiliki prerequisite atau pasangan prerequisitenya bernilai (NULL)
2. Program akan menampilkan matakuliah tersebut pada layar
3. Program akan menghapus pasangan matakuliah dengan prerequisitenya tersebut dari list prerequisite
4. Program akan menghapus matakuliah tersebut dari list matakuliah sehingga prerequisite matakuliah lain yang memiliki prerequisite matakuliah tersebut akan bernilai NULL
5. Program akan mengulang dari no 1 hingga no 3 sehingga list matakuliah dan prerequisite akan kembali kosong
6. Program selesai

## Requirement Program
* Program menggunakan bahasa C
* Pengguna perlu menginstalasi bahasa C terlebih dahulu pada device pengguna

## Penggunaan Program
1. Clone repository pada device Anda
2. Buatlah file testing (.txt) yang berisi test case program
3. Simpan file testing tersebut dalam folder test pada repository
4. Bukalah folder src, kemudian bukalah file main13519217.c
5. Pada line 13, ubahlah nilai 'test1.txt' pada variabel 'file' dengan nama file testing yang telah dibuat sebelumnya
6. Save file main13519217.c tersebut
7. Compile dengan gcc src/modul13519217.c src/main13519217.c -o bin/13519217.exe
8. Kembali ke repository utama, buka folder bin, jalankan 13519217.exe

## Author
- Hughie Alghaniyyu Emiliano
- NIM 13519217
- Kelas 04
