#ifndef _G_GAUSS_HPP_
#define _G_GAUSS_HPP_
#include <vector>

namespace gauss
{
    typedef std::vector<double> vec;

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
}

#endif
