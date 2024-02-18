#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ans = 0;
        int a;

        while(n--) {
          cin >> a; 
          ans = max(ans, a * (ans / a + 1));
        }
        
        cout << ans << '\n'; 
    }
}
