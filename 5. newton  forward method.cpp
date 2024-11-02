#include<bits/stdc++.h>
using namespace std;
int fact(int i)
{
    int factorial =1;
    for(int j=1; j<=i; j++)
        factorial*=j;
    return factorial;
}
double newtonforwardinterpolation(double x[], double y[], double value, int n)
{
    double differ_table[n][n];
    for(int i=0; i<n; i++)
        differ_table[i][0]=y[i];
    for(int j=1; j<n; j++){
        for(int i=0; i<n-j; i++){
        differ_table[i][j]=differ_table[i+1][j-1]-differ_table[i][j-1];
        }}

    cout<<"Difference Table\n"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++)
           cout<<setw(10)<<differ_table[i][j]<<"\t";
       cout<<endl;
    }
    double h=x[1]-x[0];
    double u=(value-x[0])/h;
    double result=x[0];
    for(int i=0; i<n; i++)
    {
        double u_term=u;
        for(int j=1; j<i; j++)
            u_term*=(u-j);
        result+=(u_term*differ_table[0][i])/fact(i);
    }
    return result;
}
int main()
{
    int n;
    cout<<"Enter the number of data points: ";
    cin>>n;
    double x[n], y[n], value;
    cout<<"\nEnter x values: ";
    for(int i=0; i<n; i++)
        cin>>x[i];
    cout<<"\nEnter their corresponding y values: ";
    for(int i=0; i<n; i++)
        cin>>y[i];
    cout<<"\nEnter the value to interpolate: ";
    cin>>value;
    double result=newtonforwardinterpolation(x,y,value,n);
    cout<<"The interpolated value at "<<value<<" is "<<result;
}
