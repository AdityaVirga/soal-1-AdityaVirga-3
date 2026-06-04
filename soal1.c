#include <stdio.h>
#include <stdbool.h>

// Fungsi cek tangga rusak 
bool is_broken(int tangga, int tangga_rusak[], int R) {
    for (int i = 0; i < R; i++) {
        if (tangga_rusak[i] == tangga) {
            return true;
        }
    }
    return false;
}

// Rekursif hitung jalur
int count_ways(int n, int tangga_rusak[], int R) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (is_broken(n, tangga_rusak, R)) return 0;

    return count_ways(n - 1, tangga_rusak, R) + count_ways(n - 2, tangga_rusak, R);
}

int main() {
    int N, R;
    if (scanf("%d %d", &N, &R) != 2) return 0;

    int tangga_rusak[R];
    
    for (int i = 0; i < R; i++) {
        scanf("%d", &tangga_rusak[i]);
    }

    int ways = count_ways(N, tangga_rusak, R);
    printf("%d\n", ways);

    return 0;
}
