cmake_minimum_required(VERSION 3.10)
project(pim_4)

set(CMAKE_C_STANDARD 99)

include_directories(include)

set(SOURCE_FILES src/main.c src/industria.c src/usuario.c src/relatorio.c)

add_executable(pim_4 ${SOURCE_FILES})

set(TEST_FILES tests/test_usuario.c tests/test_industria.c)

add_executable(test_usuario ${TEST_FILES} src/industria.c src/usuario.c src/relatorio.c)
add_executable(test_industria ${TEST_FILES} src/industria.c src/usuario.c src/relatorio.c)

target_link_libraries(pim_4 kernel32 user32 gdi32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32)
target_link_libraries(test_usuario kernel32 user32 gdi32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32)
target_link_libraries(test_industria kernel32 user32 gdi32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32)
