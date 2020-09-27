#ifndef _UT_GAUSS_HPP_
#define _UT_GAUSS_HPP_
#include <cassert>
#include <sstream>

#include "src/gauss.hpp"

namespace gauss
{
    namespace test
    {
        void Test_CrossProduct()
        {
            std::cout << "Cross product:" << std::endl;
            vec u{ 2,  4, -3 };
            vec v{ -3,  4,  8 };
            vec w1{ 44, -7, 20 };
            vec w2 = CrossProduct(u, v);

            for (int i = 0; i < w1.size(); i++)
            {
                std::stringstream ss;
                assert((w1[i] == w2[i]) && "Cross Product : wrong answer");
                std::cout << "    verify index " << i << ": PASS" << std::endl;
            }
        }

        void TestAll()
        {
            Test_CrossProduct();
        }
    }
}


#endif _UT_GAUSS_HPP_