# Strategy Pattern

## Intent
1. Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from the clients that use it.
2. Capture the abstraction in an interface, bury implementation details in derived classes.

## Problem
One of the dominant strategies of object-oriented design is the "open-closed principle".

Encapsulate interface details in a base class, and bury implementation details in derived classes. Clients can then couple themselves to an interface, and not have to experience the upheaval associated with change: no impact when the number of derived classes changes, and no impact when the implementation of a derived class changes.


A generic value of the software community for years has been,
**maximize cohesion and minimize coupling**.

A more popular characterization of this "abstract coupling" principle is "Program to an interface, not an implementation".

## Example
A Strategy defines a set of algorithms that can be used interchangeably. Modes of transportation to an airport is an example of a Strategy. Several options exist such as driving one's own car, taking a taxi, an airport shuttle, a city bus, or a limousine service. For some airports, subways and helicopters are also available as a mode of transportation to the airport. Any of these modes of transportation will get a traveler to the airport, and they can be used interchangeably. The traveler must chose the Strategy based on trade-offs between cost, convenience, and time.
