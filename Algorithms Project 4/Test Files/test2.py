import Vertex
import Edge

class UndirectedWeightedGraph(object):
	
	def __init__(self):
		
		self.graph = {}
		
	def add_vertex(self,value):
		self.graph[value] = {}
		
	def add_edge(self,src,dest,cost):
		self.graph[src][dest]= cost
		self.graph[dest][src]= cost
		
	def dijkstra_loop(graph,src,dest,visited=[],distances={},predecessors={}):
    
    # ending condition
		if src == dest:
			# We build the shortest path and display it
			path=[]
			pred=dest
			while pred != None:
				path.append(pred)
				pred=predecessors.get(pred,None)
			print('shortest path: '+str(path)+" cost="+str(distances[dest])) 
		else :     
        # if it is the initial  run, initializes the cost
			if not visited: 
				distances[src]=0
        # visit the neighbors
			for neighbor in graph[src] :
				if neighbor not in visited:
					new_distance = distances[src] + graph[src][neighbor]
					if new_distance < distances.get(neighbor,float('inf')):
						distances[neighbor] = new_distance
						predecessors[neighbor] = src
        # mark as visited
			visited.append(src)
        # now that all neighbors have been visited: recurse                         
        # select the non visited node with lowest distance 'x'
        # run Dijskstra with src='x'
			unvisited={}
			for k in graph:
				if k not in visited:
					unvisited[k] = distances.get(k,float('inf'))        
			x=min(unvisited, key=unvisited.get)
			dijkstra_loop(graph,x,dest,visited,distances,predecessors)
	
	def dijkstra(self,initial,destination):
		graph= self.convert_to_dict()
		self.dijkstra_loop(graph,initial,destination)
	
	def dijkstra_tree(self,initial):
		print self.graph
				


	
