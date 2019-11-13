template< typename String >
Node( String name ):
  Node_t( Node_t::makeMap() )
{ 
  // Log::info( "" );
  // Log::info( "Constructing Node with string" );
  this->insert( "name", Node_t{ name } );
  this->insert( "metadata", Node_t::makeMap() );
}

Node( const pugi::xml_node& xmlNode ):
  Node( xmlNode.name() )
{
  Log::info( "" );
  Log::info( "Constructing node from XML" );

  Log::info( "Iterating over attributes of:\t\t{}", xmlNode.name() );
  for( pugi::xml_attribute& attr : xmlNode.attributes() ) {
    Log::info( "\tname: {}, value: {}", attr.name(), attr.value() );
    this->metadata( attr.name(), attr.value() );
  }

  Log::info( "Iterating over child nodes of:\t{}", xmlNode.name() );
  for( pugi::xml_node child: xmlNode.children() ) {
    Log::info( "\tchild node name: {}", child.name() );
    this->insert( child.name(), Node( child ) );
  }
}
