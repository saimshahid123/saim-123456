#include <iostream>
#include <fstream>
using namespace std;

const int rows = 100;
const int col = 100;

int jagged[rows][col];
int colSizes[rows];             
int row;                           
void saveJaggedToFile(const char* filename) {
    ofstream file(filename);
    for (int i = 0; i < rows; i++) {
        file << colSizes[i] << " ";
        for (int j = 0; j < colSizes[i]; j++) {
            file << jagged[i][j] << " ";
        }
        file << endl;
    }
    file.close();
}
void displayJagged() {
    cout << "Jagged Array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            cout << jagged[i][j] << " ";
        }
        cout << endl;
    }
}
void inputRow(int index) {
    cout << "Enter number of elements in new row: ";
    cin >> colSizes[index];
    cout << "Enter elements: ";
    for (int j = 0; j < colSizes[index]; j++) {
        cin >> jagged[index][j];
    }
}
void growFront() {
    for (int i = rows; i > 0; i--) {
        colSizes[i] = colSizes[i - 1];
        for (int j = 0; j < colSizes[i - 1]; j++) {
            jagged[i][j] = jagged[i - 1][j];
        }
    }
    inputRow(0);
    row++;
}
void growEnd() {
    inputRow(row);
    row++;
}
void growAtPosition(int pos) {
    if (pos < 0 || pos > row) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = rows; i > pos; i--) {
        colSizes[i] = colSizes[i - 1];
        for (int j = 0; j < colSizes[i - 1]; j++) {
            jagged[i][j] = jagged[i - 1][j];
        }
    }
    inputRow(pos);
    row++;
}
void shrinkFront() {
    for (int i = 0; i < rows - 1; i++) {
        colSizes[i] = colSizes[i + 1];
        for (int j = 0; j < colSizes[i + 1]; j++) {
            jagged[i][j] = jagged[i + 1][j];
        }
    }
    row--;
}
void shrinkEnd() {
    if (rows > 0)
        row--;
}
void shrinkAtPosition(int pos) {
    if (pos < 0 || pos >= rows) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < rows - 1; i++) {
        colSizes[i] = colSizes[i + 1];
        for (int j = 0; j < colSizes[i + 1]; j++) {
            jagged[i][j] = jagged[i + 1][j];
        }
    }
    row--;
}
int main() {
    cout << "Enter number of rows: ";
    cin >> row;
    for (int i = 0; i < rows; i++) {
        cout << "Enter number of columns in row " << i << ": ";
        cin >> colSizes[i];
        cout << "Enter elements: ";
        for (int j = 0; j < colSizes[i]; j++) {
            cin >> jagged[i][j];
        }
    }

    saveJaggedToFile("original_jagged.txt");

    int choice, pos;
    do {
        cout << "\nMenu:\n";
        cout << "1. Grow from front\n2. Grow from end\n3. Grow at position\n";
        cout << "4. Shrink from front\n5. Shrink from end\n6. Shrink at position\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: growFront(); break;
        case 2: growEnd(); break;
        case 3:
            cout << "Enter position (0 to " << rows << "): ";
            cin >> pos;
            growAtPosition(pos);
            break;
        case 4: shrinkFront(); break;
        case 5: shrinkEnd(); break;
        case 6:
            cout << "Enter position (0 to " << rows - 1 << "): ";
            cin >> pos;
            shrinkAtPosition(pos);
            break;
        case 0: break;
        default: cout << "Invalid choice!\n";
        }

        if (choice >= 1 && choice <= 6) {
            displayJagged();
            saveJaggedToFile("updated_jagged.txt");
        }

    } while (choice != 0);

    return 0;
}
