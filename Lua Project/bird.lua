return{

	x=math.random(800)
	y=0
    image =love.graphics.newImage("PELICAN.png")
    physics = love.physics.newBody(world,x,y, "dynamic")
    physics:setMass(10)

}
