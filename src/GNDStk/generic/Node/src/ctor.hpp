template< typename String >
Node( String name ):
  Node_t( Node_t::makeMap() )
{ 
  this->insert( "name", Node_t{ name } );
  this->insert( "metadata", Node_t::makeMap() );
}

Node( const pugi::xml_node& xmlNode ):
  Node( xmlNode.name() )
{
  Log::info( "" );
  Log::info( "Constructing node from XML named: {}", xmlNode.name() );

  Log::info( "\tIterating over attributes" );
  for( const auto& attr : xmlNode.attributes() ) {
    Log::info( "\t\tname: {}, value: {}", attr.name(), attr.value() );
    this->metadata( attr.name(), attr.value() );
  }

  auto& map = std::get< map_type >( this->core );

  Log::info( "\tIterating over child nodes" );
  for( const auto& child: xmlNode.children() ) {
    Log::info( "\t\tchild node name: {}", child.name() );

    if( map.find( child.name() ) == map.end() ){
      try {
        this->insert( child.name(), Node_t::makeList() );
      } catch( std::runtime_error& ){
        Log::error( "error adding list node for XML children" );
        throw;
        
      } catch( ... ){
        Log::error( "Something bad happened" );
        throw;
      }
    }
    this->operator[]( child.name() ).push_back( Node( child ) );
  }
}
