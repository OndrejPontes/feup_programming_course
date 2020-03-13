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

void Lab_02::task_03()
{
    int a, b;

    std::cout << "Task 2.3 INT_MAX and INT_MIN tester" << std::endl;
	
    std::cout << "Give me first number: ";
    std::cin >> a;
	std::cout << "Give me next number: ";
    std::cin >> b;

    if (b > 0 && a > INT_MAX - b)
        std::cout << "sum overflow" << std::endl;
    else if (b < 0 && a < INT_MIN - b)
        std::cout << "sum underflow" << std::endl;
    else
        std::cout << "Hooray, numbers are countable. Result is: " << a + b << std::endl;
}

void Lab_02::task_04()
{
    int weight;
	
    std::cout << "Task 2.4 merchandise transport price calculator." << std::endl;
    std::cout << "Give me weight of merchandise in grams: ";
    std::cin >> weight;

    std::cout << "Total price is: ";
    if (weight <= 500)
        std::cout << "5 euros." << std::endl;
    else if (weight <= 1000)
        std::cout << 5 + 1.5 * ceil((weight - 500) / float(100)) << " euros." << std::endl;
    else
        std::cout << 12.5 + 5 * ceil((weight - 1000) / float(250)) << " euros." << std::endl;     
}

void Lab_02::task_05()
{
    std::vector<int> input;
    double diskriminant;
	
    std::cout << "Task 2.5 calculator of quadratic equation." << std::endl;
    std::cout << "Solution of Ax^2 + Bx + C = 0" << std::endl;
    std::cout << "Insert the coefficients (A B C): ";
	
    input = getNumbersFromUser();
    diskriminant = std::pow(input.at(1), 2) - 4 * input.at(0) * input.at(2);

    if (diskriminant < 0)
        std::cout << "Equation doesn't have any solution in real numbers." << std::endl;
    else if (diskriminant == 0)
        std::cout << "The equation has 1 complex root: " << -input.at(1) / 2 * input.at(0) << std::endl;
    else
    {
        double x1 = -input.at(1) + std::sqrt(diskriminant) / 2 * input.at(0);
        double x2 = -input.at(1) - std::sqrt(diskriminant) / 2 * input.at(0);
        std::cout << "The equation has 2 complex roots: " << x1 << " and " << x2 << std::endl;
    }
}




