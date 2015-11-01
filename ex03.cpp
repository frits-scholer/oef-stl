#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;

double DistanceToOrigin(const vector<double>& p) {
  return sqrt(inner_product(p.begin(), p.end(), p.begin(), 0.0));
}

int main() {
  cout << "Enter space separated point coordinates:\n";
  string pointstr;
  getline(cin, pointstr);
  istringstream nrstream(pointstr);
  vector<double> v((istream_iterator<double>(nrstream)), istream_iterator<double>());
  cout << "Distance to origin: " << DistanceToOrigin(v) << endl;
}
