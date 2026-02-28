PROJECT_NAME := helium3

SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

# Platform specific search for headers and libraries.
OS := $(shell uname -s)

ifeq ($(OS), Linux)
OS_INCLUDE_DIR := /opt/homebrew/opt/glfw/include
endif

ifeq ($(OS), Darwin) # Darwin is MacOS.
OS_INCLUDE_DIR := /opt/homebrew/opt/glfw/include
endif

ifeq ($(OS), Windows) # 64 bit only.
OS_INCLUDE_DIR := /opt/homebrew/opt/glfw/include
endif

GSL := -I/opt/homebrew/opt/gsl/include -lgsl -lgslcblas -lm

CC := gcc
CFLAGS := -Wall -Wextra -I$(INCLUDE_DIR) -I$(OS_INCLUDE_DIR) $(GSL)

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

all: $(BUILD_DIR)/$(PROJECT_NAME)

$(BUILD_DIR)/$(PROJECT_NAME): $(OBJS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(OBJS) -o $(BUILD_DIR)/$(PROJECT_NAME) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -r $(BUILD_DIR)/*

exec: $(BUILD_DIR)/$(PROJECT_NAME)
	./$(BUILD_DIR)/$(PROJECT_NAME)

.PHONY: all clean exec
