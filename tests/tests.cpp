#include <gtest/gtest.h>
#include "circ_buf.h"

// Тест для конструктора по умолчанию
TEST(CircularBufferTest, DefaultConstructor) {
    CircularBuffer cb;
    EXPECT_EQ(cb.size(), 0);
    EXPECT_EQ(cb.capacity(), 1);
    EXPECT_TRUE(cb.empty());
}

// Тест для конструктора с заданной емкостью
TEST(CircularBufferTest, ConstructorWithCapacity) {
    CircularBuffer cb(5);
    EXPECT_EQ(cb.size(), 0);
    EXPECT_EQ(cb.capacity(), 5);
    EXPECT_TRUE(cb.empty());
}

// Тест для метода push_back
TEST(CircularBufferTest, PushBack) {
    CircularBuffer cb(3);
    cb.push_back(1);
    cb.push_back(2);
    cb.push_back(3);
    EXPECT_EQ(cb.size(), 3);
    EXPECT_EQ(cb.front(), 1);
    EXPECT_EQ(cb.back(), 3);
}

// Тест для метода push_front
TEST(CircularBufferTest, PushFront) {
    CircularBuffer cb(3);
    cb.push_front(1);
    cb.push_front(2);
    cb.push_front(3);
    EXPECT_EQ(cb.size(), 3);
    EXPECT_EQ(cb.front(), 3);
    EXPECT_EQ(cb.back(), 1);
}

// Тест для метода pop_back
TEST(CircularBufferTest, PopBack) {
    CircularBuffer cb(3);
    cb.push_back(1);
    cb.push_back(2);
    cb.pop_back();
    EXPECT_EQ(cb.size(), 1);
    EXPECT_EQ(cb.front(), 1);
    EXPECT_EQ(cb.back(), 1);
}

// Тест для метода pop_front
TEST(CircularBufferTest, PopFront) {
    CircularBuffer cb(3);
    cb.push_back(1);
    cb.push_back(2);
    cb.pop_front();
    EXPECT_EQ(cb.size(), 1);
    EXPECT_EQ(cb.front(), 2);
    EXPECT_EQ(cb.back(), 2);
}

// Тест для метода at
TEST(CircularBufferTest, At) {
    CircularBuffer cb(3);
    cb.push_back(1);
    cb.push_back(2);
    EXPECT_EQ(cb.at(0), 1);
    EXPECT_EQ(cb.at(1), 2);
    EXPECT_THROW(cb.at(3), std::out_of_range);
}

// Тест для оператора присваивания
TEST(CircularBufferTest, AssignmentOperator) {
    CircularBuffer cb1(3);
    cb1.push_back('1');
    cb1.push_back('2');

    CircularBuffer cb2;
    cb2 = cb1;

    EXPECT_EQ(cb2.size(), 2);
    EXPECT_EQ(cb2.front(), '1');
    EXPECT_EQ(cb2.back(), '2');
}

// Тест для копирующего конструктора
TEST(CircularBufferTest, CopyConstructor) {
    CircularBuffer cb1(3);
    cb1.push_back('1');
    cb1.push_back('2');

    CircularBuffer cb2(cb1);
    EXPECT_EQ(cb2.size(), 2);
    EXPECT_EQ(cb2.front(), '1');
    EXPECT_EQ(cb2.back(), '2');
}

// Тест для конструктора перемещения
TEST(CircularBufferTest, MoveConstructor) {
    CircularBuffer cb1(3);
    cb1.push_back('1');
    cb1.push_back('2');

    CircularBuffer cb2(std::move(cb1));
    EXPECT_EQ(cb2.size(), 2);
    EXPECT_EQ(cb2.front(), '1');
    EXPECT_EQ(cb2.back(), '2');
    EXPECT_EQ(cb1.size(), 0);
}

// Главная функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}