#include <iostream>
using namespace std;

int main() {
    int row_a, column_a, row_b, column_b, choice, maxx_element;

    cout << "[1] Matrix addition" << endl;
    cout << "[2] Matrix subtraction" << endl;
    cout << "[3] Matrix multiplication" << endl;
    cout << "[4] Matrix division (undefined, will exit)" << endl;
    cout << "[5] Trace of Matrix (for both diagonal sides)" << endl;
    cout << "[6] Print an input matrix" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    // Input for the first matrix
    cout << endl;
    cout << "Number of rows for the 1st matrix: ";
    cin >> row_a;
    cout << "Number of columns for the 1st matrix: ";
    cin >> column_a;
    int a[row_a][column_a];

    cout << endl;
    cout << "Enter elements for the 1st matrix," << endl;
    for (int i = 0; i < row_a; i++) {
        for (int j = 0; j < column_a; j++) {
            cout << "Enter element [" << i << "][" << j << "]" << ": ";
            cin >> a[i][j];
        }
    }

    // Declare second matrix with maximum reasonable size to avoid scope issues
    int b[50][50];
    int c[50][50] = {0};

    // Input for the second matrix (only for cases 1, 2, 3, 4)
    if (choice >= 1 && choice <= 4) {
        cout << endl;
        cout << "Number of rows for the 2nd matrix: ";
        cin >> row_b;
        cout << "Number of columns for the 2nd matrix: ";
        cin >> column_b;

        cout << endl;
        cout << "Enter elements for the 2nd matrix," << endl;
        for (int i = 0; i < row_b; i++) {
            for (int j = 0; j < column_b; j++) {
                cout << "Enter element [" << i << "][" << j << "]" << ": ";
                cin >> b[i][j];
            }
        }
    }

    switch (choice) {
        case 1: // Matrix addition
            if (row_a == row_b && column_a == column_b) {
                for (int i = 0; i < row_a; i++) {
                    for (int j = 0; j < column_a; j++) {
                        c[i][j] = a[i][j] + b[i][j];
                    }
                }
                cout << endl;
                cout << "Output Matrix:" << endl;
                for (int i = 0; i < row_a; i++) {
                    for (int j = 0; j < column_a; j++) {
                        cout << " " << c[i][j];
                    }
                    cout << endl;
                }
            }
            else {
                cout << "Error: Matrices must have the same dimensions for addition!" << endl;
                return 1;
            }
            break;

        case 2: // Matrix subtraction
            if (row_a == row_b && column_a == column_b) {
                for (int i = 0; i < row_a; i++) {
                    for (int j = 0; j < column_a; j++) {
                        c[i][j] = a[i][j] - b[i][j];
                    }
                }
                cout << endl;
                cout << "Output Matrix:" << endl;
                for (int i = 0; i < row_a; i++) {
                    for (int j = 0; j < column_a; j++) {
                        cout << " " << c[i][j];
                    }
                    cout << endl;
                }
            }
            else {
                cout << "Error: Matrices must have the same dimensions for subtraction!" << endl;
                return 1;
            }
            break;

        case 3: // Matrix multiplication
            if (column_a == row_b) {
                for (int i = 0; i < row_a; i++) {
                    for (int j = 0; j < column_b; j++) {
                        c[i][j] = 0;
                        for (int k = 0; k < column_a; k++) {
                            c[i][j] += a[i][k] * b[k][j];
                        }
                    }
                }
                cout << endl;
                cout << "Output Matrix:" << endl;
                for (int i = 0; i < row_a; i++) {
                    for (int j = 0; j < column_b; j++) {
                        cout << " " << c[i][j];
                    }
                    cout << endl;
                }
            }
            else {
                cout << "Error: Number of columns in 1st matrix must equal number of rows in 2nd matrix!" << endl;
                return 1;
            }
            break;

        case 4: // Matrix division
            cout << "Matrix division is not defined yet. Exiting!" << endl;
            return 1;
            break;

        case 5: // Trace of Matrix
            if (row_a == column_a) {
                int right_sum = 0, left_sum = 0;

                for (int i = 0; i < row_a; i++) {
                    for (int j = 0; j < column_a; j++) {
                        if (i == j) {
                            left_sum += a[i][j];
                        }
                        if (i + j == row_a - 1) {
                            right_sum += a[i][j];
                        }
                    }
                }
                cout << endl;
                cout << "Sum of the left diagonal (primary diagonal): " << left_sum << endl;
                cout << "Sum of the right diagonal (secondary diagonal): " << right_sum << endl;
            }
            else {
                cout << "Error: Number of rows and columns in 1st matrix must be equal!" << endl;
                return 1;
            }
            break;

        case 6: // Print the input matrix
            cout << endl;
            cout << "Input Matrix:" << endl;
            for (int i = 0; i < row_a; i++) {
                for (int j = 0; j < column_a; j++) {
                    cout << " " << a[i][j];
                }
                cout << endl;
            }
            break;

        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    return 0;
}
