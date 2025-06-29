#include <iostream>
#include <fstream>
using namespace std;

const int rows= 100;
const int col = 100;

void save2DArrayToFile(int arr[][col], int rows, int cols, const char* filename) {
    ofstream file(filename);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file << arr[i][j] << " ";
        }
        file << endl;
    }
    file.close();
}

void growFromFront(int arr[][col], int& rows, int cols) {
    for (int i = rows; i > 0; i--) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = arr[i - 1][j];
        }
    }
    cout << "Enter new row values:\n";
    for (int j = 0; j < cols; j++) {
        cin >> arr[0][j];
    }
    rows++;
}

void growFromEnd(int arr[][col], int& rows, int cols) {
    cout << "Enter new row values:\n";
    for (int j = 0; j < cols; j++) {
        cin >> arr[rows][j];
    }
    rows++;
}

void growFromPosition(int arr[][col], int& rows, int cols, int pos) {
    for (int i = rows; i > pos; i--) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = arr[i - 1][j];
        }
    }
    cout << "Enter new row values:\n";
    for (int j = 0; j < cols; j++) {
        cin >> arr[pos][j];
    }
    rows++;
}

void shrinkFromFront(int arr[][col], int& rows, int cols) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = arr[i + 1][j];
        }
    }
    rows--;
}

void shrinkFromEnd(int& rows) {
    rows--;
}

void shrinkFromPosition(int arr[][col], int& rows, int cols, int pos) {
    for (int i = pos; i < rows - 1; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = arr[i + 1][j];
        }
    }
    rows--;
}

void display2DArray(int arr[][col], int rows, int cols) {
    cout << "Current 2D Array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[rows][col];
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter 2D array values:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
    save2DArrayToFile(arr, rows, cols, "original_2D.txt");

    int choice, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Grow from front\n2. Grow from end\n3. Grow from position\n";
        cout << "4. Shrink from front\n5. Shrink from end\n6. Shrink from position\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            growFromFront(arr, rows, cols);
            break;
        case 2:
            growFromEnd(arr, rows, cols);
            break;
        case 3:
            cout << "Enter position (0 to " << rows << "): ";
            cin >> pos;
            if (pos >= 0 && pos <= rows)
                growFromPosition(arr, rows, cols, pos);
            else
                cout << "Invalid position!\n";
            break;
        case 4:
            if (rows > 0)
                shrinkFromFront(arr, rows, cols);
            else
                cout << "Array is empty!\n";
            break;
        case 5:
            if (rows > 0)
                shrinkFromEnd(rows);
            else
                cout << "Array is empty!\n";
            break;
        case 6:
            cout << "Enter position (0 to " << rows - 1 << "): ";
            cin >> pos;
            if (pos >= 0 && pos < rows)
                shrinkFromPosition(arr, rows, cols, pos);
            else
                cout << "Invalid position!\n";
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice!\n";
        }

        if (choice >= 1 && choice <= 6) {
            display2DArray(arr, rows, cols);
            save2DArrayToFile(arr, rows, cols, "updated_2D.txt");
        }

    } while (choice != 0);

    return 0;
}
