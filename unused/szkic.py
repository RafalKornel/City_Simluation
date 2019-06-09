#!/usr/bin/python3.7

from matplotlib import pylab as pl
import numpy as np
import random
from math import cos, sin, pi


population = 1000
time = 10
threshold = 0


def dist(c1, c2):
    return ( (c1.x - c2.x)**2 + (c1.y - c2.y)**2 )**0.5


class citizen():
    def __init__(self):
        self.x = random.random() * 25
        self.y = random.random() * 25
        self.club = random.randint(0, 1)

    def check(self, threshold):
        good_count = 0
        bad_count = 0
        for citizen in citizens:
            d = dist(self, citizen)
            if citizen.club != self.club and d < 1:
                bad_count += 1
            if citizen.club == self.club and d < 1:
                good_count += 1

        c_count = good_count - bad_count
        if c_count <= threshold:
            self.move()

    def move(self):
        fi = random.random() * 2*pi
        #print(fi)
        #print(f"{c.x} | {c.y}")
        self.x += cos(fi)
        self.y += sin(fi)

        #print(f"{c.x} | {c.y}")


citizens = [ citizen() for _ in range(5000) ]

for epoch in range(time):
    x_0, y_0 = [], []
    x_1, y_1 = [], []

    print(epoch)

    for c in citizens:
        if c.club == 1:
            x_1.append(c.x)
            y_1.append(c.y)
        if c.club == 0:
            x_0.append(c.x)
            y_0.append(c.y)

        c.check(threshold)

pl.plot(x_0, y_0, 'r.')
pl.plot(x_1, y_1, 'g.')
pl.show()
