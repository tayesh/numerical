#include<bits/stdc++.h>
using namespace std;
double f(double x, double y)
{
    return x+y;
}
void euler(double x0, double y0,double h, double target)
{
    double x=x0, y=y0;
    cout<<"x = "<<x<<", y = "<<y<<endl;
    while(x<target)
    {
        y=y+h*f(x,y);
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
    euler(x0,y0,h,target);
}
