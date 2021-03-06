/*
	*** 3-Component vector class
	*** src/templates/vector3.h
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

#ifndef ATENCALC_VECTOR3_H
#define ATENCALC_VECTOR3_H

#include "base/constants.h"
#include "base/mathfunc.h"
#include <stdio.h>
#include <math.h>

// 3D vector
template <class T> class Vec3
{
	public:
	// Constructor
	Vec3<T>(T xx = 0, T yy = 0, T zz = 0);
	// Components of vector
	T x,y,z;


	/*
	// Set / adjust / retrieve
	*/
	public:
	// Set the vector to 0,0,0
	void zero();
	// Set the specific element to value
	void set(int index, T d);
	// Set all three values simultaneously
	void set(T x, T y, T z);
	// Set all three values simultaneously, converting supplied spherical coordinates to cartesian
	void setFromSpherical(T r, T phi, T theta);
	// Add value to single value
	void add(int index, T delta);
	// Add values to all three values simultaneously
	void add(T dx, T dy, T dz);
	// Returns the value of the specified element
	T get(int) const;


	/*
	// Operators
	*/
	public:
	// Operator =
	void operator=(T);
	// Operators + and +=
	void operator+=(T);
	void operator+=(const Vec3<T>&);
	Vec3<T> operator+(T) const;
	Vec3<T> operator+(const Vec3<T>&) const;
	// Operators - and -=
	void operator-=(T);
	void operator-=(const Vec3<T>&);
	Vec3<T> operator-(T) const;
	Vec3<T> operator-() const;
	Vec3<T> operator-(const Vec3<T>&) const;
	// Operators / and /=
	void operator/=(const T);
	void operator/=(const Vec3<T>&);
	Vec3<T> operator/(T) const;
	Vec3<T> operator/(const Vec3<T>&) const;
	// Operators * and *=
	Vec3<T> operator*(T) const;
	void operator*=(T);
	Vec3<T> operator*(const Vec3<T>&) const;
	// Element access operator
	T operator[](int index);


	/*
	// Methods
	*/
	public:
	// Return vector of absolute elements
	Vec3<T> abs() const;
	// Returns the largest absolute value of the vector
	T absMax() const;
	// Returns the index of the maximum absolute-valued element in the vector
	int absMaxElement() const;
	// Returns the smallest absolute value of the vector
	T absMin() const;
	// Returns the index of the minimum absolute-valued element in the vector
	int absMinElement() const;
	// Dot product between this and supplied vector
	double dp(const Vec3<T> &v) const;
	// Normalise and return original magnitude
	double magAndNormalise();
	// Calculate vector magnitude
	inline double magnitude() const;
	// Calculate square of vector magnitude
	inline double magnitudeSq() const;
	// Returns the largest value of the vector
	T max() const;
	// Returns the maximum valued element in the vector
	int maxElement() const;
	// Returns the smallest value of the vector
	T min() const;
	// Returns the minimum valued element in the vector
	int minElement() const;
	// Multiply elements of this vector with those of supplied vector
	void multiply(const Vec3<T> &v);
	// Normalise the vector to unity
	void normalise();
	// Returns an orthogonal vector
	Vec3<T> orthogonal() const;
	// Orthogonalise (Gram-Schmidt) w.r.t. supplied vector
	void orthogonalise(const Vec3<T>&);
	// Orthogonalise (two vectors)
	void orthogonalise(const Vec3<T> &source1, const Vec3<T> &source2);
	// Prints the contents of the vector
	void print() const;
	// Generate random unit vector
	void randomUnit();
	// Convert spherical who,phi,theta coordinates into cartesian x,y,z
	void toCartesian();
	// Convert cartesian x,y,z coordinates into spherical (rho,phi/zenith,theta/azimuthal)
	void toSpherical();
};

// Constructor
template <class T> Vec3<T>::Vec3(T xx, T yy, T zz)
{
	x = xx;
	y = yy;
	z = zz;
}

/*
// Set / adjust / retrieve 
*/

// Zero
template <class T> void Vec3<T>::zero()
{
	x = 0;
	y = 0;
	z = 0;
}

// Set element
template <class T> void Vec3<T>::set(int el, T value)
{
	if (el == 0) x = value;
	else if (el == 1) y = value;
	else if (el == 2) z = value;
}

// Set
template <class T> void Vec3<T>::set(T a, T b, T c)
{
	x = a;
	y = b;
	z = c;
}

// Set all three values simultaneously, converting supplied spherical coordinates to cartesian
template <class T> void Vec3<T>::setFromSpherical(T r, T phi, T theta)
{
	x = r;
	y = phi;
	z = theta;
	toCartesian();
}

// Adjust element
template <class T> void Vec3<T>::add(int el, T value)
{
	if (el == 0) x += value;
	else if (el == 1) y += value;
	else if (el == 2) z += value;
}

// Add to all
template <class T> void Vec3<T>::add(T a, T b, T c)
{
	x += a;
	y += b;
	z += c;
}

// Retrieve single element
template <class T> T Vec3<T>::get(int index) const
{
	if (index == 0) return x;
	else if (index == 1) return y;
	else if (index == 2) return z;
	printf("Vec3 - element index %i is out of bounds.\n", index);
	return 0;
}

/*
// Operators
*/

// Assignment from single value
template <class T> void Vec3<T>::operator=(T a)
{
	x = a;
	y = a;
	z = a;
}

// Operator += (T)
template <class T> void Vec3<T>::operator+=(T v)
{
	x += v;
	y += v;
	z += v;
}

// Operator += (Vec3)
template <class T> void Vec3<T>::operator+=(const Vec3<T> &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

// Operator + (T)
template <class T> Vec3<T> Vec3<T>::operator+(T v) const
{
	Vec3<T> result;
	result.x = x+v;
	result.y = y+v;
	result.z = z+v;
	return result;
}

// Operator + (Vec3)
template <class T> Vec3<T> Vec3<T>::operator+(const Vec3<T> &v) const
{
	Vec3<T> result;
	result.x = x+v.x;
	result.y = y+v.y;
	result.z = z+v.z;
	return result;
}

// Operator -= (T)
template <class T> void Vec3<T>::operator-=(T v)
{
	x -= v;
	y -= v;
	z -= v;
}

// Operator -= (Vec3)
template <class T> void Vec3<T>::operator-=(const Vec3<T> &v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

// Unary Operator -
template <class T> Vec3<T> Vec3<T>::operator-() const
{
	Vec3<T> result;
	result.x = -x;
	result.y = -y;
	result.z = -z;
	return result;
}

// Operator - (T)
template <class T> Vec3<T> Vec3<T>::operator-(T v) const
{
	Vec3<T> result;
	result.set(x-v,y-v,z-v);
	return result;
}

// Operator - (Vec3)
template <class T> Vec3<T> Vec3<T>::operator-(const Vec3<T> &v) const
{
	Vec3<T> result;
	result.set(x-v.x,y-v.y,z-v.z);
	return result;
}

// Operator /= (T)
template <class T> void Vec3<T>::operator/=(T v)
{
	x /= v;
	y /= v;
	z /= v;
}

// Operator /= (Vec3)
template <class T> void Vec3<T>::operator/=(const Vec3<T> &v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
}

// Operator / (T)
template <class T> Vec3<T> Vec3<T>::operator/(T v) const
{
	Vec3<T> result;
	result.x = x/v;
	result.y = y/v;
	result.z = z/v;
	return result;
}

// Operator / (Vec3)
template <class T> Vec3<T> Vec3<T>::operator/(const Vec3<T> &v) const
{
	Vec3<T> result;
	result.x = x/v.x;
	result.y = y/v.y;
	result.z = z/v.z;
	return result;
}

// Operator *= (T)
template <class T> void Vec3<T>::operator*=(T v)
{
	x *= v;
	y *= v;
	z *= v;
}

// Operator * (T)
template <class T> Vec3<T> Vec3<T>::operator*(T v) const
{
	Vec3<T> result;
	result.x = x*v;
	result.y = y*v;
	result.z = z*v;
	return result;
}

// Operator * (Vec3) (Cross product)
template <class T> Vec3<T> Vec3<T>::operator*(const Vec3<T> &v) const
{
	Vec3<T> result;
	result.x = y * v.z - z * v.y;
	result.y = z * v.x - x * v.z;
	result.z = x * v.y - y * v.x;
	return result;
}

// Element access operator
template <class T> T Vec3<T>::operator[](int index)
{
	if (index == 0) return x;
	else if (index == 1) return y;
	else if (index == 2) return z;
	printf("Vec3 - array access failed - index %i is out of bounds.\n", index);
	return 0;
}

/*
// Methods
*/

// Return vector of absolute elements
template <class T> Vec3<T> Vec3<T>::abs() const
{
	return Vec3<T>(fabs(x), fabs(y), fabs(z));
}

// Largest absolute value
template <class T> T Vec3<T>::absMax() const
{
	T a = (fabs(x) < fabs(y)) ? fabs(y) : fabs(x);
	return (a < fabs(z)) ? fabs(z) : a;
}

// Maximum absolute element
template <class T> int Vec3<T>::absMaxElement() const
{
	if ((fabs(x) >= fabs(y)) && (fabs(x) >= fabs(z))) return 0;
	if ((fabs(y) >= fabs(x)) && (fabs(y) >= fabs(z))) return 1;
	return 2;
}

// Smallest absolute value
template <class T> T Vec3<T>::absMin() const
{
	T a = (fabs(x) > fabs(y)) ? fabs(y) : fabs(x);
	return (a > fabs(z)) ? fabs(z) : a;
}

// Minimum absolute element
template <class T> int Vec3<T>::absMinElement() const
{
	if ((fabs(x) <= fabs(y)) && (fabs(x) <= fabs(z))) return 0;
	if ((fabs(y) <= fabs(x)) && (fabs(y) <= fabs(z))) return 1;
	return 2;
}

// Dot product
template <class T> double Vec3<T>::dp(const Vec3<T> &v) const
{
	return (x*v.x + y*v.y + z*v.z);
}

// Normalise and return original magnitude
template <class T> double Vec3<T>::magAndNormalise()
{
	double mag = sqrt(x*x + y*y + z*z);
	if (mag < 1.0E-8) zero();
	else
	{
		x /= mag;
		y /= mag;
		z /= mag;
	}
	return mag;
}

// Vector magnitude
template <class T> double Vec3<T>::magnitude() const
{
	return sqrt(x*x + y*y + z*z);
}

// Vector magnitude squared
template <class T> double Vec3<T>::magnitudeSq() const
{
	return x*x + y*y + z*z;
}

// Largest value
template <class T> T Vec3<T>::max() const
{
	T a = (x < y) ? y : x;
	return (a < z) ? z : a;
}

// Maximum element
template <class T> int Vec3<T>::maxElement() const
{
	if ((x >= y) && (x >= z)) return 0;
	if ((y >= x) && (y >= z)) return 1;
	return 2;
}

// Smallest value
template <class T> T Vec3<T>::min() const
{
	T a = (x > y) ? y : x;
	return (a > z) ? z : a;
}

// Minimum element
template <class T> int Vec3<T>::minElement() const
{
	if ((x <= y) && (x <= z)) return 0;
	if ((y <= x) && (y <= z)) return 1;
	return 2;
}

// Multiply elements of this vector with those of the supplied vector
template <class T> void Vec3<T>::multiply(const Vec3<T> &v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
}

// Normalise
template <class T> void Vec3<T>::normalise()
{
	double mag = sqrt(x*x + y*y + z*z);
	if (mag < 1.0E-8) zero();
	else
	{
		x /= mag;
		y /= mag;
		z /= mag;
	}
}

// Get orthogonal vector
template <class T> Vec3<T> Vec3<T>::orthogonal() const
{
	// Returns a vector orthogonal to this vector
	Vec3<T> result;
	int a = absMaxElement();
	if (a == 0) result.set(-y,x,0);
	else result.set(-get(a),(a == 1 ? x : y),0);
	result = result * (*this);
	result.normalise();
	return result;
}

// Orthogonalise
template <class T> void Vec3<T>::orthogonalise(const Vec3<T> &source)
{
	double sourcemag = source.magnitude();
	double dpovermagsq = dp(source) / (sourcemag * sourcemag);
	x = x - dpovermagsq * source.x;
	y = y - dpovermagsq * source.y;
	z = z - dpovermagsq * source.z;
}

// Orthogonalise (two vectors)
template <class T> void Vec3<T>::orthogonalise(const Vec3<T> &source1, const Vec3<T> &source2)
{
	// This routine actually generates the orthogonal vector via the cross-product
	// We also calculate the scalar resolute (dp) to ensure the new vector points in the same direction
	Vec3<T> newvec = source1 * source2;
	newvec.normalise();
	double dp = newvec.dp(*this);
	if (dp < 0.0) newvec *= -1.0;
	*this = newvec;
}

// Print
template <class T> void Vec3<T>::print() const
{
	printf("%8.4f %8.4f %8.4f\n",(double)x,(double)y,(double)z);
}

// Generate random unit vector
template <class T> void Vec3<T>::randomUnit()
{
	// Generates a random unit vector
	x = AtenMath::random()-0.5;
	y = AtenMath::random()-0.5;
	z = AtenMath::random()-0.5;
	normalise();
}

// Convert to cartesian
template <class T> void Vec3<T>::toCartesian()
{
	// x = rho, y = theta (inclination), z = phi (azimuthal angle), assuming that phi and theta are in degrees
	T newx,newy,newz;
	y /= DEGRAD;
	z /= DEGRAD;
	newx = x * sin(y) * cos(z);
	newy = x * sin(y) * sin(z);
	newz = x * cos(y);
	set(newx,newy,newz);
}

// Convert to spherical
template <class T> void Vec3<T>::toSpherical()
{
	T rho, phi, theta;
	rho = magnitude();
	theta = acos(z/rho);
	phi = atan2(y,x);
	set(rho,phi*DEGRAD,theta*DEGRAD);
}

#endif
