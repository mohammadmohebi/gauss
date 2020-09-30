#ifndef _G_GAUSS_HPP_
#define _G_GAUSS_HPP_
#include <vector>
#include <math.h>

namespace gauss
{
    typedef std::vector<double> vec;
    typedef std::vector<std::vector<double> > matrix;

    /**
     * Function find the vector norm
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
        n = pow(n, 1.0/(double)(v.size()));

        return n;
    }

    /**
     * Function applies cross product to two 3d vectors. u x v = w
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
     * Function that create an identity matrix of size n
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
     * Function applies cross product to two 3d vectors. u x v = w 
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
     * Function applies dot product to two vectors. u • v = k 
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
            for(int i = 0; i < u.size(); i++)
                k += u[i] * v[i];
        }
        return k;
    }

    /*
    
    */
    matrix MatrixMulti(matrix A, matrix B)
    {
        matrix C;
        if(A.empty() || B.empty())
            return C;

        if(A[0].empty() || A[0].size() != B.size())
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

    double VectorsAngle(vec a, vec b)
    {

    }
}

#endif
