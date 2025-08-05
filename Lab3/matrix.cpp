#include <iostream>
#include <vector>
using namespace std;

int scalarMults = 0;
int scalarAdds = 0;

typedef vector<vector<int>> Matrix;

Matrix create(int n) {
    return Matrix(n, vector<int>(n, 0));
}

void input(Matrix& M, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> M[i][j];
}

void output(const Matrix& M, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << M[i][j] << " ";
        cout << "\n";
    }
}

void multiply(const Matrix& A, const Matrix& B, Matrix& C, int n) {
    if (n == 1) {
        C[0][0] += A[0][0] * B[0][0];
        scalarMults++;
        if (C[0][0] != A[0][0] * B[0][0])
            scalarAdds++;
        return;
    }

    int half = n / 2;
    Matrix A11(half, vector<int>(half));
    Matrix A12(half, vector<int>(half));
    Matrix A21(half, vector<int>(half));
    Matrix A22(half, vector<int>(half));
    Matrix B11(half, vector<int>(half));
    Matrix B12(half, vector<int>(half));
    Matrix B21(half, vector<int>(half));
    Matrix B22(half, vector<int>(half));
    Matrix C11(half, vector<int>(half));
    Matrix C12(half, vector<int>(half));
    Matrix C21(half, vector<int>(half));
    Matrix C22(half, vector<int>(half));

    for (int i = 0; i < half; ++i)
        for (int j = 0; j < half; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }

    multiply(A11, B11, C11, half);
    multiply(A12, B21, C11, half);

    multiply(A11, B12, C12, half);
    multiply(A12, B22, C12, half);

    multiply(A21, B11, C21, half);
    multiply(A22, B21, C21, half);

    multiply(A21, B12, C22, half);
    multiply(A22, B22, C22, half);

    for (int i = 0; i < half; ++i)
        for (int j = 0; j < half; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
}

int main() {
    int n;
    cin >> n;

    Matrix A = create(n);
    Matrix B = create(n);
    Matrix C = create(n);

    input(A, n);
    input(B, n);

    multiply(A, B, C, n);

    output(C, n);
    cout << scalarMults << endl;
    cout << scalarAdds << endl;

    return 0;
}