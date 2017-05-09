
# YoungTab v1.0.1

## Summary
YoungTab is a mathematical tool to compute the dimension of irreducible representations of the classical Lie algebras A, B, C, D, described by Young tableaux. In particular for any Young tableau drawn in the drawing area and selected rank it will list the dimension of the irreducible representation associated with it for the four classical Lie algebras. Due to the correspondence between Young tableaux and irreducible tensors, it is useful in finding the representation associated with tensors carrying indices in any of the Lie algebras mentioned above. Although it is trivial to compute the dimension of irreps for the A-type algebra it is not completely trivial to impose irreducible conditions on tensors when one is dealing with the other classical Lie algebras. In these cases with YoungTab one could immediately compute the dimension of the representation codified in the tensor since it is trivial to translate tensorial indices in Young tableaux. YoungTab has a wide range of application, from pure math to theoretical physics, where group theoretical structures and tensors are ubiquitous.

## Installation
YoungTab is a program written in C code thought for linux 64 and the GUI is based on the GTK toolkit. It could be directly downloaded and used by placing the bin file in a folder containing another folder with name glade containing in turn the logo and the glade file. The required libraries are gtk, gdk, cairo, gobject, glib and pthread.


## Usage
The user could select the rank of the algebra from the list menu. On the display there are four different labels, under the column "algebra", for the four classical Lie algebras. The Young tableaux could be drawn on the blackboard, the black drawing area. Any left mouse click adds a cell justifying it automatically to the left. The dimension of the representations described by the Young tableaux appearing on the blackboard, is sketched near the corresponding algebra in the column "Dim". If the tableau does not respect the rules required to be identified with a legitimate Lie algebra irreducible representation (non increasing number of cells in each row from the top to the bottom and non increasing number of cells in each column from the left to the right) the output Dim will say "no". If the tableux exceeds the computational power it says "over". The tableaux could be deleted by a right mouse click on the blackboard.

## Example
As an example we can try to compute the independent components of the tensor T<sub>MN,P</sub> where MN are antisymmetric indices and are symmetrized with respect to P and all the indices belong to a rank 4 algebra. This tensor is represented by a Young tableaux of type [2,1] namely with two cells in the first row and one cell in the second row. Depending on the type of algebra the indices belong, different irreducibility conditions should be imposed resulting in a different number of indpendent components. Drawing the table it is immediate to get the result for A<sub>4</sub> (SL(5)), B<sub>4</sub> (SO(9)), C<sub>4</sub> (Sp(8)) and D<sub>4</sub> (SO(8)).

![YoungTab example](https://github.com/luk87/YoungTab/blob/master/YTimage.png) 

### Test

Taking the Young tableuax [2,1] its dimension for the rank n classical Lie algebras should give the numerical value for the well known formulae

* A<sub>n</sub> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    n(n+2)(n+1)/3
* B<sub>n</sub> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    (2n+3)(4n<sup>2</sup>-1)/3
* C<sub>n</sub> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    8n(n<sup>2</sup>-1)/3
* D<sub>n</sub> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    8n(n<sup>2</sup>-1)/3.

## Contributing

Any [comment](https://github.com/luk87/YoungTab/issues) or [contribution](https://github.com/luk87/YoungTab/pulls) is welcome. Please use the [issue page](https://github.com/luk87/YoungTab/issues) to report bugs.
