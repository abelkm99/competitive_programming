#include <bits/stdc++.h>
#include <string>
#include <utility>
#define ll long long
#define pb push_back
using namespace std;
/*

   url = https://www.hackerrank.com/challenges/crossword-puzzle/problem
                        Input 	   		Output

                      ++++++++++ 		++++++++++
                      +------+++ 		+POLAND+++
                      +++-++++++ 		+++H++++++
                      +++-++++++ 		+++A++++++
                      +++-----++ 		+++SPAIN++
                      +++-++-+++ 		+++A++N+++
                      ++++++-+++ 		++++++D+++
                      ++++++-+++ 		++++++I+++
                      ++++++-+++ 		++++++A+++
                      ++++++++++ 		++++++++++
                      POLAND;LHASA;SPAIN;INDIA

                      6,5
                      5,5

                      POLAND



*/
struct Node {
  char axis;
  int index;
  int start;
  int length;
  string info;
};
void print_map(vector<string> vs) {
  for (auto x : vs)
    cout << x << endl;
}
void searchHorizontal(vector<string> vs, vector<Node> &horizontal, int index) {
  int i = 0;
  while (i < vs[index].length()) {
    if (vs[index][i] == '-') {
      int j = i + 1;
      while (j < vs[index].length() && vs[index][j] == '-') {
        j++;
      }
      if (j - i > 1) {

        Node a;
        a.axis = 'H';
        a.index = index;
        a.start = i;
        a.length = j - i;
        a.info += a.axis;
        a.info += " " + to_string(a.index) + " " + to_string(a.start) + " " +
                  to_string(a.length);
        horizontal.pb(a);
      }
      i = j;
      continue;
    } else {
      i++;
    }
  }
}
void searchVertical(vector<string> vs, vector<Node> &vertical, int index) {
  int i = 0;
  while (i < vs.size()) {
    if (vs[i][index] == '-') {
      int j = i + 1;
      while (j < vs.size() && vs[j][index] == '-')
        j++;
      if (j - i > 1) {
        Node a;
        a.axis = 'V';
        a.index = index;
        a.start = i;
        a.length = j - i;
        a.info += a.axis;
        a.info += " " + to_string(a.index) + " " + to_string(a.start) + " " +
                  to_string(a.length);
        vertical.pb(a);
      }
      i = j;
      continue;
    } else {
      i++;
    }
  }
}
vector<Node> searchLocation(vector<string> crosswords) {
  vector<string> cp(crosswords);
  // print_map(crosswords);
  vector<Node> nodes;
  for (int i = 0; i < 10; i++)
    searchHorizontal(cp, nodes, i);
  for (int i = 0; i < 10; i++)
    searchVertical(cp, nodes, i);
  sort(nodes.begin(), nodes.end(),
       [](auto a, auto b) { return a.length < b.length; });
  // for (Node x : nodes) {
  //   cout << x.info << endl;
  // }
  return nodes;
}
bool can_it(string s, vector<string> &vs_cp, Node node) {
  bool can = true;
  if (node.axis == 'H') {
    int string_index = 0;
    int arr_index = node.start;
    while (string_index <= s.length() - 1) {
      if (vs_cp[node.index][arr_index] == '-') {
        vs_cp[node.index][arr_index] = s[string_index];
      } else if (vs_cp[node.index][arr_index] == s[string_index]) {
        vs_cp[node.index][arr_index] = s[string_index];
      } else {
        can = false;
        break;
      }
      string_index++;
      arr_index++;
    }
  } else {
    int string_index = 0;
    int arr_index = node.start;
    while (string_index <= s.length() - 1) {
      if (vs_cp[arr_index][node.index] == '-') {
        vs_cp[arr_index][node.index] = s[string_index];
      } else if (vs_cp[arr_index][node.index] == s[string_index]) {
        vs_cp[arr_index][node.index] = s[string_index];
      } else {
        can = false;
        break;
      }
      string_index++;
      arr_index++;
    }
  }
  return can;
}
void permutation(vector<string> &arr, vector<string> &ans, vector<int> memo,
                 int index, vector<Node> &nodes, vector<int> nodeMemo,
                 vector<string> &puzzle, bool &found) {
  if (ans.size() == arr.size()) {
    print_map(puzzle);
    found = true;
    return;
  }
  /*
     check the horizontal and vertocal for each
     get all the possible nodes from the array that are not checked
     and that can enter the data;
  */
  for (int i = 0; i < arr.size() && !found; i++) {
    if (memo[i] == 0) {
      // search for memory for arr[]
      for (int k = 0; k < nodes.size() && !found; k++) {
        if (nodes[k].length == arr[i].length() && nodeMemo[k] == 0) {
          vector<string> vs_cp = (puzzle);
          bool res = can_it(arr[i], vs_cp, nodes[k]);
          if (res) {
            ans.push_back(arr[i]);
            memo[i] = 1;
            nodeMemo[k] = 1;
            permutation(arr, ans, memo, ans.size(), nodes, nodeMemo, vs_cp,
                        found);
            memo[i] = 0;
            nodeMemo[k] = 0;
            ans.pop_back();
          }
        }
      }
      // ans.push_back(arr[i]);
      // memo[i] = 1;
      // permutation(arr, ans, memo, ans.size(), nodes, nodeMemo, puzzle);
      // memo[i] = 0;
      // ans.pop_back();
    }
  }
}
vector<string> get_words(string words) {
  vector<string> arr;
  string temp = "";
  for (int i = 0; i < words.length(); i++) {
    if (words[i] == ';') {
      arr.pb(temp);
      temp = "";
    } else {
      temp += words[i];
    }
  }
  if (temp.length())
    arr.push_back(temp);
  return arr;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string words;
  vector<string> crosswords(10);
  for (int i = 0; i < 10; i++)
    cin >> crosswords[i];
  cin >> words;
  // answer;
  vector<string> arr = get_words(words);
  vector<Node> nodes = searchLocation(crosswords);
  vector<string> ans;
  vector<int> memo(arr.size(), 0);
  vector<int> nodeMemo(nodes.size(), 0);
  bool found = false;
  permutation(arr, ans, memo, 0, nodes, nodeMemo, crosswords, found);
  return 0;
}
