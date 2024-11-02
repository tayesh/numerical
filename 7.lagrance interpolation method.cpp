#include<bits/stdc++.h>
using namespace std;
double lagrange(double x[], double y[], double value, int n)
{
    double result=0;
    for(int i=0; i<n; i++)
    {
        double term=y[i];
        for(int j=0; j<n; j++)
           if(i!=j)
            term*=((value-x[j])/(x[i]-x[j]));
        result+=term;
    }
    return result;
}
int main()
{
    int n;
    cout<<"Enter the number of data points: ";
    cin>>n;
    double x[n], y[n], value, result;
    cout<<"\nEnter the values of x: ";
    for(int i=0; i<n; i++)
        cin>>x[i];
    cout<<"\nEnter the corresponding values of x that is y: ";
    for(int i=0; i<n; i++)
        cin>>y[i];
    cout<<"\nEnter the point of interpolation: ";
    cin>>value;
    result=lagrange(x,y,value,n);
    cout<<"\nThe interpolated value of "<<value<<" is "<<result;
}
