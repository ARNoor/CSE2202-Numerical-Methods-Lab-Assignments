#include<bits/stdc++.h>

#define   SIZE   10

using namespace std;

double a[SIZE][SIZE], x[SIZE], ratio;
int i,j,k,n;


void Gauss_Elimination(){
    /* Applying Gauss Elimination */
	 for(i=1;i<=n-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   cout<<"Mathematical Error!";
			   exit(0);
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = a[j][i]/a[i][i];

			   for(k=1;k<=n+1;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }
	 /* Obtaining Solution by Back Substitution Method */
	 x[n] = a[n][n+1]/a[n][n];

	 for(i=n-1;i>=1;i--)
	 {
		  x[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		x[i] = x[i] - a[i][j]*x[j];
		  }
		  x[i] = x[i]/a[i][i];
	 }

}


int main()
{    /* Setting precision and writing floating point values in fixed-point notation. */
     cout<< setprecision(3)<< fixed;


	 /* Reading number of unknowns */
	 cout<<"Enter number of unknowns: ";
	 cin>>n;

	 /* 2. Reading Augmented Matrix */
	 cout<<"Enter Coefficients of Augmented Matrix: "<< endl;
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++)
		  {
			   //cout<<"a["<< i<<"]"<< j<<"]= ";
			   cin>>a[i][j];
		  }
	 }
     clock_t time_req;
	 time_req =clock();
	 Gauss_Elimination();
     time_req=clock()-time_req;
	 /* Displaying Solution */
	 cout<<"\nSolution: "<< endl;
	 for(i=1;i<=n;i++)
	 {
	  	cout<<"x["<< i<<"] = "<< x[i]<< endl;
	 }
	 //double elapsed = (double)(stop - start) * 1000.0/CLOCKS_PER_SEC;
     cout<<"time: "<<(double)(time_req)/CLOCKS_PER_SEC<<" mili-seconds";

	 return 0;
}
