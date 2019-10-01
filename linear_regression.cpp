#include<bits/stdc++.h>
using namespace std;
#define v 100
double x[v], y[v];

void linear_regression(double x[v], double y[v], int n){
    double sum_of_x = 0.0;
    for(int i=1; i<=n; i++){
        sum_of_x += x[i];
    }
    double sum_of_y = 0.0;
    for(int i=1; i<=n; i++){
        sum_of_y += y[i];
    }
    double sum_of_x_squared = 0.0;
    for(int i=1; i<=n; i++){
        sum_of_x_squared += x[i]*x[i];
    }
    double sum_of_xy = 0.0;
    for(int i=1; i<=n; i++){
        sum_of_xy += x[i]*y[i];
    }

    double b = ((n*sum_of_xy)-(sum_of_x*sum_of_y))/((n*sum_of_x_squared)-(sum_of_x*sum_of_x));
    double a = (sum_of_y - (b*sum_of_x))/n;
    cout<<endl;
    cout<<"The equation is: y = "<<a<<" + "<<b<<"x^2";

}

int main()
{
    cout<<"How many values: ";
    int n;
    cin>>n;

    cout<<"Enter values for x: ";
    for(int i=1; i<=n; i++){
        cin>>x[i];
    }
    cout<<"Enter values for y: ";
    for(int i=1; i<=n; i++){
        cin>>y[i];
    }

    linear_regression(x, y, n);

    return 0;
}
