#include <bits/stdc++.h>
using namespace std;

void solvebitonic(int arr[], int n, int target) {
    int mid = (n/2)+1;
    int comps = 0, swaps = 0;

    // bubble sort for lh
    for (int i = 0; i < mid - 1; i++) {
        for (int j = 0; j < mid - i - 1; j++) {
            comps++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }

    // selection sort for rh
    for (int i = mid; i < n - 1; i++) {
        int mx = i;
        for (int j = i + 1; j < n; j++) {
            comps++;
            if (arr[j] > arr[mx]) mx = j;
        }
        if (mx != i) {
            swap(arr[i], arr[mx]);
            swaps++;
        }
    }

    cout << "sorted bitonic array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "total comparisons: " << comps << endl;
    cout << "total swaps: " << swaps << endl;

    // linear search
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            idx = i;
            break;
        }
    }

    if (idx != -1)
        cout << "target found at index: " << idx << endl;
    else
        cout << "target not found"<< endl;
}

int main() {
    int n;
    cout << "enter size: ";
    cin >> n;

    int arr[n];
    cout << "enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout << "enter target: ";
    cin >> target;

    solvebitonic(arr, n, target);

    return 0;
}
