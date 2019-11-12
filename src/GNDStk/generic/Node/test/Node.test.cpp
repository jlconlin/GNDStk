#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO( "Testing generic GNDStk Node" ){
  GIVEN( "a generic node" ){
    generic::Node genNode{ std::string{ "XYs1d" } };
    WHEN( "data has been added" ){
      genNode.metadata( "interpolation", "log-log" );
      genNode.metadata( "index", "0" );
      genNode.insert( "child", generic::Node::makeList() );
      auto childList = genNode[ "child" ];
      childList.push_back( "child1", "child2", "child3" );

      THEN( "the metadata can be checked" ){
        CHECK( "log-log" == genNode.metadata( "interpolation" ) );
        CHECK( "0" == genNode.metadata( "index" ) );

        auto metadata = genNode.metadata();
        CHECK( "log-log" == metadata[ "interpolation" ].get< std::string >() );
        CHECK( "0" == metadata[ "index" ].get< std::string >() );
      } // THEN

      THEN( "the children can be checked" ){
        CHECK( 3 == genNode[ "child" ].list().size() );
      } // THEN
    } // WHEN
    WHEN( "accessing a node that doesn't exist" ){
      THEN( "an exception is thrown" ){
        CHECK_THROWS_AS( genNode[ "abc" ], std::out_of_range& );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::string testNode();
SCENARIO( "Creating Node from XML" ){
  auto sNode = testNode();
  std::istringstream iNode{ sNode };

  GIVEN( "a pugixml::node" ){

    pugi::xml_document doc;
    auto pNode = doc.load_string( sNode.c_str() );
    
  } // GIVEN
} // SCENARIO

std::string testNode(){
  return R"xml(
<regions1d>
  <axes>
    <axis index="1" label="energy_in" unit="eV"/>
    <axis index="0" label="crossSection" unit="b"/>
  </axes>
  <XYs1d index="0">
    <values length="42">
      1.00000000e-05 0.000000e+00 2.53000000e-02 0.000000e+00 4.00000000e+05 0.000000e+00 4.01000000e+05 -1.660000e-03 4.50000000e+05 -1.660000e-03 4.51000000e+05 -1.720000e-03 5.00000000e+05 
    </values>
  </XYs1d>
  <XYs1d index="1">
    <values length="5376">
      8.80000000e+07 1.182806e+00 8.90000000e+07 1.171179e+00 9.00000000e+07 1.159459e+00 9.10000000e+07 1.146647e+00 9.20000000e+07 1.132441e+00 9.30000000e+07 1.117779e+00 9.40000000e+07 
    </values>
  </XYs1d>
  </regions1d>
                )xml";
}
