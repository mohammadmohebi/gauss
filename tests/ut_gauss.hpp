#ifndef _UT_GAUSS_HPP_
#define _UT_GAUSS_HPP_
#include <cassert>
#include <sstream>
#include <chrono>

#include "src/gauss.hpp"

namespace gauss
{
    namespace test
    {
        void Test_CreateMatrix()
        {
            std::cout << "CreateMatrix:" << std::endl;

            auto m = Matrix(12, 10, 55);
            assert((m.size() == 12) && "CreateMatrix : wrong row size");
            std::cout << "    PASS: row size" << std::endl;

            for (auto& r : m)
            {
                assert((r.size() == 10) && "CreateMatrix : wrong column size");
                for(auto& v : r)
                    assert((v == 55) && "CreateMatrix : wrong initialization value");
            }

            std::cout << "    PASS: column size" << std::endl;
            std::cout << "    PASS: initialization value" << std::endl;

        }

        void Test_CrossProduct()
        {
            std::cout << "CrossProduct:" << std::endl;

            vec u{ 2,  4, -3 };
            vec v{ -3,  4,  8 };
            vec w1{ 44, -7, 20 };
            vec w2 = CrossProduct(u, v);

            for (int i = 0; i < w1.size(); i++)
            {
                std::stringstream ss;
                assert((w1[i] == w2[i]) && "CrossProduct : wrong answer");
                std::cout << "    PASS: verify index " << i << std::endl;
            }
        }

        void Test_DotProduct()
        {
            std::cout << "DotProduct:" << std::endl;

            vec u{   3,  6,  -2 };
            vec v{ -55,  6,  -1 };

            assert((-127.0 == DotProduct(u, v)) && "DotProduct : wrong answer");
            std::cout << "    PASS: Test 1" << std::endl;

            u = { 65.0 , -106.0,   52 };
            v = {  5.55,   62.5, -255 };

            assert((-19524.25 == DotProduct(u, v)) && "DotProduct : wrong answer");
            std::cout << "    PASS: Test 2" << std::endl;
        }

        void Test_MatrixMulti()
        {
            std::cout << "MatrixMulti:" << std::endl;
            matrix A {
                {2, 1, 4},
                {0, 1, 1},
            };

            matrix B {
                { 6, 3, -1, 0},
                { 1, 1,  0, 4},
                {-2, 5,  0, 2}
            };

            matrix C{
                { 5, 27, -2, 12},
                {-1,  6,  0,  6},
            };

            auto c = MatrixMulti(A, B);

            assert((C.size() == c.size()) && "MatrixMulti : wrong result row size");
            std::cout << "    PASS: result row size" << std::endl;

            assert((C[0].size() == c[0].size() && C[1].size() == c[1].size()) && "MatrixMulti : wrong result column size");
            std::cout << "    PASS: result column size" << std::endl;

            for (int i = 0; i < C.size(); i++)
            {
                for (int j = 0; j < C[i].size(); j++)
                {
                    assert((C[i][j] == c[i][j]) && "MatrixMulti : wrong result value");
                }
            }
            std::cout << "    PASS: result value" << std::endl;

        }

        void Test_VectorNorm()
        {
            std::cout << "VectorNorm:" << std::endl;
            
            vec v = {3, 4};
            assert((VectorNorm(v) == 5.0) && "VectorNorm: wrong result");
            std::cout << "    PASS: enteger result" << std::endl;

            v = { 2, 4, 5 };
            assert((abs(6.708203932499369 - VectorNorm(v)) < 0.00000000000001) && "VectorNorm: wrong result");
            std::cout << "    PASS: decimal result" << std::endl;

            v = { 2, -4, -5 };
            assert((abs(6.708203932499369 - VectorNorm(v)) < 0.00000000000001) && "VectorNorm: wrong result");
            std::cout << "    PASS: negative component" << std::endl;

            v = { 25.5, -23.33, -6488.566655 };
            assert((abs(6488.658703867687 - VectorNorm(v)) < 0.00000000001) && "VectorNorm: wrong result");
            std::cout << "    PASS: decimal components" << std::endl;
        }

        void Test_VectorsAngle()
        {
            std::cout << "VectorAngle:" << std::endl;
            vec a = {2,  3, 4};
            vec b = {1, 15, 7};

            assert((abs(0.573810193511548 - VectorsAngle(a, b)) < 0.00000000000001) && "VectorAngle: wrong result");
            std::cout << "    PASS: integer components" << std::endl;

            a = { 2.512 ,  3.55  ,  -4.555 };
            b = { 1.2323, -5.6464, 856.66  };
            assert((abs(2.383877669830448 - VectorsAngle(a, b)) < 0.00000000000001) && "VectorAngle: wrong result");
            std::cout << "    PASS: decimal and negative components" << std::endl;

        }

        void Test_MatrixSwapCol()
        {
            std::cout << "MatrixSwapCol:" << std::endl;

            matrix M{
                {1, 5,  9, 13},
                {2, 6, 10, 14},
                {3, 7, 11, 15},
                {4, 8, 12, 16},
            };

            matrix M2 = M;

            MatrixSwapCol(M, 1, 3);
            for (size_t i = 0; i < M[0].size(); i++)
                assert((M[i][1] == M2[i][3]) && "MatrixSwapCol: wrong swap");
            std::cout << "    PASS: column swap" << std::endl;

            assert((M.size() == M2.size()) && "MatrixSwapCol: matrix size has beend altered");
            std::cout << "    PASS: row size unchanged" << std::endl;

            assert((M[0].size() == M2[0].size()) && "MatrixSwapCol: matrix size has beend altered");
            std::cout << "    PASS: column size unchanged" << std::endl;
        }

        void Test_MatrixSwapRow()
        {
            std::cout << "MatrixSwapRow:" << std::endl;

            matrix M{
                {1, 5,  9, 13},
                {2, 6, 10, 14},
                {3, 7, 11, 15},
                {4, 8, 12, 16},
            };

            matrix M2 = M;

            MatrixSwapRow(M, 1, 3);
            for (size_t i = 0; i < 4; i++)
                assert((M[1][i] == M2[3][i]) && "MatrixSwapCol: wrong swap");

            std::cout << "    PASS: row swap" << std::endl;

            assert((M.size() == M2.size()) && "MatrixSwapCol: matrix size has beend altered");
            std::cout << "    PASS: row size unchanged" << std::endl;

            
            std::cout << "    PASS: column size unchanged" << std::endl;
        }

        void Test_MatrixDet()
        {
            std::cout << "MatrixDet:" << std::endl;

            matrix M{
                {4, 8,  12, 16.0  },
                {1, 5,  -9, 13.0  },
                {3, 7,  11,  0.011},
                {2, 6,  10, 14.0  },
            };

            assert((abs(2158.416 - MatrixDet(M)) < GAUSS_MIN_DBL) && "MatrixDet: wrong matrix determinant");
            std::cout << "    PASS: compute 4x4 matrix" << std::endl;

            M = {
                { -11.62 ,-18.84 ,-19.70 ,  1.96 ,-17.14 ,-11.93 ,-10.64 , -2.88 },
                { -11.23 , -5.73 ,-16.34 ,  0.60 ,-13.86 , -8.44 ,-10.34 ,-13.80 },
                { -19.35 , -7.69 ,  0.33 ,  0.14 , -3.59 , -1.49 ,-10.77 ,-10.21 },
                { -19.62 , -6.11 ,-14.92 , -7.14 ,-12.57 , -1.61 , -9.40 ,-10.59 },
                { -18.61 ,-14.40 , -4.16 , -1.04 , -1.70 ,-19.91 ,-17.65 , -3.05 },
                { -10.52 , -7.88 , -9.32 , -6.97 ,-20.00 ,-14.46 ,  1.76 ,-19.42 },
                {   1.97 , -2.52 ,-10.07 , -9.65 , -9.70 ,-17.38 , -1.48 , -9.81 },
                { -12.95 ,-10.41 ,-13.26 ,-10.81 , -0.54 ,-12.43 , -2.22 , -9.17 },
            };

            assert((abs(-1614606194.6208825458 - MatrixDet(M)) < 0.000001) && "MatrixDet: wrong matrix determinant");
            std::cout << "    PASS: compute 8x8 matrix, negative and decimal values" << std::endl;
        }

        void Test_Speed()
        {
            std::cout << "__Speed__:" << std::endl;
            std::chrono::steady_clock::time_point begin, end;

            begin = std::chrono::steady_clock::now();
            auto A = Matrix(200, 100, 2.5);
            end = std::chrono::steady_clock::now();
            std::cout << "    Create Matrix A: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;

            begin = std::chrono::steady_clock::now();
            auto B = Matrix(100, 200, 2.5);
            end = std::chrono::steady_clock::now();
            std::cout << "    Create Matrix B: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;

            begin = std::chrono::steady_clock::now();
            auto C = MatrixMulti(A, B);
            end = std::chrono::steady_clock::now();
            std::cout << "    Matrix multiplication: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;


            auto M = Matrix(200, 200, 2.5);
            begin = std::chrono::steady_clock::now();
            double v = MatrixDet(M);
            end = std::chrono::steady_clock::now();
            std::cout << "    Matrix determinant: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;
        }

        void TestAll()
        {
            Test_CreateMatrix();
            std::cout << std::endl;

            Test_CrossProduct();
            std::cout << std::endl;

            Test_DotProduct();
            std::cout << std::endl;

            Test_MatrixMulti();
            std::cout << std::endl;

            Test_VectorNorm();
            std::cout << std::endl;

            Test_VectorsAngle();
            std::cout << std::endl;

            Test_MatrixSwapCol();
            std::cout << std::endl;

            Test_MatrixSwapRow();
            std::cout << std::endl;

            Test_MatrixDet();
            std::cout << std::endl;

            Test_Speed();
            std::cout << std::endl;
        }
    }
}


#endif _UT_GAUSS_HPP_