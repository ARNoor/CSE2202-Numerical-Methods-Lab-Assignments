#include<bits/stdc++.h>
using namespace std;
#define Error 0.001

double poly2[10];
double poly3[10];

double equation(double poly[], int n, double x){
    double result = poly[0];
    for (int i=1; i<n; i++)
        result = result*x + poly[i];
    return result;
}

void derivative(double poly[], int n){
    for(int i=0; i<n; i++){
        poly2[i] = poly[i]*(n-i);
    }
}

double newton_raphson_method(double poly[], int n, double x1){
    double f1 = equation(poly, n, x1);
    derivative(poly, n);
    double f2 = equation(poly2, n-1, x1);

    double x2 = x1 - (f1/f2);
    while(abs((x2-x1)/x2) > Error){
        x1 = x2;
        f1 = equation(poly, n, x1);
        derivative(poly, n);
        f2 = equation(poly2, n-1, x1);
        x2 = x1 - (f1/f2);
    }
    cout<<"Root: "<<x2<<endl;
    return x2;
}

void finding_all_roots(double poly[], int n, double x1){
    double r = newton_raphson_method(poly, n, x1);
    double poly2[n];

    poly3[0] = poly[0];
    for(int i=1; i<n; i++){
        poly3[i] = poly3[i-1]*r + poly[i];
    }

    //cout<<"And the equation we got is: "<<endl;
    for(int i=0; i<n-1; i++){
        cout<<poly3[i]<<" ";
    }
    cout<<endl;
    if(n>2)
        finding_all_roots(poly3, n-1, r);
}

int main()
{
    cout<<"Enter the degree of the co-efficients: "<<endl;
    int n;
    cin>>n;

    //double roots[n];
    n++;
    double poly[n];
    cout<<"Enter values: "<<endl;
    for(int i=0; i<n; i++){
        cin>>poly[i];
    }
    cout<<"Enter initial guess: "<<endl;
    double x1;
    cin>>x1;

    finding_all_roots(poly, n, x1);

    return 0;
}
