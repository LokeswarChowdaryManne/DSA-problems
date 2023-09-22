#include <bits/stdc++.h>

using namespace std;

int main(){
    int W,n,i,j,x;
    cout<<"Enter total weight :";
    cin>>W;
    cout<<"Enter number of items:";
    cin>>n;
    int temp=n;
    vector<int> w,p;
    i=0;
    while(temp--){
        cout<<"Enter weight of item "<<i+1<<":";
        cin>>x;
        w.push_back(x);
        cout<<"Enter profit obtained on loading item "<<i+1<<":";
        cin>>x;
        p.push_back(x);
        i++;
    }
    vector < vector < int > > matrix (n+1, vector<int> (W+1, 0));
    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(i==0 || j==0){
                matrix[i][j]=0;
            }
            else if(w[i-1]<=j){
                matrix[i][j]=max(matrix[i-1][j],matrix[i-1][j-w[i]]+p[i]);
            }
            else{
                matrix[i][j]=matrix[i-1][j];
            }
        }
    }
    for(i=0;i<n+1;i++){
        cout<<"";
        for(j=0;j<W+1;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
