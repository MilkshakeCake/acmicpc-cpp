#include "subway.h"

// 기본 생성자 구현
Node::Node(){};

// 멤버 변수를 받아 저장하는 Node 생성자 구현
Node::Node(int w, int l, string i) : weight(w), line(l), idx(i){};

// Node형 변수 간에 크기 비교는 weight만 필요하다
bool Node::operator<(const Node &b) const
{
    return weight > b.weight;
}

// 다익스트라 알고리즘
void metro::shortest_Path(int sline, string start)
{
    for (auto &i : routes)
        i.push_back(start);
    for (auto &i : lineRoute)
        i.push_back(sline);
    cache[idxNum[start]] = 0;

    priority_queue<Node> pq;
    pq.push(Node(0, sline, start));

    while (!pq.empty())
    {
        Node now = pq.top();
        int nowidx = idxNum[now.idx];
        pq.pop();

        if (now.weight > cache[nowidx])
            continue;

        // cache[i] : 현재 알고 있는 i번 노드로 가는 최소 비용
        for (Node next : graph[nowidx])
        {
            int nextidx = idxNum[next.idx];

            // 출발역이 아닌 곳에서 호선이 변경되는 경우 환승으로 간주
            if (next.line != now.line && now.idx != start)
                next.weight += 30;

            // 현재 저장된 최소 비용보다 낮은 비용의 경로 발견
            if (next.weight + now.weight < cache[nextidx])
            {
                // cache에 새로운 최소 비용 업데이트
                cache[nextidx] = next.weight + now.weight;
                // 새로운 최단 경로를 지나온 경우를 우선순위 큐에 저장
                pq.push(Node(cache[nextidx], next.line, next.idx));

                // routes에 최단 경로 업데이트
                // 직전 노드까지의 최단 경로 정보를 깊게 복사하고 최신 노드 추가
                routes[nextidx] = routes[nowidx];
                routes[nextidx].push_back(next.idx);

                // lineRoutes에 최단 경로의 호선 정보 업데이트
                // 직전 노드까지의 최단 경로 정보를 깊게 복사하고 최신 노드 추가
                lineRoute[nextidx] = lineRoute[nowidx];
                lineRoute[nextidx].push_back(next.line);
            }
        }
    }
}

// 중점까지의 거리 계산. shortest_Path()에서 구한 최단 경로 정보 활용
void metro::midPoint(int to, int &h1, int &h2)
{
    h1 = 0;
    h2 = 0;

    int len = (int)routes[to].size();

    int i;

    for (i = 1; i < len; i++)
    {
        // 경로 내의 i번째 노드에 도달하는 비용 + 60이 전체 비용보다 클 때 중단
        // 남은 비용은 i번째 노드에서 종점까지의 비용에 전달
        if (h1 + 60 >= cache[to] - h1)
            break;

        h1 += 60;

        if (lineRoute[to][i] != lineRoute[to][i - 1])
            h1 += 30;
    }

    // i++된 직후에 break하므로 routes[to][i - 1]이 중점
    cout << routes[to][i - 1] << endl;

    h2 += 60;

    // 중점까지의 거리 계산
    for (i++; i < len; i++)
    {
        h2 += 60;

        if (lineRoute[to][i] != lineRoute[to][i - 1])
            h2 += 30;
    }
}

void printMinute(int time)
{
    cout << time / 60 << ':';

    cout.width(2);
    cout.fill('0');
    cout << time % 60 << endl;
}
