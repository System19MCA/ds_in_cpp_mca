// WAP Matrices oprations

#include <iostream>

using namespace std;

void display(int arr[][3], int rows, int cols)
{
    cout << "[" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "[";
        for (int j = 0; j < cols; j++)
        {

            cout << arr[i][j] << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]";
}

int main()
{

    int mat1[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int result[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    cout << "Addition of Matrices \n";
    display(result, 3, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    cout << "Subtraction of Matrices \n";
    display(result, 3, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            result[i][j] = mat1[j][i];
        }
    }

    cout << "Transpose of Matrices \n";
    display(result, 3, 3);

    // initialization
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            result[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }

    cout << "Multiplication of Matrices \n";
    display(result, 3, 3);

    return 0;
}