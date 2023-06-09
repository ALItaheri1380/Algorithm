import turtle
from random import randint
from time import sleep

stage = [[8,0,0] , [0,5,0] , [0,9,0]]
color_palette = ['#003f5c', '#2f4b7c', '#665191', '#a05195', '#d45087', '#f95d6a', '#ff7c43', '#ffa600']

SUM = 15

myPen = turtle.Turtle()
myPen.tracer(0)
myPen.speed(0)


def drawGrid(stage):
    intDim=100

    for row in range(0,4):
        myPen.penup()
        myPen.goto(topLeft_x,topLeft_y-row*intDim)
        myPen.pendown()
        myPen.goto(topLeft_x+3*intDim,topLeft_y-row*intDim)
    for col in range(0,4):
        myPen.penup()
        myPen.goto(topLeft_x+col*intDim,topLeft_y)
        myPen.pendown()
        myPen.goto(topLeft_x+col*intDim,topLeft_y-3*intDim)

    for row in range (0,3):
        for col in range (0,3):
            if stage[row][col]!=0:
                text(stage[row][col],topLeft_x+col*intDim+25,topLeft_y-row*intDim-intDim+25,50)


def text(message,x,y,size):
    FONT = ('Arial', size, 'normal')
    myPen.penup()
    myPen.goto(x,y)          
    myPen.write(message, align="left", font=FONT)

def checkGrid(stage):
    global SUM
    for row in range(0,3):
        for col in range(0,3):
            if stage[row][col]==0:
                return False
            
    for row in range(0,3):
        if (stage[row][0]+stage[row][1]+stage[row][2])!=SUM:
            return False
        
    for col in range(0,3):
        if (stage[0][col]+stage[1][col]+stage[2][col])!=SUM:
            return False
        
    if (stage[0][0]+stage[1][1]+stage[2][2])!=SUM:
        return False
    
    if (stage[0][2]+stage[1][1]+stage[2][0])!=SUM:
        return False

    return True 

def solveGrid(stage):

    for i in range(0,9):

        row=i//3
        col=i%3

        if stage[row][col]==0:
            for value in range (1,10):

                if not(value in stage[0] or value in stage[1] or value in stage[2]):
                    stage[row][col]=value

                    myPen.clear()
                    drawGrid(stage) 
                    myPen.getscreen().update()   

                    if checkGrid(stage):
                        print("stage Complete and Checked")
                        return True
            
                    else:
                        if solveGrid(stage):
                            return True
            break
    print("chenge...")
    stage[row][col]=0  


topLeft_x = -150
topLeft_y = 170

myPen.getscreen().bgcolor("#f2f2f2")

drawGrid(stage) 
myPen.getscreen().update()
sleep(1)

solved = solveGrid(stage)
if solved:
    print("Magic Square Solved :)")
    text("Magic Square Solved", -130, -180, 20)
else:  
    print("Cannot Solve Magic Square :(")
    text("Cannot Solve Magic Square", -150, -180, 20)

myPen.getscreen().update()