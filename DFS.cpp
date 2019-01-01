#include<bits/stdc++.h>
using namespace std;
class Graph
{
private:
	int *start_time;
	int *finish_time;
	int vertices;
	bool *visited;
	list<int> *adj;
	int time;
public:
	Graph(int);
	void addedge(int,int);
	void DFS(int);
	void Time();
};
Graph::Graph(int v)
{
	this->vertices=v;
	start_time = new int[v];
	finish_time = new int[v];
	adj = new list<int>[v];
	visited= new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	time=0;
}

void Graph::addedge(int u,int v)
{
	adj[u].emplace_back(v);
}

void Graph::DFS(int source)
{
	time+=1;
	start_time[source]=time;
	visited[source]=true;
	cout<<source<<" ";
	//cout<<"vertex"<<source<<"Start time"<<start_time[source]<<" ";
	for(auto i=adj[source].begin();i!=adj[source].end();++i)
	{
		if(visited[*i]==false)

			DFS(*i);


	}
	time++;
	finish_time[source]=time;
	//cout<<"Vertex "<<source<<" end time "<<finish_time[source]<<endl;
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
	cout<<"The DFS starting with "<<source<<" is\n";
	g.DFS(source);
	cout<<endl;
}