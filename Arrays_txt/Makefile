CC = g++
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses
OBJ = main.o updater.o configuration_arr.o figure_insert.o
DEPS = updater.h include/cellstruct.h include/configuration_arr.h include/figure_insert.h
DEPS2 = include/cellstruct.h include/figure_insert.h

main.o: main.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

configuration_arr.o: include/configuration_arr.c $(DEPS2)
	$(CC) $(CFLAGS) -c -o $@ $<

figure_insert.o: include/figure_insert.c include/cellstruct.h
	$(CC) $(CFLAGS) -c -o $@ $<

updater.o: updater.c include/cellstruct.h
	$(CC) $(CFLAGS) -c -o $@ $<

gameoflife: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ) gameoflife
