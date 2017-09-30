#include "gtest\gtest.h"
#include "TiledFixture.h"

TEST_F(TiledFixture, tileset_should_be_parsed)
{
    auto tilest = this->_parsedMap->getTileset(1);

    ASSERT_EQ("untitled.tsx", tilest.get_source());
}