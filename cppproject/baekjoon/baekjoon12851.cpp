#include <bits/stdc++.h>

using namespace std;

int s, e, ans = -1, cnt;
bool visited[200001];

bool safe(int cur) {
	return 0 <= cur && cur <= 200000;
}

void bfs() {
	queue<pair<int,int> >Q;
	Q.push({s,0});
	visited[s] = true;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		visited[cur.first] = true;

		if (cur.first == e) {
			ans = cur.second;
			cnt++;
		}

		if (cur.second > ans && ans != -1) {
			break;
		}

		if (safe(cur.first - 1) && visited[cur.first-1] == false) {
			Q.push({ cur.first - 1, cur.second + 1});
		}
		
		if (safe(cur.first + 1) && visited[cur.first + 1] == false) {
			Q.push({ cur.first + 1, cur.second + 1 });
		}
		if (safe(cur.first * 2) && visited[cur.first * 2] == false) {
			Q.push({ cur.first * 2, cur.second + 1 });
		}

	}
	printf("%d\n", ans);
	printf("%d", cnt);
}
int main() {
	scanf("%d %d", &s, &e);
	if(s>e){
		printf("%d\n",s-e);
		printf("1");
	}
	else	bfs();
	return 0;
}