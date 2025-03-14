/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:45:06 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/14 16:16:37 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	draw_on_image(t_scene_data *data, mlx_image_t *img)
{
	int			i;
	int			j;
	uint32_t	col = col_rgb(data->ambient->col_r, data->ambient->col_g, data->ambient->col_b, 0xFF);

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mlx_put_pixel(img, i, j, col);
			j ++;
		}
		i ++;
	}
}

void	render_scene(t_scene_data *data)
{
	t_window_data	window_data;

	(void)data;
	window_data.mlx_window = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (!window_data.mlx_window)
		fatal_error(ERR_WINDOW, &window_data);
	window_data.mlx_image = mlx_new_image(window_data.mlx_window, WIDTH, HEIGHT);
	if (!window_data.mlx_image)
		fatal_error(ERR_IMAGE, &window_data);
	window_data.image_data = (unsigned char *)window_data.mlx_image->pixels;
	if (!window_data.image_data)
		fatal_error(ERR_DATA, &window_data);
	draw_on_image(data, window_data.mlx_image);
	mlx_image_to_window(window_data.mlx_window, window_data.mlx_image, 0, 0);
	mlx_key_hook(window_data.mlx_window, &escape_key, window_data.mlx_window);
	mlx_loop(window_data.mlx_window);
	clean_exit(EXIT_SUCCESS, &window_data);
}
