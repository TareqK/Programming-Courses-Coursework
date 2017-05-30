
bird={}
image =love.graphics.newImage("rocket.png")
score=0

function love.load()

  
   love.graphics.setBackgroundColor(0,186, 255)
    persisting=0
   num=50
	num2=350
   gravity=-200
   text2="stuff"
   world = love.physics.newWorld(0, gravity, true)  --Gravity is being set to 0 in the x direction and 200 in the y direction.
   world:setCallbacks(beginContact, endContact, preSolve, postSolve)
   timer=0.4
   bob = {img=love.graphics.newImage("suicidebomb1.png"),num2=50,num=350,phys=love.physics.newBody(world,num,num2,"dynamic"),shape=love.physics.newRectangleShape(num2,num-300,75,100,0)}
   bob.f=love.physics.newFixture(bob.phys,bob.shape)
   bob.phys:setMass(0)
   speed=0
end


function love.update(dt)
world:update(dt)

score=score+speed*dt*100
timer = timer - (1 * dt)
 if timer<=0 then
newbird={img=image ,phys=love.physics.newBody(world,math.random(800),600,"dynamic"),shape=love.physics.newRectangleShape(50,50)}
newbird.f=love.physics.newFixture(newbird.phys,newbird.shape)
table.insert(bird,newbird)
 timer=0.4-speed*dt
 if(timer<0.1) then
 timer=0.1
 end
 end
 
   if love.keyboard.isDown("w") then
      bob.num2 = bob.num2 - 300 * dt -- this would increment num by 100 per second
      end
   if love.keyboard.isDown("s") then
       bob.num2 = bob.num2 + 300 * dt -- this would increment num by 100 per second
       end
         if love.keyboard.isDown("a") then
      bob.num = bob.num - 300* dt -- this would increment num by 100 per second
      end
   if love.keyboard.isDown("d") then
       bob.num = bob.num + 300* dt -- this would increment num by 100 per second
       end
       
       bob.phys:setX(num)
       bob.phys:setY(num2-300)
       
    
    

     speed=speed+0.01
       
end
function love.draw()

 love.graphics.draw(bob.img, bob.num ,bob.num2)
 love.graphics.polygon("line", bob.phys:getWorldPoints(bob.phys:getPoints()))
 for i, b in ipairs(bird) do
  love.graphics.draw(b.img, b.phys:getX(),b.phys:getY())
end
text=tostring(score)
score=math.floor(score)

    love.graphics.print(score, 10, 10)
	love.graphics.print(text2,10,100)
end

function beginContact(a, b, coll)
    x,y = coll:getNormal()
    text2 = text2.."\n".."bob".." colliding with ".."rocket".." with a vector normal of: "..x..", "..y
end

function endContact(a, b, coll)
    persisting = 0
    text2 = text2.."\n".."bob".." uncolliding with ".."rocket"
end
 
function preSolve(a, b, coll)
    if persisting == 0 then    -- only say when they first start touching
        text2 = text2.."\n".."bob".." touching ".."rocket"
    elseif persisting < 20 then    -- then just start counting
        text2 = text2.." "..persisting
    end
    persisting = persisting + 1    -- keep track of how many updates they've been touching for
end
 
function postSolve(a, b, coll, normalimpulse, tangentimpulse)
end
