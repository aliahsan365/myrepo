#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre){
    int pos = (esq+dre)/2;
    if (esq > dre) return -1;
    else if (x == v[pos]) return pos; 
    else if (x > v[pos]) return posicio(x,v,pos+1,dre);
    else return posicio(x,v,esq,pos-1);
    
}

*
void read_vector(vector<double> &v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) cin >> v[i];
}


int main() {
    int n;
    double x;
    cout << "introduce vectors size: " << endl;
    cin >> n;
    cout << "introduce the value to search for" << endl;
    cin >> x;
    vector<double> v(n);
    read_vector(v);
    int pos = position(x,v,0,n);
    cout << "the position where you will fine the element is: " << pos << endl;
}

