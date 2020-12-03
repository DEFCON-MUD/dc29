inherit "/std/monster_race";

void create(void) {
   ::create();
   set_race_short_desc("A fox...");
   set_race_long_desc("This is a fox.");
   base_stat_minimum["str"] = 15;
   base_stat_minimum["con"] = 15;
   base_stat_minimum["dex"] = 15;
   base_stat_minimum["int"] = 10;
   base_stat_minimum["wis"] = 10;
   base_stat_minimum["cha"] = 10;

   base_stat_maximum["str"] = 30;
   base_stat_maximum["con"] = 20;
   base_stat_maximum["dex"] = 30;
   base_stat_maximum["int"] = 20;
   base_stat_maximum["wis"] = 20;
   base_stat_maximum["cha"] = 20;
}
