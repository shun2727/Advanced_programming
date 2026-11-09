CXX := g++
CXXFLAGS := -std=c++20
CPPFLAGS := -IIncludes

TARGET := event_management_system
BUILD_DIR := build

SRCS := \
	Main/driver.cpp \
	ClassSources/Event.cpp \
	ClassSources/Participant.cpp \
	ClassSources/Registration.cpp \
	ClassSources/MainData.cpp \
	Sources/GenerateReport.cpp \
	Sources/HelperFunctions.cpp \
	Sources/ManageRegistraions.cpp \
	Sources/MenuFeatures.cpp

OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

fclean: clean

re: clean all

.PHONY: all clean fclean re