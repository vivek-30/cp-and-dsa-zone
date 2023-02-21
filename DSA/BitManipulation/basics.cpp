#include<iostream>
using namespace std;

#define null NULL
#define inf INT_MAX
#define minf INT_MIN
#define ll long long int
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define vi vector<int>
#define mii map<int, int>
#define vvi vector<vector<int> >
#define pii pair<int, int>
#define mid(l, r) (l + (r - l) / 2)
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define f(i,s,n) for(ll i = s; i <= n; i++)
#define fr(i,s,e) for(ll i = s; i >= e; i--)

int getBit(int n, int pos) {
  return (n&(1<<pos)) != 0 ? 1 : 0;
}

int setBit(int n, int pos) {
  return (n | 1<<pos);
}

int clearBit(int n, int pos) {
  return (n&(~(1<<pos)));
}

int updateBit(int n, int pos, int bit) {
  n = n&(~(1<<pos));
  return (n | bit<<pos);
}

int countSetBits(int n) {   // use __builtin_popcount(n) for this
  int ans = 0;
  while(n) {
    ans++;
    n = n&(n-1); // removes 1 set bit from RHS
  }

  return ans;
}

bool checkPowerOfTwo(int n) {
  return (n && !(n & (n-1)));   // as only 1 bit is set in a number of power 2
}


int main() {

  int n = 13, pos = 3;
  
  cout<<countSetBits(30)<<endl;
  cout<<getBit(30, 0)<<endl;
  cout<<getBit(30, 3)<<endl;
  
  n = updateBit(30, 0, 1);
  cout<<n<<endl;
  
  cout<<countSetBits(n)<<endl;
  cout<<clearBit(n, 4)<<endl;
  cout<<setBit(5,1)<<endl;

  cout<<(checkPowerOfTwo(0) ? "Yes" : "No")<<endl;
  cout<<(checkPowerOfTwo(32) ? "Yes" : "No")<<endl;
  cout<<(checkPowerOfTwo(17) ? "Yes" : "No")<<endl;
  cout<<(checkPowerOfTwo(1) ? "Yes" : "No")<<endl;
  cout<<(checkPowerOfTwo(1024) ? "Yes" : "No")<<endl;
  cout<<(checkPowerOfTwo(56) ? "Yes" : "No")<<endl;

  return 0;
}
