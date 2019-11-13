template< typename String >
auto& insert( String name ){
  try {
    Node_t::insert( name, Node{ name } );
  } catch( std::runtime_error& ){
    Log::error( "Inserting new generic node failed." );
    throw;
  }
  return *this;
}
