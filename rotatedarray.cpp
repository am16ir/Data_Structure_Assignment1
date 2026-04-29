/*best case: O(1)/avg case: O(n) /worst case: O(n) */
#include <bits/stdc++.h>
using namespace std;

int searchrotated(int arr[], int n, int target, int& comps) {

    int peak = -1;

    for (int i = 0; i < n - 1; i++) {
        comps++;
        if (arr[i] > arr[i + 1]) {
            peak = i;
            break;
        }
    }

    if (peak == -1) peak = n - 1;

    int l = 0, r = n - 1;

    comps+=2;
    if (target >= arr[0] && target <= arr[peak]) {
        l = 0;
        r = peak;
    } else {
        l = peak + 1;
        r = n - 1;
    }

    for (int i = l; i <= r; i++) {
        comps++;
        if (arr[i] == target)
            return i;
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    int comps = 0;

    int idx = searchrotated(arr, n, target, comps);

    cout << "index: " << idx << endl;
    cout << "comparisons: " << comps << endl;

    return 0;
}
/*
10
4 5 6 6 7 0 1 2 2 4
2
*/
