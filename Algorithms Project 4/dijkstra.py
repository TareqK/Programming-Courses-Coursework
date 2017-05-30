# dijkstra_loop's algorithm for shortest paths
# David Eppstein, UC Irvine, 4 April 2002
# Updated and and Optimized, Tareq Kirresh,BZU, 14 April 2017
# Changelog as follows:
# 1)Added convert_to_dict Function, To convert A Weighted Graph object to 
#   a simple dictionary for easier iteration
# 2)Changed name of function dijkstra to dijkstra_loop 
# 3)Created a new function with the name dijkstra, which 
#   Converts a Weighted Graph Object to a dict then send it
#   to dijkstra_loop


# The Function shortestPath was not used at all, since we dont want to 
# find the shortest path between 2 particular nodes, even though it 
# could easily be implemented with another inputbox and button
# in the main.py file of this project

from priodict import priorityDictionary

import Vertex
import Edge

def convert_to_dict(graph):
	G= dict()
	for vertex in graph.vertexList:
		G[vertex.get_value()]= dict()
		for neighbour in vertex.get_neighbours():
			edge = graph.find_edge_of(vertex,neighbour)
			G[vertex.get_value()][neighbour.get_value()] = edge.get_value()
	return G

def dijkstra(graph,start):
	G = convert_to_dict(graph)
	d,p = dijkstra_loop(G,start.get_value())	
	return (d,p)
	
	
def dijkstra_loop(G,start,end=None):


	D = {}	# dictionary of final distances
	P = {}	# dictionary of predecessors
	Q = priorityDictionary()	# estimated distances of non-final vertices
	Q[start] = 0
	
	for v in Q:
		D[v] = Q[v]
		if v == end: break
		
		for w in G[v]:
			vwLength = D[v] + G[v][w]
			if w in D:
				if vwLength < D[w]:
					raise ValueError, "dijkstra_loop: found better path to already-final vertex"
			elif w not in Q or vwLength < Q[w]:
				Q[w] = vwLength
				P[w] = v
	return (D,P)
			
def shortestPath(G,start,end):
	"""
	Find a single shortest path from the given start vertex to the given end vertex.
	The input has the same conventions as dijkstra_loop().
	The output is a list of the vertices in order along the shortest path.
	"""
	
	D,P = dijkstra_loop(G,start,end)
	Path = []
	while 1:
		Path.append(end)
		if end == start: break
		end = P[end]
	Path.reverse()
	return Path
