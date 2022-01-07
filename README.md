# networkx-cpp
Header-only C++ wrapper for Python3 networkx library. Reads graphs from a text file "graph.txt" storing the edge list data. Graphs are directed, and may have multiple edges. By use of networkx MultiDiGraph() class, the following functions are implemented:

* number of nodes in the graph
* neighbours of a given node
* number of edges between two nodes
* transition id of a given edge

Can be extended easily to include more networkx functions by modifying graph.py and graph.h.  

Example of usage given in example.cpp.
