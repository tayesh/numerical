#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return pow(x,3)-4*pow(x,2)-2*x+3;
}
double simpsonthreeeight(double u, double l, int interval)
{
    double h=(u-l)/interval;
    double sum=f(u)+f(l);
    for(int i=1; i<interval; i++)
    {
        double x=l+i*h;
        if(i%3==0)
            sum+=2*f(x);
        else
            sum+=3*f(x);
    }
    return 3*h*sum/8;
}
int main()
{
    int n;
    double u, l;
    cout<<"Enter upper limit: ";
    cin>>u;
    cout<<"\nEnter lower limit: ";
    cin>>l;
    cout<<"\nEnter the number of intervals: ";
    cin>>n;
    double result = simpsonthreeeight(u,l,n);
    cout<<"\nThe approximate value of the integral is: "<<result;
}
