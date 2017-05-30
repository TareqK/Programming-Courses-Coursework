def print_text(text,pos):
	myFont = pygame.font.SysFont("Calibri", 20)
	myText = myFont.render(text, 1, (0,0,0))
	window.blit(myText,pos)
	
def add_to_graphical_edge_list():
	
def add_to_graphical_vertex_list(GraphicalVertexList,VertexList,pos):
	GraphicalVertexList.append([pygame.draw.circle(window, (255, 0, 0),pos, 15),counter])
	VertexList.append(Vertex.Vertex(counter))
	print_text(counter,pos)
	counter = chr(ord(counter)+1)
	add_to_vertex_list(VertexList[-1])
	
def add_to_vertex_list(vertex)
	Graph.add_vertex(vertex)

def add_to_edge_list(GraphicalPathList,GraphicalVertexList,counter1,counter2,directional,start,end,cost):
	
	
									#Node 1                         Node 2                      Directional?
		GraphicalPathList.append([GraphicalVertexList[counter1],GraphicalVertexList[counter2],     directional,
				#LineObject                                           Weight
		pygame.draw.line(window,(0,0,0),start.center,end.center)     ,cost])
		
		PathList.append(Edge.Edge(VertexList[counter1],VertexList[counter2],answer))
		VertexList[counter1].add_neighbour(VertexList[counter2])
		print_text(GraphicalVertexList[counter2][1],GraphicalVertexList[counter2][0])
		pygame.draw.circle(window, (255,0, 0),end.center, 15)#color the end node red again
		
	if(directional == False):
		GraphicalPathList.append([GraphicalVertexList[counter2],GraphicalVertexList[counter1],     directional,
	
		pygame.draw.line(window,(0,0,0),end.center,start.center)     ,cost])
		
		
		PathList.append(Edge.Edge(VertexList[counter2],VertexList[counter1],cost))
		VertexList[counter2].add_neighbour(VertexList[counter1])
		print_text(GraphicalVertexList[counter1][1],GraphicalVertexList[counter1][0])

def add_neigbour():
	return
