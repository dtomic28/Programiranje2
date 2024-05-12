//
// Created by Danijel Tomić on 12. 05. 24.
//

#ifndef PROGRAMIRANJE2_MATRIX_H
#define PROGRAMIRANJE2_MATRIX_H
#include <vector>
#include <ostream>
#include <stdexcept>
template <class T>
class Matrix
{
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        for (const auto& row : matrix.data)
        {
            for (const auto& elem : row)
            {
                os << elem << " ";
            }
            os << "\n";
        }
        return os;
    }

private:
    std::vector<std::vector<T>> data;
    unsigned int rows;
    unsigned int cols;

public:
    Matrix(unsigned int rows, unsigned int cols)
        : rows(rows)
        , cols(cols)
    {
        data = std::vector<std::vector<T>>(rows, std::vector<T>(cols));
    }
    ~Matrix()
    {
        data.clear();
    }

    void setData(std::vector<std::vector<T>> newData)
    {
        if (!IsMatrixCorrectDimension(cols, rows, newData))
        {
            throw std::invalid_argument("Matrix not right size");
        }

        data = newData;
    }
    Matrix operator+(const Matrix& right)
    {
        if (!IsMatrixCorrectDimension(*this, right))
        {
            throw std::invalid_argument("Matrix not right size");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] + right.data[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix& right)
    {
        if (!IsMatrixCorrectDimension(*this, right))
        {
            throw std::invalid_argument("Matrix not right size");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] - right.data[i][j];
            }
        }
        return result;
    }
    Matrix operator++()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j]++;
            }
        }
        return *this;
    }
    Matrix operator++(int dummy)
    {
        Matrix tmp(*this);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j]++;
            }
        }
        return tmp;
    }

    static bool IsMatrixCorrectDimension(unsigned int cols, unsigned int rows, std::vector<std::vector<T>> data)
    {
        if (data.size() != rows)
            return false;
        for (int i = 0; i < rows; i++)
        {
            if (data[i].size() != cols)
                return false;
        }
        return true;
    }

    static bool IsMatrixCorrectDimension(const Matrix& left, const Matrix& right)
    {
        return (left.cols == right.cols && left.rows == right.rows);
    }
};

#endif  // PROGRAMIRANJE2_MATRIX_H
