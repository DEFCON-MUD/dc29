inherit "/std/room";

void setup(void) {
   add_area("required");

   set_domainname("EvilMogs Funland");

   set_short("A large open field");
   set_long("You are in a large open field.  To the north you see a large " +
      "dead tree with some sort of sign on it. \n\n%^RED%^*%^YELLOW%^*%^RESET%^%^RED%^* %^HRED%^WARNING: %^RESET%^Permadeath is active in this game, you can buy death insurance. Right now the game is configured to drop you to level 1 on death.");
   add_action("fuck", "fuck");

   add_object( "/domains/dungeon/objects/sign.c", 9);
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


