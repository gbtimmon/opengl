#ifndef _VEC3_H
#define _VEC3_H

#include <iostream>

#define TYPE float 

#define VEC3_X_AXIS Vec3( 1.0f,0.0f,0.0f)
#define VEC3_Y_AXIS Vec3( 0.0f,1.0f,0.0f)
#define VEC3_Z_AXIS Vec3( 0.0f,0.0f,1.0f)

using namespace std;
class Vec3 { 

    public :
        // Data
        TYPE x; 
        TYPE y; 
        TYPE z; 

        // Constructors 
        Vec3( void ); 
        Vec3( TYPE, TYPE, TYPE );
        Vec3( TYPE[] ); 
        Vec3( const Vec3& ); 

        
        // Operators
        friend ostream& operator<< ( ostream&, const Vec3&); 
        friend Vec3	operator+  ( const Vec3&, const Vec3& ); 
        friend Vec3   	operator+  ( const Vec3&, const TYPE  ); 
        void            operator+= ( const Vec3& );
        void            operator+= ( const TYPE  );
        friend Vec3     operator-  ( const Vec3&, const Vec3& );         
        friend Vec3     operator-  ( const Vec3&, const TYPE  );         
        void            operator-= ( const Vec3& ); 
        void            operator-= ( const TYPE  );
        friend TYPE	operator*  ( const Vec3&, const Vec3& ); 
        friend Vec3   	operator*  ( const Vec3&, const TYPE  ); 
        void            operator*= ( const TYPE  );
        friend Vec3     operator/  ( const Vec3&, const TYPE );
        void            operator/= ( const TYPE );

        // Functions                
        Vec3            rotate     ( const Vec3&, const TYPE );
        Vec3            rotateX    ( const TYPE );
        Vec3            rotateY    ( const TYPE );
        Vec3            rotateZ    ( const TYPE );

        TYPE         	magnitude  ( );
        Vec3     	unit       ( );      
        Vec3            cross      ( const Vec3& );

};

#endif

