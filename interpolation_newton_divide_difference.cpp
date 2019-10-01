#include<bits/stdc++.h>
using namespace std;
#define v 100

float x[v];
float fx[v];
float d[v][v];
float s[v][v];
float a[v];
float xp, sum;

void newton_divide_difference(int n){
    for(int i=1; i<=n; i++){
        d[i][1] = fx[i];
    }

    for(int j=2; j<=n; j++){
        for(int i=1; i<=n-j+1; i++){
            d[i][j] = (d[i+1][j-1] - d[i][j-1])/(x[i+j-1]-x[i]);
            s[i][j] = d[i][j];
        }
    }

    for(int j=1; j<=n; j++){
        a[j] = d[1][j];
    }

    cout<<"x\t"<<"f(x)"<<endl;
    for(int i=1; i<=15; i++){
        cout<<"-";
    }
//showing output
    for(int i=1; i<=n; i++){
        cout<<"\n"<< x[i] <<"\t" <<fx[i];
        for(int j=2;j<=n;j++){
            if(s[i][j]!= 0)
                cout<<"\t\t"<<s[i][j];
            if( j== n && i==1 )
                cout<<"\t\t"<<s[i][j];
        }
        cout<<endl;
    }

    cout<<"\nEnter X for finding f(x): ";
    cin>>xp;

    sum=a[1];
    for(int i=2; i<=n; i++){
        float p=1.0;
        for(int j=1; j<=i-1; j++){
            p = p*(xp-x[j]);
        }
        sum += a[i]*p;
    }
    cout<<"\nx:\t"<<sum<<endl;
}

int main()
{
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    cout<<"Enter the values of x and then f(x)"<<endl;
    for(int i=1; i<=n; i++){
        cin>>x[i]>>fx[i];
    }

    newton_divide_difference(n);

    return 0;
}
