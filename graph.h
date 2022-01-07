#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<vector>

std::vector<int> readFile()
{
	std::ifstream File("output.txt");
	std::vector<int> arr;
	std::string number;
	while(getline(File,number))
	{
		arr.push_back(stoi(number));
	}
	return arr;
}

int no_of_parallel_edges(int u, int v)
{
	std::string command = "python3 graph.py 1 ";
	command.append(std::to_string(u));
	command.append(" ");
	command.append(std::to_string(v));
	system(command.c_str());
	auto arr = readFile();
	return arr[0];
}

int transition_id(int u, int v, int id)
{
	std::string command = "python3 graph.py 2 ";
	command.append(std::to_string(u));
	command.append(" ");
	command.append(std::to_string(v));
	command.append(" ");
	command.append(std::to_string(id));
	system(command.c_str());
	auto arr = readFile();
	return arr[0];
}

int num_nodes()
{
	system("python3 graph.py 3");
	auto arr = readFile();
	return arr[0];
}

std::vector<int> neighbours_list(int x)
{
	std::string command = "python3 graph.py 4 ";
	command.append(std::to_string(x));
	system(command.c_str());
	return readFile();
}