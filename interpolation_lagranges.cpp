#include<iostream>
#include<conio.h>
#define v 100
using namespace std;

float x[v], fx[v], xp, value=0, p;
int i,j,n;

void lagranges_interpolation(int n){

	 /* Implementing Lagrange Interpolation */
	 for(i=1; i<=n; i++){
		  p=1;
		  for(j=1; j<=n; j++){
			   if(i!=j){
			    	p = p*(xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  value += p*fx[i];
	 }
	 //cout<< endl<<"Interpolated value at "<<xp<< " is "<<value;
    cout<<"result:"<<endl;
    cout<<"fx["<<xp<<"] = "<<value;
}

int main()
{
	 /* Input Section */
	 cout<<"Enter number of data: ";
	 cin>>n;
	 cout<<"Enter data:"<< endl;
	 for(i=1; i<=n; i++){
		  cout<<"x["<< i<<"] = ";
		  cin>>x[i];
		  cout<<"fx["<< i<<"] = ";
		  cin>>fx[i];
	 }
	 cout<<"Enter interpolation point: ";
	 cin>>xp;

	 lagranges_interpolation(n);

	 return 0;
}
