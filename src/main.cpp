#include <stdio.h>

#include "math/matrix.h"

constexpr Matrix<2, 3> a = Matrix<2, 3>({
    {1.0f, 2.0f, 3.0f},
    {4.0f, 5.0f, 6.0f}
});

constexpr Matrix<3, 1> b = Matrix<3, 1>({{7.0f}, {8.0f}, {9.0f}});

int main() {
    printf("Matrix A :\n");
    a.print();

    printf("Matrix B :\n");
    b.print();

    printf("\nResult :\n");
    auto c = a * b;
    c.print();

    return 0;
}
