inherit "/std/room";

#include "../include.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
 set_exits( ([
  "south" : DIR+"/rooms/7c.c",
  "east" : DIR+"/rooms/6d.c",
  "west" : DIR+"/rooms/6b.c",
  "northwest" : DIR+"/rooms/5b.c"
  ]) );
  set_long( "The floors and walls appear to be made of stone while the roof appears to be dripping some kind of liquid.  The floors and wall also appear to be covered in some kind of slime.\n\nThe dungeon continues to the  south, east, west, and northwest.%^RESET%^");
}
