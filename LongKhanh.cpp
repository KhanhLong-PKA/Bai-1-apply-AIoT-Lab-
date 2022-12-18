#include <bits/stdc++.h>

using namespace std;

const int maxn = 1001;
int n , ans = 0 , a[maxn] , b[maxn] , c[maxn];
int main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	while(n > 0){
		for(int i = 1 ; i <= n ; i++) b[i] = a[i];
		sort(b + 1 , b + 1 + n);
		int dem = 1 , idx = b[1] , maxdem = 1;
		b[n + 1] = b[n] + 23;
		for(int i = 2 ; i <= n + 1 ; i++){
			if(b[i] == b[i - 1]) dem++;
			else{
				if(dem > maxdem){
					idx = b[i - 1];
					maxdem = dem;
				}
				dem = 1;
			}
		}
		ans += maxdem;
		int cnt = 0;
		for(int i = 1 ; i <= n ; i++) if(a[i] != idx && (cnt == 0 || (cnt > 0 && c[cnt] != a[i]))){
			c[++cnt] = a[i];
		}
		if(c[1] == c[cnt] && cnt > 1) cnt--;
		n = cnt;
		for(int i = 1 ; i <= cnt ; i++){
			a[i] = c[i];
		} 
	}
	cout << ans;
    return 0;
}
