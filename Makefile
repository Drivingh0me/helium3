PROJECT_NAME := helium3

SRC_DIR := src
BUILD_DIR := build
INCLUDE := include
# LIB := lib

# Platform specific search for headers and libraries.
OS := $(shell uname -s)

ifeq ($(OS), Linux)
OS_INCLUDE := /opt/apt/
endif

ifeq ($(OS), Darwin) # Darwin is MacOS.
OS_INCLUDE := /opt/homebrew/include
endif

ifeq ($(OS), Windows) # 64 bit only.
OS_INCLUDE := /path
endif

GSL_I := /usr/local/include
GSL_L := /usr/local/lib

CC := gcc
CFLAGS := -Wall -Wextra -lgsl -I$(INCLUDE) -I$(OS_INCLUDE) -I$(GSL_I) -L$(GSL_L)

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

all: $(BUILD_DIR)/$(PROJECT_NAME)

$(BUILD_DIR)/$(PROJECT_NAME): $(OBJS)
	$(CC) $(OBJS) -o $(BUILD_DIR)/$(PROJECT_NAME) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -r $(BUILD_DIR)/*

exec: $(BUILD_DIR)/$(PROJECT_NAME)
	./$(BUILD_DIR)/$(PROJECT_NAME)

.PHONY: all clean exec
