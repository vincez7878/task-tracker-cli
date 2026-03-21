#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"
#include "task.hpp"

TEST_CASE("Task Class Tests") {
    SECTION("Proper Construction") {
        std::string test_desc = "test";
        Task t(1, test_desc);
        REQUIRE(t.GetId() == 1);
        REQUIRE(t.GetDescription() == "test");
        REQUIRE(t.GetStatus() == "Todo");
        REQUIRE_FALSE(t.GetTimeCreated().empty());
        REQUIRE_FALSE(t.GetTimeUpdated().empty());
        REQUIRE(t.GetTimeCreated() == t.GetTimeUpdated());
    }

    SECTION("Updated Task") {
        std::string test_desc = "test";
        std::string test_desc_update = "test1";
        Task t(1, test_desc);
        t.UpdateTask(test_desc_update);
        REQUIRE(t.GetDescription() == test_desc_update);
    }

    SECTION("Mark Task") {
        std::string test_desc = "test";
        Task t(1, test_desc);
        std::string mark = "In-Progress";
        t.MarkTask(mark);
        REQUIRE(t.GetStatus() == "In-Progress");
    }
}