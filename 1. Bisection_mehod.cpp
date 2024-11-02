#include<bits/stdc++.h>
using namespace std;
double f(double x){
return pow(x,3)-4*pow(x,2)-3*x+2;
}

double bisection(double a, double b, double tol)
{
    double c;
    while((b-a)>=tol)
    {
        c=(a+b)/2;
        if(f(c)==0)break;
        else if(f(c)>0)a=c;
        else b=c;
    }
    return c;
}
int main()
{
    double a=-8, b=7, c, d, tol=0.0001;
       double minDistance = b - a;
    for (double i = a; i < b; i += 0.5)
        for (double j = i + 0.5; j <= b; j += 0.5) {
            if (f(i) * f(j) < 0 && abs(j - i) < minDistance) {
                   f(i)>0?c=i:d=i;
                c==i?d=j:c=j;
                minDistance = abs(j - i);
            }}
    double root = bisection(c, d, tol);
    cout<<"The root of the function is "<<root;
}

