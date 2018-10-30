Game of Life for the Embedded & Real Time Systems Course
Code developed by: Ángel Matilla, Javier Asensio, Álvaro Serra and Marc Pujol

In this directory you will find two implementations of Game of Life:

	Our main implementation is the one named tCell, which uses
	a custom database, you will find the team-work strategy
	in its main.c.

	A second implementation was done using Arrays of Arrays to
	check the difference in performance between this approach
	and the tCell one.

Both of them use TXT files to load the initial configuration with name "structures.txt".
The current "structures.txt" loads the infinite glider initial configuration.

In each directory you will find a folder named structures with different intial configurations,
the three main configurations that we were asked and two random configurations that were used
to make the performance check.
You can load those configurations by replacing them with the current "structures.txt" and renaming it.

To compile the code you can use:
make
make gameoflife

To run it:
./gameoflife


