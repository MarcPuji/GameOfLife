CC = g++
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses
OBJ = main.o database.o configuration_v2.o figure_insert.o 
DEPS =  configuration_v2.h include/database.h include/figure_insert.h 
DEPS2 = include/database.h include/figure_insert.h 

main.o: main.c configuration_v2.h include/database.h
	$(CC) $(CFLAGS) -c -o $@ $<

configuration_v2.o: configuration_v2.c $(DEPS2)
	$(CC) $(CFLAGS) -c -o $@ $<

figure_insert.o: include/figure_insert.c include/database.h
	$(CC) $(CFLAGS) -c -o $@ $<

database.o: include/database.c
	$(CC) $(CFLAGS) -c -o $@ $<

gameoflife: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ) gameoflife

