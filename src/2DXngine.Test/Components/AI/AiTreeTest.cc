#include "gtest/gtest.h"
#include <Components/Data/AI/AINode.h>
#include <Components/Data/AI/BehaviorTreeValidator.h>

TEST(TreeBuildTest, when_one_node_is_added_as_child_parent_should_be_assigned)
{
    auto patent = new LeafNode([&](NodeInformation* info) { return true; }, [&](NodeInformation* info) { return; });
    auto child = new LeafNode([&](NodeInformation* info) { return true; }, [&](NodeInformation* info) { return; });

    patent->addChild(child);

    ASSERT_EQ(1, patent->get_children().size());
    ASSERT_TRUE(child->get_parent() != nullptr);
}

TEST(TreeBuildTest, when_two_node_is_added_as_child_parent_should_be_assigned)
{
    auto patent = new LeafNode([&](NodeInformation* info) { return true; }, [&](NodeInformation* info) { return; });
    auto child1 = new LeafNode([&](NodeInformation* info) { return true; }, [&](NodeInformation* info) { return; });
    auto child2 = new LeafNode([&](NodeInformation* info) { return true; }, [&](NodeInformation* info) { return; });

    patent->addChild(child1);
    patent->addChild(child2);

    ASSERT_EQ(2, patent->get_children().size());
    ASSERT_TRUE(child1->get_parent() != nullptr);
    ASSERT_TRUE(child2->get_parent() != nullptr);
}

TEST(TreeBaseValidationTest, when_tree_dont_have_root_node_validation_will_fail)
{
    auto parent = new LeafNode([&](NodeInformation* info) { return true; }, [&](NodeInformation* info) { return; });
    auto child = new LeafNode([&](NodeInformation* info) { return true; }, [&](NodeInformation* info) { return; });
    parent->addChild(child);
    auto validator = new BehaviorTreeValidator();

    auto result = validator->validate(parent);

    ASSERT_FALSE(result);
}

TEST(TreeBaseValidationTest, when_tree_root_node_dont_have_childern_validation_will_fail)
{
    auto parent = new RootNode();

    auto validator = new BehaviorTreeValidator();

    auto result = validator->validate(parent);

    ASSERT_FALSE(result);
}

TEST(TreeBaseValidationTest, when_tree_root_node_have_at_least_one_child_validation_will_success)
{
    auto parent = new RootNode();
    auto child = new LeafNode([&](NodeInformation* info) { return true; }, [&](NodeInformation* info) { return; });
    parent->addChild(child);

    auto validator = new BehaviorTreeValidator();

    auto result = validator->validate(parent);

    ASSERT_TRUE(result);
}