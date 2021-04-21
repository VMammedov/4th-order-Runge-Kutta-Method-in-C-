#include <iostream>
using namespace std;

double f(double x, double y, double z)
{
    return z;
}

double g(double x, double y, double z)
{
    return (double)(x * z) / (2 * x + 1); // your equation
}

double rungeKutta(double x0, double y0, double z0, double h, int n, double &zn)
{
    double k1, k2, k3, k4, q1, q2, q3, q4;

    double y = y0;
    double z = z0;
    for (int i = 1; i <= n; i++)
    {
        k1 = h * f(x0, y, z);
        q1 = h * g(x0, y, z);
        k2 = h * f(x0 + 0.5 * h, y + 0.5 * h * k1, z0 + 0.5 * h * q1);
        q2 = h * g(x0 + 0.5 * h, y + 0.5 * h * k1, z0 + 0.5 * h * q1);
        k3 = h * f(x0 + 0.5 * h, y + 0.5 * h * k2, z0 + 0.5 * h * q2);
        q3 = h * g(x0 + 0.5 * h, y + 0.5 * h * k2, z0 + 0.5 * h * q2);
        k4 = h * f(x0 + h, y + h * k3, z0 + h * q3);
        q4 = h * g(x0 + h, y + h * k3, z0 + h * q3);

        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        z = z + (1.0 / 6.0) * (q1 + 2 * q2 + 2 * q3 + q4);

        x0 = x0 + h;
    }
    zn = z;

    return y;
}

int main()
{
    double x0, y0, z0, h, zn;
    int n;
    cout << "Initial value Problem X0 : ";
    cin >> x0;
    cout << "Initial value Problem Y0 : ";
    cin >> y0;
    cout << "Initial value Problem Z0 : ";
    cin >> z0;
    cout << "Step H : ";
    cin >> h;
    cout << "The number of iterations N : ";
    cin >> n;
    cout << "The value of y : " << rungeKutta(x0, y0, z0, h, n, zn) << endl;
    cout << "The value of z : " << zn << endl;
    return 0;
}