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

template<typename T>inline T Bigmod(T a, T b, T MOD)
{
    T x = 1, y = a%MOD;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x = (x*y)%MOD;
        }
        y = (y*y)%MOD;
        b /= (T)2;
    }
    return x;
}

const int MAXN = 100000;
int status[(MAXN/32)+10];
int primelist[MAXN], primesz;

bool check(int n, int pos)
{
    return (bool)(n & (1<<pos));
}
int SET(int n, int pos)
{
    return n=n|(1<<pos);
}

void sieve()
{
    int sqrtN=int (sqrt(MAXN));
    status[1>>5]=SET(status[1>>5],1&31);
    for(int j=4; j<MAXN; j=j+2)
        status[j>>5]=SET(status[j>>5],j&31);
    for(int i=3; i<=sqrtN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(int j=i*i; j<=MAXN; j= j + (i<<1))
            {
                status[j>>5]=SET(status[j>>5],j&31);
            }
        }
    }

    primelist[primesz++] = 2;
    for(int i=3; i<=MAXN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            primelist[primesz++] = i;
        }
    }
}

LLU ncnt[103][100005];
LLU lcnt[103][100005];

void facto(int cs, int n, int type )
{
    if(type==1)
    {
        for(int i=0; i<primesz; i++)
        {
            if(primelist[i]*primelist[i]>n) break;
            while(n%primelist[i]==0)
            {
                n = n / primelist[i];
                ncnt[cs][primelist[i]]++;
            }
        }
        if(n>1)
        {
            ncnt[cs][n]++;
        }
    }
    if(type==2)
    {
        for(int i=0; i<primesz; i++)
        {
            if(primelist[i]*primelist[i]>n) break;
            while(n%primelist[i]==0)
            {
                n = n / primelist[i];
                if(ncnt[cs][primelist[i]]>0) ncnt[cs][primelist[i]]--;
                else lcnt[cs][primelist[i]]++;
            }
        }
        if(n>1)
        {
            if(ncnt[cs][n]>0) ncnt[cs][n]--;
            else lcnt[cs][n]++;
        }
    }

}

int main()
{
    sieve();
    int test;
    scanf("%d", &test);
    for(int caseno=1; caseno<=test; caseno++)
    {
        LLU n, r, p;
        scanf("%lld %lld %lld", &n, &r, &p);
        if(r>n)
        {
            puts("0");
            continue;
        }
        if(r==n)
        {
            puts("1");
            continue;
        }

        LLU lft = min(r, n-r);

        for(int i=n; i>max(r, n-r); i--)
        {
            facto(caseno, i, 1);
        }
        for(int j=1; j<=min(r, n-r); j++)
        {
            facto(caseno, j,2);
        }

        LLU hor = 1, lob = 1;
        for(int i=0; i<primesz; i++)
        {
            //cout<<primelist[i]<<' '<<ncnt[caseno][primelist[i]]<<' '<<lcnt[caseno][primelist[i]]<<endl;
            if(ncnt[caseno][primelist[i]]>0)
            {
                lob = (lob * Bigmod((LLU)primelist[i], ncnt[caseno][primelist[i]], p))%p;
            }
            if(lcnt[caseno][primelist[i]]>0)
            {
                hor = (hor * Bigmod((LLU)primelist[i], lcnt[caseno][primelist[i]], p))%p;
            }
        }


        LLU ans = (lob * Bigmod(hor, p-2, p))%p;
        printf("%lld\n", ans);
    }
}
