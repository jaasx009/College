/*WAP to convert the Sparse Matrix into non-zero form and vice-versa. */
#include <iostream>
using namespace std;
class Sparse {
    private:
        int standardMatrix[10][10];
        int tripletMatrix[100][3];
        int rows;
        int cols;
        int nonZeroCount;
    public:
        Sparse() {
            rows = 0;
            cols = 0;
            nonZeroCount = 0;
        }
        void standardToTriplet() {
            cout << "Enter total rows and columns for the Standard Matrix: ";
            cin >> rows >> cols;
            cout << "Enter the elements of the matrix (mostly zeros):\n";
            nonZeroCount = 0;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cin >> standardMatrix[i][j];
                    if (standardMatrix[i][j] != 0) {
                        nonZeroCount++;
                    }
                }
            }
            tripletMatrix[0][0] = rows;
            tripletMatrix[0][1] = cols;
            tripletMatrix[0][2] = nonZeroCount;
            int k = 1;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (standardMatrix[i][j] != 0) {
                        tripletMatrix[k][0] = i;              // Row index
                        tripletMatrix[k][1] = j;              // Column index
                        tripletMatrix[k][2] = standardMatrix[i][j]; // Value
                        k++;
                    }
                }
            }
            cout << "\nMatrix successfully converted to Triplet Form.\n";
        }
        void displayTriplet() {
            if (rows == 0 && cols == 0) {
                cout << "No matrix data available.\n";
                return;
            }
            cout << "\nTriplet Form (Row | Column | Value)\n";
            cout << "------------------------------------\n";
            for (int i = 0; i <= tripletMatrix[0][2]; i++) {
                cout << "  " << tripletMatrix[i][0] << "\t|\t" 
                     << tripletMatrix[i][1] << "\t|\t" 
                     << tripletMatrix[i][2] << "\n";
            }
        }
        void tripletToStandard() {
            cout << "Enter matrix metadata: [Total Rows] [Total Columns] [Total Non-Zero Values]: ";
            cin >> tripletMatrix[0][0] >> tripletMatrix[0][1] >> tripletMatrix[0][2];            
            rows = tripletMatrix[0][0];
            cols = tripletMatrix[0][1];
            nonZeroCount = tripletMatrix[0][2];
            cout << "\nEnter the non-zero elements (Use 0-based indexing for Rows/Cols)\n";
            for (int i = 1; i <= nonZeroCount; i++) {
                cout << "Element " << i << " (Format: RowIndex ColIndex Value): ";
                cin >> tripletMatrix[i][0] >> tripletMatrix[i][1] >> tripletMatrix[i][2];
            }
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    standardMatrix[i][j] = 0;
                }
            }
            for (int i = 1; i <= nonZeroCount; i++) {
                int r = tripletMatrix[i][0];
                int c = tripletMatrix[i][1];
                int val = tripletMatrix[i][2];
                if (r < rows && c < cols) {
                    standardMatrix[r][c] = val;
                } else {
                    cout << "Warning: Coordinate (" << r << "," << c << ") is out of bounds!\n";
                }
            }
            cout << "\nTriplet Form successfully converted back to Standard Matrix.\n";
        }
        void displayStandard() {
            if (rows == 0 && cols == 0) {
                cout << "No matrix data available.\n";
                return;
            }
            cout << "\nStandard Sparse Matrix:\n";
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << standardMatrix[i][j] << "\t";
                }
                cout << "\n";
            }
        }
};
int main() {
    Sparse obj;
    int ch;
    while (1) {
        cout << "\n===== SPARSE MATRIX CONVERTER =====";
        cout << "\n1. Convert Standard Matrix -> Triplet Form";
        cout << "\n2. Convert Triplet Form -> Standard Matrix";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                obj.standardToTriplet();
                obj.displayTriplet();
                break;
            case 2:
                obj.tripletToStandard();
                obj.displayStandard();
                break;
            case 0:
                cout << "Program ended.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}