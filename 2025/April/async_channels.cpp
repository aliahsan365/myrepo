#include <iostream>
#include <future>
using namespace std;


int factorial(future<int>&fu) {
	int res = 1;
	int n = fu.get();
	for (int i = n; i > 0; --i)
		res = res * i;
	return res;
}

int main() {
	int x;
	promise<int> p;
	future<int> fu = p.get_future();
	future<int> f = async(std::launch::async, factorial, std::ref(fu));
	std::this_thread::sleep_for(std::chrono::seconds(2));
	p.set_value(5);
	x = f.get();
	cout << "res computed in async way is: " << x << endl;
}