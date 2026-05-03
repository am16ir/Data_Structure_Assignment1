#include <iostream>

using namespace std;

int Search(int arr[], int n, int target, int &comparisons) {
    int low = 0, high = n - 1;
    comparisons = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        comparisons++;
        if (arr[mid] == target) {
            return mid;
        }

        comparisons += 2;
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        comparisons++;
        if (arr[low] <= arr[mid]) {
            comparisons += 2;
            if (target >= arr[low] && target < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            comparisons += 2;
            if (target > arr[mid] && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int arr[] = {4, 5, 6, 6, 7, 0, 1, 2, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;
    int comparisons = 0;

    int result = Search(arr, n, target, comparisons);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    cout << "Total element-to-element comparisons: " << comparisons << endl;

    return 0;
}