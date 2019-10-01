#include<bits/stdc++.h>
#define   SIZE   10

using namespace std;

clock_t t1, t2;
//t1 = clock();
int main()
{
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i,j,k,n;
    //cout<< setprecision(3)<< fixed;
    cout<<"Gauss Elimination with pivoting"<<endl;
    cout<<"Enter number of unknowns: ";
    cin>>n;

	 /* Reading Augmented Matrix */
    cout<<"Enter Coefficients of Augmented Matrix: "<< endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1;j++){
			   //cout<<"a["<< i<<"]"<< j<<"]= ";
            cin>>a[i][j];
        }
    }


	/* Applying Gauss Elimination */

    for(i=1;i<=n-1;i++){
        if(a[i][i] == 0.0){
            cout<<"Mathematical Error!";
            exit(0);
        }

        /* setting up the pivot*/
        int pivot = i;
        for(int j=i; j<n; j++){
            if(a[j][i] > a[j+1][i])
                pivot = j;
            else
                pivot = j+1;
        }
        swap(a[pivot], a[i]);

        /*forward elimination*/
        for(j=i+1;j<=n;j++){
            ratio = a[j][i]/a[i][i];
            for(k=1;k<=n+1;k++)
                a[j][k] = a[j][k] - ratio*a[i][k];
        }
    }
    /* Obtaining Solution by Back Substitution Method */
    x[n] = a[n][n+1]/a[n][n];

    for(i=n-1;i>=1;i--){
        x[i] = a[i][n+1];
        for(j=i+1;j<=n;j++)
            x[i] = x[i] - a[i][j]*x[j];
        x[i] = x[i]/a[i][i];
    }
    t2 = clock();

    /* Displaying Solution */
    cout<< endl<<"Solution: "<< endl;
    for(i=1;i<=n;i++)
        cout<<"x["<< i<<"] = "<< x[i]<< endl;

    cout<<"time: "<<(double)t2-t1/CLOCKS_PER_SEC;
    return 0;
}

