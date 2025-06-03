#include <iostream>

#include <vector>
using namespace std;

//read only (const), does not find the smallest element. Modifications are not allowed.
int find_smallest_pos(const vector<int>& v, int ini) {
    int pos = ini;
    int n = v.size();
    for (int i = ini; i < n; ++i)
        if (v[i] < v[pos])
            pos = i;
    return pos;
}
//modify the position of elements within the vector. Modifications are allowed (no const).
void swap(vector<int>& v, int i, int j) {
    int tmp = v[j];
    v[j] = v[i];
    v[i] = tmp;
}

int main() {
    vector<int> v1 = { 11,2,34,45,6,6,7,3,34,5,6,-1,2,34,5,-34,0 };
    int n = v1.size();
    for (int i = 0; i < n; ++i) {
        int pos = find_smallest_pos(v1, i);
        swap(v1, i, pos);
    }
    for (int i = 0; i < n; ++i)
        cout << v1[i] << " ";
    cout << endl;
}