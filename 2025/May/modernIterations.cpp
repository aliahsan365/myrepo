#include <iostream>
#include <vector>
using namespace std;

class Car {
public:
  Car() = delete; // forcing a car to be incialized with a given price.
  Car(int price) : m_price(price) {}
  int getPrice() { return m_price; }
  void setPrice(int price) { m_price = price; }

private:
  int m_price;
};
int main() {

  // A showroom
  vector<Car> cars = {Car{10000}, Car{20000}, Car{30000},
                      Car{40000}, Car{50000}, Car{60000},
                      Car{70000}, Car{80000}, Car{100000}};

  cout << "Car price before covid-19" << endl;
  for (auto c : cars) {
    cout << c.getPrice() << endl;
  }

  // c is an entair copy of the object car.
  int total = 0;
  for (auto c : cars) {
    total += c.getPrice();
  }

  cout << "Show room total price: " << total << endl;

  cout << "Cars price after covid-19" << endl;

  // A reference is needed becase we are going to modify the car object.
  for (auto &c : cars) {
    int currentPrice = c.getPrice();
    c.setPrice(currentPrice * 2);
  }

  for (auto c : cars) {
    cout << c.getPrice() << endl;
  }
}