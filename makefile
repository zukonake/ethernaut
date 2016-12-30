SOURCE_PATH := src/
BUILD_PATH := build/
OBJ_PATH := $(BUILD_PATH)obj/
TARGET_PATH := ethernaut
SOURCES := $(shell find $(SOURCE_PATH) -type f -name "*.cpp" -printf '%p ')
HEADERS := $(shell find $(SOURCE_PATH) -type f -name "*.hpp" -printf '%p ')
OBJS := $(addprefix $(OBJ_PATH),$(patsubst %.cpp,%.o,$(shell find $(SOURCE_PATH) -type f -name "*.cpp" -exec basename {} \;)))
DEBUG := -g -O0
STD := -std=c++14
LDLIBS := -lboost_filesystem -lboost_system -lsfml-window -lsfml-graphics -lsfml-system -llua5.2 -lluapp
INCFLAGS := -I include -I src
LIBFLAGS := -L lib -L /usr/lib
CXXFLAGS := $(STD) -Wall $(DEBUG) $(INCFLAGS)
LDFLAGS := $(STD) -Wall $(LDLIBS) $(DEBUG) $(INCFLAGS) $(LIBFLAGS)
COMPILER := g++

.PHONY : clean run

$(TARGET_PATH) : $(OBJS)
	$(COMPILER) $(LDFLAGS) $(OBJS) -o $@

.SECONDEXPANSION:
$(OBJ_PATH)%.o : $$(shell find $(SOURCE_PATH) -type f -name %.cpp)
	@mkdir -p $(BUILD_PATH)
	@mkdir -p $(OBJ_PATH)
	$(COMPILER) $(CXXFLAGS) -c $< -o $@
	$(COMPILER) -MM $(CXXFLAGS) $< > $(BUILD_PATH)$*.d
	@sed -i '1s/^/build\/obj\//' $(BUILD_PATH)$*.d

clean :
	$(RM) -r $(BUILD_PATH) *~ bin $(TARGET_PATH) vgcore.* callgrind.out.*

run : $(TARGET_PATH)
	./$(TARGET_PATH)

-include $(shell find $(BUILD_PATH) -type f -name "*.d" -printf '%p ')
