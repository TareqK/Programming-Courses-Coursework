
#Tareq Kirresh
#1142828
#A GUI program that enables us to create graphs.
#The program allows us to create Verticies  and Set
#the relationships between them(Directed , Undirected , Weight),
#allows us to save to and load from a file,
#and calculates various graph(Data structure) Algorithms, and 
#outputs their results

#In The Name Of Allah , Most Merciful is He.



import Vertex
import Edge
import pygame
import random
import inputbox as inputbox
import Buttons as Buttons
import numpy
import topsort
import kruskal
import BFS
import dijkstra
import WeightedGraph
import MyFuncs as Func
pygame.init()
pygame.display.set_caption("Graphing Tool")

Graph = WeightedGraph.WeightedGraph()	
		
#variables
window = pygame.display.set_mode((600, 600))
window.fill([255,255,255])
running = True
mode = [True,False,False,False]#the current selected tools

ButtonNode = Buttons.Button() #the Button for the Node tool

ButtonUndirectedPath = Buttons.Button()# the Button for the Undirected Path tool

ButtonWeight = Buttons.Button() # the button for the Weight tool

ButtonDirectedPath = Buttons.Button() # the button for the directed path tool

ButtonRun = Buttons.Button()

ButtonSave = Buttons.Button()#save button   

ButtonLoad = Buttons.Button()#load button

GraphicalVertexList= ([])#The List of Nodes in the GUI. This is different to the List of verticies , which is computed from it

GraphicalPathList = ([])

PathList=([])#The list of paths

VertexList=([])# the list of verticies in the Graph. It contains the 2 nodes , if the relation is directed , the Line object between them,
#and the weight of the relation

Graph = WeightedGraph.WeightedGraph()

counter = '1'

# two counters to make our lives easier
counter1=0;
counter2=0;

start = pygame.Rect(0,0,0,0)#The Current Object on the Screen Selected. 


#Main Loop
while running:
	
	#Seperating the drawing area from the tool area
	pygame.draw.line(window,(0,0,0),(50,0), (50,550))
	pygame.draw.line(window,(0,0,0),(50,550),(600,550)) 
	
	#Drawin the Buttons
	ButtonNode.create_button(window, (255,255,255), 0, 100, 49,    50,    0,        "N", (255,255,255))
	ButtonUndirectedPath.create_button(window, (255,255,255), 0, 160, 49,    50,    0,"U", (255,255,255))
	ButtonDirectedPath.create_button(window, (255,255,255), 0, 220, 49,    50,    0,"D", (255,255,255))
	ButtonRun.create_button(window, (255,255,255), 0, 280, 49,    50,    0, "R", (255,255,255))
	#Processing the events in the window
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			running = False
		if event.type == pygame.MOUSEBUTTONDOWN:#If a mouse button was clicked
			
			pos = pygame.mouse.get_pos()#get the position of the cursor
			
			if(pos[1]<535 and pos[0]>65):#if we are in the drawing area
				
				if(mode[0]==True):#if the node tool is selected
					#create a node and add it to the list of nodes
					Func.add_to_vertex_list(window,GraphicalVertexList,VertexList,counter,pos,Graph)
					counter = chr(ord(counter)+1)
				if(mode[1]==True):#if the undirected Tool is selcted
					if(start.centerx==0): #if no node is currently selected 
						
						#go through the nodes and see if our click has selcted one
						for node in GraphicalVertexList:

							if node[0].collidepoint(pos):
								start=node[0]
								pygame.draw.circle(window, (0, 255, 0),node[0].center, 15)#color it green )
								break
							counter1=counter1+1
					else:#if a node is selected 
						#go through the other nodes and find out if we clicked another one
						for node in GraphicalVertexList:
							if node[0].collidepoint(pos):
								answer = inputbox.ask(window,"Enter Weight")
								if node[0]!=start:
									Func.add_to_edge_list(window,GraphicalPathList,GraphicalVertexList,VertexList,PathList,counter1,counter2,False,start,node[0],answer,Graph)
									break
							counter2=counter2+1		
						
						
						start=pygame.Rect(0,0,0,0)
						counter1=0
						counter2=0
	 
				
				
				if(mode[2]==True):#if the directed tool is selected
					if(start.centerx==0): #if no node is currently selected 
						
						#go through the nodes and see if our click has selcted one
						for node in GraphicalVertexList:

							if node[0].collidepoint(pos):
								start=node[0]
								pygame.draw.circle(window, (0, 255, 0),node[0].center, 15)#color it green 
								break
							counter1=counter1+1
					else:#if a node is selected 
						#go through the other nodes and find out if we clicked another one
						for node in GraphicalVertexList:
							if node[0].collidepoint(pos):
								answer = inputbox.ask(window,"Enter Weight")
								if node[0]!=start:
									Func.add_to_edge_list(window,GraphicalPathList,GraphicalVertexList,VertexList,PathList,counter1,counter2,True,start,node[0],answer,Graph)
									break
							counter2=counter2+1		
						start=pygame.Rect(0,0,0,0)
						counter1=0
						counter2=0
						
							
			else:#if we are not in the drawing area , we are in the toolbar and Bottom Bar area
				
				
				
				#so we check if a button has been pressed and Change the Tool we have selected accordingly
					if ButtonNode.pressed(pos):
						print "Node tool Selected"
						mode=[True,False,False,False]

						
					if ButtonUndirectedPath.pressed(pos):
						print "Undirected Path Tool Selected"
						mode=[False,True,False,False]
						
					if ButtonDirectedPath.pressed(pos):
						print "Directed Path Tool Selected"
						mode=[False,False,True,False]
						
						
					if ButtonRun.pressed(pos):
						
						print("Minimum Spanning Tree Is:") 
						
						print(kruskal.kruskal(Graph))
						
						print("Topological Sort")
						
						print(topsort.dfs_topsort(Graph))
						
						print("Breadth First Search")
						
						answer = inputbox.ask(window,"Enter Node for BFS")
						answer = ord(answer)-ord('1')
						print(BFS.BFS(Graph,Graph.vertexList[answer]))
						
						print("Dijkstra Tree")
						
						answer = inputbox.ask(window,"Enter Node for Dijkstra Tree")
						answer = ord(answer)-ord('1')
						d,p = dijkstra.dijkstra(Graph,Graph.vertexList[answer])
						
						print("Distances:")
						print d
						print("Parents:")
						print p
						
						
						
					
						
					
	pygame.display.update() #Refreshes the Display
