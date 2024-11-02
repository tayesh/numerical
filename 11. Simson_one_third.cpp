#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return pow(x,3)-4*pow(x,2)-2*x+3;
}
double simpsononethird(double u, double l, int interval)
{
    double h=(u-l)/interval;
    double sum=f(u)+f(l);
    for(int i=1; i<interval; i++)
    {
        double x= l+i*h;
        if(i%2==0)
            sum+=2*f(x);
        else sum+=4*f(x);
    }
    return (h/3)*sum;
}
int main()
{
    int n;
    double u,l;
    cout<<"Enter upper limit: ";
    cin>>u;
    cout<<"\nEnter lower limit: ";
    cin>>l;
    cout<<"\nEnter number of intervals: ";
    cin>>n;
    double result= simpsononethird(u,l,n);
    cout<<"\nThe approximate value of integral is: "<<result;
}
