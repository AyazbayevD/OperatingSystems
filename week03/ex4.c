#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quick_sort(int a[], int l, int r){
    if (l >= r) return; //this kinds of intervals are already sorter, no need to consider them
    int rand_index = rand() % (r - l + 1) + l; //picking random index from our interval
    int rnd_num = a[rand_index]; //extracting the number from this random index

    //placing all numbers less or equal than "rnd_num" to the left of the array
    int numbers_moved = 0;
    for (int i = l; i <= r; ++i){
        if (a[i] <= rnd_num){
            int x = a[i];
            a[i] = a[l + numbers_moved];
            a[l + numbers_moved] = x;
            numbers_moved++;
        }
    }

    //"rnd_num" should be placed on top of numbers than are less than "rnd_num"
    for (int i = l; i <= r; ++i){
        if (a[i] == rnd_num){
            a[i] = a[l + numbers_moved - 1];
            a[l + numbers_moved - 1] = rnd_num;
            break;
        }
    }

    //dividing into two intervals, numbers placed before "rnd_num"
    quick_sort(a, l, l + numbers_moved - 2);

    //numbers placed after "rnd_num"
    quick_sort(a, l + numbers_moved, r);
}

int main() {
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
    return 0;
}