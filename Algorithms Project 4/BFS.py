import Vertex
import Edge
#Preforms a Breadth First search from a vertex, using a 
#List of visited Nodes. each node's neighbours that are not 
#visited are added to the queue, and marked as visited. 
#Then a vertex is popped from the queue, added to the 
#list, and if any of its adjacent verticies are not 
#visited, queues them and marks them as visited, 
#so on and so forth until the queue is empty
def BFS(graph, s):
 
	order = []
		# Mark all the vertices as not visited
	visited = dict()
		
	for vertex in graph.vertexList:
		visited[vertex.get_value()]=False
			
		# Create a queue for BFS
	queue = []
 
		# Mark the source node as visited and enqueue it
	queue.append(s)
	visited[s.get_value()] = True
 
	while queue:
			# Dequeue a vertex from queue and add it to order
		s = queue.pop(0)
		order.append(s.get_value())
 
			# Get all adjacent vertices of the dequeued
			# vertex s. If a adjacent has not been visited,
			# then mark it visited and enqueue it
		for i in s.get_neighbours():
			if visited[i.get_value()] == False:
				queue.append(i)
				visited[i.get_value()] = True
					
	return order
