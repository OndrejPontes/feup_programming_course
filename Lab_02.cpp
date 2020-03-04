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

void Lab_02::task_02()
{
    int a, b, c;
    std::vector<int> numbers;

    std::cout << "Task 2.2 number evaluator." << std::endl;
    std::cout << "Give me first number: ";
	std::cin >> a;
    std::cout << "Give me second number: ";
    std::cin >> b;
    std::cout << "Give me third number: ";
    std::cin >> c;
    std::cout << std::endl;

    numbers = { a, b, c };
    std::sort(std::begin(numbers), std::end(numbers), std::greater<>());

    std::cout << "The biggest number is: " << numbers.at(0) << std::endl;

	std::cout << "Numbers in decreasing order: ";
    for (auto const& number : numbers)
        std::cout << number << " ";
    std::cout << std::endl;

    if (numbers.at(0) > numbers.at(1) + numbers.at(2))
        std::cout << "You can't create triangle with length of these sides." << std::endl;
    else
        std::cout << "You can create triangle with length of these sides." << std::endl;
}

