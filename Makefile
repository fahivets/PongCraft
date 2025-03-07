NAME = PongCraft

SRC     := 	main.cpp \
			Display.cpp \
			Input.cpp \
			Block.cpp \
			Platform.cpp \
			Ball.cpp \
			GameObject.cpp \
			Game.cpp \
			DrawVisitor.cpp \
			Player.cpp \
			LeatherBag.cpp \
			PhysicsManager.cpp \
			AIPlayer.cpp \

OBJ     := $(SRC:.cpp=.o)

G++		:= g++ -stdlib=libc++ -arch x86_64 -std=c++14 \
			-I Frameworks/SDL2.framework/Versions/A/Headers \
			-F Frameworks/ \
			-I Frameworks/SDL2_ttf.framework/Versions/A/Headers \
			-F Frameworks/ \
			-I Frameworks/SDL2_image.framework/Versions/A/Headers \
			-F Frameworks/ \
			-I Frameworks/SDL2_mixer.framework/Versions/A/Headers \
			-F Frameworks/

#-Wall -Wextra -Werror <---!!!!

FLAGS 	:= -rpath Frameworks/ \
			-framework SDL2 \
			-framework SDL2_ttf \
			-framework SDL2_image \
			-framework SDL2_mixer

all: $(NAME)

$(NAME): $(OBJ)
	$(G++) $(OBJ) $(FLAGS) -o $(NAME)

%.o: %.cpp
	$(G++) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
