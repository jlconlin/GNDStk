template< typename String >
Generic( String name ):
  Node_t( Node_t::makeMap() )
{ 
  this->insert( "name", Node_t{ name } );
  this->insert( "metadata", Node_t::makeMap() );
}
