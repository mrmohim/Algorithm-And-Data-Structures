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

int arr[100005];
int tree[3*100005];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }
    int left = 2*node;
    int right = 2*node + 1;
    int mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(j<b || i>e) return 0;
    if(b>=i && e<=j) return tree[node];
    int left = 2*node;
    int right = 2*node + 1;
    int mid = (b+e)/2;
    int seg1 = query(left, b, mid, i, j);
    int seg2 = query(right, mid+1, e, i, j);
    return seg1 + seg2;
}

void update(int node, int b, int e, int i, int value)
{
    if(i>e || i<b) return;
    if(b>=i && e<=i)
    {
        tree[node] = value;
        return;
    }
    int left = 2*node;
    int right = 2*node + 1;
    int mid = (b+e)/2;
    update(left, b, mid, i, value);
    update(right, mid+1, e, i, value);
    tree[node] = tree[left] + tree[right];
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", arr+ i);
    init(1,1,n);
    int q, b, e;
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        scanf("%d %d", &b, &e);
        printf("%d\n", query(1, 1, n, b, e));
    }
    int up, node, value;
    scanf("%d", &up);
    for(int i=0; i<up; i++)
    {
        scanf("%d %d", &node, &value);
        update(1, 1, n, node, value);
        scanf("%d %d", &b, &e);
        printf("%d\n", query(1, 1, n, b, e));
    }
    return 0;
}
