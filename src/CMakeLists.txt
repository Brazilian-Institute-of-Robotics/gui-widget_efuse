rock_library(efuse_board
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(efuse_board_bin Main.cpp
    DEPS efuse_board)

