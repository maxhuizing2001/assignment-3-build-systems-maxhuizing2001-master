[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8752821&assignment_repo_type=AssignmentRepo)
# Lift Simulation project

This program simulates a lift. There are two simulation classes `buttons` and `lift` there are responsible for physical behavior of a lift and a button interface. The functioning of a lift is governed by a *polymorphic state machine*. Every state in it is a class that inherits from `lift_state`. States are switched by swapping pointers.

Read the [assignment description here](ASSIGNMENT.md)