#include "gtest/gtest.h"
#include <Utils/SimpleCSV.h>
#include <Utils/Path.h>
#include <SDL.h>

TEST(SimpleCsv, parser_can_parse_one_line_properly)
{
    std::string line = "aaa;ddd;fff;ggg;ddd";
    SimpleCSV* parser = new SimpleCSV(';');
    auto result = parser->parseLine(line);

    ASSERT_EQ("aaa", result[0]);
    ASSERT_EQ("ddd", result[1]);
    ASSERT_EQ("fff", result[2]);
    ASSERT_EQ("ggg", result[3]);
    ASSERT_EQ("ddd", result[4]);
}

TEST(SimpleCsv, parser_can_parse_raw_string_properly)
{
    std::string text = R"(aaa;ddd;fff;ggg;ddd
    dsdweds;sdsdsdsds;sdsdsdsd;)";
    SimpleCSV* parser = new SimpleCSV(';');
    auto result = parser->parseText(text);

    ASSERT_EQ("aaa", result[0][0]);
    ASSERT_EQ("ddd", result[0][1]);
    ASSERT_EQ("fff", result[0][2]);
    ASSERT_EQ("ggg", result[0][3]);
    ASSERT_EQ("ddd", result[0][4]);
    ASSERT_EQ("dsdweds", result[1][0]);
    ASSERT_EQ("sdsdsdsds", result[1][1]);
    ASSERT_EQ("sdsdsdsd", result[1][2]);
}

TEST(SimpleCsvFile, parser_can_parse_file_properly)
{
    std::string filePath = std::string(SDL_GetBasePath()) + "\\Content\\test.csv";
    filePath = Path::normalize(filePath);
    SimpleCSV* parser = new SimpleCSV(';');
    auto result = parser->parseFile(filePath);

    //sss; ddd; fff; ggg
    //qqq; www; eee; rrr

    ASSERT_EQ("sss", result[0][0]);
    ASSERT_EQ("ddd", result[0][1]);
    ASSERT_EQ("fff", result[0][2]);
    ASSERT_EQ("ggg", result[0][3]);
    ASSERT_EQ("qqq", result[1][0]);
    ASSERT_EQ("www", result[1][1]);
    ASSERT_EQ("eee", result[1][2]);
    ASSERT_EQ("rrr", result[1][3]);
}

TEST(SimpleCsvFile, should_return_empty_content_if_no_file_exist)
{
    std::string filePath = std::string(SDL_GetBasePath()) + "Content\\test2.csv";
    filePath = Path::normalize(filePath);
    SimpleCSV* parser = new SimpleCSV(';');
    
    auto result = parser->parseFile(filePath);

    ASSERT_TRUE(result.empty());
}
