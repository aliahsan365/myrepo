#include <iostream>
#include <vector>
using namespace std;


//Modify the position of elements within the vector. Modifications are allowed (no const).
void swap(vector<int>& v, int i, int j) {
    int tmp = v[j];
    v[j] = v[i];
    v[i] = tmp;
}

//Does find the position of the smallest element from init position to N. 
//Modifications are not allowed (Read Only).
int find_smallest_pos(const vector<int>& v, int ini) {
    int pos = ini;
    int n = v.size();
    for (int i = ini; i < n; ++i)
        if (v[i] < v[pos])
            pos = i;
    return pos;
}

void selection_sort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        int pos = find_smallest_pos(v, i);
        swap(v, i, pos);
    }
}

void print_vector(const vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << endl;
}


int main() {
    vector<int> v = { 11,2,34,45,6,6,7,3,34,5,6,-1,2,34,5,-34,0 };
    selection_sort(v);
    print_vector(v);
}