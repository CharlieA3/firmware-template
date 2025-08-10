cmake_minimum_required(VERSION 3.22)
# set(BOARD plaitpilot)
set(BOARD_ROOT /home/charlie/generate-firmware)
# set(ZEPHYR_BASE /home/charlie/generate-firmware)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(plaitpilot_app)

target_sources(plaitpilot_app PRIVATE src/main.c)
