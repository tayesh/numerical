#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return pow(x,3)-4*pow(x,2)-3*x+2;
}
double df(double x)
{
    return 3*pow(x,2)-8*x-3;
}
double newton(double initial_guess, double tol)
{
    double x0=initial_guess;
    double x1;
    int i=0, m=1000;
    while(i<m)
    {
        x1=x0-f(x0)/df(x0);
        x0=x1;
        i++;
        if(abs(x1-x0)==tol)return x1;
    }
    return x1;
}
int main()
{
    double initial_guess=0, tol=0.000000001;
    double root = newton(initial_guess, tol);
    cout<<fixed<<setprecision(9);
    cout<<"The root is "<<root;
}
