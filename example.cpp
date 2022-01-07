#include<iostream>
#include"graph.h"
using namespace std;

int main()
{
	int num = num_nodes();
	cout<<"Number of nodes in G: "<<num<<".\n";

	for (int n = 1; n <= num; n++)
	{
		auto vec = neighbours_list(n);
		cout<<"Neighbours of "<<n<<": ";
		for (int i = 0; i < vec.size(); i++)
		{
			if (i == vec.size() - 1)
			{
				cout<<vec.at(i)<<".\n";
			}
			else
			{
				cout<<vec.at(i)<<", ";
			}
		}
		if (vec.size() == 0)
		{
			cout<<"None.\n";
		}
	}

	int count = no_of_parallel_edges(1,2);
	cout<<"Number of edges between 1 and 2: "<<count<<".\n";
	for (int i = 0; i < count; i++)
	{
		cout<<"Transition ID of edge "<<i<<" between 1 and 2: "<<transition_id(1,2,i)<<".\n";
	}

	count = no_of_parallel_edges(1,3);
	cout<<"Number of edges between 1 and 3: "<<count<<".\n";
	for (int i = 0; i < count; i++)
	{
		cout<<"Transition ID of edge "<<i<<" between 1 and 3: "<<transition_id(1,3,i)<<".\n";
	}

	return 0;
}