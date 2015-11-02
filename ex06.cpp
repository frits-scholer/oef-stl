#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int RandomNumber() {
  return rand()%100;
}

int main() {
  cout << "How many random numbers do you want? ";
  int N;
  cin >> N;
  vector<int> v;
  srand(static_cast<unsigned int>(time(NULL)));
  generate_n(back_inserter(v), N, RandomNumber);
  for (auto n: v) cout << n << "\t";
  cout << endl;
  double average = 0.0;
  cout << "Average = " << accumulate(v.begin(), v.end(), average)/v.size() << endl;
}
