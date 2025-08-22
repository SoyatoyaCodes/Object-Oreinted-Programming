// Implement a Matrix2x2 class in C++ that supports the following operations using operator overloading: 
// 1. Matrix Addition (+): Add two 2x2 matrices. 
// 2. Matrix Subtraction (-): Subtract one 2x2 matrix from another. 
// 3. Matrix Multiplication (*): Multiply two 2x2 matrices. 
// 4. Output (<<): Overload the << operator to display the matrix in a readable format. 
// Note: 
// For Matrix Addition and subtraction, add and subtract the numbers in the same positions.  
// For matrix multiplication: Multiply rows of the first matrix by columns of the second matrix and add 
// the results. 
// Step-by-Step: 
// 1. Take the first row of the first matrix and the first column of the second matrix. 
// 2. Multiply the corresponding numbers and add them together. 
// 3. Repeat for all rows and columns. 
#include <iostream>
using namespace std;

class matrix2by2 {
    int matrix[2][2];
public:
    //constructor
    matrix2by2(bool userinput = true) {
        if (userinput) {
            cout << "initialize it with values ✎ᝰ" << endl;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    cin >> matrix[i][j];
                }
            }  cout << "matrix populated with values yippie!! .⋆𐙚₊˚⊹♡" << endl;
        }
        else {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //NOTE!!
    //matrix2by2& operator+(const matrix2by2& m2) RETURNING A LOCAL VAR mat BY REFERENCE IS WRONG! CAUSE IT IS DESTROYED AS THE FUNCTION ENDS IN STACK

    matrix2by2 operator+(const matrix2by2& m2) const {
        matrix2by2 mat(false);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mat.matrix[i][j] = this->matrix[i][j] + m2.matrix[i][j];
            }
        }  return mat;
    }

    matrix2by2 operator-(const matrix2by2& m2) const {
        matrix2by2 mat(false);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mat.matrix[i][j] = this->matrix[i][j] - m2.matrix[i][j];
            }
        }  return mat;
    }

    matrix2by2 operator*(const matrix2by2& m) const {
        matrix2by2 mat(false);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mat.matrix[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    mat.matrix[i][j] += this->matrix[i][k] * m.matrix[k][j];
                }
            }
        }  return mat;
    }
    friend ostream& operator<<(ostream& os, const matrix2by2& m);

};

ostream& operator<<(ostream& os, const matrix2by2& m) {
    for (int i = 0; i < 2; i++) {
        os << "[ ";
        for (int j = 0; j < 2; j++) {
            os << m.matrix[i][j] << " ";
        } os << " ]" << endl;
    }
    return os;
}

int main() {

    matrix2by2 m1;
    matrix2by2 m2;
    matrix2by2 m = m1 + m2;
    cout << "new addition matrix" << endl;
    cout << m;
    matrix2by2 mat = m1 - m2;
    cout << "new substraction matrix" << endl;
    cout << mat;
    matrix2by2 matr = m1 * m2;
    cout << "new multiplied matrix" << endl;
    cout << matr;

}