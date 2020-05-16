# Load the module and generate the functions
# Load the module and generate the functions
module ranluxppJulia
  using CxxWrap
  @wrapmodule(joinpath("/usr/people/snirgaz/snirgaz/data_landau/git/ranluxpp/build/lib","libranluxpp_julia"))

  function __init__()
    @initcxx
  end
end



# Call greet and show the result
rng=ranluxppJulia.ranluxpp(UInt64(5))
ranluxppJulia.get_int(rng)