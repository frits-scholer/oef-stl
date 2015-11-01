#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <iterator>
#include <string>
#include <sstream>

using namespace std;

void readitems(map<string, double>& m) {
  string word, valstr;
  double val;
  while (getline(cin, word)) {
    getline(cin, valstr);
    istringstream valstream(valstr);
    valstream >> val;
    m[word] = val;
  }
}

set<string> CriticsPick(const map<string, double>& m) {
  multimap<double, string> m_dual;
  for_each(m.begin(), m.end(), [&](pair<string, double> p) {
      m_dual.insert(pair<double, string>(-p.second, p.first));});
  set<string> movies;
  auto it = m_dual.begin();
  for (int i=0; i<10 && it !=m_dual.end();++it, ++i)
    movies.insert(it->second);
  return movies;
}

int main() {
  map<string, double> ml;
  readitems(ml);
  set<string> m = CriticsPick(ml);
  for (auto s:m) cout << s << endl;
}
