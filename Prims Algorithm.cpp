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

vector<int>node[100];
int value[100][100],par[100];

struct edge{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w > p.w;
    }
};

int find(int i)
{
    return (par[i]==i) ? i : find(par[i]);
}

int Prims(int n,int src)
{
    priority_queue<edge>q;
    edge get;
    for(int i=0;i<node[src].size();i++)
    {
        get.u=src; get.v=node[src][i]; get.w=value[src][node[src][i]];
        q.push(get);
    }
    int c=1,s=0;
    for(int i=1;i<=n;i++) par[i]=i;
    while(!q.empty())
    {
        edge e=q.top();

        q.pop();
        int u=find(e.u);
        int v=find(e.v);
        if(u!=v)
        {
            //cout<<e.u<<" "<<e.v<<endl;
            par[u]=v;
            c++;
            s+=e.w;
            //cout<<e.w<<endl;
            //cout<<s<<endl;
            //if(c==n-1) break;
            for(int i=0;i<node[e.v].size();i++)
            {
                int a=find(e.v);
                int b=find(node[e.v][i]);
                if(a!=b){
                    get.u=e.v; get.v=node[e.v][i]; get.w=value[e.v][node[e.v][i]];
                    q.push(get);
                }
            }
        }
    }
    return s;
}

int main()
{
    int i,j,a,b,n,m,u,v,w;
    while(cin>>n>>m)
    {
        for(i=1;i<=m;i++)
        {
            cin>>u>>v>>w;
            node[u].push_back(v);
            node[v].push_back(u);
            value[u][v]=w;
            value[v][u]=w;
        }
        cout<<"Enter the source node : "; cin>>a;
        b=Prims(n,a);
        cout<<"Minimum Cost : "<<b<<endl;
    }
    return 0;
}
/*
9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 9 2
3 6 4
8 9 7
8 7 1
9 7 6
7 6 2
6 4 14
4 5 9
6 5 10
Enter the source node : 1
Minimum Cost : 37
*/
