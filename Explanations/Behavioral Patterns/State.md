# State Design Pattern

### Intent
1. Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.
2. An object-oriented state machine
3. wrapper + polymorphic wrappee + collaboration


### Problem
A monolithic object's behavior is a function of its state, and it must change its behavior at run-time depending on that state. Or, an application is characterized by large and numerous case statements that vector flow of control based on the state of the application.

### Discussion
The State pattern is a solution to the problem of how to make behavior depend on state.

1. Define a "context" class to present a single interface to the outside world.
2. Define a State abstract base class.
3. Represent the different "states" of the state machine as derived classes of the State base class.
4. Define state-specific behavior in the appropriate State derived classes.
5. Maintain a pointer to the current "state" in the "context" class.
6. To change the state of the state machine, change the current "state" pointer.

### Example
The State pattern allows an object to change its behavior when its internal state changes. This pattern can be observed in a vending machine. Vending machines have states based on the inventory, amount of currency deposited, the ability to make change, the item selected, etc. When currency is deposited and a selection is made, a vending machine will either deliver a product and no change, deliver a product and change, deliver no product due to insufficient currency on deposit, or deliver no product due to inventory depletion.
