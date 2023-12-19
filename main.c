/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:58:05 by rita              #+#    #+#             */
/*   Updated: 2023/12/19 21:48:15 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int main(int argc, char **argv)
{
    t_win   minirita;

    (void) argc;
    (void) argv;
    minirita = new_program(1280,700, "minirita");
    mlx_hook(minirita.win_ptr, 17, 0L, &close_window, (void *)&minirita);
    mlx_key_hook(minirita.win_ptr, handle_key_event, &minirita);
    mlx_loop(minirita.mlx_ptr);
}