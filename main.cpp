#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>   

using namespace std;

class BubbleSorter {
public:
    BubbleSorter(int size) : arr(size) {}
    
    void fillArrayManually() {
        cout << "Enter " << arr.size() << " elements: ";
        for (int& num : arr) {
            cin >> num;
        }
    }
    
    void fillArrayRandomly() {
        for (int& num : arr) {
            num = rand() % 100;
        }
        cout << "Generated array: ";
        printArray();
    }
    
    void sort() {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    
    void printArray() const {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

private:
    vector<int> arr;
};

int main() {
    srand(time(0));
    
    int size;
    cout << "Enter array size: ";
    cin >> size;
    
    BubbleSorter sorter(size);
    
    int choice;
    cout << "Choose array filling method: 1 - manually, 2 - randomly: ";
    cin >> choice;
    
    if (choice == 1) sorter.fillArrayManually();
    else sorter.fillArrayRandomly();
    
    
    sorter.sort();
    
    cout << "Sorted array: ";
    sorter.printArray();
    
    return 0;
}
