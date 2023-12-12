#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> addMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

vector<vector<int>> subtractMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

void splitMatrix(const vector<vector<int>> &A,
                 vector<vector<int>> &A11, vector<vector<int>> &A12,
                 vector<vector<int>> &A21, vector<vector<int>> &A22)
{
    int n = A.size();
    int halfSize = n / 2;
    for (int i = 0; i < halfSize; ++i)
    {
        for (int j = 0; j < halfSize; ++j)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + halfSize];
            A21[i][j] = A[i + halfSize][j];
            A22[i][j] = A[i + halfSize][j + halfSize];
        }
    }
}

vector<vector<int>> strassen(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
    }
    else
    {
        vector<vector<int>> A11(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> A12(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> A21(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> A22(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> B11(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> B12(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> B21(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> B22(n / 2, vector<int>(n / 2, 0));

        splitMatrix(A, A11, A12, A21, A22);
        splitMatrix(B, B11, B12, B21, B22);

        vector<vector<int>> P1 = strassen(A11, subtractMatrix(B12, B22));
        vector<vector<int>> P2 = strassen(addMatrix(A11, A12), B22);
        vector<vector<int>> P3 = strassen(addMatrix(A21, A22), B11);
        vector<vector<int>> P4 = strassen(A22, subtractMatrix(B21, B11));
        vector<vector<int>> P5 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
        vector<vector<int>> P6 = strassen(subtractMatrix(A12, A22), addMatrix(B21, B22));
        vector<vector<int>> P7 = strassen(subtractMatrix(A11, A21), addMatrix(B11, B12));

        vector<vector<int>> C11 = addMatrix(subtractMatrix(addMatrix(P5, P4), P2), P6);
        vector<vector<int>> C12 = addMatrix(P1, P2);
        vector<vector<int>> C21 = addMatrix(P3, P4);
        vector<vector<int>> C22 = addMatrix(subtractMatrix(subtractMatrix(P5, P3), P7), P1);

        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = 0; j < n / 2; ++j)
            {
                C[i][j] = C11[i][j];
                C[i][j + n / 2] = C12[i][j];
                C[i + n / 2][j] = C21[i][j];
                C[i + n / 2][j + n / 2] = C22[i][j];
            }
        }
    }
    return C;
}

int main()
{
    vector<vector<int>> A = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};
    vector<vector<int>> B = {{17, 18, 19, 20},
                             {21, 22, 23, 24},
                             {25, 26, 27, 28},
                             {29, 30, 31, 32}};

    vector<vector<int>> result = strassen(A, B);

    cout << "Input Matrix: A" << endl
         << endl;
    for (const auto &row : A)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "\nInput Matrix: B" << endl
         << endl;
    for (const auto &row : B)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "\nResultant Matrix:\n"
         << endl;
    for (const auto &row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "\n";
    return 0;
}
