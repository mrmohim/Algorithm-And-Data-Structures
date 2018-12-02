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

const double GRS = (1 + sqrt(5))/2;

LL power(int X, int P)
{
    LL ans = 1;
    for(int i=1; i<=P; i++)
    {
        ans = ans * (LL)X;
    }
    return ans;
}

LL ABS(LL A, LL B)
{
    LL ret = A - B;
    if(ret<0) return -ret;
    return ret;
}

LL MOD = 1000000007;
const LL BIGMAX = power(2,63) - 1;

LL ADD(LL X, LL Y)
{
    if(X+Y<0)
        return (X - MOD) + Y;
    else if(X+Y>=MOD)
        return X+Y-MOD;
    else
        return X+Y;
}

LL prod(LL X, LL Y) // CUSTOM PRODUCT FUNCTION FOR BIG NUMBER MULTIPLICATION
{
    if(Y==0 || X<=(BIGMAX/Y)) return (X*Y)%MOD;
    LL result = 0;

    if(X>Y) swap(X,Y);
    while(X>0)
    {
        if(X&1!=0)
        {
            result = ADD(result, Y);
        }
        X>>=1;
        Y -= MOD - Y;
        if(Y<0)
            Y = Y + MOD;
    }
    return result;
}

LL bigmod(LL a, LL b)
{
    LL x = 1, y = a%MOD;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x = prod(x,y);
        }
        y = prod(y,y);
        b /= (LL)2;
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

const int MAXN = 1000005;
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
    for(int j=4; j<=MAXN; j=j+2)
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
    primelist.push_back(2);
    for(int i=3; i<=MAXN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            primelist.push_back(i);
        }
    }
}


/**----------------------------------------------------------------------------**/
/** Template Ends Here. Main Function And User Defined Functions Starts Here. **/
/**--------------------------------------------------------------------------**/


char a[55],b[55],c[55];
int dp[55][55][55],state[55][55][55],save[55][55][55][4],caseno=0, len1, len2, len3;
char alpha[123];

int lcs(int i, int j, int l)
{

    if(i>=len1 || j>=len2 || l>=len3) return 0;
    if(state[i][j][l]==caseno) return dp[i][j][l]; //save tym from clearing dp array frequently.
    state[i][j][l]=caseno;
    int ret=0;
    save[i][j][l][0]=-1; // print er mto kono letter nei seta 1st e indicate kore dilam.
    for(int k=0; k<52; k++) //'a' theke 'z'  porjonto check
    {
        int p,q,r;
        for(p=i; p<len1; p++) // k letter taki string duitay kommon ache??
            if(a[p]==alpha[k]) break;
        for(q=j; q<len2; q++)
            if(b[q]==alpha[k]) break;
        for(r=l; r<len3; r++)
            if(c[r]==alpha[k]) break;

        if(p==len1 || q==len2 || r==len3) continue;
        int tamp=1+lcs(p+1,q+1,r+1); // common thakle next position e pathao.
        if(tamp>ret) //eknkar ta max hle seta nao and letter k ke save koro , sathe save koro path keo.
        {
            ret=tamp;
            save[i][j][l][0]=k;
            save[i][j][l][1]=p+1;
            save[i][j][l][2]=q+1;
            save[i][j][l][3]=r+1;
        }
    }
    return dp[i][j][l]=ret;
}

void print(int i, int j, int l)
{
    if(i>=len1 || j>=len2 || l>=len3 || save[i][j][l][0]==-1) return;
    printf("%c",alpha[save[i][j][l][0]]);
    print(save[i][j][l][1],save[i][j][l][2], save[i][j][l][3]);
}

int main()
{
    //fin("1110.txt");
    char ch = 'A';
    for(int i=0; i<52 ; i++)
    {
        alpha[i] = ch;
        if(ch=='Z')
        {
            ch = 'a';
        }
        else
        {
            ch++;
        }
    }

    int t;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        scanf("%s",&a);
        scanf("%s",&b);
        scanf("%s",&c);
        len1 = strlen(a);
        len2 = strlen(b);
        len3 = strlen(c);
        ++caseno;
        int res=lcs(0,0,0);
        printf("Case %d: ",caseno);
        if(res==0) printf("0 T.A.T\n");
        else
        {
            printf("%d ", res);
            print(0,0,0);
            puts("");
        }
    }
    return 0;
}
