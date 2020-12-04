int level, experience;

int ready_for_next_level(void) {
   int tmpexp;

   tmpexp = level * level * 2000;

   if (experience > tmpexp) {
      return 1;
   }
   return 0;
}

string query_level_title(int level) {
   switch (level) {
      case 1:
         return "the uninitiated.";
         break;
      case 2:
         return "the newbie.";
         break;
      case 3:
         return "is getting the hang of things.";
         break;
      case 4:
         return "the mediocre.";
         break;
      case 5:
         return "the Sub-average.";
         break;
      case 6:
         return "the Average.";
         break;
      case 7:
         return "the Strong.";
         break;
      case 8:
         return "the Great.";
         break;
      case 9:
         if (this_object()->query_race() == "male") {
            return "the Baron.";
         } else {
            return "the Baroness.";
         }
         break;
      case 10:
         return "the Titan.";
         break;
      case 11:
         return "the Conquerer.";
         break;
      case 12:
         return "the Famous.";
         break;
      case 13:
         return "the Awe-inspiring.";
         break;
      case 14:
         return "the Battle Hardened.";
         break;
      case 15:
         return "the More than Adequate.";
         break;
      case 16:
         if (this_object()->query_race() == "male") {
            return "the Grand Baron.";
         } else {
            return "the Grand Baroness.";
         }
         break;
      case 17:
         return "the Great Titan.";
         break;
      case 18:
         return "the Mighty Conquerer.";
         break;
      case 19:
         return "the High and Mighty.";
         break;
      default:
         return "the Grand Wizard!!!";
         break;
   }
}

void set_level(int lvl) {
   object obj;
   int tmpexp;
   obj = this_object();
   if (obj->is_player()) {
      obj->initialize_stat_dependant_variables();
   }
   switch (lvl) {
     case 1:
       tmpexp = 0;
       break;
     case 2:
       tmpexp = 2000;
       break;
     default:
       tmpexp = ((lvl - 1) * (lvl - 1)) * 2000;
       break;
   }
   level = lvl;
   obj->set_title("$N the " + query_level_title(level));
   obj->set_expr(tmpexp);
   obj->set_hp(obj->query_max_hp());
   obj->set_end(obj->query_max_end());
   obj->set_mana(obj->query_max_mana());
   obj->set_internal_max_weight((15 + this_object()->query_base_stat("str")) * 100);
}

void reset_title(void) {
   object obj;
   int lvl;
   obj = this_object();
   lvl = obj->query_level();
   obj->set_title("$N the " + query_level_title(level));
}

void increase_level(void) {
/*EVILMOG-TODO change increase_level*/
   level += 1;
   this_object()->set_max_hp((level *
      this_object()->query_base_stat("str")) + 20);
   this_object()->set_max_mana((level *
      this_object()->query_base_stat("wis")) + 20);
   this_object()->set_max_end((level *
      this_object()->query_base_stat("con")) + 20);
   write("Congratulations, you just achieved level: " + level + "\n");
   this_object()->set_title("$N " + query_level_title(level));
}

void increase_expr(int expr) {
   if (expr < 0) {
      expr = expr * -1;
   }
   experience += expr;
   if (experience < 0) {
      experience = 0;
   }
   if (ready_for_next_level()) {
      increase_level();
      write("Congratulations, you just went up a level...\n");
      level += 1;
   }
}

void decrease_expr(int expr) {
   if (expr > 0) {
      expr = expr * -1;
   }
   experience -= expr;
   if (experience < 0) {
      experience = 0;
   }
}

void set_expr(int expr) {
   experience = expr;
   if (experience < 0) {
      experience = 0;
   }
}

int query_expr(void) {
   return (experience);
}

int query_level(void) {
   return (level);
}
