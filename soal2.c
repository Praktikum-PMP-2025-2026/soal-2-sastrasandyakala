#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mendefinisikan tipe data bentukan (struct) untuk Meteorit
typedef struct {
    char nama[100]; // string tanpa spasi
    int massa;      // integer
    int kemurnian;  // integer
} Meteorit;

// Fungsi komparator untuk digunakan dalam qsort
int compare(const void *a, const void *b) {
    Meteorit *m1 = (Meteorit *)a;
    Meteorit *m2 = (Meteorit *)b;

    // 1. Prioritas Utama: Kemurnian lebih tinggi lebih baik (Descending)
    if (m1->kemurnian != m2->kemurnian) {
        return m2->kemurnian - m1->kemurnian;
    }
    
    // 2. Prioritas Kedua: Jika kemurnian sama, massa lebih kecil lebih baik (Ascending)
    if (m1->massa != m2->massa) {
        return m1->massa - m2->massa;
    }
    
    // 3. Prioritas Ketiga: Jika kemurnian dan massa sama, nama secara alfabetis (Ascending)
    return strcmp(m1->nama, m2->nama);
}

int main() {
    int n;
    
    // Membaca jumlah data (N)
    if (scanf("%d", &n) != 1) return 1;

    // Menangani kasus jika N adalah 0
    if (n <= 0) return 0;
    
    // Mengalokasikan memori dinamis untuk array struct Meteorit
    Meteorit *arr = (Meteorit *)malloc(n * sizeof(Meteorit));
    if (arr == NULL) {
        return 1;
    }
    
    // Membaca setiap data meteorit sesuai format: nama massa kemurnian
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", arr[i].nama, &arr[i].massa, &arr[i].kemurnian);
    }
    
    // Mengurutkan data menggunakan Quick Sort bawaan C
    qsort(arr, n, sizeof(Meteorit), compare);
    
    // Menentukan batas output (Maksimal 3 data teratas. Jika N < 3, cetak semua)
    int limit = (n < 3) ? n : 3;
    
    // Mencetak hasil kandidat terbaik
    for (int i = 0; i < limit; i++) {
        printf("%s %d %d\n", arr[i].nama, arr[i].massa, arr[i].kemurnian);
    }
    
    // Membebaskan memori dinamis
    free(arr);
    
    return 0;
}
