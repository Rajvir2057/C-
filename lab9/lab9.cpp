#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    
public:
    // Default constructor
    DynamicArray() : arr(nullptr), size(0) {}
    
    // Parameterized constructor
    DynamicArray(int size) : size(size) {
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = i + 1; // Initialize array with some values
        }
    }
    
    // Destructor
    ~DynamicArray() {
        delete[] arr;
        cout << "Destructor called" << endl;
    }
    
    // Copy constructor
    DynamicArray(const DynamicArray& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }
    
    // Overload assignment operator
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        delete[] arr; // Free existing memory
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
        return *this;
    }
    
    friend ostream& operator<<(ostream& outs, const DynamicArray& theArray);
};

// Overload << operator
ostream& operator<<(ostream& outs, const DynamicArray& theArray) {
    outs << "Items in the Array: " << theArray.size << endl;
    for (int i = 0; i < theArray.size; ++i) {
        outs << theArray.arr[i] << "-";
    }
    outs << "\n";
    return outs;
}

int main() {
    int choice;
    DynamicArray obj1, obj2;
    
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    obj1 = DynamicArray(size); // Use Parameterized constructor
    cout << obj1;
    
    obj2 = obj1; // Copy using assignment operator
    cout << obj2;
    
    DynamicArray obj3(obj1); // Copy using copy constructor
    cout << obj3;
    
    return 0;
}