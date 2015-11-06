#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
  cout << "File to print: ";
  string from;
  cin >> from;
  ifstream is(from.c_str());
  istreambuf_iterator<char> ii(is);
  istreambuf_iterator<char> eos;
  ostreambuf_iterator<char> oo(cout);
  copy(ii, eos, oo);
  cout << endl;
}
