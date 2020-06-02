#include<iostream>
#define loop(i,n) for(int i=1;i<=n;i++)
using namespace std;

#define N 101
long a[N][N],I[N][N];

void print(long A[][N],int dim){
    loop(i,dim){
        loop(j,dim){
           cout<<A[i][j]<<" ";
           }cout<<endl;
        
    }
}

void mul(long A[][N],long B[][N], int dim){
    
    int res[dim+1][dim+1];
    loop(i,dim){
        loop(j,dim){
            res[i][j]=0;
            loop(k,dim) res[i][j]+=A[i][k]*B[k][j]; 
        }
    }
    loop(i,dim) loop(j,dim) A[i][j]=res[i][j];
 }

void power(long A[][N],int dim, long n)
{
    loop(i,dim) loop(j,dim){
        if(i==j) I[i][j]=1;
        else I[i][j]=0;
    }
    
    //loop(i,n) mul(I,A,dim);
   while(n){
       if(n%2){
           mul(I,A,dim) ,n--;
       }
       else
        mul(I,A,dim) ,n=n/2;
   }
    loop(i,dim) loop(j,dim) A[i][j]=I[i][j];
    
}
int main(){
    int  t;
    cin>>t;
    while(t--){
    int m;
    long n;
    cin>>m>>n;
    
    
    loop(i,m) loop(j,m) cin>>a[i][j];
    
    power(a,m,n);
    print(a,m); 
    }
    
}

