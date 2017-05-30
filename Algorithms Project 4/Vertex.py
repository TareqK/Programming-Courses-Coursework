"""The vertex Class. A vertex is simply a value with a String name that takes a list of strings as neighbours"""


class Vertex(object):
	def __init__(self,value,neighbours = None):
		self.value=value
		
		if neighbours == None:
			neighbours=[]
		self.neighbours=neighbours
		
	def set_value(self,value):
		self.value=value
	
	def get_value(self):
		return self.value
		
	def add_neighbour(self,vertex):
		self.neighbours.append(vertex)
		
	def get_neighbours(self):
		return self.neighbours
		
		
		
	def __cmp__(self,other):
		if self.value > other.value:
			return 1
		if self.value == other.value:
			return 0
		if self.value < other.value:
			return -1	
			
	def __str__(self):
		res = self.value+":"
		for vertex in self.neighbours:
			res+= vertex.get_value()
			res+=" "
		return res
					
	__repr__=__str__
