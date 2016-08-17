#ifndef _VEC3_C
#define _VEC3_C

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <sstream>

#include "vec3.h"

#define SIZE(x) (sizeof(x) / sizeof(*x))

#define PRINT_PRECISION 2
#define PRINT_WIDTH     6

/**********
 * CONSTRUCTORS 
 **********/

Vec3::Vec3( void ) { 
    this->x = 0; 
    this->y = 0; 
    this->z = 0;
};

Vec3::Vec3( TYPE a, TYPE b, TYPE c){
    this->x = a; 
    this->y = b; 
    this->z = c; 
};

Vec3::Vec3( TYPE *e ) {
    this->x = x; 
    this->y = y; 
    this->z = z; 
};

Vec3::Vec3( const Vec3& cpy)  {
    this->x = cpy.x;
    this->y = cpy.y;
    this->z = cpy.z; 
};

/***********
 * OPERATORS
 ***********/
ostream& operator<< ( ostream& os, const Vec3& m){
    std::stringstream ss;
    ss << fixed << setprecision(PRINT_PRECISION) << "Vec3( " 
       << setw(PRINT_WIDTH) << m.x << ", " 
       << setw(PRINT_WIDTH) << m.y << ", " 
       << setw(PRINT_WIDTH) << m.z << " )";
    os << ss.str();
    return os; 
};

Vec3 operator+ ( const Vec3& l, const Vec3& r){
    return Vec3(
        l.x + r.x,
        l.y + r.y,
        l.z + r.z
    );
};
    
Vec3 operator+ ( const Vec3& l, const TYPE value  ){
    return Vec3( 
        l.x + value,
        l.y + value, 
        l.z + value 
    ); 
};

void Vec3::operator+= ( const Vec3& r ) {
    this->x += r.x;
    this->y += r.y;
    this->z += r.z;
};

void Vec3::operator+= ( const TYPE v ) {
    this->x += v; 
    this->y += v; 
    this->z += v; 
};

Vec3 operator- ( const Vec3& l, const Vec3& r){
    return Vec3(
        l.x - r.x,
        l.y - r.y,
        l.z - r.z
    );
};
    
Vec3 operator- ( const Vec3& l, const TYPE value  ){
    return Vec3( 
        l.x - value,
        l.y - value, 
        l.z - value 
    ); 
};

void Vec3::operator-= ( const Vec3& r ) {
    this->x -= r.x;
    this->y -= r.y;
    this->z -= r.z;
};

void Vec3::operator-= ( const TYPE v ) {
    this->x -= v; 
    this->y -= v; 
    this->z -= v; 
};

TYPE operator* ( const Vec3& l, const Vec3& r){
    return l.x * r.x
         + l.y * r.y
         + l.z * r.z;
};

Vec3 operator* ( const Vec3& l, const TYPE value ) {
    return Vec3(
        l.x * value,
        l.y * value,
        l.z * value 
    );
};

void Vec3::operator *= ( const TYPE v ) {
    this->x *= v; 
    this->y *= v; 
    this->z *= v; 
};

Vec3 operator/ ( const Vec3& l, const TYPE value ) {
    return Vec3(  
        l.x / value,
        l.y / value,
        l.z / value 
    );
};

void Vec3::operator/= ( const TYPE v ) {
    this->x /= v; 
    this->y /= v; 
    this->z /= v; 
};

/*************
 * FUNCTIONS
 *************/

TYPE Vec3::magnitude( void ) {
    return pow(
        ( this->x * this->x ) + 
        ( this->y * this->y ) + 
        ( this->z * this->z ),
        0.5
    );
};

Vec3 Vec3::unit( void ) { 
    return Vec3( *this ) / this->magnitude();
};

Vec3 Vec3::cross( const Vec3& u ) { 
     return Vec3( 
         this->y * u.z - this->z * u.y,
         this->z * u.x - this->x * u.z,
         this->x * u.y - this->y * u.x
     );
};

/*
 * Rodriguez Rotation Formula
 *
 * Vrot = V cos + ( K cross V ) sin + K ( K dot V )(1 - cos)
 *
 */
Vec3 Vec3::rotate( const Vec3& U, const TYPE rads ) { 
    float Ti   = ( 1 - cos( rads ) );
    float Uxx  = U.x * U.x * Ti;
    float Uxy  = U.x * U.y * Ti;
    float Uxz  = U.x * U.z * Ti;
    float Uyy  = U.y * U.z * Ti; 
    float Uyz  = U.y * U.z * Ti; 
    float Uzz  = U.z * U.z * Ti;

    float Ts   = sin(rads);
    float Uxs  = U.x * Ts; 
    float Uys  = U.z * Ts;
    float Uzs  = U.y * Ts;

    float Tc   = cos(rads);

    return Vec3(
         (this->x * ( Uxx + Tc  ) ) + (this->y * ( Uxy - Uzs ) ) + (this->z * ( Uxz + Uys ) ),
         (this->x * ( Uxy + Uzs ) ) + (this->y * ( Uyy + Tc  ) ) + (this->z * ( Uyz - Uxs ) ), 
         (this->x * ( Uxz - Uxz ) ) + (this->y * ( Uyz + Uxs ) ) + (this->z * ( Uzz + Tc  ) )  
    );
};
             



#endif

