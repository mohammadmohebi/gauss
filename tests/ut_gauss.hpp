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

            Test_Speed();
            std::cout << std::endl;
        }
    }
}


#endif _UT_GAUSS_HPP_