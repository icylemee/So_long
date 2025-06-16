
#define _GNU_SOURCE
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


#include <math.h>

#define LEFT_CLICK     1
#define RIGHT_CLICK    3
#define MIDDLE_CLICK   2
#define SCROLL_UP      4
#define SCROLL_DOWN    5


typedef struct	s_vars {
	void	*mlx;
	void	*win;
    int     k;
    int     lastkey;
    int     keyok;
    int     keyup;
    int xinit;
    int yinit;
    int coord;
    int okbutton;
    int lastbutton;
    int angle;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


int hello_mouse(int x, int y, void *param)
{
    (void)param;
    write(1, "Salut !", 7);
    return 0;
}


int bye_mouse(int x, int y, void *param)
{
    (void)param;
    write(1, "Bye !", 5);
    return 0;
}

int cross_close(void *param)
{
    t_vars *vars;

    vars = (t_vars *)param;
    mlx_destroy_window(vars->mlx, vars->win);
    exit (0);
    return 0;
}
int keydown(int keycode, void *param)
{
    t_vars *vars;

    vars = (t_vars *)param;

    if (keycode == 65307)
    { 
        write(1, "ESC PRESSED, BYE\n", 17);
        mlx_destroy_window(vars->mlx, vars ->win);
        exit (0);
    }
    if (keycode == vars->lastkey)
        vars->k += 1;
    else if (keycode != vars->lastkey)
    {
        vars->k = 0;
    }
    if (vars->k > 40 && !vars->keyok)
    {
        printf("touche %d appuyee longtemps\n", keycode);
        vars->keyok = 1;
    }
    vars->lastkey = keycode;
    return 0;
}

int mouse_move(int x, int y, void *param)
{
    t_vars *vars;
    vars = (t_vars *)param;

    //  printf("MOVE IN IN \n\n");
    // printf("Position curseur : x = %d, y = %d\n", x, y);
    if (vars->coord)
    {
        //  printf("CALCUL IN\n\n");
        if (y == vars->yinit && x == vars->xinit)
            vars->angle = 0;
        else 
            vars->angle = atan2(y - vars->yinit, x - vars->xinit) * (180.0/M_PI);
    }
    return 0;
}

int mouse_click(int button, int x, int y, void *param)
{
    t_vars *vars;
    vars = (t_vars*)param;

    // printf("CLICK CLICK IN\n\n");
    if (!vars->coord)
    {
        vars->xinit = x;
        vars->yinit = y;
        vars->angle = 0;
        // printf("CLICK IN X = %d et Y = %d\n\n", vars->xinit, vars->yinit);
        vars->coord = 1;
        vars->lastbutton = button;
    }
    if (button == vars->lastbutton)
        vars->okbutton = 1;
    else 
        vars->okbutton = 0;
    return 0;
}

int mouse_release (int button, int x, int y, void *param)
{
    t_vars *vars;
    vars = (t_vars*)param;

    
    // printf("RELEASE IN\n\n");
    // printf("coord = %d, button = %d et lastbutton = %d\n\n", vars->coord, button, vars->lastbutton);
    if (vars->coord && button == vars->lastbutton)
    {
        printf("l'angle est : %d\n", vars->angle);
    }
    vars->coord = 0;
    return 0;
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void draw_line(t_data *img, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int x = x0;
    int y = y0;
    
    for(int i = 0; i < dx; i++)
    {
        my_mlx_pixel_put(img, x++, y, color);
    }
}

void draw_rectangle(t_data *img, int x, int y ,int width, int larg, int color)
{
    for (int i = x; i < x + width; i++)
    {
        for (int j = y; j < y + larg; j++)
        {
            my_mlx_pixel_put(img, i, j, color);
        }
    }
}

void draw_circle(t_data *img, int x0, int y0, int radius, int color)
{
    double angle;
    int x, y;
    
    // On parcourt tous les angles de 0 à 2π
    for (angle = 0; angle < 2 * M_PI; angle += 0.01)
    {
        // Calcul des coordonnées x et y pour chaque point du cercle
        x = x0 + (radius * cos(angle));
        y = y0 + (radius * sin(angle));
        
        // On dessine le pixel si les coordonnées sont dans la fenêtre
        if (x >= 0 && y >= 0 && x < 500 && y < 500)
            my_mlx_pixel_put(img, x, y, color);
    }
}

int	main(void)
{
	t_vars vars;
    t_data img;

    int i = 1;

    vars.k = 0;
    vars.lastkey = 0;
    vars.keyok = 0;
    vars.keyup = 0;
    vars.xinit = 0;
    vars.yinit = 0;
    vars.coord = 0;
    vars.okbutton = 0;
    vars.lastbutton = 0;
    vars.angle = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "tests");

    img.img = mlx_new_image(vars.mlx, 500, 500);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    // my_mlx_pixel_put(&img ,150, 150, 0x00FF0000);
    draw_line(&img, 15, 50, 450, 480, 0x00FF0000);
    draw_rectangle(&img, 150, 150, 250, 250, 0x00FF0000);
    draw_circle(&img, 50, 60, 25, 0x00FF0000);

    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0,0);

    mlx_hook(vars.win, 7, (1L<<4), hello_mouse, NULL); //print qund mouse rentre dans window
    mlx_hook(vars.win, 8, (1L<<5), bye_mouse, NULL); //  print quand mopuse quitte win

    mlx_hook(vars.win, 2, (1L<<0), keydown, &vars);

    mlx_hook(vars.win, 17, (1L<<17), cross_close, &vars);

    
    mlx_hook(vars.win, 4, (1L<<2), mouse_click, &vars);
    mlx_hook(vars.win, 6, (1L<<6), mouse_move, &vars);
    mlx_hook(vars.win, 5, (1L<<3), mouse_release, &vars);



    mlx_loop(vars.mlx);
}
