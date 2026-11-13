CFLAGS = -Wall -Wextra -Werror -std=c++20 -IIncludes
CC = g++

NAME = event_management_system
SRC = Main/driver.cpp \
	ClassSources/Event.cpp \
	ClassSources/Participant.cpp \
	ClassSources/Registration.cpp \
	ClassSources/MainData.cpp \
	Sources/GenerateReport.cpp \
	Sources/HelperFunctions.cpp \
	Sources/ManageRegistraions.cpp \
	Sources/MenuFeatures.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

all : $(NAME)

#how do we create the objects (by compiling with -c)
#create the .o by having it's .cpp counterpart
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#specify program, say what it depends on (object files) specify how to make object files from cpp files

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all

.PHONY : clean fclean re all
