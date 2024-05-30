cmake_minimum_required(VERSION 3.10)
project(Task_1_UPPRO)

# Добавляем поддиректорию с Google Test
add_subdirectory(googletest)

# Указываем директории с заголовочными файлами и исходниками
include_directories(include)
add_subdirectory(src)
add_subdirectory(tests)

# Включаем тестирование
enable_testing()