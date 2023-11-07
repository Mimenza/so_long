/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:59:07 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/07 11:22:47 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

/* Any function that you hook with the key event must be like this:
* Recibing and int for the code of the key pressed
* and a void pointer in case you need to recibe someting */
int	ft_input(int key, void *param)
{
	t_program *program = (t_program *)param;

	// mlx function that clears the window
	mlx_clear_window(program->mlx, program->window.reference);

	// move in a direction based on the key
	if (key == KEY_RIGHT)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == KEY_LEFT)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == KEY_DOWN)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == KEY_UP)
		program->sprite_position.y -= program->sprite.size.y;
	else if (key == KEY_ESC)
	{
		mlx_destroy_window(program->mlx,program->window.reference);
		ft_close();
	}

	// mlx function that puts and image into a window at a given position
	// (the position 0,0 is the upper-left corner)
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);

	// print the key pressed so you know the number of each key
	printf("Key pressed -> %d\n", key);
	return (0);
}

int	ft_update (void *param)
{
	t_program	*program = (t_program *)param;
	// a static that saves how many frames have passed
	static int	frame;

	// add a frame and every x frames change the position by 1 pixel
	// so it looks like its animated
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_position.y += 1;
	// every x*2 frames go back that pixel to loop the animation
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}
	
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);

	return (0);
}