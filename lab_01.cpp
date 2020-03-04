#include "Lab_01.h"
#include "utils.h"

void Lab_01::task_01()
{
    char x;

    std::cout << "Task 1.1 Write any character" << std::endl;
    std::cin >> x;
    std::cout << "ASCII value of character " << x << "is: " << int(x) << std::endl;
}

void Lab_01::task_02()
{
    int a, b, c;
    float mean;

    std::cout << "Task 1.2 Please, input 3 integer number" << std::endl;

    std::cout << "A ? ";
    std::cin >> a;
    std::cout << "B ? ";
    std::cin >> b;
    std::cout << "C ? ";
    std::cin >> c;

    mean = (a + b + c) / (float)3;

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    std::cout << "mean   = " << mean << std::endl;
    std::cout << "A-mean = " << mean - a << std::endl;
    std::cout << "B-mean = " << mean - b << std::endl;
    std::cout << "C-mean = " << mean - c << std::endl;
}

void Lab_01::task_03()
{
    float p, r;

    std::cout << "Task 1.3 Sphere mass calculator" << std::endl;

    std::cout << "Enter material in Kg/m^3: ";
    std::cin >> p;
    std::cout << "Enter radius in m: ";
    std::cin >> r;

    std::cout << "Mass of the sphere is: " << 4 / 3 * (p * M_PI * r) << "Kg" << std::endl;
}

void Lab_01::task_04()
{
    int a, b, c, d, e, f;
    float x, y;

    std::cout << "Task 1.4 Linear equation solver for two variables" << std::endl
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

    x = (float)(c * e - b * f) / (float)(a * e - b * d);
    y = (float)(a * f - c * d) / (float)(a * e - b * d);

    std::cout << "x = " << x;
    std::cout << "y = " << y;

}

void Lab_01::task_05()
{
    int h, m, s;
    std::vector<int> time1, time2;

    std::cout << "Task 1.5 Time counter" << std::endl;
    std::cout << "Time1 (hours minutes seconds) ? ";
    time1 = getNumbersFromUser();
    std::cout << "Time2 (hours minutes seconds) ? ";
    time2 = getNumbersFromUser();

    s = time1.at(2) + time2.at(2);
    m = time1.at(1) + time2.at(1) + s / 60;
    h = time1.at(0) + time2.at(0) + m / 60;

    std::cout << "Time1 + Time2 = " << h / 24 << " days, " << h % 24 << " hours, " << m % 60 << " minutes, " << s % 60 << " seconds." << std::endl;
}

class Vertex {
private:
    int x, y;

public:
    Vertex()
    {
        x = 0;
        y = 0;
    }

    Vertex(int x1, int y1)
    {
        x = x1;
        y = y1;
    }

    double distanceFrom(Vertex v)
    {
        return std::sqrt(std::pow(v.x - x, 2) + std::pow(v.y - y, 2));
    }
};

class Triangle
{
private:
    Vertex v1, v2, v3;
public:
    Triangle(Vertex c1, Vertex c2, Vertex c3)
    {
        v1 = c1;
        v2 = c2;
        v3 = c3;
    }

    double area(double s)
    {
        return std::sqrt(s * (s - v1.distanceFrom(v2)) * (s - v2.distanceFrom(v3)) * (s - v3.distanceFrom(v1)));
    }
};

void Lab_01::task_06()
{
    int x, y;
    double semiperimeter;
    Vertex a, b, c;

    std::cout << "Task 1.6: Triangle area counter" << std::endl;

    std::cout << "Enter x of vertex A: ";
    std::cin >> x;
    std::cout << "Enter y of vertex A: ";
    std::cin >> y;
    a = Vertex(x, y);

    std::cout << "Enter x of vertex B: ";
    std::cin >> x;
    std::cout << "Enter y of vertex B: ";
    std::cin >> y;
    b = Vertex(x, y);

    std::cout << "Enter x of vertex C: ";
    std::cin >> x;
    std::cout << "Enter y of vertex C: ";
    std::cin >> y;
    c = Vertex(x, y);

    Triangle t = Triangle(a, b, c);

    std::cout << "Enter semi-perimeter: ";
    std::cin >> semiperimeter;

    std::cout << "Area of your triangle is: " << t.area(semiperimeter);
}