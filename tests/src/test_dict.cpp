#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dict.hpp"
#include <string>

using Catch::Matchers::UnorderedEquals;

TEST_CASE("Test Dict")
{
    // Implement your own tests. You can use below as a reference.
    // When implementing tests, think of the edge cases where you
    // suspect the program is likely to fail.
    // For example inserting the 'same' person twice or removing an
    // non existent person from the dictionary.
    Dict<std::string, int> name_to_age;

    REQUIRE(name_to_age.len() == 0);
    REQUIRE(name_to_age.keys().empty());
    REQUIRE(name_to_age.values().empty());

    name_to_age.set("Jane", 20);
    REQUIRE(name_to_age.len() == 1);
    REQUIRE(name_to_age.has("Jane"));
    REQUIRE(name_to_age.get("Jane").has_value());
    REQUIRE(name_to_age.get("Jane").value() == 20);
    REQUIRE_THAT(name_to_age.keys(), UnorderedEquals(std::vector<std::string>{"Jane"}));
    REQUIRE_THAT(name_to_age.values(), UnorderedEquals(std::vector<int>{20}));

    name_to_age.set("Tarzan", 25);

    // Should have 2 entries in dict
    REQUIRE(name_to_age.len() == 2);

    // Removing tarzan should leave us with only jane
    name_to_age.del("Tarzan");
    REQUIRE_THAT(name_to_age.keys(), UnorderedEquals(std::vector<std::string>{"Jane"}));
    REQUIRE_THAT(name_to_age.values(), UnorderedEquals(std::vector<int>{20}));
    REQUIRE(name_to_age.len() == 1);

    // If we check for key tarzan we should get false and if we try
    // to get it we get should get null
    REQUIRE(!name_to_age.has("Tarzan"));
    REQUIRE(!name_to_age.get("Tarzan"));

    // Deleting a key not in the dict should do nothing
    name_to_age.del("Tarzan");
    REQUIRE_THAT(name_to_age.keys(), UnorderedEquals(std::vector<std::string>{"Jane"}));
    REQUIRE_THAT(name_to_age.values(), UnorderedEquals(std::vector<int>{20}));

    // Two of the same people
    Dict<std::string, int> two_ppl;
    two_ppl.set("Frost", 67);
    two_ppl.set("Frost", 49);
    // Length should be one
    REQUIRE(two_ppl.len() == 1);
    // Person should have the overwritten value
    REQUIRE(two_ppl.get("Frost").value() == 49);
    // Person should be overwritten
    REQUIRE_THAT(two_ppl.keys(), UnorderedEquals(std::vector<std::string>{"Frost"}));
    REQUIRE_THAT(two_ppl.values(), UnorderedEquals(std::vector<int>{49}));
    // Should only contain one Frost so 
    // deleting once removes all entries
    two_ppl.del("Frost");
    REQUIRE(!two_ppl.has("Frost"));
    // Should be empty
    REQUIRE(two_ppl.len() == 0);
    REQUIRE(two_ppl.keys().empty());
    REQUIRE(two_ppl.values().empty());
}
