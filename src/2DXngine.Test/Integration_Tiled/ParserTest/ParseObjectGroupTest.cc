#include "gtest/gtest.h"
#include "TiledFixture.h"

TEST_F(TiledFixture, map_object_group_shoudl_have_5_objects)
{
    auto group = _parsedMap->getObjectGroup("TestObject");

    ASSERT_EQ(5, group.get_objects().size());
}

TEST_F(TiledFixture, first_object_should_be_NormalObject)
{
    auto group = _parsedMap->getObjectGroup("TestObject");
    
    auto obj = group.get_objects()[0];
    
    ASSERT_EQ(ObjectType::OBJECT, obj.get_tmxtype());
    ASSERT_EQ(1, obj.get_id());
    ASSERT_EQ(117, obj.get_x());
    ASSERT_EQ(113, obj.get_y());
    ASSERT_EQ(59, obj.get_width());
    ASSERT_EQ(61, obj.get_height());
}

TEST_F(TiledFixture, second_object_should_be_Ellipse)
{
    auto group = _parsedMap->getObjectGroup("TestObject");
    
    auto obj = group.get_objects()[1];
    
    ASSERT_EQ(ObjectType::ELLIPSE, obj.get_tmxtype());
    ASSERT_EQ(2, obj.get_id());
    ASSERT_EQ(33, obj.get_x());
    ASSERT_EQ(44, obj.get_y());
    ASSERT_EQ(59, obj.get_width());
    ASSERT_EQ(57, obj.get_height());
}

TEST_F(TiledFixture, second_object_should_be_Polygon)
{
    auto group = _parsedMap->getObjectGroup("TestObject");

    auto obj = group.get_objects()[2];
    auto points = obj.get_points();
    
    ASSERT_EQ(ObjectType::POLYGON, obj.get_tmxtype());
    ASSERT_EQ(3, obj.get_id());
    ASSERT_EQ(23, obj.get_x());
    ASSERT_EQ(208, obj.get_y());
    ASSERT_EQ(6, points.size());
}

TEST_F(TiledFixture, Polygon_points_should_be_parsed_correctly)
{
    auto group = _parsedMap->getObjectGroup("TestObject");

    auto obj = group.get_objects()[2];
    auto points = obj.get_points();

    ASSERT_EQ(points[0].x, 0);
    ASSERT_EQ(points[0].y, 0);
    
    ASSERT_EQ(points[1].x, 84);
    ASSERT_EQ(points[1].y, -9);
    
    ASSERT_EQ(points[2].x, 99);
    ASSERT_EQ(points[2].y, 89);
    
    ASSERT_EQ(points[3].x, -9);
    ASSERT_EQ(points[3].y, 82);
    
    ASSERT_EQ(points[4].x, 49);
    ASSERT_EQ(points[4].y, 35);
    
    ASSERT_EQ(points[5].x, -11);
    ASSERT_EQ(points[5].y, 38);
}


TEST_F(TiledFixture, second_object_should_be_Polyline)
{
    auto group = _parsedMap->getObjectGroup("TestObject");

    auto obj = group.get_objects()[3];
    auto points = obj.get_points();

    ASSERT_EQ(ObjectType::POLYLINE, obj.get_tmxtype());
    ASSERT_EQ(4, obj.get_id());
    ASSERT_EQ(119, obj.get_x());
    ASSERT_EQ(63, obj.get_y());
    ASSERT_EQ(9, points.size());
}


TEST_F(TiledFixture, Polyline_points_should_be_parsed_correctly)
{
    auto group = _parsedMap->getObjectGroup("TestObject");

    auto obj = group.get_objects()[3];
    auto points = obj.get_points();

    ASSERT_EQ(points[0].x, 0);
    ASSERT_EQ(points[0].y, 0);
    
    ASSERT_EQ(points[1].x, 84);
    ASSERT_EQ(points[1].y, -30);
    
    ASSERT_EQ(points[2].x, 147);
    ASSERT_EQ(points[2].y, 30);
    
    ASSERT_EQ(points[3].x, 139);
    ASSERT_EQ(points[3].y, 141);
    
    ASSERT_EQ(points[4].x, 54);
    ASSERT_EQ(points[4].y, 194);
    
    ASSERT_EQ(points[5].x, 99);
    ASSERT_EQ(points[5].y, 228);

    ASSERT_EQ(points[6].x, 159);
    ASSERT_EQ(points[6].y, 172);

    ASSERT_EQ(points[7].x, 174);
    ASSERT_EQ(points[7].y, 255);

    ASSERT_EQ(points[8].x, 187);
    ASSERT_EQ(points[8].y, 154);
}

TEST_F(TiledFixture, second_object_should_be_Text)
{
    auto group = _parsedMap->getObjectGroup("TestObject");

    auto obj = group.get_objects()[4];
    auto text = obj.get_text();

    ASSERT_EQ(ObjectType::TEXT, obj.get_tmxtype());
    ASSERT_EQ(6, obj.get_id());
    ASSERT_EQ(9, obj.get_x());
    ASSERT_EQ(129, obj.get_y());
    ASSERT_EQ(83, obj.get_width());
    ASSERT_EQ(19, obj.get_height());
    ASSERT_EQ("Hello World", text.value);
}