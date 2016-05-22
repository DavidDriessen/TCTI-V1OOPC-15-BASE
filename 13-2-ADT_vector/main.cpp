#include "ostream"
#include "../Catch/include/catch_with_main.hpp"
#include "Vector.h"

TEST_CASE( "constructor, two_parameters" ){
    Vector v( 5, 8 );
    std::stringstream s;
    s << v;
    REQUIRE( s.str() == "(5, 8)" );
}

TEST_CASE( "equality, equal" ){
    Vector v( 1, 2 );
    REQUIRE( v == Vector( 1, 2 ) );
}

TEST_CASE( "equality, unequal" ){
    Vector v( 1, 2 );
    REQUIRE( ! ( v == Vector( 1, 3 )) );
}

TEST_CASE( "multiply by integer" ){
    Vector v( 3, 4 );
    Vector x = v * 7;
    REQUIRE( v == Vector( 3, 4 ) );
    REQUIRE( x == Vector( 21, 28 ) );
}

TEST_CASE( "multiply by Vector" ){
    Vector v( 3, 4 );
    Vector x = v * Vector( 9, 7 );
    REQUIRE( v == Vector( 3, 4 ) );
    REQUIRE( x == Vector( 27, 28 ) );
}

TEST_CASE( "add Vector into Vector" ){
    Vector v( 3, 10 );
    v += Vector( 6, 7 );
    REQUIRE( v == Vector( 9, 17 ) );
}

TEST_CASE( "add Vector into Vector; return value" ){
    Vector v( 1, 2 );
    Vector x = ( v += Vector( 1, 4 ));
    REQUIRE( v == Vector( 2, 6 ) );
    REQUIRE( x == Vector( 2, 6 ) );
}

TEST_CASE( "subtract Vector from Vector" ){
    Vector v( 3, 10 );
    v += Vector( 6, 7 );
    REQUIRE( v == Vector( 9, 17 ) );
}

TEST_CASE( "subtract Vector from Vector; return value" ){
    Vector v( 1, 2 );
    Vector x = ( v += Vector( 1, 4 ));
    REQUIRE( v == Vector( 2, 6 ) );
    REQUIRE( x == Vector( 2, 6 ) );
}

TEST_CASE( "multiply Vector into Vector" ){
    Vector v( 3, 10 );
    v *= Vector( 1, 2 );
    REQUIRE( v == Vector( 3, 20 ) );
}

TEST_CASE( "multiply Vector into Vector; return value" ){
    Vector v( 3, 10 );
    Vector x = ( v *= Vector( 1, 2 ));
    REQUIRE( v == Vector( 3, 20 ) );
    REQUIRE( x == Vector( 3, 20 ) );
}