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

LL power(int X, int P)
{
    LL ans = 1;
    for(int i=1; i<=P; i++)
    {
        ans = ans * (LL)X;
    }
    return ans;
}

LL MOD = 1000000007;

LL bigmod(LL a, LL b)
{
    LL x = 1, y = a%MOD;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

LL MODINVERSE(LL a)
{
    return bigmod(a, MOD-2);
}

LL ncrdp[900][1000];
LL NCR(int n, int r)
{
    if(r==1) return n;
    else if(n==r) return 1;
    else
    {
        if(ncrdp[n][r]!=-1) return ncrdp[n][r];
        else
        {
            ncrdp[n][r]=NCR(n-1,r) + NCR(n-1,r-1);
            return ncrdp[n][r];
        }
    }
}

const int MAXN = 46400;
int status[(MAXN/32)+10];
vector<int>primelist;

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
//    for(int j=4; j<=MAXN; j=j+2)
//        status[j>>5]=SET(status[j>>5],j&31);
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
    primelist.push_back(2);
    for(int i=3; i<=MAXN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            primelist.push_back(i);
        }
    }
}


/**-------------------------------------------------------------------**/
/** Template Ends Here. Main Function Starts Here. **/
/**------------------------------------------------------------------**/

int caseno;
char str[1005], ttr[1005];
int visited[1005][1005], len1, len2;
LL lcslen;
LL dp[1005][1005];
string ans, res;

LL LCS(int pos1, int pos2)
{
    if(pos1==len1 || pos2==len2)  return 0;
    if(visited[pos1][pos2]==caseno)  return dp[pos1][pos2];
    visited[pos1][pos2] = caseno;

    LL ans = 0;
    if(str[pos1]==ttr[pos2])
    {
        ans = 1 + LCS(pos1+1, pos2+1);
    }
    else
    {
        ans = max(LCS(pos1, pos2+1), LCS(pos1+1, pos2));
    }
    dp[pos1][pos2] = ans;
    return dp[pos1][pos2];
}

void LCSPRINT(int pos1, int pos2)
{
    if(pos1==len1 || pos2==len2)
    {
        cout<<ans;
        return;
    }
    if(str[pos1]==ttr[pos2])
    {
        ans = ans + str[pos1];
        LCSPRINT(pos1+1, pos2+1);
    }
    else
    {
        if(dp[pos1+1][pos2]>dp[pos1][pos2+1]) LCSPRINT(pos1+1, pos2);
        else LCSPRINT(pos1, pos2+1);
    }
}

void LCSPRINTALL(int pos1, int pos2)
{
    if(pos1==len1 || pos2==len2)
    {
        cout<<res;
        puts("");
        return;
    }
    if(str[pos1]==ttr[pos2])
    {
        res = res + str[pos1];
        LCSPRINTALL(pos1+1, pos2+1);
        res.erase(res.end()-1);
    }
    else
    {
        if(dp[pos1+1][pos2]>dp[pos1][pos2+1]) LCSPRINTALL(pos1+1, pos2);
        else if(dp[pos1+1][pos2]<dp[pos1][pos2+1]) LCSPRINTALL(pos1, pos2+1);
        else
        {
            LCSPRINTALL(pos1+1, pos2);
            LCSPRINTALL(pos1, pos2+1);
        }
    }
}

int main()
{
    int test;
    scanf("%d", &test);
    getchar();
    FOR(caseno, 1, test)
    {
        ans.clear();
        res.clear();
        scanf("%s", str);
        len1 = strlen(str);
        scanf("%s", ttr);
        len2 = strlen(ttr);
        lcslen = LCS(0, 0);
        printf("LCS Length: %lld\n", lcslen);
        printf("LCS is:\n");
        LCSPRINT(0, 0);
        puts("");
        printf("All LCS ARE:\n");
        LCSPRINTALL(0, 0);
    }
}

