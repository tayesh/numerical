#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return pow(x,3)-4*pow(x,2)-4*x+2;
}
double secant(double x0, double x1, double tol)
{
    double x2;
    int i=0, m=1000;
    while(i<m)
    {
        x2= x1 -((f(x1)*(x1-x0)) / (f(x1)-f(x0)));
        if(abs(x2-x1)<tol)return x2;
        x0=x1;
        x1=x2;
        i++;
    }
    return x2;
}
int main()
{
    double x0=0, x1=.5, tol=0.0001;
    double root=secant(x0,x1,tol);
    cout<<"The root is "<<root;
}
