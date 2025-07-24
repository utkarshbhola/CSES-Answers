#include <iostream>
#include <algorithm>
#include <vector>
#include <climits> // For INT_MAX
#include <utility> // For std::pair
using namespace std;
class SegmentTree {
public:
    int n;
    vector<int> arr;
    vector<int> seg;
    SegmentTree(int n) : n(n) {
        arr.resize(n);
        seg.resize(4 * n);
    }
    
    void BuildTree(int idx,int low, int high){
        if(low == high){
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        BuildTree(2 * idx + 1, low, mid);
        BuildTree(2 * idx + 2, mid + 1, high);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    int Query(int idx, int low, int high, int l, int r){
        if(l <= low && high <= r){
            return seg[idx]; // Full overlap
        }
        if(high < l || low > r){
            return INT_MAX; // No overlap
        }
        int mid = (low + high) / 2;
        int left = Query(2*idx + 1, low, mid, l, r);
        int right = Query(2*idx + 2, mid + 1, high, l, r);
        return min(left, right);
    }
};

int main(){
    int n, q; // n is the number of elements, q is the number of queries
    cin >> n >> q;
    SegmentTree st(n);
    for(int i = 0; i < n; i++){
        cin >> st.arr[i];
    }
    st.BuildTree(0, 0, n - 1); // (idx,low,high)
    
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << st.Query(0, 0, n - 1, l - 1, r - 1) << endl; // Convert to 0-based index
    }
    return 0;
}

