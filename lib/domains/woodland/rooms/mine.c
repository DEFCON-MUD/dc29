inherit "/std/room";
inherit "/std/evil/mine";

#include "../domain.h"
void setup( void ) {

  #include "area.h"
  set_coords(({ 1, 1 }));
  set_dimensions(({ 1, 1 }));
  add_area( "woodland" );
  set_short( "Woodland Crypto Currency Mines" );
  set_long( "I know what you are thinking, why the heck is a crypto currency mine in a forest... To be honest there " +
  	"is no real answer, if you have a problem with that take it up with management... Oh wait they don't care either. " +
  	"Somehow there is a terminal embedded in a tree, to be honest I'm surprised it works, and yet here we are." +
  	"\n\nYou should try to '%^EXT_129%^crypto%^RESET%^' here." );

  add_action("do_crypto", "crypto");

 set_exits( ([
  "east" : "/domains/woodland/rooms/5_16"
  ]) );
}
