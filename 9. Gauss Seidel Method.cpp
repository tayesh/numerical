#include<bits/stdc++.h>
using namespace std;
void print(double x[], int n)
{
    cout<<"The Result is: ";
    for(int i=0; i<n; i++)
        cout<<"x["<<i+1<<"]= "<<x[i]<<endl;
}
void gauss(double l[][10], double r[], double tol, int n, int maxiter)
{
    double x[10]={0}, x_new[10]={0}, norm[10];
    bool converge=false;
    for(int k=0; k<maxiter; k++)
    {
        converge=false;
        for(int i=0; i<n; i++)
        {
            double sum=0;
            for(int j=0; j<n; j++)
                if(j!=i)
                 sum+=l[i][j]*x[j];
            x_new[i]=(r[i]-sum)/l[i][i];
            if(fabs(x_new[i]-x[i])<=tol)converge=true;
            x[i]=x_new[i];
        }
        for(int i=0; i<n; i++)
        {
            x[i]=x_new[i];
        }
        if(converge){
            print(x_new,n);
            return;
        }
    }
    cout<<"could not found the convergence within the max iteration!";
}
int main()
{
    int n, maxiter;
    cout<<"Enter the number of equations: ";
    cin>>n;
    double l[10][10], r[10], tol;
    cout<<"\nEnter the coefficient matrix (row_wise): \n";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        cin>>l[i][j];
    cout<<"\nEnter the right side of the equations: \n";
    for(int i=0; i<n; i++)
        cin>>r[i];
    cout<<"\nEnter tolerance: ";
    cin>>tol;
    cout<<"\nEnter max iteration: ";
    cin>>maxiter;
    gauss(l, r, tol, n, maxiter);
}
