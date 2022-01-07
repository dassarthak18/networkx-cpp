import networkx as nx
import sys

# Functions to get desired data from graph

def no_of_parallel_edges(G,u,v):
	i = 0
	while True:
		if G.has_edge(u,v,i):
			i += 1
		else:
			break
	file = open("output.txt","w")
	file.write(str(i))
	file.close()

def transition_id(G,u,v,ID):
	file = open("output.txt","w")
	file.write(str(G.get_edge_data(u,v[0])[int(ID)]['weight']))
	file.close()

def num_nodes(G):
	file = open("output.txt","w")
	file.write(str(nx.number_of_nodes(G)))
	file.close()

def neighbours_list(G,x):
	file = open("output.txt","w")
	list = nx.neighbors(G,x)
	for i in list:
		file.write(str(i)+"\n")
	file.close()

# Build graph from graph.txt

G = nx.MultiDiGraph()
file = open("graph.txt")
i = 1
for line in file.readlines():
	data = line.split()
	x = data[0]
	y = data[1]
	G.add_edge(x, y, weight=i)
	i = i + 1
file.close()

# Returns data to command prompt - can extend to as many networkx functions as desired

choice = int(sys.argv[1])

if choice == 1:
	u = sys.argv[2]
	v = sys.argv[3]
	no_of_parallel_edges(G,u,v)

elif choice == 2:
	u = sys.argv[2]
	v = sys.argv[3]
	ID = sys.argv[4]
	transition_id(G,u,v,ID)

elif choice == 3:
	num_nodes(G)

elif choice == 4:
	x = sys.argv[2]
	neighbours_list(G,x)