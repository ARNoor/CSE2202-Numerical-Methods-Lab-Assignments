#include<bits/stdc++.h>
using namespace std;

void synthetic_division(int poly[], int n, int r){
    int poly2[n];

    poly2[0] = poly[0];
    for(int i=1; i<n; i++){
        poly2[i] = poly2[i-1]*r + poly[i];
    }

    cout<<"And the equation we got is: "<<endl;
    for(int i=0; i<n-1; i++){
        cout<<poly2[i]<<" ";
    }

}

int main()
{
    cout<<"Enter the degree of the co-efficients: "<<endl;
    int n;
    cin>>n;
    n++;
    int poly[n];
    cout<<"Enter values: "<<endl;
    for(int i=0; i<n; i++){
        cin>>poly[i];
    }
    cout<<"Enter one root: "<<endl;
    int r;
    cin>>r;

    synthetic_division(poly, n, r);
    
    return 0;
}
