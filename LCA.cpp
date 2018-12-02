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
int dx4[] = {0, 0, 1, -1}; int dy4[] = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, -1, 1, 1, -1, -1}; int dy8[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dxH[] = {2, 2, -2, -2, 1, 1, -1, -1}; int dyH[] = {1, -1, 1, -1, 2, -2, 2, -2};

const double GRS = (1 + sqrt(5))/2;

template<typename T> T power(T X, T P)
{
    T ans = (T)1;
    for(T i=1; i<=P; i++){
        ans = ans * X;
    }
    return ans;
}

template<typename T> T ABS(T A, T B)
{
    T ret = A - B;
    if(ret<0) return -ret;
    return ret;
}

const LL MOD = 1000000007;
const LL BIGMAX = power(2,63) - 1;

template<typename T> T ADD(T X, T Y, T M)
{
    if(X+Y<0)
        return (X - M) + Y;
    else if(X+Y>=M)
        return X+Y-M;
    else
        return X+Y;
}

template<typename T> T prod(T a, T b, T c) // CUSTOM PRODUCT FUNCTION FOR BIG NUMBER MULTIPLICATION
{
    T x = 0, y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = ADD(x, y, c);
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

template<typename T> T bigmod(T a, T b, T c){
    T x = (T)1, y = a%c;
    while(b > 0) {
        if(b%(T)2 == (T)1) {
            x = (x * y)%c;
        }
        y = (y * y)%c;
        b /= (T)2;
    }
    return x;
}


template <typename T> T MODINVERSE(T a){
    return bigmod(a, MOD-2);
}

template<typename T> T GCD(T x, T y) {
  while ( y != 0 ) {
    T z = x % y;
    x = y;
    y = z;
  }
  return x;
}

bool isvowel(char ch)
{
    ch = toupper(ch);
    if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='Y') return true;
    return false;
}

template<typename T>T isleap (T year)
{
    if (year%(T)400 == (T)0 || (year%(T)100 != (T)0 && year%(T)4 == (T)0)) return true;
    return false;
}

/**----------------------------------------------------------------------------**/
/** Template Ends Here. Main Function And User Defined Functions Starts Here. **/
/**--------------------------------------------------------------------------**/

vector<int>graph[123456];
int Depth[123456], Parent[123456];
int Sparse[123456][20];

void DFS(int from, int node, int dep)  // Protita Node er Parent Calculation Korar Jonne .
{
    Depth[node] = dep;
    Parent[node] = from;
    for(int i=0; i<(int)graph[node].size(); i++){
        int v = graph[node][i];
        if(v==from) continue;
        DFS(node, v, dep+1);
    }
}

void LCA_INIT(int N) // LCA Initialization for 2^0th Node .
{
    ERASE(Sparse, -1);  // Initially Sobgulo Node er 2^jth parent -1
    for(int i=0; i<N; i++){
        Sparse[i][0] = Parent[i];
    }

    for(int j=1; (1<<j)<N; j++){
        for(int i=0; i<N; i++){
            if(Sparse[i][j-1]!=-1)
                Sparse[i][j] = Sparse[Sparse[i][j-1]][j-1]; // [i][2^j] th Parent Bosano Hoise Rule Onusare
        }
    }
}

int LCA_Query(int N, int p, int q)
{
    if(Depth[p]<Depth[q]) swap(p, q); // Q node er Level ta always Kom rakha hoise

    int log = 1;
    while(1){  // P node ta kon level e ache seta Ber kora hoise .
        int next = log + 1;
        if((1<<next)>Depth[p]) break;
        log++;
    }

    for(int i=log; i>=0; i--){  // P & Q node ke same level niye asa hoyeche.
        if(Depth[p] - (1<<i)>=Depth[q]){
            p = Sparse[p][i];
        }
    }

    if(p==q) return p;  // Jodi Q node je Level e ache sei level er node ta P node hoi tahole P hobe LCA

    for(int i=log; i>=0; i--){  // Same Level e asar por dui node ke Level by Level uporer dike niye ese Same parent ber kora hoyeche
        if(Sparse[p][i]!=-1 && Sparse[p][i]!=Sparse[q][i]){
            p = Sparse[p][i], q = Sparse[q][i];
        }
    }

    return Parent[p]; // LCA return korsi
}

int main()
{
    int node, edges;
    scanf("%d %d", &node, &edges);
    for(int i=0; i<edges; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(0, 0, 0);
//    for(int i=0; i<node; i++){
//        cout<<i<<' '<<Parent[i]<<' '<<Depth[i]<<endl;
//    }
    LCA_INIT(node);
    int q;
    scanf("%d", &q);
    while(q--){
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", LCA_Query(node, u, v));
    }
}

/*
17 16
0 1
1 2
2 3
3 4
4 5
5 6
6 7
1 8
8 9
9 10
10 11
11 12
12 13
11 15
12 16
14 6
*/



