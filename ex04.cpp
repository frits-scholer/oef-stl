#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void BiasedSort(vector<string>& v) {
  sort(v.begin(), v.end());
  stable_partition(v.begin(), v.end(), [](string s){return s == "Me first";});
}

int main() {
  vector<string> strs {
    "ZCats", "ZDogs", "ZBears", "ZDonkeys", "Me first", "ZEels", "Me first", "ZFlies",
      "Me first", "Me first", "Gazelles"};
  for (auto str: strs) cout << str << endl;
  cout << endl;
  BiasedSort(strs);
  for (auto str: strs) cout << str << endl;
  cout << endl;
}
