/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:46:06 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/07 11:13:58 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int main()
{
	// ----------

	// Struct with all the info that I need to run the program (mlx_sample.h)
	t_program program;
	// mlx function that initialize the mlx and returns a pointer to it.
	program.mlx = mlx_init();
	// Open a window (window.c whitin this project)
	program.window = ft_new_window(program.mlx, 1980, 1080, "JUEGAZO");

	// ----------

	// Create a new image/sprite (image.c)
	program.sprite = ft_new_sprite(program.mlx, "./textures/block.xpm");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;
	// mlx function that draws an image into a window at the given position
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x, program.sprite_position.y);

	// ----------

	// hook the input() (hooks.c) function to the the key pressed event
	mlx_key_hook(program.window.reference, *ft_input, &program);
	// hook a function to the loop (it would be called each frame)
	mlx_loop_hook(program.mlx, *ft_update, &program);

	// ----------

	// mlx constant loop that keeps the detects the events
	mlx_loop(program.mlx);
}
