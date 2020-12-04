inherit "/std/room";

void setup(void) {
   add_area("required");

   set_domainname("EvilMogs Funland");

   set_short("A large open field");
   set_long("Welcome to the DEFCON NewYears MUD. You can decide to play or you can decide to code.\n\n" + 
    "To the north is woodland which is being completely overhauled, down doesn't go anywhere but it might.\n\n" +
    "Permadeath is active in the game along with other shenanigans.");
   add_action("fuck", "fuck");

   set_exits(([
      "north" : "/domains/newbie/rooms/tree",
      "down" : "#do_core"
   ]));
}

int fuck(string args) {
  this_player()->increment_death();
  return 1;
}



void do_core(void) {
  object player;
  player = this_player();
  write("The shuttle to colony has been shut down");
  return;
}


