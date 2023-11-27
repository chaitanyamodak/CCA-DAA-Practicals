#include <iostream>
using namespace std;

void findMinAndMax(int arr[], int low, int high, int &min, int &max) {
    if (low == high) {
        min = arr[low];
        max = arr[low];
        return;
    } else if (high - low == 1) {
        if (arr[low] < arr[high]) {
            min = arr[low];
            max = arr[high];
        } else {
            min = arr[high];
            max = arr[low];
        }
        return;
    }

    int mid = low + (high - low) / 2;
    int min1, max1, min2, max2;
    findMinAndMax(arr, low, mid, min1, max1);
    findMinAndMax(arr, mid + 1, high, min2, max2);

    min = (min1 < min2) ? min1 : min2;
    max = (max1 > max2) ? max1 : max2;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinAndMax(arr, 0, n - 1, min, max);

    cout << "Minimum element in the array: " << min << endl;
    cout << "Maximum element in the array: " << max << endl;

    return 0;
}

