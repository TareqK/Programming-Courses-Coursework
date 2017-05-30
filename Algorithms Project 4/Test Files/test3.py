
		
		
	def dijkstra_loop(self,src,dest,visited=[],distances={},predecessors={}):
    
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
			for neighbor in self.graph[src].keys() :
				if neighbor not in visited:
					new_distance = distances[src] + self.graph[src][neighbor]
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
			dijkstra_loop(x,dest,visited,distances,predecessors)
	
	def dijkstra(self,initial,destination):
		graph= self.convert_to_dict()
		self.dijkstra_loop(graph,initial.get_value(),destination.get_value())
	
	def dijkstra_tree(self,initial):
		self.graph = self.convert_to_dict()
		for vertex in self.vertexList:
			if vertex.get_value() != initial.get_value():
				self.dijkstra_loop(initial.get_value(),vertex.get_value())
