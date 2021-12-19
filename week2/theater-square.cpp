#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll how_much(ll a, ll b) {
  ll ans = a / b;
  if (a % b)
    ans++;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  double h, v, a;
  cin >> v >> h >> a;
  ll sol = 0;
  sol+=ceil(v/a)*ceil(h/a);
  // cout<<perfect<<" "<<f_v<<" "<<f_h<<" \n";
  cout<<sol <<endl;
  /*
     10 18
     2*1 

     10/4 = 2
     18/4 = 4
     =      8

     4*4 = 16
     2*4 = 8


     do the columns
     get the remaining squares
     6%4 = 2
     6%4 = 2

     perfect = 6/4 = 1

     for vertical = v/4 +  v%4
     for horizontal = h-mod_v + v%4


  */

  // // do the doable
  // ll col = n / a;
  // ll row = m / a;

  // ll col_rem = (col*a<n ? 0 : 1);

  // ll row_rem = (row*a<m ? 0 : 1);
  // /*
  //         000011
  //         000011
  //         000011
  //         000011
  //         111111
  //         111111

  //         000
  //         000
  //         000
  // */
  // cout<<col_rem<<" "<<row_rem<<endl;
  // row_rem = how_much(n - (n % a), a);
  // col_rem = how_much(m, a);
  // sol = (row_rem+col_rem?max(col,row):col*row) + col_rem + row_rem;
  // cout << sol << endl;
  return 0;
}
