#include <iostream>  // Only header needed for input/output operations
using namespace std; // Allows us to use cout, cin without std:: prefix

class matrix_manipulation {
private:
    // Class member variables to store matrix data and information
    double **matrices;    // Array of pointers to 2D matrices (dynamic allocation)
    int *rows, *cols;     // Arrays to store row and column count for each matrix
    int numOfMatrices;    // Total number of matrices created

public:
    // Constructor - initializes all pointers to nullptr and counter to 0
    matrix_manipulation() {
        matrices = nullptr;    // No matrices allocated initially
        rows = nullptr;        // No row array allocated initially
        cols = nullptr;        // No column array allocated initially
        numOfMatrices = 0;     // Start with zero matrices
    }

    // Destructor - automatically called when object is destroyed
    ~matrix_manipulation() {
        cleanup();  // Call cleanup function to free all allocated memory
    }

    // Function to initialize matrices based on user input
    void init_matrices() {
        cout << "Enter the number of Matrices: ";  // Prompt user for matrix count
        cin >> numOfMatrices;                      // Read number of matrices

        // Allocate memory for array of matrix pointers
        matrices = new double*[numOfMatrices];     // Array to hold pointers to each matrix
        rows = new int[numOfMatrices];             // Array to store row count for each matrix
        cols = new int[numOfMatrices];             // Array to store column count for each matrix

        // Loop through each matrix to get dimensions and elements
        for (int i = 0; i < numOfMatrices; i++) {
            // Get matrix dimensions from user
            cout << "Enter row number for Matrix " << (i + 1) << ": ";
            cin >> rows[i];                        // Store row count for matrix i
            cout << "Enter column number for Matrix " << (i + 1) << ": ";
            cin >> cols[i];                        // Store column count for matrix i

            // Allocate single block of memory for 2D matrix (rows*cols elements)
            matrices[i] = new double[rows[i] * cols[i]];

            // Get matrix elements from user
            cout << "Enter elements for Matrix " << (i + 1) << ":" << endl;
            for(int r = 0; r < rows[i]; r++) {     // Loop through each row
                for(int c = 0; c < cols[i]; c++) { // Loop through each column
                    cout << "Element [" << r << "][" << c << "]: ";
                    cin >> get(i, r, c);          // Use access function to store element
                }
            }
        }
    }

    // Access function to get/set matrix elements using single block allocation
    double& get(int matrixIndex, int r, int c) {
        // Convert 2D coordinates (r,c) to 1D array index
        // Formula: index = row * number_of_columns + column
        return matrices[matrixIndex][r * cols[matrixIndex] + c];
    }

    // Function to display a specific matrix
    void displayMatrix(int matrixIndex) {
        cout << "\nMatrix " << (matrixIndex + 1) << ":" << endl;  // Header for matrix
        for(int i = 0; i < rows[matrixIndex]; i++) {              // Loop through rows
            for(int j = 0; j < cols[matrixIndex]; j++) {          // Loop through columns
                cout << get(matrixIndex, i, j) << " ";            // Print each element
            }
            cout << endl;  // New line after each row
        }
    }

    // Sequential multiplication of all matrices (A × B × C × D...)
    void multiplyAllMatrices() {
        // Check if we have enough matrices for multiplication
        if(numOfMatrices < 2) {
            cout << "Need at least 2 matrices for multiplication!" << endl;
            return;  // Exit function if insufficient matrices
        }

        // Pre-check: Verify all matrices can be multiplied sequentially
        // For matrices A×B×C, cols(A) must equal rows(B), cols(B) must equal rows(C)
        for(int i = 0; i < numOfMatrices - 1; i++) {
            if(cols[i] != rows[i + 1]) {
                cout << "Cannot multiply Matrix " << (i + 1) << " and Matrix " << (i + 2)
                     << ": columns (" << cols[i] << ") != rows (" << rows[i + 1] << ")" << endl;
                return;  // Exit if dimensions incompatible
            }
        }

        // Initialize result with first matrix
        double *result = new double[rows[0] * cols[0]];  // Allocate memory for result
        int resultRows = rows[0];                        // Result will have rows of first matrix
        int resultCols = cols[0];                        // Initially, columns of first matrix

        // Copy first matrix to result array
        for(int i = 0; i < resultRows * resultCols; i++) {
            result[i] = matrices[0][i];  // Direct memory copy
        }

        // Multiply result with each subsequent matrix
        for(int m = 1; m < numOfMatrices; m++) {
            // Allocate new result array for current multiplication
            double *newResult = new double[resultRows * cols[m]];

            // Perform matrix multiplication: result × matrix[m]
            for(int i = 0; i < resultRows; i++) {           // Loop through result rows
                for(int j = 0; j < cols[m]; j++) {          // Loop through matrix[m] columns
                    newResult[i * cols[m] + j] = 0;         // Initialize sum to 0
                    // Calculate dot product of row i and column j
                    for(int k = 0; k < resultCols; k++) {   // Loop through common dimension
                        newResult[i * cols[m] + j] += result[i * resultCols + k] * get(m, k, j);
                    }
                }
            }

            delete[] result;           // Free old result memory
            result = newResult;        // Point to new result
            resultCols = cols[m];      // Update result column count

            // Show intermediate result after each multiplication
            cout << "\nResult after multiplying with Matrix " << (m + 1) << ":" << endl;
            displayResult(result, resultRows, resultCols);
        }

        // Display final multiplication result
        cout << "\n***** FINAL MULTIPLICATION RESULT *****" << endl;
        displayResult(result, resultRows, resultCols);
        delete[] result;  // Clean up final result memory
    }

    // Matrix addition function (element-wise addition)
    void addMatrices(int mat1Index, int mat2Index) {
        // Check if matrices have same dimensions (required for addition)
        if(rows[mat1Index] != rows[mat2Index] || cols[mat1Index] != cols[mat2Index]) {
            cout << "Cannot add: matrices have different dimensions!" << endl;
            return;  // Exit if dimensions don't match
        }

        cout << "\nAddition Result (Matrix " << (mat1Index + 1) << " + Matrix " << (mat2Index + 1) << "):" << endl;
        // Loop through each position and add corresponding elements
        for(int i = 0; i < rows[mat1Index]; i++) {
            for(int j = 0; j < cols[mat1Index]; j++) {
                double sum = get(mat1Index, i, j) + get(mat2Index, i, j);  // Add elements
                cout << sum << " ";  // Display sum
            }
            cout << endl;  // New line after each row
        }
    }

    // Matrix subtraction function (element-wise subtraction)
    void subtractMatrices(int mat1Index, int mat2Index) {
        // Check if matrices have same dimensions (required for subtraction)
        if(rows[mat1Index] != rows[mat2Index] || cols[mat1Index] != cols[mat2Index]) {
            cout << "Cannot subtract: matrices have different dimensions!" << endl;
            return;  // Exit if dimensions don't match
        }

        cout << "\nSubtraction Result (Matrix " << (mat1Index + 1) << " - Matrix " << (mat2Index + 1) << "):" << endl;
        // Loop through each position and subtract corresponding elements
        for(int i = 0; i < rows[mat1Index]; i++) {
            for(int j = 0; j < cols[mat1Index]; j++) {
                double diff = get(mat1Index, i, j) - get(mat2Index, i, j);  // Subtract elements
                cout << diff << " ";  // Display difference
            }
            cout << endl;  // New line after each row
        }
    }

    // Element-wise division function
    void divideMatricesElementWise(int mat1Index, int mat2Index) {
        // Check if matrices have same dimensions (required for element-wise division)
        if(rows[mat1Index] != rows[mat2Index] || cols[mat1Index] != cols[mat2Index]) {
            cout << "Cannot divide: matrices have different dimensions!" << endl;
            return;  // Exit if dimensions don't match
        }

        cout << "\nElement-wise Division Result (Matrix " << (mat1Index + 1) << " / Matrix " << (mat2Index + 1) << "):" << endl;
        // Loop through each position and divide corresponding elements
        for(int i = 0; i < rows[mat1Index]; i++) {
            for(int j = 0; j < cols[mat1Index]; j++) {
                // Check for division by zero
                if(get(mat2Index, i, j) == 0) {
                    cout << "Error: Division by zero at position [" << i << "][" << j << "]!" << endl;
                    return;  // Exit if division by zero encountered
                }
                double result = get(mat1Index, i, j) / get(mat2Index, i, j);  // Divide elements
                cout << result << " ";  // Display quotient
            }
            cout << endl;  // New line after each row
        }
    }

    // Matrix division using inverse (A / B = A * B^(-1))
    void divideMatricesUsingInverse(int mat1Index, int mat2Index) {
        // Check if second matrix is square (required for inverse calculation)
        if(rows[mat2Index] != cols[mat2Index]) {
            cout << "Cannot divide: second matrix must be square for inverse!" << endl;
            return;  // Exit if not square
        }

        // Check if dimensions are compatible for multiplication after inverse
        if(cols[mat1Index] != rows[mat2Index]) {
            cout << "Cannot divide: incompatible dimensions for multiplication!" << endl;
            return;  // Exit if incompatible
        }

        int n = rows[mat2Index];  // Size of square matrix

        // Create augmented matrix [A|I] for Gauss-Jordan elimination
        double **augmented = new double*[n];          // Allocate array of row pointers
        for(int i = 0; i < n; i++) {
            augmented[i] = new double[2 * n];         // Each row has 2n columns
            // Copy original matrix to left side of augmented matrix
            for(int j = 0; j < n; j++) {
                augmented[i][j] = get(mat2Index, i, j);
            }
            // Create identity matrix on right side of augmented matrix
            for(int j = n; j < 2 * n; j++) {
                augmented[i][j] = (i == j - n) ? 1.0 : 0.0;  // 1 on diagonal, 0 elsewhere
            }
        }

        // Gauss-Jordan elimination to find inverse
        for(int i = 0; i < n; i++) {
            // Find pivot (largest absolute value in column for numerical stability)
            int pivot = i;
            for(int j = i + 1; j < n; j++) {
                double val1 = augmented[j][i];    // Get current element
                if(val1 < 0) val1 = -val1;       // Manual absolute value
                double val2 = augmented[pivot][i]; // Get pivot element
                if(val2 < 0) val2 = -val2;       // Manual absolute value
                if(val1 > val2) {
                    pivot = j;  // Update pivot if larger value found
                }
            }

            // Swap rows if needed to bring pivot to diagonal
            if(pivot != i) {
                for(int j = 0; j < 2 * n; j++) {
                    double temp = augmented[i][j];      // Temporary storage
                    augmented[i][j] = augmented[pivot][j];  // Swap elements
                    augmented[pivot][j] = temp;
                }
            }

            // Check for singular matrix (determinant = 0, no inverse exists)
            double pivotVal = augmented[i][i];
            if(pivotVal < 0) pivotVal = -pivotVal;  // Manual absolute value
            if(pivotVal < 0.0000001) {              // Very small number = essentially zero
                cout << "Cannot divide: second matrix is singular (not invertible)!" << endl;
                // Cleanup allocated memory before returning
                for(int k = 0; k < n; k++) delete[] augmented[k];
                delete[] augmented;
                return;
            }

            // Scale current row to make diagonal element = 1
            double scale = augmented[i][i];  // Get diagonal element
            for(int j = 0; j < 2 * n; j++) {
                augmented[i][j] /= scale;    // Divide entire row by diagonal element
            }

            // Eliminate column (make all other elements in column = 0)
            for(int j = 0; j < n; j++) {
                if(j != i) {  // Skip diagonal row
                    double factor = augmented[j][i];  // Element to eliminate
                    for(int k = 0; k < 2 * n; k++) {
                        // Subtract (factor × current_row) from target row
                        augmented[j][k] -= factor * augmented[i][k];
                    }
                }
            }
        }

        // Now multiply mat1 with the inverse (right side of augmented matrix)
        int resultRows = rows[mat1Index];
        int resultCols = cols[mat2Index];

        cout << "\nMatrix Division Result (Matrix " << (mat1Index + 1) << " / Matrix " << (mat2Index + 1) << " = Matrix " << (mat1Index + 1) << " * Inverse of Matrix " << (mat2Index + 1) << "):" << endl;

        // Perform matrix multiplication: mat1 × inverse_of_mat2
        for(int i = 0; i < resultRows; i++) {           // Loop through result rows
            for(int j = 0; j < resultCols; j++) {       // Loop through result columns
                double result = 0;                      // Initialize sum
                for(int k = 0; k < cols[mat1Index]; k++) {  // Loop through common dimension
                    // Multiply mat1[i][k] with inverse[k][j] (inverse is right side of augmented)
                    result += get(mat1Index, i, k) * augmented[k][j + n];
                }
                cout << result << " ";  // Display result element
            }
            cout << endl;  // New line after each row
        }

        // Cleanup augmented matrix memory
        for(int i = 0; i < n; i++) delete[] augmented[i];
        delete[] augmented;
    }

    // Matrix inverse calculation using Gauss-Jordan elimination
    void inverseMatrix(int matIndex) {
        // Check if matrix is square (required for inverse)
        if(rows[matIndex] != cols[matIndex]) {
            cout << "Cannot find inverse: matrix is not square!" << endl;
            return;  // Exit if not square
        }

        int n = rows[matIndex];  // Size of square matrix

        // Create augmented matrix [A|I] where A is original matrix, I is identity
        double **augmented = new double*[n];
        for(int i = 0; i < n; i++) {
            augmented[i] = new double[2 * n];  // 2n columns for [A|I]
            // Copy original matrix to left side
            for(int j = 0; j < n; j++) {
                augmented[i][j] = get(matIndex, i, j);
            }
            // Create identity matrix on right side
            for(int j = n; j < 2 * n; j++) {
                augmented[i][j] = (i == j - n) ? 1.0 : 0.0;  // 1 on diagonal, 0 elsewhere
            }
        }

        // Gauss-Jordan elimination process (same as division function)
        for(int i = 0; i < n; i++) {
            // Find pivot for numerical stability
            int pivot = i;
            for(int j = i + 1; j < n; j++) {
                double val1 = augmented[j][i];
                if(val1 < 0) val1 = -val1;       // Manual absolute value
                double val2 = augmented[pivot][i];
                if(val2 < 0) val2 = -val2;       // Manual absolute value
                if(val1 > val2) {
                    pivot = j;
                }
            }

            // Swap rows to bring pivot to diagonal
            if(pivot != i) {
                for(int j = 0; j < 2 * n; j++) {
                    double temp = augmented[i][j];
                    augmented[i][j] = augmented[pivot][j];
                    augmented[pivot][j] = temp;
                }
            }

            // Check for singular matrix
            double pivotVal = augmented[i][i];
            if(pivotVal < 0) pivotVal = -pivotVal;
            if(pivotVal < 0.0000001) {
                cout << "Matrix is singular (not invertible)!" << endl;
                // Cleanup and exit
                for(int k = 0; k < n; k++) delete[] augmented[k];
                delete[] augmented;
                return;
            }

            // Scale row to make diagonal = 1
            double scale = augmented[i][i];
            for(int j = 0; j < 2 * n; j++) {
                augmented[i][j] /= scale;
            }

            // Eliminate column
            for(int j = 0; j < n; j++) {
                if(j != i) {
                    double factor = augmented[j][i];
                    for(int k = 0; k < 2 * n; k++) {
                        augmented[j][k] -= factor * augmented[i][k];
                    }
                }
            }
        }

        // Display inverse matrix (right side of augmented matrix)
        cout << "\nInverse of Matrix " << (matIndex + 1) << ":" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = n; j < 2 * n; j++) {  // Only right side (inverse)
                cout << augmented[i][j] << " ";
            }
            cout << endl;
        }

        // Cleanup memory
        for(int i = 0; i < n; i++) delete[] augmented[i];
        delete[] augmented;
    }

    // Utility function to display any result matrix
    void displayResult(double* result, int rows, int cols) {
        for(int i = 0; i < rows; i++) {          // Loop through rows
            for(int j = 0; j < cols; j++) {      // Loop through columns
                cout << result[i * cols + j] << " ";  // Access using 1D index formula
            }
            cout << endl;  // New line after each row
        }
    }

    // Function to display all matrices
    void displayAllMatrices() {
        for(int i = 0; i < numOfMatrices; i++) {  // Loop through all matrices
            displayMatrix(i);                     // Display each matrix
        }
    }

    // Interactive menu system for user operations
    void showMenu() {
        int choice;  // Variable to store user's menu choice
        do {         // Loop until user chooses to exit
            // Display menu options
            cout << "\n========== MATRIX OPERATIONS MENU ==========" << endl;
            cout << "1. Display all matrices" << endl;
            cout << "2. Multiply all matrices (sequential)" << endl;
            cout << "3. Add two matrices" << endl;
            cout << "4. Subtract two matrices" << endl;
            cout << "5. Divide matrices (element-wise)" << endl;
            cout << "6. Divide matrices (using inverse)" << endl;
            cout << "7. Find inverse of a matrix" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;  // Read user's choice

            // Process user's choice using switch statement
            switch(choice) {
                case 1:  // Display all matrices
                    displayAllMatrices();
                    break;
                case 2:  // Sequential matrix multiplication
                    multiplyAllMatrices();
                    break;
                case 3: {  // Matrix addition (block scope for local variables)
                    int mat1, mat2;  // Variables for matrix indices
                    cout << "Enter first matrix number (1-" << numOfMatrices << "): ";
                    cin >> mat1;
                    cout << "Enter second matrix number (1-" << numOfMatrices << "): ";
                    cin >> mat2;
                    // Validate matrix numbers (convert from 1-based to 0-based indexing)
                    if(mat1 >= 1 && mat1 <= numOfMatrices && mat2 >= 1 && mat2 <= numOfMatrices) {
                        addMatrices(mat1-1, mat2-1);  // Call with 0-based indices
                    } else {
                        cout << "Invalid matrix numbers!" << endl;
                    }
                    break;
                }
                case 4: {  // Matrix subtraction
                    int mat1, mat2;
                    cout << "Enter first matrix number (1-" << numOfMatrices << "): ";
                    cin >> mat1;
                    cout << "Enter second matrix number (1-" << numOfMatrices << "): ";
                    cin >> mat2;
                    if(mat1 >= 1 && mat1 <= numOfMatrices && mat2 >= 1 && mat2 <= numOfMatrices) {
                        subtractMatrices(mat1-1, mat2-1);
                    } else {
                        cout << "Invalid matrix numbers!" << endl;
                    }
                    break;
                }
                case 5: {  // Element-wise division
                    int mat1, mat2;
                    cout << "Enter first matrix number (1-" << numOfMatrices << "): ";
                    cin >> mat1;
                    cout << "Enter second matrix number (1-" << numOfMatrices << "): ";
                    cin >> mat2;
                    if(mat1 >= 1 && mat1 <= numOfMatrices && mat2 >= 1 && mat2 <= numOfMatrices) {
                        divideMatricesElementWise(mat1-1, mat2-1);
                    } else {
                        cout << "Invalid matrix numbers!" << endl;
                    }
                    break;
                }
                case 6: {  // Matrix division using inverse
                    int mat1, mat2;
                    cout << "Enter first matrix number (1-" << numOfMatrices << "): ";
                    cin >> mat1;
                    cout << "Enter second matrix number (1-" << numOfMatrices << "): ";
                    cin >> mat2;
                    if(mat1 >= 1 && mat1 <= numOfMatrices && mat2 >= 1 && mat2 <= numOfMatrices) {
                        divideMatricesUsingInverse(mat1-1, mat2-1);
                    } else {
                        cout << "Invalid matrix numbers!" << endl;
                    }
                    break;
                }
                case 7: {  // Matrix inverse
                    int mat;
                    cout << "Enter matrix number for inverse (1-" << numOfMatrices << "): ";
                    cin >> mat;
                    if(mat >= 1 && mat <= numOfMatrices) {
                        inverseMatrix(mat-1);  // Convert to 0-based index
                    } else {
                        cout << "Invalid matrix number!" << endl;
                    }
                    break;
                }
                case 0:  // Exit program
                    cout << "Exiting program..." << endl;
                    break;
                default:  // Invalid choice
                    cout << "Invalid choice! Please try again." << endl;
            }
        } while(choice != 0);  // Continue until user chooses 0 (exit)
    }

private:
    // Private cleanup function to free all allocated memory
    void cleanup() {
        if(matrices) {  // Check if matrices array exists
            // Free each individual matrix
            for(int i = 0; i < numOfMatrices; i++) {
                delete[] matrices[i];  // Free matrix i
            }
            delete[] matrices;  // Free array of matrix pointers
        }
        delete[] rows;  // Free rows array
        delete[] cols;  // Free columns array
    }
};

// Main function - program entry point
int main() {
    cout << "===== MATRIX MANIPULATION PROGRAM =====" << endl;  // Program title

    matrix_manipulation mm;  // Create matrix manipulation object
    mm.init_matrices();      // Initialize matrices with user input
    mm.showMenu();          // Show interactive menu for operations

    return 0;  // Indicate successful program completion
}
