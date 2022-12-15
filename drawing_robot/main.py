#!/usr/bin/env pybricks-micropython
from pybricks.hubs import EV3Brick
from pybricks.ev3devices import (Motor, TouchSensor, ColorSensor,
                                 InfraredSensor, UltrasonicSensor, GyroSensor)
from pybricks.parameters import Port, Stop, Direction, Button, Color
from pybricks.tools import wait, StopWatch, DataLog
from pybricks.robotics import DriveBase
from pybricks.media.ev3dev import SoundFile, ImageFile
import math


# This program requires LEGO EV3 MicroPython v2.0 or higher.
# Click "Open user guide" on the EV3 extension tab for more information.


# Create your objects here.
ev3 = EV3Brick()


# motors initialization
BASE_MOTOR = Motor(Port.C, Direction.CLOCKWISE)
END_MOTOR = Motor(Port.A, Direction.CLOCKWISE)
PEN_MOTOR = Motor(Port.B)

# constants
l1 = 0.15
l2 = 0.126

def pen_up():
    PEN_MOTOR.run_until_stalled(10, Stop.COAST, 70)

def pen_down():
    PEN_MOTOR.run_until_stalled(-10, Stop.COAST, 70)

# returns angle of the two joints to reach to the desired location by computing the inverse kinematics
def get_angles_to_reach(point):

    x, y = point

    if (x < (l1-l2)) or (x > (l1+l2)) or (y < (l1 - l2)) or (y > (l1+l2)):
        print("Cannot be reached")
        return


    gamma = math.atan( y / x)
    
    alpha_val = (l1 ** 2 + x ** 2 + y ** 2 - l2 ** 2) / (2 * l1 * math.sqrt(x ** 2 + y ** 2))
    if (alpha_val > 1):
        alpha_val = 0.99
    alpha = math.acos(alpha_val)

    theta1 = gamma - alpha

    theta2_val = (x ** 2 + y ** 2 - l1 ** 2 - l2 ** 2) / (2 * l1 * l2)
    if (theta2_val > 1):
        theta2_val = 0.99
    theta2 = math.acos(theta2_val)
    
    if(math.degrees(theta1) == None or math.degrees(theta2) == None):
        print("Point: ", point)

    return math.degrees(theta1), math.degrees(theta2) # convert theta1 and theta2 to degrees

def generate_intermediary_points(pos1, pos2, point_size):
    dist = math.sqrt((pos2[1] - pos1[1]) ** 2 + (pos2[0] - pos1[0]) ** 2)
    number_of_points = int(dist / point_size)
    all_points = list()

    for i in range(number_of_points):
        new_x = pos1[0] + ((i * point_size) / dist) * (pos2[0] - pos1[0])
        new_y = pos1[1] + ((i * point_size) / dist) * (pos2[1] - pos1[1])

        all_points.append((new_x, new_y))
    
    return all_points

def generate_path(edge_points, point_size):
    path = list()

    for i in range(len(edge_points) - 1):
        path.extend(generate_intermediary_points(edge_points[i], edge_points[i+1], point_size))
    
    return path

def draw(path):
    pen_up()
    for i, point in enumerate(path):
        print("point: ", point)
        
        theta1, theta2 = get_angles_to_reach(point)
        print("theta1: %f, theta2: %f\n" % (theta1, theta2))
        print()
        END_MOTOR.run_target(10,theta2,Stop.HOLD,True)
        BASE_MOTOR.run_target(10,theta1,Stop.HOLD,True)

        if i == 0:
            pen_down()
            ev3.speaker.say("Starting to draw now")
    pen_up()

letter_A = [(0.05,0.03),(0.1,0.12),(0.125,0.075),(0.075,0.075),(0.125,0.075),(0.15,0.03)]
test_shape = [(0.05,0.03),(0.16,0.03),(0.07,0.12),(0.17,0.13),(0.05,0.03)]
letter_P = [(0.05,0.03),(0.05,0.15),(0.11,0.15),(0.12,0.13),(0.12,0.12),(0.11,0.1),(0.05,0.1)]

test_points = test_shape

full_path = generate_path(test_points, 0.005)
# print(full_path)
draw(full_path)
# print([get_angles_to_reach(point) for point in full_path])
# print(full_path)


# Write your program here.
# pen_up()
ev3.speaker.beep()
