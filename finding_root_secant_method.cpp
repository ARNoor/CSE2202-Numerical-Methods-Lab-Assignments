#include<bits/stdc++.h>
using namespace std;
#define Error 0.0001

double x1, x2;
double x3;

double equation(double x){
    return (x*x)-(4*x)-10;
}

void secant_method(){

    double f1 = equation(x1);
    double f2 = equation(x2);

    x3 = ((f2*x1)-(f1*x2))/(f2-f1);

    while(abs((x3-x2)/x3) > Error){
        x1 = x2;
        f1 = f2;
        x2 = x3;
        f2 = equation(x2);

        x3 = ((f2*x1)-(f1*x2))/(f2-f1);
    }


    cout<<"Found root is: "<<x3;
}

int main()
{

    cout<<"Enter initial guesses: ";
    cin>>x1>>x2;
    secant_method();
    return 0;

}
