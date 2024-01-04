#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

vector<double> movingTiles(int l, int s1, int s2, vector<long long> queries) {
  vector<double> times;
  for (int i = 0; i < queries.size(); i++)
    times.push_back((l - sqrt(queries[i])) / abs(s1 - s2) * sqrt(2));
  return times;
}

int main() {
  ifstream ifile("input.txt");
  int l, s1, s2, q;
  ifile >> l >> s1 >> s2;
  ifile >> q;
  vector<long long> queries(q);
  
  for (int i = 0; i < q; i++)
    ifile >> queries[i];
  
  ifile.close();
  
  vector<double> times = movingTiles(l, s1, s2, queries);
  
  ofstream ofile("output.txt");
  
  for (int i = 0; i < q; i++)
    ofile << fixed << setprecision(6) << times[i] << '\n';
  
  ofile.close();
}