<br />
<p align="center">
  <h1 align="center">Gauss</h1>

  <p align="center">
    A lightweight and header only linear algebra library
  </p>
</p>

This library does not have dependencies besides the standard C++ library. Furthermore only `std::vector` container is used to create a matrix structure. This way that library can be integrated into any project. The syntax used inside the library source code is compatible with most of C++ version compilers. 

Matrix multiplication.
``` cpp
#include "gauss.hpp"

// gauss::matrix --> typedef std::vector<std::vector<double> > matrix;
gauss::matrix A {
    {2, 1, 4},
    {0, 1, 1}
};

gauss::matrix B {
    { 6, 3, -1, 0},
    { 1, 1,  0, 4},
    {-2, 5,  0, 2}
};

gauss::matrix C = gauss::MatrixMulti(A, B);

```

## Features

- Vector
- Matrix
- Identity matrix
- Diagonal matrix
- Cross product
- Dot product
- Matrix multiplication

More features are going to be developed.
