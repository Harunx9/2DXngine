#include "gtest/gtest.h"
#include "TiledFixture.h"

TEST_F(TiledFixture, ImageLayer_should_have_parsed_properly)
{
    auto img = _parsedMap->getImageLayer("Image Layer 1");
    auto image = img.get_image();
    ASSERT_EQ(img.get_name(), "Image Layer 1");
    ASSERT_EQ(image.source, "../Pictures/newclass.PNG");
    ASSERT_EQ(image.width, 876);
    ASSERT_EQ(image.height, 622);
}