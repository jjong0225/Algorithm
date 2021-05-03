void Dijkstra_Using_Heap()
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, Start));
    Dist[Start] = 0;
 
    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
 
        for (int i = 0; i < Vertex[Cur].size(); i++)
        {
            int Next = Vertex[Cur][i].first;
            int nCost = Vertex[Cur][i].second;
 
            if (Dist[Next] > Cost + nCost)
            {
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }
 
    for (int i = 1; i <= V; i++)
    {
        if (Dist[i] == INF) cout << "INF" << endl;
        else cout << Dist[i] << endl;
    }
}

void floyd(int n){
    for (int mid=1;mid<=n;mid++){
        for (int start=1;start<=n;start++){
            for (int end=1;end<=n;end++){
                if (graph[start][end] > graph[start][mid] + graph[mid][end]){
                    // 더 가까운 경로가 있을 경우 최신화
                    graph[start][end] = graph[start][mid] + graph[mid][end];
                    // 직전정점 행렬 최신화
                    before[start][end] = before[mid][end];
                    
                }
            }
        }
    }
}




