#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO( "Testing generic GNDStk Node" ){
  GIVEN( "a generic node" ){
    Generic genNode{ std::string{ "XYs1d" } };
    WHEN( "data has been added" ){
      genNode.metadata( "interpolation", "log-log" );
      genNode.metadata( "index", "0" );
      genNode.insert( "child" );

      THEN( "the metadata can be checked" ){
        CHECK( "log-log" == genNode.metadata( "interpolation" ) );
        CHECK( "0" == genNode.metadata( "index" ) );

        auto metadata = genNode.metadata();
        CHECK( "log-log" == metadata[ "interpolation" ].get< std::string >() );
        CHECK( "0" == metadata[ "index" ].get< std::string >() );
      } // THEN
    } // WHEN
    WHEN( "accessing a node that doesn't exist" ){
      THEN( "an exception is thrown" ){
        CHECK_THROWS_AS( genNode[ "abc" ], std::out_of_range& );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

