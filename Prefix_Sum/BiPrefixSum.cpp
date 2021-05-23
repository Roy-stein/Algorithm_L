#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define ll long long

using namespace std;

const int N = 1e5 + 50;
int a[N];
bool can[N];
ll aa[N], bb[N];
int n, k;
ll cur, ret;

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ )
        cin >> a[i];
    for (int i = 1; i <= n; i ++ )
        cin >> can[i];
    for(int i = 1; i <= n; ++i){
        if(can[i]){
            aa[i] = aa[i-1] + a[i];         //choose or not choose
        }else{
            aa[i] = aa[i-1];
        }
        bb[i] = bb[i-1] + a[i];
    }
    ll ret = 0;
    for(int i = k; i <= n; ++i){
        ret = max(ret, bb[i] - bb[i-k] - aa[i] + aa[i-k]);
    }
    cout << ret + aa[n];
}
