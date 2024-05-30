# Создаем исполняемый файл для тестов
add_executable(my_tests tests.cpp)

# Связываем тесты с библиотекой проекта и Google Test
target_link_libraries(my_tests my_project gtest gtest_main)

# Добавляем тесты
add_test(NAME MyTests COMMAND my_tests)