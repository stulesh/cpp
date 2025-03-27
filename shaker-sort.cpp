#include <iostream>
using namespace std;

void forward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    for (unsigned i = begin_idx; i < end_idx; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
}

void backward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    for (unsigned i = end_idx; i > begin_idx; i--) {
        if (arr[i] < arr[i - 1]) {
            swap(arr[i], arr[i - 1]);
        }
    }
}

void shaker_sort(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    unsigned left = begin_idx;
    unsigned right = end_idx;
    bool swapped = true;

    while (left < right && swapped) {
        swapped = false;
        forward_step(arr, left, right);
        right--;
        backward_step(arr, left, right);
        left++;
        if (left < right) swapped = true;
    }
}

void test_forward_step() {
    unsigned arr[] = {5, 3, 8, 6, 2};
    unsigned size = sizeof(arr)/sizeof(arr[0]);

    cout << "forward_step: ";
    for (unsigned i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    forward_step(arr, 0, size-1);

    cout << "forward_step: ";
    for (unsigned i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl << endl;
}

void test_backward_step() {
    unsigned arr[] = {3, 5, 6, 2, 8};
    unsigned size = sizeof(arr)/sizeof(arr[0]);

    cout << "backward_step: ";
    for (unsigned i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    backward_step(arr, 0, size-1);

    cout << "backward_step: ";
    for (unsigned i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl << endl;
}

void test_shaker_sort() {
    unsigned arr[] = {5, 3, 8, 6, 2, 9, 1, 4, 7};
    unsigned size = sizeof(arr)/sizeof(arr[0]);

    cout << "shaker_sort: ";
    for (unsigned i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    shaker_sort(arr, 0, size-1);

    cout << "shaker_sort: ";
    for (unsigned i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl << endl;
}

int main() {
    test_forward_step();
    test_backward_step();
    test_shaker_sort();
    return 0;
}