#include <iostream>
#include <cstdio>

using namespace std;
int roads[500][500] = {0};
bool passed[500] = {0};
int teams[500] = {0};
int N = 0, M = 0;
int C1 = 0, C2 = 0;
int minc = 500;
int maxt = 0;
int cnt = 0;

void dfs_(int cur, int length) {
  if (cur > N - 1)
    return;
  passed[cur] = true;
  if (cur == C2) {
    if (length < minc)
      minc = length;
    return;
  }

  for (int i = 0; i < N; ++i) {
    if (!passed[i] && roads[cur][i] != -1) {
      dfs_(i, length + roads[cur][i]);
      passed[i] = false;
    }
  }
}

void dfs(int cur, int length, int team) {
  if (cur > N - 1)
    return;
  passed[cur] = true;
  if (cur == C2) {
    if (length == minc) {
      cnt++;
      if (maxt < team)
        maxt = team;
    }
    return;
  }

  for (int i = 0; i < N; ++i) {
    if (roads[cur][i] != -1 && !passed[i]) {
      dfs(i, length + roads[cur][i], team + teams[i]);
      passed[i] = false;
    }
  }
}
int main() {
  freopen("1003.in", "r", stdin);
  freopen("1003.out", "w", stdout);
  cin >> N >> M >> C1 >> C2;
  for (int i = 0; i < N; ++i) {
    cin >> teams[i];
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      roads[i][j] = -1;
    }
  }
  int s = 0, e = 0, L = 0;
  for (int i = 0; i < M; ++i) {
    cin >> s >> e >> L;
    roads[s][e] = L;
    roads[e][s] = L;
  }
  dfs_(C1, 1);
  dfs(C1, 1, teams[C1]);
  cout << cnt << " " << maxt;
  return 0;
}