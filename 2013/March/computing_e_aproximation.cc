#include <iostream>
using namespace std;


int main() {
    cout.setf(ios::fixed);
    cout.precision(10);
    int n;
    while(cin >> n) {
        int aux = n;
        if(n == 0) cout << "Amb " << aux << " terme(s) s'obte " << 0.0000000000 << "." << endl;
        else  {
            double e = 1;
            double dem = 1;
            int i = 1;
            while (i < n) {
                dem = dem * i;
                e = e  + 1.0/dem;
                i = i  + 1;
            }
            cout <<"Amb " << aux << " terme(s) s'obte " << e << "." << endl;
        } 
    }
}




