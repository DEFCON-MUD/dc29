string gender;

void set_gender(string gen) {
   gender = gen;
}

string query_gender(void) {
   switch (gender) {
      case "male":
         return "male";
      case "female":
         return "female";
      default:
         return gender;
   }
}

string query_gender_pronoun(void) {
   switch (gender) {
      case "male":
         return "he";
      case "female":
         return "she";
      default:
         return "they";
   }
}

string query_gender_determiner(void) {
   switch (gender) {
      case "male":
         return "his";
      case "female":
         return "her";
      default:
         return "their";
   }
}

string query_gender_possessive(void) {
   switch (gender) {
      case "male":
         return "his";
      case "female":
         return "hers";
      default:
         return "their";
   }
}

string query_gender_reflexive(void) {
   switch (gender) {
      case "male":
         return "himself";
      case "female":
         return "herself";
      default:
         return "themself";
   }
}
