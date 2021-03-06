# Pendulum

## Table of Contents
* [Introduction](#introduction)
* [Features](#features)
* [Setup and Execution](#setup-and-execution)


## Introduction
This program emulates a swinging 3D pendulum. The pendulum is enclosed inside of a 3D space (in this instance the space has a nightclub asthetic and the pendulum is a swinging disco ball). The project was completed as the semester long project portion of Visual Graphics II class in Spring 2019. 


## Features
This program was built using C++ and OpenGL. 

The swinging motion used physics principles along with 3D transformations of rotation, translation and scaling.

The enclosed space is a room with 4 walls, a ceiling and floor. The walls and the pendulum were given a realistic feel using texturing capability in OpenGL. There was collision detection code implemented so that the camera position was able to freely move around the enclosed space but would stop once it hit a wall or tried to go past the ceiling or floor. The room also utilized lighting capabilities in OpenGL including a spotlight.

The program also features a 2D graph that can be toggled on and off that tracks the motion of the pendulum. 


## Setup and Execution
To compile this program in a Unix/Linux environment, type `make` in the console. Then type `pend` in the console to run it. Note that the system must have OpenGL libraries. The user can then use the keyboard to make directional changes to the camera position (W,A,S,D for moving up/down/left/right and directional arrows for rotations). To toggle the graph press "g". 



