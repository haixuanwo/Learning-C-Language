# --- 变量定义 ---
CC       := gcc
CFLAGS   := -Wall -Wextra -g -Iinclude
TARGET   := my_program
BUILD_DIR := build
SRC_DIR   := src

# 1. 递归查找所有 .c 文件 (find 命令是处理递归最可靠的方式)
SRCS := $(shell find $(SRC_DIR) -name "*.c")

# 2. 将 src/path/file.c 转换为 build/path/file.o
# 这样可以保持 build 目录与 src 目录结构一致，避免同名文件冲突
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# 3. 提取所有需要的子目录路径
OBJ_DIRS := $(sort $(dir $(OBJS)))

# --- 核心规则 ---

all: $(TARGET)

# 链接目标文件
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
	@echo "Build successful: $(TARGET)"

# 编译模式规则
# $(BUILD_DIR)/%.o 对应 $(SRC_DIR)/%.c
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

# 4. 自动创建编译所需的目录结构
$(OBJ_DIRS):
	mkdir -p $@

# --- 辅助功能 ---

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	@echo "Cleaned up."

.PHONY: all clean