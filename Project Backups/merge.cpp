#include <stdio.h>
 
void MergeArray(int A[], int m, int n, int p){
    int i = m, j = n + 1;
    while(i < j && j <= p) {
        if (A[i] <= A[j] ) i++;
        else {
            int x = A[j];
            for (int k = j - 1; k >= i; k--)
            A[k + 1] = A[k];
            A[i] = x;
            i++;
            j++;
        }
    }
}
 
int main() {
    int m, n;
 
    printf("Nhap so luong phan tu mang 1: ");
    scanf("%d", &m);
    int a[m];
 
    printf("Nhap cac phan tu cho mang 1: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
   
    printf("Nhap so luong phan tu mang 2: ");
    scanf("%d", &n);
    int b[n];
 
    printf("Nhap cac phan tu cho mang 2: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
 
    int c[m + n];
    int i = 0, j = 0, k = 0;
 
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
 
    while (i < m) {
        c[k++] = a[i++];
    }
 
    while (j < n) {
        c[k++] = b[j++];
    }
 
    MergeArray(c, m, n, k);
 
    printf("Mang da sap xep: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", c[i]);
    }
    return 0;
}