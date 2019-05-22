#include <bits/stdc++.h>

using namespace std;

void add_edge(vector<int> mat[], int source, int dest)
{
    mat[source].push_back(dest);
}

int depth_search(vector<int> mat[], int source, int f)
{
    list<int> queue;
    bool visited[f];

    for (int i = 0; i < f; i++)
    {
        visited[i] = false;
    }

    visited[source] = true;
    queue.push_back(source);
    int counter = 0;

    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < mat[u].size(); i++)
        {
            if (visited[mat[u][i]] == false)
            {
                visited[mat[u][i]] = true;
                queue.push_back(mat[u][i]);
                counter++;
            }
        }
    }

    printf("%d\n", ++counter);

    return false;
}

int main()
{

    int f;
    scanf("%d", &f);

    int source;
    scanf("%d", &source);

    vector<int> mat[f];

    int num;

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < f; j++)
        {
            scanf("%d", &num);

            if (num)
            {
                add_edge(mat, i, j);
            }
        }
    }

    depth_search(mat, source - 1, f);

    return 0;
}

