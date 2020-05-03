SRC = functions.o program.o
TARGET = railway

all: $(TARGET)

program.o: program.cpp
	gcc program.cpp -c -o program.o

functions.o: functions.cpp
	gcc functions.cpp -c -o functions.o

$(TARGET): $(SRC)
	gcc $(SRC) -o $(TARGET)

install:
	install $(TARGET) ~/forProgramm

clean:
	rm -rf $(SRC)
