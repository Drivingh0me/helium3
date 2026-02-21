PROJECT_NAME := helium3

SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

# Platform specific search for headers and libraries.
OS := $(shell uname -s)

ifeq ($(OS), Linux)
GLFW_INCLUDE_DIR := /opt/homebrew/opt/glfw/include
GLFW_LIB_DIR := /opt/homebrew/opt/glfw/lib
CGLM_INCLUDE_DIR := /opt/homebrew/opt/cglm/include/cglm
endif

ifeq ($(OS), Darwin) # Darwin is MacOS.
GLFW_INCLUDE_DIR := /opt/homebrew/opt/glfw/include
GLFW_LIB_DIR := /opt/homebrew/opt/glfw/lib
CGLM_INCLUDE_DIR := /opt/homebrew/opt/cglm/include/cglm
endif

ifeq ($(OS), Windows) # 64 bit only.
GLFW_INCLUDE_DIR := /opt/homebrew/opt/glfw/include
GLFW_LIB_DIR := /opt/homebrew/opt/glfw/lib
CGLM_INCLUDE_DIR := /opt/homebrew/opt/cglm/include/cglm
endif

# To include sokol, unhash the line below this and add the line below
# that to CFLAGS.
#SOKOL_INCLUDE_DIR := /Users/calebgriffin/sokol/include  
#-I$(SOKOL_INCLUDE_DIR)


CC := gcc
CFLAGS := -Wall -Wextra -I$(INCLUDE_DIR) -I$(GLFW_INCLUDE_DIR)
LDFLAGS := -L$(GLFW_LIB_DIR) -lglfw -ldl -framework OpenGL -framework Cocoa

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
