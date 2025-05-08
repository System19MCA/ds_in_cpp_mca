#include <iostream>
#include <vector>
#include <map>
using namespace std;

template <class T>
class SparseEntry
{
public:
    int row, col;
    T val;
    SparseEntry(int r, int c, T v)
    {
        row = r;
        col = c;
        val = v;
    }
    friend ostream &operator<<(ostream &os, SparseEntry<T> &s)
    {
        os << "[" << s.row << "," << s.col << "," << s.val << "]";
        return os;
    }

    bool operator==(const SparseEntry<T> &other) const
    {
        return this->row == other.row && this->col == other.col;
    }

    bool operator>(const SparseEntry<T> &other) const
    {
        return this->row > other.row || (this->row == other.row && this->col > other.col);
    }

    bool operator<(const SparseEntry<T> &other) const
    {
        return this->row < other.row || (this->row == other.row && this->col < other.col);
    }

    int compare(SparseEntry<T> &s)
    {
        if (this->row == s.row)
        {
            if (this->col == s.col)
                return 0;
            else if (this->col < s.col)
                return -1;
            return 1;
        }
        else if (this->row < s.row)
            return -1;
        return 1;
    }
};

template <class T>
class SparseMatrix
{
    vector<SparseEntry<T>> list;

public:
    SparseMatrix() {}
    SparseMatrix(vector<vector<T>> matrix)
    {
        int rows = matrix.size();
        if (rows == 0)
            return;
        int cols = matrix.at(0).size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] != 0)
                {
                    SparseEntry<T> sp(i, j, matrix[i][j]);
                    list.push_back(sp);
                }
            }
        }
    }

    friend ostream &operator<<(ostream &os, SparseMatrix<T> &sm)
    {
        int size = sm.list.size();
        for (int i = 0; i < size; i++)
            os << sm.list.at(i) << endl;
        return os;
    }

    SparseMatrix operator+(SparseMatrix &s2)
    {
        int size1 = this->list.size(), size2 = s2.list.size(), i = 0, j = 0;
        SparseMatrix temp;
        while (i < size1 && j < size2)
        {
            if (this->list[i] == s2.list[j])
            {
                SparseEntry<T> sp(this->list[i].row, s2.list[j].col, this->list[i].val + s2.list[j].val);
                temp.list.push_back(sp);
                i++;
                j++;
            }
            else if (this->list[i] < s2.list[j])
            {
                SparseEntry<T> sp(this->list[i].row, this->list[i].col, this->list[i].val);
                temp.list.push_back(sp);
                i++;
            }
            else
            {
                SparseEntry<T> sp(s2.list[j].row, s2.list[j].col, s2.list[j].val);
                temp.list.push_back(sp);
                j++;
            }
        }
        while (i < size1)
        {
            SparseEntry<T> sp(this->list[i].row, this->list[i].col, this->list[i].val);
            temp.list.push_back(sp);
            i++;
        }
        while (j < size2)
        {
            SparseEntry<T> sp(s2.list[j].row, s2.list[j].col, s2.list[j].val);
            temp.list.push_back(sp);
            j++;
        }
        return temp;
    }

    SparseMatrix operator-(SparseMatrix &s2)
    {
        int size1 = this->list.size(), size2 = s2.list.size(), i = 0, j = 0;
        SparseMatrix temp;
        while (i < size1 && j < size2)
        {
            if (this->list[i] == s2.list[j])
            {
                if (this->list[i].val != s2.list[j].val)
                {
                    SparseEntry<T> sp(this->list[i].row, s2.list[j].col, this->list[i].val - s2.list[j].val);
                    temp.list.push_back(sp);
                }
                i++;
                j++;
            }
            else if (this->list[i] < s2.list[j])
            {
                SparseEntry<T> sp(this->list[i].row, this->list[i].col, this->list[i].val);
                temp.list.push_back(sp);
                i++;
            }
            else
            {
                SparseEntry<T> sp(s2.list[j].row, s2.list[j].col, s2.list[j].val);
                temp.list.push_back(sp);
                j++;
            }
        }
        while (i < size1)
        {
            SparseEntry<T> sp(this->list[i].row, this->list[i].col, this->list[i].val);
            temp.list.push_back(sp);
            i++;
        }
        while (j < size2)
        {
            SparseEntry<T> sp(s2.list[j].row, s2.list[j].col, s2.list[j].val);
            temp.list.push_back(sp);
            j++;
        }
        return temp;
    }

    SparseMatrix operator&(SparseMatrix &s2) // intersection
    {
        int size1 = this->list.size(), size2 = s2.list.size(), i = 0, j = 0;
        SparseMatrix temp;
        while (i < size1 && j < size2)
        {
            if (this->list[i] == s2.list[j])
            {
                SparseEntry<T> sp(this->list[i].row, s2.list[j].col, this->list[i].val);
                temp.list.push_back(sp);
            }
            i++;
            j++;
        }
        return temp;
    }

    SparseMatrix operator|(SparseMatrix &s2) // union
    {
        int size1 = this->list.size(), size2 = s2.list.size(), i = 0, j = 0;
        SparseMatrix temp;
        while (i < size1 && j < size2)
        {
            if (this->list[i] == s2.list[j])
            {
                SparseEntry<T> sp(this->list[i].row, s2.list[j].col, this->list[i].val);
                temp.list.push_back(sp);

                i++;
                j++;
            }
            else if (this->list[i] < s2.list[j])
            {
                SparseEntry<T> sp(this->list[i].row, this->list[i].col, this->list[i].val);
                temp.list.push_back(sp);
                i++;
            }
            else
            {
                SparseEntry<T> sp(s2.list[j].row, s2.list[j].col, s2.list[j].val);
                temp.list.push_back(sp);
                j++;
            }
        }
        while (i < size1)
        {
            SparseEntry<T> sp(this->list[i].row, this->list[i].col, this->list[i].val);
            temp.list.push_back(sp);
            i++;
        }
        while (j < size2)
        {
            SparseEntry<T> sp(s2.list[j].row, s2.list[j].col, s2.list[j].val);
            temp.list.push_back(sp);
            j++;
        }
        return temp;
    }

    SparseMatrix operator*(SparseMatrix &other)
    {
        SparseMatrix result;
        map<pair<int, int>, T> temp;

        for (auto &a : this->list)
        {
            for (auto &b : other.list)
            {
                if (a.col == b.row)
                {
                    temp[{a.row, b.col}] += a.val * b.val;
                }
            }
        }

        for (auto &entry : temp)
        {
            if (entry.second != 0)
            {
                result.list.push_back(SparseEntry<T>(entry.first.first, entry.first.second, entry.second));
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> v1 = {{0, 2, 0},
                              {4, 0, 0},
                              {0, 8, 0}};
    vector<vector<int>> v2 = {{0, 2, 0},
                              {4, 0, 0},
                              {0, 0, 3}};

    SparseMatrix<int> s1(v1);
    SparseMatrix<int> s2(v2);

    SparseMatrix<int> s3 = s1 + s2;
    SparseMatrix<int> s4 = s1 - s2;
    SparseMatrix<int> s5 = s1 & s2;
    SparseMatrix<int> s6 = s1 | s2;
    SparseMatrix<int> s7 = s1 * s2;
    cout << "Multiplication Result:\n"
         << s7;

    return 0;
}