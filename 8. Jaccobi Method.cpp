#include<bits/stdc++.h>
using namespace std;
void print(double x[], int n)
{
    cout<<"The solution is:\n";
    for(int i=0; i<n; i++)
        cout<<"x["<<i+1<<"]= "<<fixed<<setprecision(6)<<x[i]<<endl;
}
void jaccobi(double l[10][10], double r[10], double tol, int n, int maxIter)
{
    double x[10]={0}, x_new[10]={0}, norm[10];
    bool conver=true;
    for(int k=0; k<maxIter; k++)
    {
        for(int i=0; i<n; i++)
        {
            double sum=0;
            for(int j=0; j<n; j++)
                if(j!=i)
                sum+=l[i][j]*x[j];
            x_new[i]=(r[i]-sum)/l[i][i];
        }
            for(int i=0; i<n; i++){
                x[i]=x_new[i];
        }
        for(int j=0; j<n; j++)
            {
                norm[j]=fabs(x_new[j]-x[j]);
                if(norm[j]<=tol)conver=true;
                else if(norm[j]>tol)conver=false;
                if(!conver)break;
            }
            if(conver){
                print(x_new, n);
                return;
                }
    }
    cout<<"Could not converge within max iterations!";
}
int main()
{
    int n, maxiter;
    cout<<"Enter the number of equations: ";
    cin>>n;
    double l[10][10], r[10], tol;
    cout<<"\nEnter the coefficients of the matrix A(row-wise):\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<0; j++)
         cin>>l[i][j];
    cout<<"\nEnter the right hand side:\n";
    for(int i=0; i<n; i++)
        cin>>r[i];
    cout<<"\nEnter tolarance: ";
    cin>>tol;
    cout<<"Enter max iterations: ";
    cin>>maxiter;
    jaccobi(l, r, tol, n, maxiter);
}
