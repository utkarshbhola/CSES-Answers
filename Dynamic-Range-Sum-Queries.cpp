#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//fenwick tree
vector<int> BIT;
vector<int> arr;
int rangesum(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}
void update(int idx, int val) {
    while (idx < BIT.size()) {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    BIT.resize(N + 1, 0);
    arr.resize(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx, val;
            cin >> idx >> val;
            update(idx, val - arr[idx]);
            arr[idx] = val;
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << rangesum(r) - rangesum(l - 1) << endl;
        }
    }
    
    return 0;
}