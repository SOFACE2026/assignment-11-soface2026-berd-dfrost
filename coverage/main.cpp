#include <cassert>
#include <iostream>
#include "../include/dict.hpp"

int main()
{
    // Implement your own tests. You can use below as a reference.
    // When implementing tests, think of the edge cases where you
    // suspect the program is likely to fail.
    // For example inserting the 'same' person twice or removing an
    // non existent person from the dictionary.
    Dict<std::string, int> name_to_age;

    name_to_age.len() == 0;
    name_to_age.keys().empty();
    name_to_age.values().empty();

    name_to_age.set("Jane", 20);
    name_to_age.len() == 1;
    name_to_age.has("Jane");
    name_to_age.get("Jane").has_value();
    name_to_age.get("Jane").value() == 20;
    name_to_age.keys();
    name_to_age.values();

    name_to_age.set("Tarzan", 25);

    // Should have 2 entries in dict
    name_to_age.len() == 2;

    // Removing tarzan should leave us with only jane
    name_to_age.del("Tarzan");
    name_to_age.keys();
    name_to_age.values();
    name_to_age.len() == 1;

    // If we check for key tarzan we should get false and if we try
    // to get it we get should get null
    !name_to_age.has("Tarzan");
    !name_to_age.get("Tarzan");

    // Deleting a key not in the dict should do nothing
    name_to_age.del("Tarzan");
    name_to_age.keys();
    name_to_age.values();

    // Two of the same people
    Dict<std::string, int> two_ppl;
    two_ppl.set("Frost", 67);
    two_ppl.set("Frost", 49);
    // Length should be one
    two_ppl.len() == 1;
    // Person should have the overwritten value
    two_ppl.get("Frost").value() == 49;
    // Person should be overwritten
    two_ppl.keys();
    two_ppl.values();
    // Should only contain one Frost so 
    // deleting once removes all entries
    two_ppl.del("Frost");
    !two_ppl.has("Frost");
    // Should be empty
    two_ppl.len() == 0;
    two_ppl.keys().empty();
    two_ppl.values().empty();

    std::cout << "We got there!" << std::endl;
    
    return 0;
}