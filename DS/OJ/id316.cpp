#include <iostream>
using namespace std;
void quickSort(int arr[], int left, int right, int n) {
    if (left >= right) return;

    int i = left, j = right;
    int pivot = arr[left];

    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;
        if (i < j) arr[i++] = arr[j];

        while (i < j && arr[i] <= pivot) i++;
        if (i < j) arr[j--] = arr[i];
    }

    arr[i] = pivot;

    for (int k = 0; k < n; ++k) {
        if (k > 0) cout << " ";
        cout << arr[k];
    }
    cout << endl;

    quickSort(arr, left, i - 1, n);
    quickSort(arr, i + 1, right, n);
}

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; ++test) {
        if (test > 0) cout << endl; 

        int n;
        cin >> n; 

        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        quickSort(arr, 0, n - 1, n); 
    }

    return 0;
}
