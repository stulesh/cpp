#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int combStep(vector<int>& arr, int step, bool& sorted) {
    int swaps = 0;
    sorted = true;
    
    for (int i = 0; i + step < arr.size(); i++) {
        if (arr[i] > arr[i + step]) {
            swap(arr[i], arr[i + step]);
            swaps++;
            sorted = false;
        }
    }
    
    return swaps;
}

void combSort(vector<int>& arr, int& total_swaps, double& time_taken) {
    clock_t start = clock();
    total_swaps = 0;
    int step = arr.size();
    bool sorted = false;
    
    while (step > 1 || !sorted) {
        step = max(1, (step * 20) / 25);
        
        int swaps = combStep(arr, step, sorted);
        total_swaps += swaps;
    }
    
    time_taken = double(clock() - start) / CLOCKS_PER_SEC;
}

int main() {
    cout << "Size\tTime (s)\tSwaps\n";
    
    for (int size = 100; size <= 5000; size += 500) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 10000;
        }
        
        int swaps;
        double time;
        
        combSort(arr, swaps, time);
        
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                cout << "Sorting error!" << endl;
                return 1;
            }
        }
        
        cout << size << "\t" << time << "\t\t" << swaps << endl;
    } 
    
    return 0;
}