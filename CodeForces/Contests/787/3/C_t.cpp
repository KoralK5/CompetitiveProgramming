//Code by gourav

#include<bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

typedef long long ll;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define gourav cout.tie(NULL);

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define itn int
#define INF 1e18
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define all(X) (X).begin(), (X).end()
#define allr(X) (X).rbegin(), (X).rend()
#define sz(X) (int)X.size()
#define endl "\n"
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (n); i++)
#define loop(i,a,b) for(ll (i)=(a);(i)<=(b);++i)
#define mod 1000000007


void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


bool sorta ( const pair < int , int > & a , const pair < int , int > & b ) { return ( a . second < b . second );}   
bool sortd ( const pair < int , int > & a , const pair < int , int > & b ) { return ( a . second > b . second );}  
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
string decToBinary ( int n ) { string s = "" ; int i = 0 ; while ( n > 0 ) { s = to_string ( n % 2 ) + s ; n = n / 2 ; i ++;} return s ;}      
// ll binaryToDecimal ( string n ) { string num = n ; ll dec_value = 0 ; int base = 1 ; int len = num . length (); for ( int i = len - 1 ; i >= 0 ; i--) { if ( num [ i ] == '1' ) dec_value + = base ; =       basebase * 2 ;} return dec_value ;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
// int binExponentiation
int power(int x,int y){ll res = 1;while(y){if(y&1)res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res%mod;}
inline int inv(int a){a %= mod;if (a < 0) a += mod;int b = mod, u = 0, v = 1;while (a){int t = b / a;b -= t * a; swap(a, b);u -= t * v; swap(u, v);}assert(b == 1);if (u < 0) u += mod;return u;}
inline void add(int &a, int b){a += b;if (a >= mod) a -= mod;}
inline void sub(int &a, int b){a -= b;if (a < 0) a += mod;}
inline int mul(int a, int b){return (int) ((long long) a * b % mod);}
/*------------------------------------------------------------------------------*/




void gourav_sv(){


	string s;
	cin >> s;

	int n = sz(s);

	

	int a = -1;
	int b = -1;

	forn(i,n){
		if(s[i]=='1')
			b=i;
	}

	forn(i,n){
		if(s[i]=='0'){
			a=i;
			break;
		}
	}

	if(a==-1 and b==-1){
		cout << n << endl;
	}else if(a==-1 and b!=-1){
		cout << n-b << endl;
	}else if(b==-1 and a!=-1){
		cout << a+1 << endl;
	}else if(a<b)
	cout << 2 << endl;
	else cout <<a-b+1 << endl;

	

}




/*-----------------------------------------------------------------------------*/

int32_t main(){

	#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
	#endif

	Code By gourav
	
	int t=1;
	int k = 1;
	cin >> t;

	while(t--){
		// cout << "Case #" << k << ": ";k++;
		gourav_sv();
	}
}
