#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
void printContainer(T be, T en)
{
	while(be!=en)
	{
		cout<<*be<<" ";
		++be;
	}
}

class Graph
{
	typedef vector<int> vi;
	int nV;
	int nE;
	vector<int>* adjList;

public:

	Graph(int n)
	{
		nV = n;
		nE = 0;
		adjList = new vi[nV + 1];
	}

	~Graph()
	{
		delete[] adjList;	
	}

	void addEdge(int x, int y,bool directional = false)
	{
		adjList[x].push_back(y);
		++nE;

		if(directional)
			return;

		adjList[y].push_back(x);
	}

	void dfs_helper(int src,bool visited[])
	{
		visited[src] = true;
		cout<< src << " ";

		for(int i=0;i<adjList[src].size();i++)
		{
			int neighbor = adjList[src][i];
			if(visited[neighbor] == false)
			{
				dfs_helper(neighbor,visited);
			} 
		}
	}

	void dfs(int src)
	{
		bool* visited = new bool[nV+1];
		dfs_helper(src,visited);
		delete[] visited;
	}

	void printConnected()
	{
		bool* visited = new bool[nV + 1]();
		for(int i=1;i<=nV;i++)
		{
			if(visited[i]==false)
			{
				dfs_helper(i,visited);
				cout<<endl;
			}
		}
		delete[] visited;
	}

	void bfs(int src)
	{
		bool* visited = new bool[nV + 1]();
		queue<int> q;

		visited[src] = true;
		q.push(src);

		while(q.empty() == false)
		{
			int curVex = q.front();
			q.pop();

			cout<<curVex<<" ";

			for(int i=0;i<adjList[curVex].size();i++)
			{
				int neighbor = adjList[curVex][i];

				if(visited[neighbor] == false)
				{
					visited[neighbor] = true;
					q.push(neighbor);
				}
			}
		}

		delete[] visited;

	}

	int shortestDistance(int src,int dest)
	{
		queue<int> q;
		bool* visited = new bool[nV+1]();
		int* distArr = new int[nV+1];

		for(int i=0;i<=nV;++i)
		{
			distArr[i] = 0;
		}

		visited[src] = true;
		q.push(src);

		while(q.empty() == false)
		{
			int curr = q.front();
			q.pop();	

			for(int i = 0; i < adjList[curr].size(); ++i)
			{
				int neighbor = adjList[curr][i];

				if(visited[neighbor] == false)
				{
					visited[neighbor] = true;
					distArr[neighbor] = distArr[curr] + 1;
					q.push(neighbor);
				}
			}
		}

		return distArr[dest];

		delete[] visited;
		delete[] distArr;
	}

	vector<int> shortestPath(int src,int dest)
	{
		queue<int> q;
		bool* visited = new bool[nV+1]();
		int* parent = new int[nV+1];

		for(int i=0;i<=nV;++i)
		{
			parent[i] = 0;
		}

		visited[src] = true;
		parent[src] = src;
		q.push(src);

		while(q.empty() == false)
		{
			int curr = q.front();
			q.pop();	

			for(int i = 0; i < adjList[curr].size(); ++i)
			{
				int neighbor = adjList[curr][i];

				if(visited[neighbor] == false)
				{
					visited[neighbor] = true;
					parent[neighbor] = curr;
					q.push(neighbor);
				}
			}
		}

		vector<int> v;
		int i = dest;

		v.push_back(i);

		while(parent[i] != i)
		{
			v.push_back(parent[i]);
			i = parent[i];
		}

		return v;

		delete[] visited;
		delete[] parent;
	}

	vector<int> topologicalSort()
	{
		int* indegree = new int[nV + 1];
		queue<int> q;

		for(int i = 0; i <= nV; ++i)
		{
			indegree[i] = 0;
		}

		for(int ver = 1; ver <= nV; ++ver)
		{
			for(int i = 0; i < adjList[ver].size(); ++i)
			{
				int neighbor = adjList[ver][i];
				++indegree[neighbor];
			}
		}

		for(int i = 1; i <= nV; ++i)
		{
			if(indegree[i] == 0)
			{
				q.push(i);
			}
		}

		std::vector<int> ans;

		while(q.empty() == false)
		{
			int curTask = q.front();
			q.pop();

			ans.push_back(curTask);

			for(int i = 0; i< adjList[curTask].size(); ++i)
			{
				int neighbor = adjList[curTask][i];
				--indegree[neighbor];

				if(indegree[neighbor] == 0)
					q.push(neighbor);
			}
		}


		delete[] indegree;
		return ans;

	}

};

#endif