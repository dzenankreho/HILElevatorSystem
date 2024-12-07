
# System with N elevators and M floors
Hardware-in-the-loop simulation of a distributed surveillance and control system for a building with N elevators and M floors.

<p align="center">  
<img src="applicationSnapshot.png" width=400/><br>Application snapshot
</p> 
 
This application/project was developed as part of the graduate elective course "Software Engineering in Automatic Control", which is part of the Automatic Control and Electronics Master's degree program offered by the Faculty of Electrical Engineering, University of Sarajevo.

The goal of the project was to create a distributed surveillance and control system for a building with N elevators and M floors. The project implements a hardware-in-the-loop simulation using the STM32 Nucleo-144 development board and Remote Procedure Call (RPC) for integration. Detailed UML diagrams were also required.

A GUI-based application is created on the PC for visualization and interaction with the system (calling and moving elevators). Each action calls a function on the MCU using RPC and displays the results if needed. In this regard, the PC acts as the client, and the MCU serves as the server for RPC. The GUI is created for N = 2 and M = 3, although the rest of the application works regardless of N and M.

The application itself is written in C++. The [Qt framework](https://www.qt.io/product/framework) is used for GUI creation. The [jsonrpc++](https://github.com/badaix/jsonrpcpp) library is used for RPC on both the PC and MCU sides. To communicate with the MCU, the [Serialib](https://github.com/imabot2/serialib) library is utilized on the PC side. The MCU uses [Arm Mbed OS 6](https://os.mbed.com/docs/mbed-os/v6.16/introduction/index.html).

The repository contains the source code and UML Use Case, Class, Sequence, and State Diagrams.

Project done by:
- [Enesa Hrustić](https://github.com/EnesaHrustic)
- [Dženan Kreho](https://github.com/dzenankreho)
