#include<bits/stdc++.h>

using namespace std;

double func(double x){
    return x*x - 3*x + 2;
}

double deriv(double x){
    return 2*x - 3;
}

void newton_raphson_method(double x0){
    double x1 = x0;
    double a = func(x1);
    double b = deriv(x1);
    double x2 = x1 - (a/b);
    int n=1;
    while(abs(x2-x1)/abs(x2) >= 0.001){
        x1 = x2;
        a = func(x1);
        b = deriv(x1);
        x2 = x1 - (a/b);
        cout<<"iteration "<<n<<"\tX1 = "<<x1<<"\tX2 = "<<x2<<"\tError: "<<abs(x2-x1)/abs(x2)<<endl;
        n++;
    }

    cout<<"Root: "<<x2;

}

int main()
{
    int x0;
    cout<<"Enter initial guess: ";
    cin>>x0;
    newton_raphson_method(x0);

    return 0;
}
