#include <iostream>
#include <string>

using namespace std;

/*
 * Find the leftmost occurrence of the substring part and remove it from s
 * - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
 * - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
 * - s = "dababc", remove "abc" starting at index 3, so s = "dab".
 */
string removeOccurrences(string s, string part) {
  while (s.find(part) != -1)
    s.erase(s.find(part), part.length());
  return s;
}

int main() {
  cout << removeOccurrences("axxxxyyyyb", "xy") << endl;
  cout << removeOccurrences("daabcbaabcbc", "abc") << endl;
  return 0;
}
