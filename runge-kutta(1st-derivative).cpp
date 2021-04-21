#include <iostream>
using namespace std;

double dydx(double x, double y)
{
    return (x * x - 2 * y); // your equation
}

double rungeKutta(double x0, double y0, double h, int n)
{
    double k1, k2, k3, k4;

    double y = y0;
    for (int i = 1; i <= n; i++)
    {
        k1 = h * dydx(x0, y);
        k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1);
        k3 = h * dydx(x0 + 0.5 * h, y + 0.5 * k2);
        k4 = h * dydx(x0 + h, y + k3);

        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4); ;

        x0 = x0 + h;
    }

    return y;
}

int main()
{
    double x0, y0, h;
    int n;
    cout << "Initial value Problem X0 : ";
    cin >> x0;
    cout << "Initial value Problem Y0 : ";
    cin >> y0;
    cout << "Step H : ";
    cin >> h;
    cout << "The number of interations N : ";
    cin >> n;
    cout << "The value of y : " << rungeKutta(x0, y0, h, n) << endl;
    return 0;
}