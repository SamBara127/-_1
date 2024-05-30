# Указываем исполняемые файлы
add_library(my_project
    circ_buf.cpp
    Laboratory_2.cpp
)

target_include_directories(my_project PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)