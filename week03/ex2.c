#include <stdio.h>

void bubble_sort(int a[], int n){
    for (int i = 0; i < n - 1; ++i){
        for (int j = 0; j < n - i - 1; ++j){
            if (a[j] > a[j + 1]){
                int x = a[j];
                a[j] = a[j + 1];
                a[j + 1] = x;
            }
        }
    }
}

int main() {
    int n;
    int a[10001];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    bubble_sort(a, n);
    for (int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
    return 0;
}