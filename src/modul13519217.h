#ifndef modul13519217_H
#define modul13519217_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define kode(P) (P)->kode
#define matkul(P) (P)->matkul
#define next(P) (P)->next
#define data(P) (P)->data
#define source(P) (P)->source
#define need(P) (P)->need
#define First(L) (L).First

// Address Mata Kuliah
typedef struct AdrMatkul *addressM;

// Address Prerequisite
typedef struct AdrPrereq *addressP;

// Struct Matakuliah
typedef struct AdrMatkul {
    int kode;
    char matkul[10];
    addressM next;
} ElmtMatkul;

// Struct Prerequisite
typedef struct AdrPrereq {
    int data;
    addressM source;
    addressM need;
    addressP next;
} ElmtPrereq;

// List Matakuliah
typedef struct {
    addressM First;
} Matakuliah;

// List Prerequisite
typedef struct {
    addressP First;
} Prerequisite;

// Alokasi Matakuliah
addressM AlokasiM (Matakuliah L, int X, char X1[]);

// Alokasi Prerequistie
addressP AlokasiP (Matakuliah L, int X, char X1[], char X2[]);

// Dealokasi Matakuliah
void DealokasiM (addressM *P);

// Dealokasi Prerequisite
void DealokasiP (addressP *P);

// Search Kode
addressM SearchKode (Matakuliah L, int X);

// Search Matakuliah
addressM SearchMatkul (Matakuliah L, char X[]);

// Search Prerequisite
addressP SearchPrereq (Matakuliah L1, Prerequisite L2, char X[]);

// Add Matakuliah
void InsVLastM (Matakuliah *L, int X, char X1[]);

// Add Prereq
void InsVLastP (Matakuliah L1, Prerequisite *L2, int X, char X1[], char X2[]);

// Fungsi untuk membaca mata kuliah dengan prerequisitenya
// Kemudian, memasukkannya ke dalam graf
void input(FILE *ptr, Matakuliah L1, Prerequisite L2);

// Menghapus matakuliah dari list
void DeleteM (Matakuliah L, char X[]);

// Menghapus keterangan prerequisite dari list
void DeleteP (Prerequisite L, char X[]);

// Mencari matakuliah yang tidak memiliki prerequisite
// atau
// Mencari matakuliah yang prerequisitenya sudah dipenuhi
addressP FindP (Matakuliah L1, Prerequisite L2);
#endif