
import Vertex
import Edge

def make_set(graph,vertex):
	graph.parent[vertex.get_value()] = vertex.get_value()
	graph.rank[vertex.get_value()] = 0

def find(graph,vertex):
	if graph.parent[vertex] != vertex:
		graph.parent[vertex] = graph.find(graph.parent[vertex])
	return graph.parent[vertex]

def union(graph,vertex1, vertex2):
	root1 = graph.find(vertex1)
	root2 = graph.find(vertex2)
	if root1 != root2:
		if graph.rank[root1] > graph.rank[root2]:
			graph.parent[root2] = root1
		else:
			graph.parent[root1] = root2
			if graph.rank[root1] == graph.rank[root2]: graph.rank[root2] += 1

def kruskal(graph):
		
	for vertex in graph.vertexList:
		graph.make_set(vertex)
		

	minimum_spanning_tree = set()
	edges = sorted(graph.edgeList)
	for edge in edges:
		vertex1 = edge.vertex1.get_value()
		vertex2 = edge.vertex2.get_value()
		weight = edge.cost
		if graph.find(vertex1) != graph.find(vertex2):
			graph.union(vertex1, vertex2)
			minimum_spanning_tree.add(edge)
	return minimum_spanning_tree
	
def find_edge_of(graph,vertex1,vertex2):
	for edge in graph.edgeList:
		if edge.is_edge_of(vertex1,vertex2):
			return edge	
	return None
		
