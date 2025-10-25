#ifndef __FUNCTION_H__
#define __FUNCTION_H__




struct s_pos 
{
    int x;
    int y;
};

typedef struct s_pos position;

char * extract_grid(FILE * fp);
void construct_grid(char **grille);
void print_grid(char**grille);
void start_position_player(char ** grille, position * pos);
void position_arr(char ** grille, position * pos);
void start_position_box(char ** grille, position * pos);
void déplacement(char ** grille, position * pos, position * box);
int win(position * box, position * end);

#endif