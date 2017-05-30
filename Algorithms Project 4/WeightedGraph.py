import Vertex
import Edge
import dijkstra
import kruskal
import topsort
import BFS
class WeightedGraph(object):
	
	def __init__(self,vertexList=None,edgeList=None,directed = None):
		if vertexList == None:
			vertexList=[]
		if edgeList == None:
			edgeList = []
		if directed == None:
			directed = False
		self.vertexList=vertexList
		self.edgeList= edgeList
		self.directed=directed
		self.parent = dict()
		self.rank = dict()
		self.dist = dict()
		self.pred = dict()
		self.visited = dict()
		self.heap_map = dict()
		self.graph = dict()
		
		
	def __generate_edges(self):
		for vertex in self.vertexList:
			for neighbour in vertex.neighbours:
				add_edge(vertex,neighbour,0)
	
	def add_vertex(self,vertex):
		self.vertexList.append(vertex)
		
	def add_edge(self,vertex1,vertex2,cost = None):
		if cost == None:
			cost = 0
		if vertex1 in self.vertexList and vertex2 in self.vertexList:
			self.edgeList.append(Edge.Edge(vertex1,vertex2,cost))
			vertex1.add_neighbour(vertex2)
			

	def extract_min(self):
			vertex = get_vertex_of(min(self.heap_map, key=self.heap_map.get))
			del self.heap_map[vertex.get_value()]
			return vertex
	
				
				
	def get_vertex_of(self,vertex):
		for v in self.vertexList:
			if vertex == v.get_value():
				return v
		return None
	
	def dijkstra(self,vertex):
		dijkstra.dijkstra(self,vertex)
	
	def kruskal(self):
		kruskal.kruskal(self)
		
	def topsort(self):
		topsort.dfs_topsort(self)
		
	def BFS(self,vertex):
		BFS.BFS(self,vertex)
		
	def find_edge_of(self,vertex1,vertex2):
		for edge in self.edgeList:
			if edge.is_edge_of(vertex1,vertex2):
				return edge	
		return None
		

	def __str__(self):
		res = "vertexs: "
		for k in self.vertexList:
			res += str(k)+"\n"
		res += "\nedges: "
		for edge in self.edgeList:
			res += str(edge) + "\n "
		return res
	
			
		
	
