#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
	list<int> *adj;
	int vertices;
public:
		
	Graph(int);
	void addedge(int,int);
	void BFS(int);
};
Graph::Graph(int v)
{
	vertices=v;
	adj = new list<int>[v];
}
void Graph::addedge(int u,int v)
{
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
}
void Graph::BFS(int source)
{
	bool visited[vertices];
	memset(visited,false,sizeof(visited));
	queue<int> q;
	q.push(source);
	visited[source]=true;
	while(!q.empty())
	{
		cout<<q.front()<<" ";
			q.pop();

		for(auto i=adj[source].begin();i!=adj[source].end();++i)
		{
			if(visited[*i] == false)
			{
				visited[*i]=true;
				q.push(*i);
			}
		}
	}

}
int main()
{
	int v;
	cout<<"Enter the number of vertices\n";
	cin>>v;
	int edges;
	cout<<"number of edges\t";
	cin>>edges;
	Graph g(v);
	for(int i=0;i<edges;i++)
	{
		int a,b;
		cin>>a>>b;
		g.addedge(a,b);
	}
	cout<<"Enter the source vertex:";
	int source;
	cin>>source;
	cout<<"The BFS starting with "<<source<<" is\n";
	g.BFS(source);
}