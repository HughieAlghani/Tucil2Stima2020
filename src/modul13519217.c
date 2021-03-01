#include "modul13519217.h"
#include "boolean13519217.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alokasi Matakuliah
addressM AlokasiM (Matakuliah L, int X, char X1[]) {
    addressM P;
    P = SearchKode(L, X);
    // Jika matakuliah sudah pernah dialokasi
    if (P != NULL) {
        return P;
    }
    // Jika mata kuliah belum dialokasi
    else {
        // Membuat alokasi baru
        P = (addressM) malloc (sizeof (X));
        if (P == NULL) {
            return P;
        }
        else {
            kode(P) = X;
            strcpy(matkul(P), X1);
            next(P) = NULL;
            return P;
        }
    }
}

// Alokasi Prerequistie
addressP AlokasiP (Matakuliah L, int X, char X1[], char X2[]) {
    addressP P;
    P = (addressP) malloc (sizeof (X));
    if (P == NULL) {
        return P;
    }
    else {
        data(P) = X;
        source(P) = SearchMatkul(L, X1);
        need(P) = SearchMatkul(L, X2);
        next(P) = NULL;
        return P;
    }
}

// Dealokasi Matakuliah
void DealokasiM (addressM *P) {
    next(*P) = NULL;
    free (*P);
}

// Dealokasi Prerequisite
void DealokasiP (addressP *P) {
    next(*P) = NULL;
    free (*P);
}

// Search Kode Matakuliah
addressM SearchKode (Matakuliah L, int X) {
    addressM P;
    P = First(L);
    while (P != NULL) {
        if (kode(P) == X) {
            return P;
        }
        else {
            P = next(P);
        }
    }
    return P;
}

// Search Matakuliah
addressM SearchMatkul (Matakuliah L, char X[]) {
    addressM P;
    P = First(L);
    while (P != NULL) {
        if ((strcmp(matkul(P), X)) == 0) {
            return P;
        }
        else {
            P = next(P);
        }
    }
    return P;
}

// Search Prerequisite
addressP SearchPrereq (Matakuliah L1, Prerequisite L2, char X[]) {
    addressP P, Pc;
    addressM M;
    M = SearchMatkul(L1, X);
    P = First(L2);
    while (P != NULL) {
        if (M == need(P)) {
            break;
        }
    }
    return Pc;
}

// Add Matakuliah
void InsVLastM (Matakuliah * L, int X, char X1[]) {
    // Cek apakah sudah ada di dalam list
    addressM P = SearchKode(*L, X);
    // Jika belum ada
    if (P == NULL) {
        // Membuat alokasi baru untuk matakuliah X1
        addressM P = AlokasiM(*L, X, X1);
        if (P != NULL) {
            // Jika list masih kosong
            if (First(*L) == NULL) {
                First(*L) = P;
            }
            // Jika list tidak kosong
            else {
                addressM Pc = First(*L);
                while (next(Pc) != NULL) {
                    Pc = next(Pc);
                }
                next(Pc) = P;
            }
        }
    }
}

// Add Prereq
void InsVLastP (Matakuliah L1, Prerequisite * L2, int X, char X1[], char X2[]) {
    // Membuat alokasi baru untuk keterangan matakuliah X1 dengan prereq X2
    addressP P = AlokasiP(L1, X, X1, X2);
    if (P != NULL) {
        // Jika list prereq masih kosong 
        if (First(*L2) == NULL) {
            First(*L2) = P;
        }
        // Jika list prereq tidak kosong
        else {
            addressP Pc = First(*L2);
            while (next(Pc) != NULL) {
                Pc = next(Pc);
            }
            next(Pc) = P;
        }
    }
}

// Fungsi untuk membaca mata kuliah dengan prerequisitenya
// Kemudian, memasukkannya ke dalam list
void input(FILE *ptr, Matakuliah L1, Prerequisite L2) {
    // Kamus
    char CC, sisa[255], kosong[10], hasilbaca[10], matkulsource[10];
    int i, data, kode;
    boolean mksource;

    // Keterangan data matakuliah dengan prerequisitenya pada list
    data = 1;
    // Keterangan kode matakuliah pada list
    kode = 1;
    // Membaca file
    CC = fgetc(ptr);
    // Iterasi hingga 'End of File'
    while (CC != EOF) {
        i = 0;
        // Menggabungkan karakter-karakter yang dibaca
        // Menjadi nama suatu matakuliah
        hasilbaca[i] = CC; i++;
        CC = fgetc(ptr);
        // Iterasi hingga 'End of Line'
        // Ket : Titik menjadi mark setiap baris
        while (CC != '.') {
            // Mereset nama matakuliah utama setelah disimpan pada list
            strcpy(matkulsource, kosong);
            // Menandakan matakuliah utama belum didapatkan
            mksource = false;
            // Proses mengambil nama matakuliah utama
            // Iterasi hingga matakuliah utama sudah didapatkan
            while (!mksource) {
                hasilbaca[i] = CC; i++;
                CC = fgetc(ptr);
                // Iterasi hingga didapatkan nama mata kuliah utama
                // Ket : Koma menjadi mark pergantian nama mata kuliah
                if (CC == ',') {
                    // Men-skip karakter koma(',') dan spasi(' ')
                    CC = fgetc(ptr);
                    CC = fgetc(ptr);
                    // Memindahkan nama matakuliah yang berhasil dibaca
                    // ke variabel matakuliah utama
                    strcpy(matkulsource,hasilbaca);
                    // Memasukkan nama matakuliah utama ke dalam list matakuliah
                    InsVLastM(&L1, kode, matkulsource); kode++;
                    // Mengosongkan variabel hasil pembacaan nama matakuliah
                    strcpy(hasilbaca, kosong);
                    // Matakuliah utama sudah didapatkan
                    mksource = true;
                    i = 0;
                }
                // Kasus matakuliah tanpa prerequisite
                if (CC == '.') {
                    // Untuk pindah ke nextline
                    fgets(sisa, 255, ptr);
                    // Membaca karakter nama matakuliah selanjutnya
                    CC = fgetc(ptr);
                    // Memindahkan nama matakuliah yang berhasil dibaca
                    // ke variabel matakuliah utama
                    strcpy(matkulsource,hasilbaca);
                    // Memasukkan nama matakuliah utama ke dalam list matakuliah
                    InsVLastM(&L1, kode, matkulsource); kode++;
                    // Memasukkan keterangan matakuliah tanpa prerequisite ke dalam list prerequisite
                    InsVLastP(L1, &L2, data, matkulsource, NULL); data++;
                    // Mengosongkan variabel hasil pembacaan nama mata kuliah
                    strcpy(hasilbaca, kosong);
                    // Mengosongkan variabel nama matakuliah utama yang didapatkan
                    strcpy(matkulsource, kosong);
                    i = 0;
                }
            }
            // Proses pemngambilan kebutuhan prerequisite matakuliah utama
            while ((CC != ',') && (mksource)) {
                // Pembacaan nama matakuliah prerequisite
                hasilbaca[i] = CC; i++;
                CC = fgetc(ptr);
                // Prerequisite sudah didapatkan
                // Masih ada prerequisite
                if (CC == ',') {
                    // Men-skip karakter koma(',') dan spasi(' ')
                    CC = fgetc(ptr);
                    CC = fgetc(ptr);
                    // Memasukan nama matakuliah prerequsiite ke dalam list matakuliah
                    InsVLastM(&L1, kode, hasilbaca); kode++;
                    // Memasukkan keterangan nama matakuliah utama dengan prerequisitenya
                    // ke dalam list prerequisite
                    InsVLastP(L1, &L2, data, matkulsource, hasilbaca); data++;
                    // Mengosongkan variabel hasil pembacaan nama matakuliah
                    strcpy(hasilbaca, kosong);
                    i = 0;
                }
                // Prerequisite sudah didapatkan
                // Tidak ada prerequisite yang harus dibaca lagi
                if (CC == '.') {
                    // Untuk ke next line
                    fgets(sisa, 255, ptr);
                    // Membaca karakter selanjutnya
                    CC = fgetc(ptr);
                    // Memasukan nama matakuliah prerequsiite ke dalam list matakuliah
                    InsVLastM(&L1, kode, hasilbaca); kode++;
                    // Memasukkan keterangan nama matakuliah utama dengan prerequisitenya
                    // ke dalam list prerequisite
                    InsVLastP(L1, &L2, data, matkulsource, hasilbaca); data++;
                    // Mengosongkan variabel hasil pembacaan nama matakuliah
                    strcpy(hasilbaca, kosong);
                    // Mengosongkan variabel matakuliah utama
                    strcpy(matkulsource,kosong);
                    i = 0;
                    // Matakuliah utama perlu dicari kembali
                    mksource = false;
                }
            }
        }
    }
}

// Menghapus matakuliah dari list
void DeleteM (Matakuliah L, char X[]) {
    addressM P, Pc;
    P = First(L);
    if (strcmp(matkul(P), X) == 0) {
        First(L) = next(P);
        DealokasiM(&P);
    }
    else {
        while (strcmp(matkul(P), X) != 0) {
            Pc = P;
            P = next(P);
        }
        next(Pc) = next(P);
        DealokasiM(&P);
    }
}

// Menghapus keterangan prerequisite dari list
void DeleteP (Prerequisite L, char X[]) {
    addressP P, Pc;
    char subject[10];
    P = First(L);
    if (strcmp(matkul(source(P)), X) == 0) {
        First(L) = next(P);
        DealokasiP(&P);
    }
    Pc = P;
    P = next(P);
    while (P != NULL) {
        if (strcmp(matkul(source(P)),X) == 0) {
            next(Pc) = next(P);
            DealokasiP(&P);
        }
        Pc = P;
        P = next(P);
    }
}

// Mencari matakuliah yang tidak memiliki prerequisite
// atau
// Mencari matakuliah yang prerequisitenya sudah dipenuhi
addressP FindP (Matakuliah L1, Prerequisite L2) {
    return SearchPrereq(L1, L2, NULL);
}