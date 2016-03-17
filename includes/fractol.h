/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:06:29 by pbie              #+#    #+#             */
/*   Updated: 2016/03/17 11:45:11 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_X 800
# define WIN_Y 600
# define UP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define MINUS1 27
# define PLUS1 24
# define MINUS2 78
# define PLUS2 69
# define ESC_KEY 53
# define PAGE_UP 116
# define PAGE_DOWN 121
# define HOME 115
# define END 119
# define ENTER 76
# define RETURN 36
# define ONE1 18
# define ONE2 83
# define TWO1 19
# define TWO2 84
# define THREE1 20
# define THREE2 85
# define HOLD 4
# define HELLO "Fractol by pbie"
# define START "Continue by pressing any key"
# define L_CONTROLS "             CONTROLS"
# define L_UP "  Move Up       ||     Up"
# define L_DOWN "  Move Down     ||     Down"
# define L_LEFT "  Move Left     ||     Left"
# define L_RIGHT "  Move Right    ||     Right"
# define L_PLUS "  Zoom In       ||     +"
# define L_MINUS "  Zoom Out      ||     -"
# define L_PAGE_UP "  Increase      ||     Page Up"
# define L_PAGE_DOWN "  Decrease      ||     Page Down"
# define L_HOME "  Psychadelic   ||     Home"
# define L_RESET "  Reset         ||     Enter"
# define L_ESC "  Exit          ||     Esc"
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASE 3
# define KEYRELEASEMASK (1L<<1)
# define MOTIONNOTIFY 6
# define POINTERMOTIONMASK (1L<<6)

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*im;
	void			*imc;
	int				imlen;
	int				bpp;
	int				endi;
	char			*argv;
	int				i;
	int				x;
	int				y;
	float			x1;
	float			y1;
	float			x2;
	float			y2;
	int				max;
	int				im_x;
	int				im_y;
	float			z_r;
	float			z_i;
	float			c_r;
	float			c_i;
	float			tmp;
	float			zoom;
	float			zoom_x;
	float			zoom_y;
	int				itm;
	int				res;
	int				bj;
	float			tmpx;
	float			tmpy;
	float			tmpx2;
	float			tmpy2;
}					t_mlx;

void				ft_put_pixel(t_mlx *m, int x, int y, int color);
int					ft_keycore(t_mlx *m);
int					ft_key_binding(int keycode, t_mlx *m);
int					ft_key_release(int keycode, t_mlx *m);
void				ft_key_action(t_mlx *m);
int					ft_mouse_hook(int keycode, int x, int y, t_mlx *m);
void				ft_fractol_init(t_mlx *m);
void				ft_print_fractol(t_mlx *m);
void				ft_init_mandel(t_mlx *m);
void				ft_mandelbrot(t_mlx *m);
void				ft_init_julia(t_mlx *m);
void				ft_julia(t_mlx *m);
int					ft_julia_hook(int x, int y, t_mlx *m);
void				ft_init_mandelbralt(t_mlx *m);
void				ft_mandelbralt(t_mlx *m);

#endif
