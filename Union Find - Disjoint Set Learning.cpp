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

int findParent(int i,int parent[])
{
    if(parent[parent[i]]!=parent[i])
        parent[i]=findParent(parent[i],parent);
    return parent[i];
}

void unionNodes(int a,int b,int parent[],int size[])
{
    int parent_a=findParent(a,parent),parent_b=findParent(b,parent);
    if(parent_a==parent_b)
        return;
    if(size[parent_a]>=size[parent_b])
    {
        size[parent_a]+=size[parent_b];
        parent[parent_b]=parent_a;
    }
    else
    {
        size[parent_b]+=size[parent_a];
        parent[parent_a]=parent_b;
    }
    return;
}

int main()
{

    int N,M,i,a,b;
    scanf(" %d %d",&N,&M);
    int parent[100001]= {0},size[100001]= {0};
    for(i=1; i<=N; i++)
    {
        parent[i]=i;
        size[i]=1;
    }

    for(i=1; i<=M; i++)
    {
        scanf(" %d %d",&a,&b);
        unionNodes(a,b,parent,size);
    }

    for(i=1; i<=N; i++)
        printf("Node %d belongs to connected component %d\n",i,findParent(i,parent));
    long long ways=1;
    int nos=0;
    for(i=1; i<=N; i++)
    {
        if(findParent(i,parent)==i)
        {
            printf("%d leader %d size\n",i,size[i]);
            nos++;
        }

    }
    printf("Total connected components : %d",nos);

    return 0;
}

/*int nodes[10];
int rankof[10];

int findnode(int a, int nodes[])
{
    if(nodes[nodes[a]]!=nodes[a])
        nodes[a] = findnode(nodes[a], nodes);
    return nodes[a];
}
void makeunion(int a, int b, int nodes[], int rankof[])
{
    int u = findnode(a, nodes);
    int v = findnode(b, nodes);
    //cout<<"GOT="<<u<<' '<<v<<endl;
    if(u==v) return;
    if(rankof[u]>=rankof[v])
    {
        rankof[u] = rankof[u] + rankof[v];
        nodes[v] = u;
    }
    else
    {
        rankof[v] = rankof[v] + rankof[u];
        nodes[u] = v;
    }
    return;
}

int main()
{
    //init();
    int x, y;
    memset(nodes,0,sizeof(nodes));
    memset(rankof,0,sizeof(rankof));
    for(int i=1; i<=10; i++)
        { nodes[i] = i; rankof[i] = 1; }
    for(int i=1; i<=7; i++)
    {
        scanf("%d %d", &x, &y);
        makeunion(x,y, nodes, rankof);
    }
    for(int i=1; i<10; i++)
        cout<<findnode(i, nodes)<<endl;
    return 0;
}*/
/*
2 4
2 3
2 1
3 6
6 7
4 5
8 9
*/
