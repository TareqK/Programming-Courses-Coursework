"""The edge class consists of 2 verticies and a weight"""
import Vertex

class Edge(object):			#from       to
	def __init__(self,vertex1,vertex2,cost = None):
		self.vertex1=vertex1
		self.vertex2=vertex2
		if cost == None:
			cost = 0
		self.cost=cost
	
	def __str__(self):
		res = (self.vertex1.get_value() + "," + self.vertex2.get_value()+","+str(self.cost))
		return res		
	def __cmp__(self,other):
		if self.cost > other.cost:
			return 1
		if self.cost == other.cost:
			return 0
		if self.cost < other.cost:
			return -1
	
	def is_edge_of(self,vertex1,vertex2):
		if self.vertex1 == vertex1:
			if self.vertex2 == vertex2:
				return True
		else:
			return False
	def get_value(self):
		return self.cost
			
	__repr__=__str__
