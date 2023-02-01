#include <iostream>

int main(int argc, char* argv[])
{
    int a, b;
    char op;
    std::cin >> a >> op >> b;
    switch (op)
    {
    case '+':
        std::cout << a + b << '\n';
        break;
    case '-':
        std::cout << a - b << '\n';
        break;
    case '*':
        std::cout << a * b << '\n';
        break;
    case '/':
        if (b == 0) {
            std::cout << "Divide for zero" << '\n';
            break;
        }
        else {
            std::cout << a / b << '\n';
            break;
        }
    case '%':
        if (b == 0) {
            std::cout << "Divide for zero" << '\n';
            break;
        }
        else {
            std::cout << a % b << '\n';
            break;
        }
    }
}