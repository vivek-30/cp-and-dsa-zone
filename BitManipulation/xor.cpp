#include<bits/stdc++.h>
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

// function to check how many bits are required to be changed to make two given numbers equal
int findBits(int a, int b) {
  
  int x = a^b; // gives 1 when both bits are diff so we have total no of diff bits
  int count = 0;
  
  while(x) { // find total set bits
    if((x&1) == 1) { // O(LogN) time as total no. of bits in a binary no. is => log2(n)+1
      count++;
    }
    x = x>>1;
  }
  // use n&(n-1) way to find total set bits as its T.C. is O(No. Of Set Bits In N)
  return count;
}

// find a single non repeating no. in a sequence where every no. is present twice
int findNum1(vi &arr) {
  int x = 0;
  f(i, 0, arr.size()-1) {
    x = x ^ arr[i];
  }

  return x;
}

// find a two non repeating no(s). in a sequence where every no. is present twice
pii findNum2(vi &arr) {
  int x = 0;
  f(i, 0, arr.size()-1) {
    x = x ^ arr[i];
  }

  int pos = 0;
  int temp = x;
  while(temp) {
    if((temp&(1<<pos)) != 0) {
      break;
    }else {
      pos++;
    }
  }

  int s1 = 0, s2 = 0;
  f(i, 0, arr.size()-1) {
    if((arr[i]&(1<<pos)) != 0) {
      s1 = s1 ^ arr[i];
    }
    else {
      s2 = s2 ^ arr[i];
    }
  }

  pii res;
  res.fi = s1;
  res.se = s1^x;

  return res;
}

// find a non repeating no. in a sequence where every no. is present k times
int findNum3(vi &arr, int k = 3) {

  vi freq(64, 0); // as integers are stored in 64 bits typically

  bool isRemaining = true;
  int pos = 0;
  
  while(isRemaining) {
    isRemaining = false;
    f(i, 0, (arr.size() - 1)) {

      freq[pos] += (arr[i]&1);
      arr[i] = arr[i]>>1;

      if(arr[i] != 0 and isRemaining == false)
        isRemaining = true;
    }
    if(!isRemaining)
      break;
    pos++;
  }

  int num = 0;
  f(i, 0, pos) {
    num = num + ((freq[i]%k) != 0 ? 1<<i : 0);
  }

  return num;
}


int main() {

  int n;
  // cin>>n;
  vi arr = {1, 3, 2, 3, 4, 2, 1, 1, 3, 2};
  vi arr1 = {2, 8, 2, 17, 15, 17, 17, 2, 8, 2, 8, 17, 8};
  // pii res = findNum2(arr);
  // cout<<res.fi<<" "<<res.se<<endl;

  // cout<<findBits(2,4)<<endl;
  // cout<<findBits(14,7)<<endl;
  // cout<<findBits(4,32)<<endl;
  // cout<<findBits(12,1)<<endl;

  cout<<findNum3(arr)<<endl;
  cout<<findNum3(arr1, 4)<<endl;

  return 0;
}
