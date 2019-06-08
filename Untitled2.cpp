#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

int min_dist(int dist[], bool arr[], int top){
	int min = INT_MAX;
	int min_in;
	for(int v = 0; v < top; v++){
		if(arr[v] == false && dist[v] <= min){
			min = dist[v], min_in = v;
		}
	}
	return min_in;
	}
	
void sol(int top, int dist[], int dest){
	if(dist[dest] < INT_MAX){
		cout << dist[dest];
	}
	else{
		cout << "-1\n" << endl;
	}
}

void dijkstra(int **graph, int source, int top, int dest)
{
    int dist[top];

    bool arr[top]; 

    for (int i = 0; i < top; i++)
    {
        dist[i] = INT_MAX;
        arr[i] = false;
    }

    dist[source] = 0;


    for (int count = 0; count < top - 1; count++)
    {
        int l = min_dist(dist, arr, top);

        arr[l] = true;

        for (int v = 0; v < top; v++)
        {
             if (!arr[v] && graph[l][v] && dist[l] != INT_MAX && dist[l] + graph[l][v] < dist[v] && graph[l][v] != -1)
             {
                dist[v] = dist[l] + graph[l][v];
             }   
        }
        
    }

    sol( top, dist, dest);
}

int main(){
	int top;
	
	cin >> top;

    int **graph = new int *[top];

    for (int i = 0; i < top; i++)
    {
        graph[i] = new int[top];
    }

    int source, dest;

    cin >> source >> dest;

    for (int i = 0; i < top; i++)
    {
        for (int j = 0; j < top; j++)
        {
            cin >> graph[i][j];
        }
    }

    dijkstra(graph, source - 1, top, dest - 1);
}


 
