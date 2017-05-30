# by Timothy Downs And Tareq Kirresh, inputbox written for my map editor

# This program needs a little cleaning up
# It ignores the shift key
# And, for reasons of my own, this program converts "-" to "_"

# A program to get user input, allowing backspace etc
# shown in a box in the middle of the screen
# Called by:
# import inputbox
# answer = inputbox.ask(screen, "Your name")


# This program was Modified in May 2017 By Tareq Kirresh
# to better Suit his needs. The code has been optimized
# for a 600*600 window and Deletes the Box after an 
# input is entered
#

import pygame, pygame.font, pygame.event, pygame.draw, string
from pygame.locals import *



def get_key():
  while 1:
    event = pygame.event.poll()
    if event.type == KEYDOWN:
      return event.key
    else:
      pass

def display_box(screen, message):
  "Print a message in a box in the bottom of the screen"
  fontobject = pygame.font.Font(None,18)
  pygame.draw.rect(screen, (255,255,255),
                   ((screen.get_width() / 2) - 100,
                    552,
                    200,20), 0)
  pygame.draw.rect(screen, (0,0,0),
                   ((screen.get_width() / 2) - 102,
                    550,
                    204,24), 1)
  if len(message) != 0:
      screen.blit(fontobject.render(message, 1, (0,0,0)),
                ((screen.get_width() / 2) - 100, 552 ))
  pygame.display.update()


def ask(screen, question):
  "ask(screen, question) -> answer"
  pygame.font.init()
  current_string = []
  display_box(screen, question + ": " + string.join(current_string,""))
  while 1:
    inkey = get_key()
    if inkey == K_BACKSPACE:
      current_string = current_string[0:-1]
    elif inkey == K_RETURN:
      break
    elif inkey == K_MINUS:
      current_string.append("_")
    elif inkey <= 127:
      current_string.append(chr(inkey))
    display_box(screen, question + ": " + string.join(current_string,""))
  pygame.draw.rect(screen, (255,255,255),
                   ((screen.get_width() / 2) - 100,
                    552,
                    200,20), 0)
  pygame.draw.rect(screen, (255,255,255),
                   ((screen.get_width() / 2) - 102,
                    550,
                    204,24), 1)
  pygame.display.update()  
  return string.join(current_string,"")

def main():
  screen = pygame.display.set_mode((320,240))
  print ask(screen, "Name") + " was entered"

if __name__ == '__main__': main()
