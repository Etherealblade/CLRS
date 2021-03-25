/*
https://zh.wikipedia.org/wiki/%E6%9C%80%E5%B0%8F%E8%B4%B9%E7%94%A8%E6%9C%80%E5%A4%A7%E6%B5%81%E9%97%AE%E9%A2%98#C++
最小费用最大流.

test data:
5 7 0 4
0 1 10 2
0 2 2 4
1 2 6 6
1 3 6 2
2 4 5 2
3 2 3 3
3 4 8 6

From 挑战程序设计竞赛Page 222
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr auto MAXN = 5000 + 50;

struct Edge {
	int fr, to, residual, cost;
};
vector<Edge> edges;
vector<int> G[MAXN];
int s, t, maxFlow, minCost;
int last[MAXN], flow[MAXN], dis[MAXN];
bool inQueue[MAXN];

bool SPFA()
{
	/*
	Shortest Path Faster algorithm
	https://zh.wikipedia.org/wiki/%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84%E5%BF%AB%E9%80%9F%E7%AE%97%E6%B3%95
	*/
	memset(inQueue, false, sizeof(inQueue));
	fill(dis, dis + MAXN, INT_MAX);
	queue<int> que;
	que.push(s);
	inQueue[s] = true;
	flow[s] = INT_MAX;
	last[s] = 0;
	dis[s] = 0;

	int nowAt;
	while (!que.empty())
	{
		nowAt = que.front();
		que.pop();
		inQueue[nowAt] = false;

		for (int i = 0; i < G[nowAt].size(); i++)
		{
			Edge& it = edges[G[nowAt][i]];

			if (it.residual > 0 &&
				dis[it.to] > dis[nowAt] + it.cost)
			{
				dis[it.to] = dis[nowAt] + it.cost;
				last[it.to] = G[nowAt][i];
				flow[it.to] = min(flow[nowAt], it.residual);
				if (!inQueue[it.to])
				{
					inQueue[it.to] = true;
					que.push(it.to);
				}
			}
		}
	}

	if (dis[t] == INT_MAX)
	{
		return false;
	}

	maxFlow += flow[t];
	minCost += dis[t] * flow[t];
	nowAt = t;

	while (nowAt != s)
	{
		edges[last[nowAt]].residual -= flow[t];
		edges[last[nowAt] ^ 1].residual += flow[t];
		nowAt = edges[last[nowAt]].fr;
	}
	return true;
}

void MCMF()
{
	maxFlow = 0;
	minCost = 0;
	while (SPFA())
	{
		;
	}
}

int main()
{
	int fr, to, cost, flow;
	int totNode, totEdges;

	scanf_s("%d%d%d%d", &totNode, &totEdges, &s, &t);
	for (int i = 0; i < totEdges; i++)
	{
		scanf_s("%d%d%d%d", &fr, &to, &flow, &cost);
		G[fr].push_back(edges.size());
		edges.push_back({ fr,to,flow,cost });
		G[to].push_back(edges.size());
		edges.push_back({ to,fr,0,-cost });
	}

	MCMF();

	printf_s("maxFlow:%d, minCost: %d\n", maxFlow, minCost);

	return 0;
}

