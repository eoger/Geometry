=== DESCRIPTION ===

Geometry is a text-based application which allows its users to create various geometric figures (circle, rectangle, polyline, line) and aggregates containing figures and other aggregates.


=== HOW TO BUILD Geometry ===

    1/ In the same folder as this README, create a makefile using cmake by entering the following command in your terminal:

cmake -H. -BBuild

This will generate a Makefile for this particular project in the Build directory.


    2/ Build the project using make :

cd Build && make all

This will generate the Geometry binary executable file in the Build directory.


    3/ (OPTIONAL) Functional tests. You can execute the functionnal tests by typing :

make test


=== AVAILAIBLE COMMANDS ===

* Create a circle

C Name X Y Radius

Eg. C c1 1 -5 10

* Create a rectangle

R Name X1 X2 Y1 Y2

Eg. R r1 5 -2 10 23

* Create a line

L Name X1 Y1 X2 Y2

Eg. L l1 1 8 6 -4

* Create a polyline

PL Name X1 Y1 X2 Y2 ... XN YN

Eg. PL pl1 4 9 -5 -4 0 8 -7 4

* Create an aggregate

OA Name Obj1 ... ObjN

Eg. OA oa1 c1 r1 l1

* Delete one or more elements

DELETE Obj1 ... ObjN

Eg. DELETE c1 r1

* Delete all elements

CLEAR

Eg. Well.. CLEAR

* Move an element

MOVE Obj X Y

Eg. MOVE l1 -5 5

* List all elements

LIST

Eg. LIST

* Undo the last user-entered command

UNDO

Eg. UNDO

* Redo the last command

REDO

Eg. REDO

* Save all elements in a file

SAVE filename

Eg. SAVE elts.geo

* Load all elements from a file

LOAD filename

Eg. LOAD elts.geo

