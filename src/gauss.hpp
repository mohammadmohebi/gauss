#ifndef _G_GAUSS_HPP_
#define _G_GAUSS_HPP_
#include <vector>
#include <math.h>

namespace gauss
{
    typedef std::vector<double> vec;
    typedef std::vector<std::vector<double> > matrix;
    #define GAUSS_PI 3.14159265358979324
    #define GAUSS_MIN_DBL DBL_MIN

    /**
     * Function find the vector norm.
     *
     * @param v Vector to use for the norm computation.
     * @return A scalar that give the value of the norm.
     */
    double VectorNorm(vec v)
    {
        double n = 0;
        if (!v.empty())
        {
            for (int i = 0; i < v.size(); i++)
                n += v[i] * v[i];
        }
        n = sqrt(n);

        return n;
    }

    /**
     * Function applies cross product to two 3d vectors. u x v = w.
     *
     * @param row Number of row for the matrix.
     * @param col Number of column for the matrix.
     * @param val Value to set to every element.
     * @return Matrix with row and col size.
     */
    matrix Matrix(int row, int col, double val = 0)
    {
        matrix m(row);
        for (size_t i = 0; i < m.size(); i++)
            m[i].resize(col, val);

        return m;
    }

    matrix Matrix(size_t row, size_t col, double val = 0)
    {
        return Matrix((int)row, (int)col, val);
    }

    /**
     * Function that create an identity matrix of size n.
     *
     * @param n Size of matrix (n x n square matrix).
     * @return n x n square matrix wiht ones on the main diagonal.
     */
    matrix MatrixI(int n)
    {
        matrix m = Matrix(n, n);
        for (size_t i = 0; i < n; i++)
            m[i][i] = 1;
        return m;
    }

    matrix MatrixI(size_t n)
    {
        return MatrixI((int)n);
    }

    /**
    * Function that create a diagonal matrix with values given as an array.
    *
    * @param d Array of values to use for the diagonal (d.size() x d.size() square matrix)
    * @return d.size() x d.size() square matrix with diagonal 
    * having the same values as passed as an array.
    */
    matrix MatrixD(std::vector<double> d)
    {
        matrix m = Matrix(d.size(), d.size());
        for (size_t i = 0; i < d.size(); i++)
            m[i][i] = d[i];
        return m;
    }

    /**
    * Function that swap two column.
    *
    * @param m Matrix used during swap.
    * @param c1 Index of the first column (0 based index).
    * @param c2 Index of the second column (0 based index).
    *
    */
    void MatrixSwapCol(matrix& m, size_t c1, size_t c2)
    {
        if (!m.empty() && c1 < m[0].size() && c2 < m[0].size())
        {
            double v1;
            for (int i = 0; i < m.size(); i++)
            {
                v1 = m[i][c1];
                m[i][c1] = m[i][c2];
                m[i][c2] = v1;
            }
        }
    }

    /**
    * Function that swap two row.
    *
    * @param m Matrix used during swap.
    * @param r1 Index of the first row (0 based index).
    * @param r2 Index of the second row (0 based index).
    *
    */
    void MatrixSwapRow(matrix& m, size_t r1, size_t r2)
    {
        if (!m.empty() && r1 < m[0].size() && r1 < m[0].size())
        {
            m[r1].swap(m[r2]);
        }
    }

    /*
    
    */
    double MatrixDet(const matrix& m)
    {
        double det = 0;
        if (!m.empty() && !m[0].empty() && m.size() == m[0].size())
        {
            matrix tm = m;
            det = 1;
            for (size_t i = 0; i < tm.size(); i++)
            {
                size_t jj = i;
                for (size_t j = i + 1; j < tm.size(); j++)
                {
                    if(abs(tm[j][j]) > abs(tm[jj][i]))
                        jj = j;
                }

                if (abs(tm[jj][i]) < GAUSS_MIN_DBL)
                {
                    det = 0;
                    break;
                }

                if (jj != i)
                {
                    MatrixSwapRow(tm, i, jj);
                    det = -det;
                }
                
                for (size_t j = i + 1; j < tm.size(); ++j)
                    tm[i][j] /= tm[i][i];

                for (size_t j = 0; j < tm.size(); ++j)
                {
                    if (j != i && abs(tm[j][i]) > GAUSS_MIN_DBL)
                    {
                        for (size_t ii = i + 1; ii < tm.size(); ++ii)
                            tm[j][ii] -= tm[i][ii] * tm[j][i];
                    }
                }

                det *= tm[i][i];
            }
        }

        return det;
    }

    /**
     * Multiplication between two matrices A and B. Number of
     * column in A should be equal to number of row in B ( A: q by n, B: n by b ).
     *
     * @param A Left matrix for the multiplication.
     * @param B Right matrix for the multiplication.
     *
     * @return Result of the multiplication. The matrix has a shape of q by b if A is
     * q by n and B is n by b.
     */
    matrix MatrixMulti(const matrix& A, const matrix& B)
    {
        matrix C;
        if (A.empty() || B.empty())
            return C;

        if (A[0].empty() || A[0].size() != B.size())
            return C;

        C = Matrix(A.size(), B[0].size());
        for (size_t i = 0; i < A.size(); i++)
        {
            for (size_t jj = 0; jj < C[i].size(); jj++)
            {
                double v = 0;
                for (size_t j = 0; j < A[i].size(); j++)
                    v += A[i][j] * B[j][jj];
                C[i][jj] = v;
            }
        }

        return C;
    }

    /**
     * Function applies cross product to two 3d vectors. u x v = w.
     *
     * @param u First vector of size 3.
     * @param v Second vector of size 3.
     * @return Resulting vector of cross product.
     */
    vec CrossProduct(vec u, vec v)
    {
        vec w;
        if (u.size() == 3 && v.size() == 3)
        {
            w.resize(3);
            w[0] = u[1] * v[2] - u[2] * v[1];
            w[1] = u[2] * v[0] - u[0] * v[2];
            w[2] = u[0] * v[1] - u[1] * v[0];
        }
        return w;
    }

    /**
     * Function applies dot product to two vectors. u • v = k. 
     *
     * @param u First vector for cross product.
     * @param v Second vector for cross product.
     * @return Resulting scalar for the dot product.
     */
    double DotProduct(vec u, vec v)
    {
        double k = 0;
        if (u.size() == v.size())
        {
            for(size_t i = 0; i < u.size(); i++)
                k += u[i] * v[i];
        }
        return k;
    }

    /**
     * Find angle between two vector.
     *
     * @param a First vector.
     * @param b Second vector.
     * @param degree If the result should be in degree or radion (default radian).
     *
     * @return Angle between vector a and b in radian by default. The result angle is
     * between -PI and PI.
     *
     */
    double VectorsAngle(vec a, vec b, bool degree = false)
    {
        double na = VectorNorm(a);
        double nb = VectorNorm(b);
        double dot_ab = DotProduct(a, b);

        double angle = acos(dot_ab / (na * nb));

        if(degree)
            angle = (angle * 180.0) / GAUSS_PI;

        return angle;
    }
}

#endif
