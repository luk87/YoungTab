#YoungTab


## Summary


YoungTab is a mathematical tool to compute the dimension of irreducible representations of the classical Lie algebras A, B, C, D, described by Young tableaux. It is useful in finding the representation associated to irreducible tensors of classical lie algebras, since tensor with given symmetries could be represented by Young tableaux. It has wide range of application in theoretical physics since group theoretical structure are obiquitus in different contexts, form condensed matter to high energy physics.  



### Installation
YoungTab is a program written in C code thought for linux 64 and the GUI is based on the GTK toolkit. It could be directly downloaded and used by placing the bin file in a folder containing another folder with name glade containing in turn the logo and the glade file. The required libraries are gtk, gdk, cairo, gobject, glib and pthread.


### Usage

The user could select the rank of the algebra from the list menu. On the display there are four different labels, under the column "algebra", for the four classical Lie algebras. The Young tablueax could be drawn on the blackboard, the black drawing area. Any left mouse click adds a cell justifying it automatically to the left. The dimension of the representations described by the Young tableaux appearing on the blackboard, is sketched near the corresponding algebra in the column "Dim". If the tableau does not respect the rules required to be identified with a legitimate Lie algebra irreducible representation (non increasing number of cells in each row from the top to the bottom and non increasing number of cells in each column from the left to the right) the output Dim will say "no". The tableaux could be deleted by a right mouse click on the blackboard.

