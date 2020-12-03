inherit M_COMMAND;
//EVILMOG-TODO rewrite to be more inclusive
string *usage(void) {
   string *lines;

   lines = ({ "Usage: gender [-h] [male|female|other]" });
   lines += ({ " " });
   lines += ({ "Allows you to set your gender.  If no argument is given " });
   lines += ({ "display your current gender." });
   lines += ({ " " });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\tgender" });
   lines += ({ "\tgender male" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("wiz", "title");
}

static void main(string str) {
   if (!alsos) {
      setup_alsos();
   }

   if (empty_str(str)) {
      write("Your current gender is: " + this_player()->query_gender() + "\n");
      return;
   }
   if (sscanf(str, "-%s", str)) {
      this_player()->more(usage());
      return;
   }

   if (lowercase(str) == "female") {
      this_player()->set_gender("female");
      write("You are now female.\n");
      this_player()->save_me();
   } else if (lowercase(str) == "male") {
      this_player()->set_gender("male");
      write("You are now male.\n");
      this_player()->save_me();
   } else if ((lowercase(str) == "other") || (lowercase(str) == "neuter")) {
      this_player()->set_gender("other");
      write("You are now other.\n");
      this_player()->save_me();
   } else {
      write("Please use \"male\", \"female\" or \"other\" as an argument.\n");
   }
}
