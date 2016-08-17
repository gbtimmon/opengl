#include <iostream> 
#include <string>
#include <iomanip>


#include "const.h"
#include "vec3.h"
#include "colors.h"

using namespace std; 

#define SIZE 20 
#define SPACE 40
#define P(x) {   cout << FBLU( x ) << endl; }
#define T(x) {\
                 out_vec x ;\
                 cout << "[" << std::setw(3) << i++ << "] " \
                      << setw(SPACE) << left << out_vec << " " \
                      << setw(SPACE) << left << #x << endl;\
             }

#define F(x) {\
                 out_float x ;\
                 cout << "[" << std::setw(3) << i++ << "] "\
                      << setw(SPACE) << left << out_float << " " \
                      << setw(SPACE) << left << #x << endl;\
             }

int main ( void ) { 
    Vec3 v[SIZE];
    string s[SIZE];
    int i = 0; 
    Vec3 out_vec;
    float out_float; 

    Vec3 test_v1 = Vec3( 3.0f, 4.0f, 5.0f );
    Vec3 test_v2 = Vec3( 5.0f, 6.0f, 7.0f );

    P("")
    P("Constructors");
    T( = Vec3( ) );
    T( = Vec3( 1.0f, 2.0f, 3.0f ) );
    T( = Vec3( {3.0f, 4.0f, 5.0f } ) );
    T( = Vec3( test_v1 ) );

    P("")
    P("Addition Operator");
    T( = Vec3( 1.f, 2.f, 3.f) + Vec3( 2.f, 3.f, 4.f ) );
    T( = Vec3( 1.f, 2.f, 3.f) + 5.0f );
    T( += Vec3( 4.f, 6.f, 7.f) );
    T( += 4.5f );

    P("")
    P("Subtraction Operator")
    T( = Vec3( 1.f, 2.f, 3.f) - Vec3( 2.f, 3.f, 4.f ) );
    T( = Vec3( 1.f, 2.f, 3.f) - 5.0f );
    T( -= Vec3( 4.f, 6.f, 7.f) );
    T( -= 4.5f );

    P("")
    P("Multiplication Operator")
    F( = Vec3( 1.f, 2.f, 3.f) * Vec3( 2.f, 3.f, 4.f ) );
    T( = Vec3( 1.f, 2.f, 3.f) * 5.0f );
    T( *= 4.5f );

    P("")
    P("Division Operator")
    T( = Vec3( 1.f, 2.f, 3.f) / 5.0f );
    T( /= .2f );
    
    P("")
    P("Methods")
    F( = Vec3( 4.f, 5.f, 6.f ).magnitude() );
    T( = Vec3( 4.f, 5.f, 6.f ).unit() );
    F( = Vec3( 4.f, 5.f, 6.f ).unit().magnitude() );
    
    P("")
    P("cross and dot")
    T( = VEC3_X_AXIS.cross(VEC3_Y_AXIS).unit());
    T( = VEC3_Y_AXIS.cross(VEC3_X_AXIS).unit());
    T( = VEC3_X_AXIS.cross(VEC3_Z_AXIS).unit());
    T( = VEC3_Z_AXIS.cross(VEC3_Y_AXIS).unit());


}

