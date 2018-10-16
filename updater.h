

typedef struct{
  int alive;
  int pos_x;
  int pos_y;
  int neighbours;
} cell;

void neighbours(struct, int);
void plotter(int, int, int);
void updater(struct, int);
