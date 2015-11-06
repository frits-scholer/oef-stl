#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <utility>
#include <algorithm>
using namespace std;

int char_average(int a, int b) {return (a+b)/2;}

bool char_diffmod2(int a, int b) {return (a-b)%2 == 0 && a != b;}

string average(const string& v, const string& w) {
  string avg(5, ' ');
  transform(v.begin(), v.end(), w.begin(), avg.begin(), char_average);
  return avg;
}

bool diffmod2(const string& v, const string& w) {
  vector<bool> p(5);
  transform(v.begin(), v.end(), w.begin(), p.begin(), char_diffmod2);
  return find(p.begin(), p.end(), false) == p.end();
}

int main() {
  ifstream is("sgb-words.txt");
  vector<string> words((istream_iterator<string>(is)), istream_iterator<string>());
  is.close();
  sort(words.begin(), words.end());
  for (auto it = words.begin();it != words.end()-1;++it)
    for (auto it2 = it+1; it2 !=words.end();++it2) 
      if (diffmod2(*it, *it2)) {
	auto it3 = find(it+1, it2, average(*it, *it2));
	if (it3 != it2) cout << "(" << *it << "," << *it3 << "," << *it2 << ")\n";
      }
}
