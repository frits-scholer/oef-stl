#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

double calc_median(vector<int>& v) {
  const vector<int>::iterator it = v.begin()+(v.size()/2); 
  nth_element(v.begin(), it, v.end());
  if (v.size()%2 == 1) {
    return (double)*it;
  }
  else {
    nth_element(v.begin(), it-1, v.end());
    return (double)(*(it-1)+*it)/2.0;
  }
}

int main() {
  vector<int> data {3, 7, 8, 11, 18, 2};
  cout << "The median is: " << calc_median(data) << endl;
}
