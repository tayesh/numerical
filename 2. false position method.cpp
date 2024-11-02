#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return pow(x,3)-4*pow(x,2)-3*x+2;}
double falsePosition(double a, double b, double tol) {
    double c;
    while ((b - a) >= tol) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (f(c) == 0.0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }
    return c;
}

int main() {
    double a = -8, b = 7, c, d, tol = 0.00001;
    double minDistance = b - a;
    for (double i = a; i < b; i += 0.5)
        for (double j = i + 0.5; j <= b; j += 0.5) {
            if (f(i) * f(j) < 0 && abs(j - i) < minDistance) {
                    if(f(i)>0)c=i;else d=i;
                c==i?d=j:c=j;
                minDistance = abs(j - i);
            }}
        double root = falsePosition(c, d, tol);
        cout << "The root of the function is " << root << endl;
}
