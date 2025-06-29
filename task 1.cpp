#include <iostream>
#include <fstream>
using namespace std;
const int SIZE= 100;

void saveArrayToFile(int arr[], int size, const char* filename) {
    ofstream file(filename);
    for (int i = 0; i < size; i++) {
        file << arr[i] << " ";
    }
    file.close();
}

void growFromFront(int arr[], int& size, int value) {
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
}

void growFromLast(int arr[], int& size, int value) {
    arr[size] = value;
    size++;
}

void growFromPosition(int arr[], int& size, int pos, int value) {
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
}

void shrinkFromFront(int arr[], int& size) {
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void shrinkFromLast(int& size) {
    size--;
}

void shrinkFromPosition(int arr[], int& size, int pos) {
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void displayArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[SIZE], size;

    cout << "Enter number of elements: ";
    cin >> size;
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    saveArrayToFile(arr, size, "original.txt");

    int choice, value, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Grow from front\n2. Grow from last\n3. Grow from position\n";
        cout << "4. Shrink from front\n5. Shrink from last\n6. Shrink from position\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            growFromFront(arr, size, value);
            break;
        case 2:
            cout << "Enter value to add: ";
            cin >> value;
            growFromLast(arr, size, value);
            break;
        case 3:
            cout << "Enter position (0 to " << size << "): ";
            cin >> pos;
            cout << "Enter value to add: ";
            cin >> value;
            if (pos >= 0 && pos <= size)
                growFromPosition(arr, size, pos, value);
            else
                cout << "Invalid position\n";
            break;
        case 4:
            if (size > 0)
                shrinkFromFront(arr, size);
            else
                cout << "Array is empty!\n";
            break;
        case 5:
            if (size > 0)
                shrinkFromLast(size);
            else
                cout << "Array is empty!\n";
            break;
        case 6:
            cout << "Enter position (0 to " << size - 1 << "): ";
            cin >> pos;
            if (pos >= 0 && pos < size)
                shrinkFromPosition(arr, size, pos);
            else
                cout << "Invalid position\n";
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice\n";
        }

        if (choice >= 1 && choice <= 6) {
            displayArray(arr, size);
            saveArrayToFile(arr, size, "updated.txt");
        }

    } while (choice != 0);

    return 0;
}
