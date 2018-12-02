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
#define ERASE(a, b)     memset(a, b, sizeof a)
#define Sort(x)         sort(x.begin(),x.end())
#define Reverse(x)      reverse(x.begin(),x.end())
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        (a * (b / gcd(a,b)))
#define sq(x)           (x)*(x)
#define DIST(x1,y1, x2, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define CLR(a)          a.clear()
#define SIZE(a)         a.size()
#define PB(a, b)        a.push_back(b)
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

LL arr[MAX];
struct info
{
    LL sum, prop;
};

info tree[MAX*3];

void build(LL node, LL b, LL e)
{
    if(b==e)
    {
        tree[node].sum = arr[b];
        return ;
    }
    LL left = 2*node;
    LL right = 2*node + 1;
    LL mid = (b+e)/2;
    build(left, b, mid);
    build(right, mid+1,e);

    tree[node].sum = tree[left].sum + tree[right].sum;
}

LL query(LL node, LL b, LL e, LL i, LL j, LL carry)
{
    if(i>e || j<b)  return 0;
    if(b>=i && e<=j)
    {
        return tree[node].sum + carry*(e-b+1);
    }
    LL left = 2*node;
    LL right = 2*node + 1;
    LL mid = (b+e)/2;
    LL ret1 = query(left, b, mid, i, j, carry + tree[node].prop);
    LL ret2 = query(right, mid+1, e, i, j, carry + tree[node].prop);

    return ret1 + ret2;
}

void update(LL node, LL b, LL e, LL i, LL j, LL x)
{
    if(i>e || j<b)  return ;
    if(b>=i && e<=j)
    {
        tree[node].sum = tree[node].sum + (e-b+1)*x;
        tree[node].prop = tree[node].prop + x;
        return ;
    }

    LL left = node*2;
    LL right = node*2 + 1;
    LL mid = (b+e)/2;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);

    tree[node].sum = tree[left].sum + tree[right].sum + ((e-b+1)*tree[node].prop);

}


int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        LL n, q, type, v1, v2, v3;
        sf("%lld%lld",&n,&q);
        ERASE(tree, 0);
        for(int i=1; i<=n; i++) sf("%d",arr[i]);
        build((LL)1, (LL)1, n);
        while(q--)
        {
            sf("%lld%lld%lld",&type,&v1,&v2);
            if(type==0)
            {
                sf("%lld",&v3); update(1, 1, n, v1, v2, v3);
            }
            else
                printf("%lld\n", query(1, 1, n, v1, v2, 0));
        }
    }
}

