#include <gtest/gtest.h>
#include "EventTestData.h"

TEST(ParameterlessEventHandler, subscriber_react_to_publisher_event_invoke)
{
    //Arrange
    auto publisher = new TestParameterlessPublisher();
    auto subscriber = new TestParameterlessSubscriber(publisher);
    
    //Act
    publisher->trigger();
    
    //Assert
    ASSERT_EQ(1, subscriber->counter);
}

TEST(ParameterlessEventHandler, when_subscriber_is_unsubscibed_publisher_trigger_has_no_effect )
{
    //Arrange
    auto publisher = new TestParameterlessPublisher();
    auto subscriber = new TestParameterlessSubscriber(publisher);
    subscriber->clearUnsubscribe();
    
    //Act
    publisher->trigger();
    
    //Assert
    ASSERT_EQ(0, subscriber->counter);
}

TEST(ParameterlessEventHandler, multiple_publiser_can_affect_one_subscriber)
{
    //Arrange
    auto publisher1 = new TestParameterlessPublisher();
    auto publisher2 = new TestParameterlessPublisher();
    auto subscriber = new TestParameterlessSubscriberWithList();
    subscriber->addPublisher(publisher1);
    subscriber->addPublisher(publisher2);
    
    //Act
    publisher1->trigger();
    publisher2->trigger();
    
    //Assert
    ASSERT_EQ(2, subscriber->counter);
}

TEST(ParameterlessEventHandler, multiple_publiser_not_affect_one_subscriber_if_cleared)
{
    //Arrange
    auto publisher1 = new TestParameterlessPublisher();
    auto publisher2 = new TestParameterlessPublisher();
    auto subscriber = new TestParameterlessSubscriberWithList();
    subscriber->addPublisher(publisher1);
    subscriber->addPublisher(publisher2);
    
    ////Act
    subscriber->clearUnsubscribe();
    publisher1->trigger();
    publisher2->trigger();
    
    //Assert
    ASSERT_EQ(0, subscriber->counter);
}

TEST(ParameterlessEventHandler, all_subscribers_react_to_publisher_event_invoke)
{
    //Arrange
    auto publisher = new TestParameterlessPublisher();
    auto subscriber1 = new TestParameterlessSubscriber(publisher);
    auto subscriber2 = new TestParameterlessSubscriber(publisher);
    
    //Act
    publisher->trigger();
    
    //Assert
    ASSERT_EQ(1, subscriber1->counter);
    ASSERT_EQ(1, subscriber2->counter);
}

TEST(ParameterEventHandler, subscriber_react_to_publisher_event_with_param_invoke)
{
    //Arrange
    auto publisher = new TestParameterPublisher();
    auto subscriber = new TestParameterSubscriber(publisher);

    //Act
    publisher->trigger();
    //Assert
    ASSERT_EQ("Test", subscriber->name);
}

TEST(ParameterEventHandler, when_subscriber_is_unsubscibed_publisher_trigger_with_param_has_no_effect)
{
    //Arrange
    auto publisher = new TestParameterPublisher();
    auto subscriber = new TestParameterSubscriber(publisher);
    subscriber->clearUnsubscribe();
    
    //Act
    publisher->trigger();
    
    //Assert
    ASSERT_EQ("", subscriber->name);
}

TEST(ParameterEventHandler, all_subscribers_react_to_publisher_event_invoke)
{
    //Arrange
    auto publisher = new TestParameterPublisher();
    auto subscriber1 = new TestParameterSubscriber(publisher);
    auto subscriber2 = new TestParameterSubscriber(publisher);
    
    //Act
    publisher->trigger();
    
    //Assert
    ASSERT_EQ("Test", subscriber1->name);
    ASSERT_EQ("Test", subscriber2->name);
}


TEST(ParameterEventHandler, multiple_publiser_can_affect_one_subscriber)
{
    //Arrange
    auto publisher1 = new TestParameterPublisher();
    auto publisher2 = new TestParameterPublisher();
    auto subscriber = new TestParameterSubscriberWithList();
    subscriber->addPublisher(publisher1);
    subscriber->addPublisher(publisher2);
   
    //Act
    publisher1->trigger();
    publisher2->trigger();
    
    //Assert
    ASSERT_EQ("Test_1", subscriber->names[0]);
    ASSERT_EQ("Test_2", subscriber->names[1]);
}

TEST(ParameterEventHandler, multiple_publiser_not_affect_one_subscriber_if_cleared)
{
    //Arrange
    auto publisher1 = new TestParameterPublisher();
    auto publisher2 = new TestParameterPublisher();
    auto subscriber = new TestParameterSubscriberWithList();
    subscriber->addPublisher(publisher1);
    subscriber->addPublisher(publisher2);

    ////Act
    subscriber->clearUnsubscribe();
    publisher1->trigger();
    publisher2->trigger();

    //Assert
    ASSERT_EQ(0, subscriber->names.size());
}