#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
  ifstream input("data.txt");
  multiset<int> values;
  //Read the data from the file
  int currValue;
  while (input >> currValue)
    values.insert(currValue);
  double total = 0.0;
  size_t n = distance(values.lower_bound(25), values.upper_bound(75));
  cout << "average is " << accumulate(values.lower_bound(25), values.upper_bound(75), total)/n
       << endl;
}
