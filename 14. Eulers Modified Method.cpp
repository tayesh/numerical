#include<bits/stdc++.h>
using namespace std;
double f(double x, double y)
{
    return x+y;
}
void eulermodified(double x0, double y0, double h, double target)
{
    double x=x0, y=y0;
    cout<<"x = "<<x<<", y = "<<y<<endl;
    while(x<target)
    {
        double y_star=y+h*f(x,y);
        y= y+(h/2)*(f(x,y)+f(x+h, y_star));
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
    eulermodified(x0, y0, h, target);
}
