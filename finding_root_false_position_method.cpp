#include<bits/stdc++.h>
using namespace std;
#define Error 0.0001

double x1, x2;
double x3;

double equation(double x){
    return (x*x)-x-2;
}

void false_position_method(){
    double f1 = equation(x1);
    double f2 = equation(x2);

    if(f1*f2 > 0){
        cout<<"Wrong initial guesses!";
        return;
    }

    do{
        x3 = x1-(f1*(x2-x1)/(f2-f1));
        double f3 = equation(x3);
        if(f3 == 0){
            cout<<"Root is: "<<x3;
            return;
        }
        if(f1*f3 < 0)
            x2 = x3;
        else
            x1 = x3;

    }while(abs((x2-x1)/x2) > Error);

    cout<<"Found root is: "<<x3;
}

int main()
{

    cout<<"Enter initial guesses: ";
    cin>>x1>>x2;
    false_position_method();
    return 0;

}
