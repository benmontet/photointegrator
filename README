This code was written by Ben Montet and Josh Carter (see citation requirements below) and
the public release is maintained by Ben Montet. Any questions should be raised as issues 
on the GitHub repository (https://github.com/benmontet/photointegrator).

Contents
--------

-License
-Credit
-Overview
-Example use of functions
-photodynam
	-Installing photodynam
	-Documenation
	-<input_file>
	-<report_file>
	-Example input file
	-Example report file
	-Running the example

License
-------


The MIT License (MIT)

Copyright (c) 2013-5 Benjamin Montet, Joshua Carter

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


Credit
------

Please cite

Science 4 February 2011: Vol. 331 no. 6017 pp. 562-565 DOI:10.1126/science.1201274

MNRAS (2012) 420 (2): 1630-1635. doi: 10.1111/j.1365-2966.2011.20151.x

Montet et al. (in prep)

when using this code towards a publication.

Overview
--------

The code included in this package facilitates so-called "photometric-dynamical" 
modeling. This model is quite simple and this is reflected in the code base. An 
N-body code provides coordinates and the photometric code produces light curves 
based on coordinates.

Currently, the code integrates an arbitrary number of bodies, returning orbital 
elements and (optionally) a predicted light curve. The code includes the effects 
of general relativity and finite light speed effects. It also includes the 
acceleration on each body in the system caused by the quadrupole moments of each 
other body in the system, which includes a spin distortion term and a tidal 
distortion term.

**Limitations** The code does NOT include the acceleration produced by tidal 
damping. It also assumes all bodies are PERFECTLY ALIGNED, assuming the 
spin-orbit misalignment is zero for each body. This is currently under active 
development.

The code also, while allowing the effects of tidal distortion, creates light 
curves based on spherical star models. All tidal effects are only included in 
the integration and calculation of orbital elements, not in the light curve 
generation. This is generally a reasonable assumption, as the tidal effects 
in the light curve are at present unobservable. This is not currently under 
active development.

The code also does not include the potential effects of starspots.


The source code (in the directory source/) should be all one needs to produce 
forward model light curves. Briefly:

A. Pal's code to compute overlap integrals:
	elliptic.c
	elliptic.h
	icirc.c
	icirc.h
	mttr.c
	scpolyint.c
	scpolyint.h

This code forms the base of the photometric code.  When using that code alone or when using the full "photodynam" code please cite him appropriately:

	MNRAS (2012) 420 (2): 1630-1635. doi: 10.1111/j.1365-2966.2011.20151.x

n_body.cpp, n_body.h:
	This code performs the N-body integration with a Burlisch-Stoer integration scheme.  Refer to the header for the description of the simple function "evolve." Alternatively, use the NBodyState object to access the integrator.

n_body_state.cpp, n_body_state.h:
	Defines a class (containing public member functions and constructors) that retains a N-body "state" which is most simply the ICs and masses at some time.  You may operate on this object in a number of ways including N-body integration which is accomplished through the overloaded operator ().

n_body_lc.cpp, n_body.h:
	Contains code (relying on A. Pal's code, see above) to produce light curves (integrated light) for any number of spherical, quadratically limb-darkened bodies of arbitrary radius and flux. Will handle multiple overlaps ("mutual events").

kepcart.c:
	Matt Holman's code to covert between cartesian coordinates of Keplerian elements. (Matt, credit?)

photodynam.cpp:
	User-end code to produce light curves and other information for a standardized input format.  Easy to use, probably a good starting point to get some light curves produced.

Example use of functions
------------------------

#include "n_body_state.h"
#include "n_body_lc.h"



photodynam
----------

	Installing photodynam
	---------------------

	Unpack directory, change to that directory, type make. Program "photodynam" will be built
	in top directory

	Documentation
	-------------
	Call code as photodynam <input_file> <report_file> [> <output_file>].

	Output is written to standard out unless redirected (shown in the optional listing above).

	<input_file> file
	-----------------

  	<input_file> is file of initial coordinates and properties in
  	following format:

  	<N> <time0>
  	<step_size> <orbit_error>

  	<mass_1> <mass_2> ... <mass_N>
  	<radius_1> <radius_2> ... <radius_N>
  	<flux_1> <flux_2> ... <flux_N>
  	<u1_1> <u1_2> ... <u1_N>
  	<u2_1> <u2_2> ... <u2_N>
        <Prot1> <Prot2> ... <Prot_N>
        <k2_1> <k2_2>  ... <k2_N>


  	<a_1> <e_1> <i_1> <o_1> <l_1> <m_1>
  	...
  	<a_(N-1)> <e_(N-1)> <i_(N-1)> <o_(N-1)> <l_(N-1)> <m_(N-1)>

  	where the Keplerian coordinates (a = semimajor axis, e = eccentricity, i = inclination,
  	o = argument periapse, l = nodal longitude, m = mean anomaly) are the
  	N-1 Jacobian coordinates associated with the masses as ordered above.
  	Angles are assumed to be in radians. The observer is along the positive z axis.
  	Rotations are performed according to Murray and Dermott.

	<report_file> file
	-------------------

	This file is a list of times to report the outputs.
  	The first line is a space-separated list of single character-defined
  	output fields according to:

  	t = time
  	F = flux
  	a = semi-major axes
  	e = eccentricities
  	i = sky-plane inclinations
  	o = arguments of periapse
  	l = nodal longitudes
  	m = mean anomalies
  	K = full keplerian osculating elements
  	x = barycentric, light-time corrected coordinates
  	v = barycentric, light-time corrected velocities
  	M = masses
  	E = fractional energy change from t0
  	L = fraction Lz change from t0

  	For example, the first line could be

  		t F E

  	and the output would have three columns of time flux and
  	fractional energy loss.


  	Example input file
	------------------ examples/kepler16_input.txt:

  	3 212.12316
  	0.01 1e-16

  	0.00020335520 5.977884E-05    9.320397E-08
  	0.00301596700 0.00104964500   0.00035941463
  	0.98474961000	0.01525038700	0.00000000000
  	0.65139908000	0.2		0.0
  	0.00587581200	0.3		0.0
        100.0           100.0          100.0
        0.0             0.0             0.0


  	2.240546E-01 1.595442E-01 1.576745E+00 4.598385E+00 0.000000E+00 3.296652E+00
  	7.040813E-01 7.893413E-03 1.571379E+00 -5.374484E-01 -8.486496E-06 2.393066E+00

	Example report file
	------------------- examples/kepler16_report.txt:

	t F E e
      	-46.461114      -46.440679      -46.420245      -46.399811      -46.379377
	...

	Running the example
	-------------------

	Run:

	./photodynam examples/kepler16_input.txt examples/kepler16_report.txt

	to write output to standard out

	or

	./photodynam examples/kepler16_input.txt examples/kepler16_report.txt > output.txt

	to dump the result into the file named output.txt

	Compare this file (whatever you call it) to examples/output.txt
