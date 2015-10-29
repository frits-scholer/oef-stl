#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool ShortWord(const string& w) {
  return w.length() <= 3;
}
void RemoveShortWords(vector<string>& v) {
  v.erase(remove_if(v.begin(), v.end(), ShortWord), v.end());
}

int main() {
  vector<string> stringvect {"this", "is", "a", "test"};
  RemoveShortWords(stringvect);
  for (auto str : stringvect) cout << str << endl;
  cout << endl;
}
