import Vertex
import Edge
# Preforms a topsort using Depth First Visiting
# and a Color List of visited nodes.
# Checks for cycles in graph, Returns error message otherwise .
# the bottom nodes of the DFS tree have the lowest indegree, 
# and are added to the top of the list. 
# after all nodes have been visited, The reversed List is 
# Returned, Giving us a Topologically sorted list of nodes
def dfs_topsort(graph):         # recursive dfs with 
		L = []                      # additional list for order of nodes
		color = { vertex.get_value() : "white" for vertex in graph.vertexList }
		found_cycle = [False]
		for vertex in graph.vertexList:
			if color[vertex.get_value()] == "white":
				dfs_visit(graph,vertex, color, L, found_cycle)
			if found_cycle[0]:
				break
 
		if found_cycle[0]:           # if there is a cycle, 
			L = []                   # then return an empty list  
			return ("This Graph has a cycle, we cannot do a topological sort of it")
 
		L.reverse()                  # reverse the list
		return L                     # L contains the topological sort
 
 
def dfs_visit(graph, vertex, color, L, found_cycle):
	if found_cycle[0]:
		return
	color[vertex.get_value()] = "gray"
	for neighbour in vertex.get_neighbours():
		if color[neighbour.get_value()] == "gray":
			found_cycle[0] = True
			return
		if color[neighbour.get_value()] == "white":
			dfs_visit(graph,neighbour, color, L, found_cycle)
	color[vertex.get_value()] = "black"      # when we're done with u,
	L.append(vertex)             # add u to list (reverse it later!)
