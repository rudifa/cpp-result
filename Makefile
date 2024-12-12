CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2
TARGET = main
SRC = main.cpp
BUILD_DIR = build
TARGET_PATH = $(BUILD_DIR)/$(TARGET)

all: $(TARGET_PATH)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET_PATH): $(SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET_PATH) $(SRC)

run: $(TARGET_PATH)
	./$(TARGET_PATH)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
