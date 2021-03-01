#include "modul13519217.h"
#include "boolean13519217.h"

// KAMUS
Matakuliah L1;
Prerequisite L2;
addressM M;
addressP P;
int semester = 0;

int main() {
    // Directory file
    char* file = "..\\test\\test1.txt";

    // Membaca file
    FILE* pFile = fopen(file, "r");

    // Jika file tidak ditemukan
    if (pFile == NULL) {
        printf("Error : File tidak dapat ditemukan!\n");
        // Keluar dari program
        exit(1);
    }
    // Memasukkan semua data input kedalam list matakuliah dan prerequisite
    input(pFile, L1, L2);
    
    // Memulai pencarian mata kuliah yang tepat
    // untuk setiap semester
    while (semester <= 8) {
        semester += 1;
        // Jika semua matakuliah sudah diambil
        if (First(L1) == NULL) {
            exit(1);
        }
        // Matakuliah masih tersedia
        else {
            // Mencari matakuliah yang tepat
            P = FindP(L1, L2);
            printf("Semester %d : ", semester);
            while (P != NULL) {
                // Print nama matakuliah yang tepat
                printf("%s ", semester, matkul(source(P)));
                DeleteP(L2, matkul(source(P)));
            }
                DeleteM(L1, matkul(source(P)));
            // Print next line
            printf("\n");
        } 
    }
}