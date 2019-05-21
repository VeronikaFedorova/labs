#include <bits/stdc++.h>

using namespace std;

void add_edge(vector<int> mat[], int s, int dest)
{
    mat[s].push_back(dest);
}

bool BFS(vector<int> mat[], int s, int dest, int vertex, int pred[], int dist[])
{

    list<int> queue;
    bool visited[vertex];

    for (int i = 0; i < vertex; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    dist[s] = 0;
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop_front();

        for (int i = 0; i < mat[u].size(); i++)
        {
            if (visited[mat[u][i]] == false)
            {
                visited[mat[u][i]] = true;
                dist[mat[u][i]] = dist[u] + 1;
                pred[mat[u][i]] = u;

                queue.push_back(mat[u][i]);

                if (mat[u][i] == dest)
                {
                    return true;
                }
            }
        }
    }

    return false;
}


void printShortestWay(vector<int> mat[], int s, int dest, int vertex)
{

    int pred[vertex], dist[vertex];

    if (BFS(mat, s, dest, vertex, pred, dist) == false)
    {
        if (s == dest)
        {
            printf("0\n");
        }
        else
        {
            printf("-1\n");
        }
        return;
    }

    vector<int> path;
    int drag = dest;
    path.push_back(drag);
    while (pred[drag] != -1)
    {
        path.push_back(pred[drag]);
        drag = pred[drag];
    }

    printf("%d\n", dist[dest]);

    for (int i = path.size() - 1; i >= 0; i--)
    {
        printf("%d ", ++path[i]);
    }
}


int main()
{
    int vertex;
    scanf("%d", &vertex);

    vector<int> mat[vertex];

    int num;

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            scanf("%d", &num);

            if (num)
            {
                add_edge(mat, i, j);
            }
        }
    }

    int s, dest;

    scanf("%d %d", &s, &dest);

    printShortestWay(mat, s - 1, dest - 1, vertex);
    return 0;
}

