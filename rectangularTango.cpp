
/* AUTHOR:- SZERO763 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int,int>
#define ivec vector<int>
#define lvec vector<ll> 
#define pvec vector<pair<int,int>>
#define Faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define _print(x) (cout << x << "\n");
#define __print(x, y)(cout << x << " " << y << "\n");
#define _prints(x) (cout << x << " ");
#define _get(x) (cin >> x);
#define __get(x, y)(cin >> x >> y);
#define repeat(i, x, n) for(int i = x; i < n; i++)
#define _repeat(i, n, x) for(int i = n; i >= x; i--)
#define endline cout << "\n";
#define YES cout << "YES\n";
#define NO cout << "NO\n";


const ll MOD = 1e9+7;
template<typename T> 
void printElement(vector<T> &a);
//cout << fixed << setprecision(6);

//__________________SOLUTION___________________________//

// 3
// 2
// -2 0 4 5
// 3 -1 6 5
// 3
// -2 1 4 5
// 3 -1 6 5
// -1 2 6 6
// 4
// -7 1 8 4
// -4 -3 10 11
// -3 -2 7 5
// 1 -5 7 3
//50,70,138


void solve(){
    int n;            cin >> n;
    
    map<ll,pair<ll,ll>> mp;
    vector<pair<ll,ll>> a(n);
    ll totalArea = 0,overlapArea = 0;
    for(int i=0;i<n;i++){
        ll x,y, w,h;             cin>>x>>y>>w>>h;
        mp[x] = {w,h};
        a[i]={x,y};
        totalArea += (w*h);
    }

    sort(a.begin(), a.end());
    vector<pair<ll,ll>> v;
    //remove completly covered rectangle
    for(int i=0; i < n; i++){
        ll a1 = a[i].first;
        ll a2 = mp[a1].first+a1;
        ll b1 = a[i].second;
        ll b2 = mp[a1].second+b1;
        bool covered = false;
        for(int j=0;j<n;j++){
            if(i!=j){
                ll x1 = a[j].first;
                ll x2 = mp[x1].first+x1;
                ll y1 = a[j].second;
                ll y2 = mp[x1].second+y1;

                if(a1>=x1&&a2<=x2&&b1>=y1&&b2<=y2){
                    overlapArea += (mp[a1].first*mp[a1].second);
                    covered = true;
                    break;
                }
            }
        }
        if(!covered){
            v.push_back(a[i]);
        }
    }

    
    //calculate overlaping area
    for(int j=0;j<v.size();j++){
        
        ll x1 = v[j].first,y1=v[j].second;

        for(int i = j+1; i < v.size() && v[i].first < mp[x1].first+x1; i++){
            ll x2 = v[i].first,y2=v[i].second;
            ll l=0,r=0;
            if(x2 < mp[x1].first+x1 && mp[x1].first+x1 <= mp[x2].first+x2){
                l = abs(x2-(mp[x1].first+x1));
            }
            else if(x2 < mp[x1].first+x1 && mp[x2].first+x2 < mp[x1].first+x1){
                l = abs(x2-(mp[x2].first+x2));
            }

            if(y1 <= y2 && y2 < mp[x1].second+y1 && mp[x1].second+y1 <= mp[x2].second+y2){
                r = abs(y2-(mp[x1].second+y1));
                
            }
            else if(y2 < y1 && y1 < mp[x2].second+y2 && mp[x1].second+y1 <= mp[x2].second+y2){
                r = abs(y1-(mp[x1].second+y1));
            }
            else if(y1<= y2 && y2 <mp[x1].second+y1 && mp[x2].second+y2 < mp[x1].second+y1){
                r = abs(y2-(mp[x2].second+y2));
                
            }
            else if(y2 < y1 && y1 < mp[x2].second+y2 && mp[x2].second+y2 < mp[x1].second+y1 ){
                r = abs(y1-(mp[x2].second+y2));
            }

            
            overlapArea += (l*r);
        }
    

    }

    _print(totalArea-overlapArea);



}




//__________________MAIN FUNCTION_______________________//

int main(){
    Faster;

    int t = 1;             _get(t);

    while(t--){
        solve();
    }


    return 0;
}




//_____________________LOCAL FUNCTION______________//


template<typename T> 
void printElement(vector<T> &a){
    for_each(a.begin(), a.end(), [](T v){
        cout << v << " ";
    });
    endline;
}