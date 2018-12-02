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

LL arr[505][505];
LL tree[4*505][4*505];
int n, m;

void build_y(int nx, int lx, int rx, int ny, int ly, int ry)
{
    if(ly==ry){
        if(lx==rx) tree[nx][ny] = arr[lx][ry];
        else tree[nx][ny] = tree[nx*2][ny] + tree[nx*2+1][ny];
        return;
    }
    int my = (ly + ry)>>1;
    build_y(nx, lx, rx, 2*ny, ly, my);
    build_y(nx, lx, rx, 2*ny+1, my+1, ry);
    tree[nx][ny] = tree[nx][2*ny] + tree[nx][2*ny+1];
}

void build_x(int nx, int lx, int rx)
{
    if(lx!=rx){
        int mx = (lx + rx)>>1;
        build_x(nx*2, lx, mx);
        build_x(nx*2+1, mx+1, rx);
    }
    build_y(nx, lx, rx, 1, 0, m-1);
}

LL query_y(int nx, int ny, int ly, int ry, int y1, int y2)
{
    if(ly>y2 || ry<y1) return 0;
    if(y1<=ly && y2>=ry)
        return tree[nx][ny];
    int my = (ly + ry)>>1;
    return query_y(nx, ny*2, ly, my, y1, y2) +
            query_y(nx, ny*2+1, my+1, ry, y1, y2);
}

LL query_x(int nx, int lx, int rx, int x1, int y1, int x2, int y2)
{
    if(rx<x1 || lx>x2) return 0;
    if(x1<=lx && x2>=rx){
        return query_y(nx, 1, 0, m-1, y1, y2);
    }
    int mx = (lx + rx)>>1;
    return query_x(nx*2, lx, mx, x1, y1, x2, y2) +
            query_x(nx*2+1, mx+1, rx, x1, y1, x2, y2);
}

void upd_y(int nx, int lx, int rx, int ny, int ly, int ry, int y, LL val )
{
    if(ly==ry){
        if(lx==rx) tree[nx][ny] = val;
        else tree[nx][ny] = tree[nx*2][ny]+ tree[nx*2+1][ny];
        return;
    }
    int my = (ly + ry)>>1;
    if(y<=my) upd_y(nx, lx, rx, ny*2, ly, my, y, val);
    else upd_y(nx, lx, rx, ny*2+1, my+1, ry, y, val);

    tree[nx][ny] = tree[nx][ny*2]+ tree[nx][ny*2+1];
}

void upd_x(int nx, int lx, int rx, int x, int y, LL val)
{
    if(lx!=rx){
        int mx = (lx + rx)>>1;
        if(x<=mx) upd_x( nx*2, lx, mx, x,  y, val);
        else upd_x(nx*2+1, mx+1, rx, x, y, val);
    }
    upd_y(nx, lx, rx, 1, 0, m-1, y, val);
}

int main()
{

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%lld", &arr[i][j]);
        }
    }
    build_x(1, 0, n-1);
    int q;
    scanf("%d", &q);
    while(q--){
        int op, x1, y1, x2, y2;
        LL val;
        scanf("%d %d %d", &op, &x1, &y1);
        if(op==1){
            scanf("%d %d", &x2, &y2);
            printf("%lld\n", query_x(1, 0, n-1, x1, y1, x2, y2));
        }
        else{
            scanf("%lld", &val);
            upd_x(1, 0, n-1, x1, y1, val);
        }
    }
    return 0;
}
