#include<bits/stdc++.h>
using namespace std;
#define v 100
double x[v], y[v];
double a[v][v];
double res[v];
double ratio;

void Gauss_Elimination(int n){
	 for(int i=1;i<=n-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   cout<<"Mathematical Error!";
			   exit(0);
		  }
		  for(int j=i+1;j<=n;j++)
		  {
			   ratio = a[j][i]/a[i][i];

			   for(int k=1;k<=n+1;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }
	 /* Obtaining Solution by Back Substitution Method */
	 res[n] = a[n][n+1]/a[n][n];

	 for(int i=n-1;i>=1;i--)
	 {
		  res[i] = a[i][n+1];
		  for(int j=i+1;j<=n;j++)
		  {
		  		res[i] = res[i] - a[i][j]*res[j];
		  }
		  res[i] = res[i]/a[i][i];
	 }

    /*for(int i=1;i<=n;i++)
    {
	  	cout<<"x["<< i<<"] = "<< res[i]<< endl;
    }*/
    cout<<endl;

    cout<<"The equation is: y = "<<res[1]<<" + "<<res[2]<<"x"<<" + "<<res[3]<<"x^2";
}


void polynomial_regression(double x[v], double y[v], int n){

    a[1][1] = n;

    double E_x = 0.0;
    for(int i=1; i<=n; i++){
        E_x += x[i];
    }
    a[1][2]= a[2][1] = E_x;

    double E_x_2 = 0.0;
    for(int i=1; i<=n; i++){
        E_x_2 += x[i]*x[i];
    }
    a[1][3] = a[2][2] = a[3][1] = E_x_2;

    double E_x_3 = 0.0;
    for(int i=1; i<=n; i++){
        E_x_3 += x[i]*x[i]*x[i];
    }
    a[2][3] = a[3][2] = E_x_3;

    double E_x_4 = 0.0;
    for(int i=1; i<=n; i++){
        E_x_4 += x[i]*x[i]*x[i]*x[i];
    }
    a[3][3] = E_x_4;

    double E_y = 0.0;
    for(int i=1; i<=n; i++){
        E_y += y[i];
    }
    a[1][4] = E_y;

    double E_x_y = 0.0;
    for(int i=1; i<=n; i++){
        E_x_y += x[i]*y[i];
    }
    a[2][4] = E_x_y;

    double E_x_2_y = 0.0;
    for(int i=1; i<=n; i++){
        E_x_2_y += x[i]*x[i]*y[i];
    }
    a[3][4] = E_x_2_y;

    Gauss_Elimination(n-1);

    //cout<<"The equation is: y = "<<a<<" + "<<b<<"x^2";

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

    polynomial_regression(x, y, n);

    return 0;
}
