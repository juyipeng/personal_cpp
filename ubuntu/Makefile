CC = g++
TARGET = test
SRCS = ${wildcard *.cpp}
OBJS = ${SRCS:%.cpp=%.o}

CFLAGS = -g -Wall

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
