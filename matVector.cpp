#include <iostream>
#include <vector>

using namespace std;

typedef vector<double> Row;

class Matrix: public vector<Row>{
    int rows, cols;
    public:
    Matrix():vector<Row>(){
        rows=0;
        cols=0;
    }
    Matrix(int rows,int cols);
    int Rows() const;
    int columns() const;
    Matrix operator+(const Matrix &mat2);
    void Read(istream &in);
    void Print(ostream &out) const;
    friend istream &operator >>(istream &in, Matrix &mt);
    friend ostream &operator << (ostream &os, const Matrix &mt);
};

inline Matrix:: Matrix(int rows, int cols):vector<Row>(rows,Row(cols)){
  if(rows>0&& cols >0){
    this->rows= rows;
    this->cols= cols;
  }
}