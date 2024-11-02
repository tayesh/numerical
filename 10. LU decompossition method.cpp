#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return pow(x,3)-4*pow(x,2)-2*x+3;
}
double trapezoidal(double l, double u, int n)
{
    double h=(u-l)/n;
    double sum=f(u)+f(l);
    for(int i=1; i<n; i++)
    {
        double x=l+h*i;
        sum+=2*f(x);
    }
    return (h/2)*sum;
}
int main()
{
    int n;
    double u, l;
    cout<<"Enter upper limit: ";
    cin>>u;
    cout<<"\nEnter lower limit: ";
    cin>>l;
    cout<<"\nEnter number of intervals: ";
    cin>>n;
    double result=trapezoidal(l,u,n);
    cout<<"\nThe approximate value of the integral is "<<result;
}
