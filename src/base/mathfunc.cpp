/*
	*** Math functions
	*** src/base/mathfunc.cpp
	Copyright T. Youngs 2010-2011

	This file is part of AtenCalc.

	AtenCalc is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AtenCalc is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AtenCalc.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "base/mathfunc.h"
#include "base/constants.h"
#include <cstdlib>
#include <math.h>

// Error Function
double AtenMath::erfc(double x)
{
	// Approximation to the complementary error function.
	// Ref: Abramowitz and Stegun, Handbook of Mathematical Functions,
	//	National Bureau of Standards, Formula 7.1.26
	static double a1 = 0.254829592, a2 = -0.284496736, a3 = 1.421413741, a4 = -1.453152027, a5 = 1.061405429, p = 0.3275911;
	double t, tp, result;
	t = 1.0 / ( 1.0 + p * x );
	tp = t * ( a1 + t * ( a2 + t * ( a3 + t * ( a4 + t * a5 ) ) ) );
	result = tp * exp(-(x*x));
	return result;
}

// Complementary error function
double AtenMath::erf(double x)
{
	return (1.0 - erfc(x));
}

// Random Number Generator (0 - 1)
double AtenMath::random()
{
	// Simple random number generator from C++ stdlib.
	// Returns numbers from 0.0 to 1.0, exclusive of 1.0.
	// TODO Better generator
	return (double(rand()-1) / RAND_MAX);
}

// Random number generator (0 - range-1)
int AtenMath::randomi(int range)
{
	// Returns a random number from 0->(range-1) inclusive.
	return int(range * random());
}

// Integer power function
int AtenMath::power(int i, int p)
{
	static int result, n;
	result = i;
	if (p == 0) result = 1;
	else for (n=1; n<p; n++) result *= i;
	return result;
}
