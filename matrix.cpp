#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Matrix
{
    vector<vector<T>> matrix;
    int rows, cols;

public:
    Matrix(int rows = 3, int cols = 3)
    {
        this->rows = rows;
        this->cols = cols;
        for (int i = 0; i < rows; i++)
        {
            vector<T> row(cols);
            matrix.push_back(row);
        }
    }

    void add(int r, int c, T data)
    {
        if (r >= rows || c >= cols || r < 0 || c < 0)
            throw exception();
        matrix[r][c] = data;
    }

    T get(int r, int c)
    {
        if (r >= rows || c >= cols || r < 0 || c < 0)
            throw exception();
        return matrix[r][c];
    }
    
    Matrix& operator+(Matrix& m2){
        if(m2.rows != this->rows || m2.cols != this->cols) throw exception();
        Matrix *res= new Matrix(this->rows, this->cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                res->matrix[i][j] = this->matrix[i][j] + m2.matrix[i][j];

        return *res;
    }
    // Matrix& operator*(Matrix& m2){
    //     if(m2.rows != this->cols || m2.cols != this->rows) throw exception();
    //     Matrix *res= new Matrix(this->rows, this->cols);
    //     for (int i = 0; i < rows; ++i)
    //         for (int j = 0; j < cols; ++j)
    //             for (int k = 0; k < cols; ++k)
    //                 res->matrix[i][j] += this->matrix[i][k] * m2.matrix[k][j];
    //     return *res;
    // }

    friend ostream &operator<<(ostream &os, Matrix &obj)
    {
        int n = obj.matrix.size();
        os << "[" << endl;
        for (int i = 0; i < n; i++)
        {
            int m = obj.matrix[i].size();
            os << "  [";
            for (int j = 0; j < m; j++)
            {
                os << obj.matrix[i][j];
                if (j < m - 1)
                    os << ", ";
            }
            os << "]";
            if (i < n - 1)
                os << ",";
            os << endl;
        }
        os << "]" << endl;
        return os;
    }
};

int main()
{
    Matrix<int> m(5, 11);
    m.add(1,2,3);
    Matrix<int> m2(7,5);
    m2.add(1,2,3);
    m2.add(1,4,3);
    // Matrix<int> m3 = m+m2;
    // Matrix<int> m4 = m*m2;
    // cout << m4;
    return 0;
}