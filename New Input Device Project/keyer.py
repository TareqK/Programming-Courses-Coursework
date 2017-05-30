#Tareq Kirresh
#a simple keyer handheld chord keyboard , based on a USB joystick
#2/7/2016
#program keeps looping indefinetly , as this can be considered a sort of "driver"
#!/usr/bin/python

import pygame
import time
import uinput
pygame.init()#initialize pygame window

j = pygame.joystick.Joystick(0)#obtain the joystick
j.init()#initialize the joystick
print "Initialized Joystick : %s" % j.get_name()#get the name of the joystick

device = uinput.Device([
		uinput.KEY_A,
		uinput.KEY_B,
		uinput.KEY_C,
		uinput.KEY_D,
		uinput.KEY_E,
		uinput.KEY_F,
		uinput.KEY_G,
		uinput.KEY_H,
		uinput.KEY_I,
		uinput.KEY_J,
		uinput.KEY_K,
		uinput.KEY_L,
		uinput.KEY_M,
		uinput.KEY_N,
		uinput.KEY_O,
		uinput.KEY_P,
		uinput.KEY_Q,
		uinput.KEY_R,
		uinput.KEY_S,
		uinput.KEY_T,
		uinput.KEY_U,
		uinput.KEY_V,
		uinput.KEY_W,
		uinput.KEY_X,
		uinput.KEY_Y,
		uinput.KEY_Z,
        ])
x=j.get_numbuttons()
while True:
	event = pygame.event.wait()#wait for input
	#pygame.event.pump()#GET EVENTS #not sure i need this 
	
	summ = 0#start the sum at zero
	val=1#start the value at one
    
	for i in range(x):#get input from the buttons
		if  j.get_button(i)==True:#if a button was presssed
			summ +=val#add its value to the sum
		
		val=val*2#increment the value
	if (val<27):
		device.emit_click(device[val-1])
		
	time.sleep(0.05)

  





