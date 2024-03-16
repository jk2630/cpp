#include<bits/stdc++.h>
#include<chrono>
using namespace std;

int counts = 0;

string swap(string s, int a, int b){
  char temp = s[a];
  s[a] = s[b];
  s[b] = temp;
  return s;
}

void solve(string s, int l, int r){
  if(l == r){
    cout << s << " count:" << ++counts << endl;
    return;
  }
  for(int i=l;i<=r;i++){
    s = swap(s, l, i);
    solve(s, l+1, r);
    s = swap(s, l, i);
  }
  return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto start = chrono::high_resolution_clock::now();

    // solve()
    string str;
    cin >> str;
    solve(str, 0, str.length()-1);

    
    auto end = chrono::high_resolution_clock::now();
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 
    time_taken *= 1e-9;
 
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    
	return 0;
}