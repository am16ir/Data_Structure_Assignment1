#include <iostream>
using namespace std;

int comparisons = 0, swaps = 0;

void BubbleSort(int arr[], int last) {
    for (int i = 0; i < last; i++) {
        for (int j = last; j > i; j--) {
            comparisons++;
            if (arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                swaps++;
            }
        }
    }
}

void SelectionSort(int arr[], int first, int last) {
    for (int i = first; i <= last; i++) {
        int max = i;
        for (int j = i+1; j <= last; j++) {
            comparisons++;
            if (arr[max] < arr[j]) {
                max = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        swaps++;
    }
}

void Bitonic_Sort(int arr[], int n) {
    BubbleSort(arr, n/2);
    SelectionSort(arr, (n/2)+1, n-1);
}

int Search(int arr[],int n, int val) {
    for (int i=0; i<n ; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

int main() {

    int arr[] = {8, 1, 4, 12, 6, 3, 7, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Bitonic_Sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n-1) cout << ", ";
    }
    cout << endl << "Number of comparisons: " << comparisons << endl << "Number of swaps: " << swaps << endl;
    cout << "Target at the bitonic point: " << Search(arr, n, 12) << endl;
    cout << "Target in the left half: " << Search(arr, n, 8) << endl;
    cout << "Target in the right half: " << Search(arr, n, 3) << endl;
    cout << "Target not present in the array: " << Search(arr, n, 2) << endl;

    return 0;
}