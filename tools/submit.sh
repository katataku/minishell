#!/bin/bash

SRC_DIR=$PWD
TARGET_DIR=$PWD/submit

make -C "$SRC_DIR" fclean
make -C "$SRC_DIR"/libft fclean
cp -r "$SRC_DIR"/includes "$TARGET_DIR"
cp -r "$SRC_DIR"/libft "$TARGET_DIR"
cp -r "$SRC_DIR"/*.c "$TARGET_DIR"
cp -r "$SRC_DIR"/srcs "$TARGET_DIR"
cp -r "$SRC_DIR"/.gitignore "$TARGET_DIR"
sed -n "/# DELETE #/q;p" "$SRC_DIR"/Makefile > "$TARGET_DIR"/Makefile
