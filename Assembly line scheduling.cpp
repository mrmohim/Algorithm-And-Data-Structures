/* ===================================*/
/* Author :   Moshiur Rahman Mohim    */
/* Email  :   mtmohim74@gmail.com     */
/* Institute: HSTU                    */
/* ===================================*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using  namespace  std;

const int INF = 0x7f7f7f7f;

#define pi              acos(-1.0)
#define mod             1000000007
#define MAX             10000
#define FOR(i, b, n)    for(LL i=b; i<=n; i++)
#define FORR(i, n, b)   for(LL i=n; i>=b; i--)
// Library.
#define mem(a,b)        memset(a,b,sizeof(a))
#define Sort(x)         sort(x.begin(),x.end())
#define Reverse(x)      reverse(x.begin(),x.end())
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        (a * (b / gcd(a,b)))
#define sq(x)           (x)*(x)
// File.
#define READ(f)         freopen(f, "r", stdin)
#define WRITE(f)        freopen(f, "w", stdout)
// i/o.
#define sf              scanf
#define pf              printf
#define pr1(x)          cout<<x<<"\n"
#define pr2(x,y)        cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)      cout<<x<<" "<<y<<" "<<z<<"\n"
// Test Case.
#define TEST(i,t)       LL i,t;scanf("%lld",&t);for(i=1;i<=t;i++)

typedef unsigned int            U;
typedef long int                L;
typedef unsigned long int       LU;
typedef long long int           LL;
typedef unsigned long long int  LLU;
typedef float                   F;
typedef double                  LF;
typedef char                    C;

//STL
typedef vector<LL>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<LL,LL>pll;
typedef pair<LF,LF>pdd;
typedef vector<pii> vpii;

#define pub              push_back
#define pob              pop_back
/*.......Global Function.......*/
// Compute b^p%m
int BigMod(LL B,LL P,LL M)
{
    LL R=1;
    while(P>0)
    {
        if(P%2==1)
            R=(R*B)%M;
        P/=2;
        B=(B*B)%M;
    }
    return (int)R;
}
//Ugly Numbers
LL maxDivide(LL a,LL b)
{
    while(a%b==0)
        a=a/b;
    return a;
}
LL isUgly(LL no)
{
    no=maxDivide(no,2);
    no=maxDivide(no,3);
    no=maxDivide(no,5);
    return (no==1)?1:0;
}
//XOR of 2 Numbers
LL myXOR(LL x,LL y)
{
    LL res=0;
    FORR(i,31,0)
    {
        bool b1=x&(1<<i);
        bool b2=y&(1<<i);
        bool xoredBit=(b1&b2)?0:(b1|b2);
        res<<=1;
        res|=xoredBit;
    }
    return res;
}
//BIG Fibonacci
//map<LLU,LL> FFF;
//LLU fff(LLU n)
//{
//    if (FFF.count(n)) return FFF[n];
//    LLU k=n/2;
//    if (n%2==0)   // n=2*k
//    {
//        return FFF[n] = (fff(k)*fff(k) + fff(k-1)*fff(k-1)) % mod;
//    }
//    else     // n=2*k+1
//    {
//        return FFF[n] = (fff(k)*fff(k+1) + fff(k-1)*fff(k)) % mod;
//    }
//}//must be define in main function (FFF[0]=FFF[1]=1)
/*............End............*/
/*.......Global Declaration.......*/
int f[100][100],a[100][100],t[100][100],l[100][100];
int main()
{
    int i,j,s1,s2,e1,e2,p,q,n,m,line,b,c;
    cout<<"Enter of starting value of line 1 and 2 : ";
    cin>>s1>>s2;
    cout<<"Enter the value of 6 station of line 1 : ";
    for(i=1;i<=6;i++) cin>>a[1][i];
    cout<<"Enter the value of 6 station of line 2 : ";
    for(i=1;i<=6;i++) cin>>a[2][i];
    cout<<"Enter the value of 5 station to transfer line 1 to 2 : ";
    for(i=1;i<6;i++) cin>>t[1][i];
    cout<<"Enter the value of 5 station to transfer line 2 to 1 : ";
    for(i=1;i<6;i++) cin>>t[2][i];
    cout<<"Enter the finishing value of line 1 and 2 : ";
    cin>>e1>>e2;
    f[1][1]=s1+a[1][1];
    f[2][1]=s2+a[1][1];
    for(i=2;i<=6;i++)
    {
        if(f[1][i-1]+a[1][i]<=f[2][i-1]+t[2][i-1]+a[1][i])
        {
            f[1][i]=f[1][i-1]+a[1][i];
            l[1][i]=1;
        }
        else{
            f[1][i]=f[2][i-1]+t[2][i-1]+a[1][i];
            l[1][i]=2;
        }
        if(f[2][i-1]+a[2][i]<=f[1][i-1]+t[1][i-1]+a[2][i])
        {
            f[2][i]=f[2][i-1]+a[2][i];
            l[2][i]=2;
        }
        else{
            f[2][i]=f[1][i-1]+t[1][i-1]+a[2][i];
            l[2][i]=1;
        }
    }
    if(f[1][6]+e1<=f[2][6]+e2)
    {
        b=f[1][6]+e1;
        c=1;
    }
    else{
        b=f[2][6]+e2;
        c=2;
    }
    cout<<"minimum cost is : "<<b<<endl;
    cout<<" line "<<c<<" Station 6"<<endl;
    for(j=6;j>=2;j--)
    {
        c=l[c][j];
        cout<<" line "<<c<<" Station "<<j-1<<endl;
    }
    return 0;
}
/*
Enter of starting value of line 1 and 2 : 10 12
Enter the value of 6 station of line 1 : 4 5 3 2 6 1
Enter the value of 6 station of line 2 : 2 3 4 5 1 6
Enter the value of 5 station to transfer line 1 to 2 : 3 4 6 1 5
Enter the value of 5 station to transfer line 2 to 1 : 2 1 6 4 3
Enter the finishing value of line 1 and 2 : 18 7
minimum cost is : 39
 line 2 Station 6
 line 2 Station 5
 line 1 Station 4
 line 1 Station 3
 line 1 Station 2
 line 1 Station 1
*/
