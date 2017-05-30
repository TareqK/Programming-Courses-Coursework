import Vertex
import Edge
import WeightedGraph
import pygame

# A group of functions that were redundantly added into the main code, so they were turned into functions instead for 
# Clarity

def print_text(window,text,pos):
	myFont = pygame.font.SysFont("Calibri", 20)
	myText = myFont.render(text, 1, (0,0,0))
	window.blit(myText,pos)
	
	
def add_to_vertex_list(window,GraphicalVertexList,VertexList,counter,pos,Graph):
	GraphicalVertexList.append([pygame.draw.circle(window, (255, 0, 0),pos, 15),counter])
	VertexList.append(Vertex.Vertex(counter))
	print_text(window,counter,pos)
	counter = chr(ord(counter)+1)
	add_to_Graph(Graph,VertexList[-1])
	
def add_to_Graph(Graph,vertex):
	Graph.add_vertex(vertex)

def add_to_edge_list(window,GraphicalPathList,GraphicalVertexList,VertexList,PathList,counter1,counter2,directional,start,end,cost,Graph):
	
	
									#Node 1                         Node 2                      Directional?
	GraphicalPathList.append([GraphicalVertexList[counter1],GraphicalVertexList[counter2],     directional,
				#LineObject                                           Weight
	pygame.draw.line(window,(0,0,0),start.center,end.center)     ,cost])
		
	PathList.append(Edge.Edge(VertexList[counter1],VertexList[counter2],int(cost)))
	#VertexList[counter1].add_neighbour(VertexList[counter2])
	
	Graph.add_edge(VertexList[counter1],VertexList[counter2],int(cost))
	
		
	
		
	if(directional == False):
		
		GraphicalPathList.append([GraphicalVertexList[counter2],GraphicalVertexList[counter1],     directional,
	
		pygame.draw.line(window,(0,0,0),end.center,start.center)     ,cost])
		
		
		PathList.append(Edge.Edge(VertexList[counter2],VertexList[counter1],int(cost)))
		#VertexList[counter2].add_neighbour(VertexList[counter1])
		Graph.add_edge(VertexList[counter2],VertexList[counter1],int(cost))
		
	if(directional == True):
		pygame.draw.circle(window,(255,255,0),GraphicalPathList[-1][3].center,7)
		Graph.directed == True
		
	print_text(window,cost,GraphicalPathList[-1][3].center)
		
	pygame.draw.circle(window, (255,0, 0),end.center, 15)#color the end node red again
	print_text(window,GraphicalVertexList[counter2][1],((end.x+7),(end.y+7)))
		
	pygame.draw.circle(window, (255, 0, 0),start.center, 15)#color the start node red again 
	print_text(window,GraphicalVertexList[counter1][1],((start.x+7),(start.y+7)))

def add_neighbour(Graph,vertex1,vertex2,cost):
	Graph.add_edge(vertex1,vertex2,cost)
"""	
#file Read/Write Functions. They were not implemented due to 
#time constraints.	
def read_from_file(self,filename):
	File = open(filename, 'r')
		
def write_to_file(Graph,filename,GraphicalPathList,GraphicalVertexList):
	File = open(filename, 'w')
	File.write(Graph.vertexList)
	File.write("-")
	File.write(Graph.edgeList)
	File.write("-")
	for Vertex in GraphicalVertexList:
		File.write(Vertex[0]+","+Vertex[1])
	File.Write("-")
	for Path in GraphicalPathList:	
		File.write(Path[3])
	File.Write("-")
	File.close()
"""
