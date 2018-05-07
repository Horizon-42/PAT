#include <iostream>
using namespace std;
int roads[500][500] = {0};
int teams[500] = {0};
int N = 0, M = 0;
int C1 = 0, C2 = 0;
int main() {
  cin >> N >> M >> C1 >> C2;
  for (int i = 0; i < N; ++i) {
    cin >> teams[i];
  }
  int s = 0, e = 0, L = 0;
  for (int i = 0; i < M; ++i) {
    cin >> s >> e >> L;
    roads[s][e] = L;
    roads[e][s] = L;
  }

  return 0;
}