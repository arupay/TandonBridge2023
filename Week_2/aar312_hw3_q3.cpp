#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double numA, numB, numC, discriminant, sqrtResult, solutionOne, solutionTwo;
    cout << "Please enter a value for a: " << endl;
    cin >> numA;
    cout << "Please enter a value for b: " << endl;
    cin >> numB;
    cout << "Please enter a value for c: " << endl;
    cin >> numC;

    discriminant = pow(numB, 2) - (4 * (numA) * (numC));
    sqrtResult = sqrt(discriminant);
    solutionOne = (-(numB) + sqrtResult) / (2 * numA);
    solutionTwo = (-(numB)-sqrtResult) / (2 * numA);

    if (numA == 0 && numB == 0 && numC == 0)
        cout << "This equation has an infinite number of solutions";
    else if (numA == 0 && numB == 0)
        cout << "This equation has no solution";
    else if (discriminant < 0)
        cout << "This equation has an no real solution";
    else if (discriminant == 0)
        cout << "This equation has a single real solution x = " << solutionOne << endl;
    else if (discriminant > 0)
        cout << "This equation has a two real solutions x1 = " << solutionOne << " and x2 = " << solutionTwo << endl;
    return 0;
}