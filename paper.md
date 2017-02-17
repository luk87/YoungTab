
---
title: 'YoungTab'
tags:
  - Young tableaux
  - tableaux
  - Lie algebra 
  - irreducible representation
  - representation
  - Lie
  - irrep
  - Physics
  - math


authors:
- affiliation: Leibniz Universitaet Hannover
- name: Luca Romano
  orcid: 0000-0001-9033-1345


date: 15 February 2017
bibliography: bibliography.bib
---

# Summary
YoungTab is a mathematical tool to compute the dimension of irreducible representations of the classical Lie algebras A, B, C, D, described by Young tableaux.  In particular for any Young tableau drawn in the drawing area and selected rank it will list the dimension of the irreducible representation associated to it for the four classical Lie algebras.  Due to the correspondence between Young tableaux and irreducible tensors, it is useful in finding the representation associated to tensors carrying indices in any of the Lie algebras mentioned above.  YoungTab has a wide range of application, from pure math to theoretical physics, where group theoretical structures and tensors are ubiquitous. 

## Installation
YoungTab is a program written in C code thought for linux 64 and the GUI is based on the GTK toolkit. It could be directly downloaded and used by placing the bin file in a folder containing another folder with name glade containing in turn the logo and the glade file. The required libraries are gtk, gdk, cairo, gobject, glib and pthread.


## Usage
The user could select the rank of the algebra from the list menu. On the display there are four different labels, under the column "algebra", for the four classical Lie algebras. The Young tableaux could be drawn on the blackboard, the black drawing area. Any left mouse click adds a cell justifying it automatically to the left. The dimension of the representations described by the Young tableaux appearing on the blackboard, is sketched near the corresponding algebra in the column "Dim". If the tableau does not respect the rules required to be identified with a legitimate Lie algebra irreducible representation (non increasing number of cells in each row from the top to the bottom and non increasing number of cells in each column from the left to the right) the output Dim will say "no". The tableaux could be deleted by a right mouse click on the blackboard.




# References
