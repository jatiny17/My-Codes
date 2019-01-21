//Jatin Kumar
//jatiny17
 
#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long int ulli;
typedef long long lli;
typedef double dd;
 
#define mod 1000000007
#define print1(a) cout<<a<<"\n";
#define print2(a,b) cout<<a<<" "<<b<<"\n";
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n";
#define print4(a,b,c,d) cout<<a<<" "<< b <<" "<<c<<" "<<d<<"\n";
#define s(a) sort(a.begin(),a.end());
 
 
//***************************************************//
 
lli ls(vector<lli>a,lli t)
{   lli n=a.end()-a.begin();
    for(lli i=0;i<n;i++)
    if(a[i]==t)
    return i;
    
    return -1;}
 
lli bs(vector<lli>a,lli t)
{
    lli n=a.end()-a.begin();
    lli  l=0,r=n-1;
    while(l<=r)
    {lli  mid=(l+r)/2;
    
   if(a[mid]==t)return mid;
   else if (a[mid]>t) r=mid-1;
   else l=mid+1;}
   
   return -1;
}
 
//***************************************************//
 
void seive(bool a[],int n)
{
    memset(a,true,n);
    
    a[0]=false;
    a[1]=false;
    
    for(int i=2;i*i<=n;i++)
    {
        if(a[i]==true)
        {
            for(int j=2*i;j<=n;j+=i)
                a[j]=false;
        }
    }
}
 
//***************************************************//
 
lli add(lli a,lli b)
{return ((a%mod)+(b%mod))%mod;}
 
lli subt(lli a,lli b)
{return ((a%mod)-(b%mod))%mod;}
 
lli mul(lli a,lli b)
{  return ((a%mod)*(b%mod))%mod;}
 
//****************************************************//
int solve(int board[10][10],int r,int c,int n)
{
    int count=0;
    
    if(n==0)
    return 0;
    
    if(r<0||c<0||r>9||c>9)
    return 0;
    
    if(board[r][c]==1&&n==1)
    return 0;
    
    if(n==1)
    {
        board[r][c]=1;
        count=1;
    }
    
    return count+solve(board,r-1,c+2,n-1)+solve(board,r-2,c+1,n-1)+
    solve(board,r-2,c-1,n-1)+solve(board,r-1,c-2,n-1)+solve(board,r+1,c-2,n-1)+
    solve(board,r+2,c-1,n-1)+solve(board,r+2,c+1,n-1)+solve(board,r+1,c+2,n-1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r,c,ct;
    cin>>r>>c>>ct;
    
    r--;
    c--;
    
    int board[10][10]={0};
    
    cout<<solve(board,r,c,ct+1);
    
    return 0;
}
Language: C++
