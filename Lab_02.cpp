#include "Lab_02.h"

void Lab_02::task_01()
{
    int a, b, c, d, e, f;
    float x, y;

    std::cout << "Task 2.1 Linear equation solver for two variables" << std::endl
        << "Enter proper values to substitute" << std::endl << "a * x + b * y = c" << std::endl << "d * x + e * y = f " << std::endl;

    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;
    std::cout << "Enter d: ";
    std::cin >> d;
    std::cout << "Enter e: ";
    std::cin >> e;
    std::cout << "Enter f: ";
    std::cin >> f;

    x = float(c * e - b * f) / float(a * e - b * d);
    y = float(a * f - c * d) / float(a * e - b * d);

    if (isnan(x) || isnan(y))
    {
        std::cout << "impossible system" << std::endl;
    }
    else
    {
        std::cout << "x = " << x;
        std::cout << "y = " << y;
    }
}
