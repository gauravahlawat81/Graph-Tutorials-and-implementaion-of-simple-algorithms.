#include<bits/stdc++.h>
using namespace std;
class Graph
{
private:
	int vertices;
	int **adjmatrices;  //2D Array
	list<int> *adjlist; //Double ended list
public:
	Graph(int);
	void addedge(int,int);// for adding the edge
	void representation();//representing the graph
};
Graph::Graph(int v)
{
	vertices=v;
	// now we will dynamically allocate a 2D array.In C++ it's a bit complicated to do so.
	adjmatrices= new int* [v];
	for(int i=0;i<v;i++)
	{
		adjmatrices[i]=new int[v];
		memset(adjmatrices[i],0,v*sizeof(int));// initializing all the values in a row to zero(reprsenting no edge)
	}
	// allocating memory for array done
	adjlist = new list<int>[v];//dynamically allocating memory for adjacency list.
}
void Graph::addedge(int u,int v )
{
	adjmatrices[u][v]=1;//edge from vertex u to v
	adjmatrices[v][u]=1;// edge from vertex v to u(we are considering undirected graph)
	adjlist[u].emplace_back(v);
	adjlist[v].emplace_back(u);

}
void Graph:: representation()
{
	cout<<"Adjacent Matrices representation of the graph is\n";
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			cout<<adjmatrices[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\nAdjacency list representation is\n";
	for(auto i=0;i<vertices;i++)
	{
		for(auto j=adjlist[i].begin();j!=adjlist[i].end();++j)
	 	{
	 		cout<<*j<<" ";
		}
		cout<<endl;
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
	g.representation();
}