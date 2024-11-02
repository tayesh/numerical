#include<bits/stdc++.h>
using namespace std;
double f(double x, double y)
{
    return x+y;
}
double rungekutta(double x0, double y0, double h, double target)
{
    double x=x0, y=y0, k1, k2, k3, k4;
    cout<<"x = "<<x<<", y = "<<y<<endl;
    while(x<target)
    {
        k1=h*f(x,y);
        k2=h*f(x+h/2,y+k1/2);
        k3=h*f(x+h/2,y+k2/2);
        k4=h*f(x+h,y+k3);
        y+=(k1+2*k2+2*k3+k4)/6;
        x=x+h;
        cout<<"x = "<<x<<", y = "<<y<<endl;
    }
    cout<<"The approximate solution at x = "<<x<<" is y = "<<y<<endl;
}
int main()
{
    double x0, y0, h, target;
    cout<<"Enter initial x0: ";
    cin>>x0;
    cout<<"\nEnter initial y0: ";
    cin>>y0;
    cout<<"\nEnter step size: ";
    cin>>h;
    cout<<"\nEnter target x: ";
    cin>>target;
    rungekutta(x0,y0, h, target);
}
