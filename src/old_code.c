/* void	define_sc(t_scene *sc)
{
	t_cam cam;
	
	set_coords(sc->pl->point, 0, -1, 0);
	set_coords(sc->pl->normal, 5, 3, 1);
	set_coords(sc->pl->point, 0, -1, 0);
	set_coords(sc->sp->center, 0, 0, -30);
	sc->sp->d = 3;
	sc->cam->aspect = (float)WIN_H/WIN_W;
	sc->cam->fov_x = 1.0;
	set_coords(sc->cam->o, 5, 2, 1);
	set_coords(sc->cam->view, 4, 2, 1);
	sc->cam->axis = get_axis(sc->cam->view, sc->cam->o);
}

/* t_inter	inter_surface_old(t_ray ray, t_obj cy, )
{
	t_auxeq aux;
	
	if(!in_cy(ray, cy, &aux) || (aux.t1 < 0 && aux.t2 < 0)) //se nao interseta o cilindro infinito
		return(it.inter = false, it);
	aux.m1 = vec3_dot(ray.d, vec3_scale(cy.vec_inver, aux.t1)) + aux.dot_cov;
	aux.m2 = vec3_dot(ray.d, vec3_scale(cy.vec_inver, aux.t2)) + aux.dot_cov;
	if (aux.m1 < 0 || aux.m1 > cy.h && aux.m2 < 0 || aux.m2 > cy.h) //se nenhum dos pontos de intersecao esta nos limites da altura do cilindro
		return(it.inter = false, it);
	if (aux.m1 >= 0 && aux.m1 <= cy.h && aux.m2 >= 0 && aux.m2 <= cy.h) //se ambos os pontos de intersecao estao no cilindro
		it.t = closer_t(aux.in_sqrt, aux.t1, aux.t2);               
	else if (aux.m1 >= 0 && aux.m1 <= cy.h) //se apenas o m1 esta no cilindro
		it.t = aux.t1;
	else
		it.t = aux.t2;
	it.point = vec3_add(ray.o, vec3_scale(ray.d, it.t));
	it.normal = vec3_normalized(vec3_sub(it.point, vec3_add(cy.cap_c, vec3_scale(cy.vec_inver, aux.m)))); p - (c + v*m);
} */

/* 		if (it1.m < 0 || it1.m > cy.h && it2.m < 0 || it2.m > cy.h) //se nenhum dos pontos de intersecao esta nos limites da altura do cilindro
			return(it1.inter = false, it1);
		if (it1.m >= 0 && it1.m <= cy.h && it2.m >= 0 && it2.m <= cy.h) //se ambos os pontos de intersecao estao no cilindro
			it1 = closer_inter(it1, it2);               
		else if (it1.m >= 0 && it1.m <= cy.h) //se apenas o m1 esta no cilindro
			it1 = closer_inter(it1, it2);
		else
			it1 = closer_inter(it1, it2); */

/* t_matrix    get_cyaxis(t_vec3 normal, t_vec3 o)
{
    t_matrix  axis;
    t_vec3  up;

    set_coord(&up, 0, 1, 0);
    if(vec3_dot(up, view) == 1 || vec3_dot(up, view) == -1)
        set_coords(&up, 1, 0, 0);
    axis.o = o;
    axis.x = normal;
    axis.y = vec3_normalized(vec3_cross(up, axis.x));
    axis.z = vec3_normalized(vec3_cross(axis.x, axis.y));
    print_vec("O: ", axis.o);
    print_vec("X: ", axis.x);
    print_vec("Y: ", axis.y);
    print_vec("Z: ", axis.z);
    return(axis);
} */

/* void    set_color(t_rgb *color, uint8_t r, uint8_t g, uint8_t b)
{
    color->r = r;
    color->g = g;
    color->b = b;
} */

/* void	rotate_cam_down(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_neg);
	if(cam.normal.x == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_pos);
	if(cam.normal.y == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_pos);
	if(cam.normal.y == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_neg);
	if(cam.normal.z == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_pos);
	if(cam.normal.z == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_neg);
}

void	rotate_cam_right(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_neg);
	if(cam.normal.x == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_neg);
	if(cam.normal.y == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_neg);
	if(cam.normal.y == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_neg);
	if(cam.normal.z == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_neg);
	if(cam.normal.z == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_neg);
}

void	rotate_cam_left(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_pos);
	if(cam.normal.x == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_pos);
	if(cam.normal.y == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_pos);
	if(cam.normal.y == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_pos);
	if(cam.normal.z == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_pos);
	if(cam.normal.z == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_pos);
}

void	rot_cam_clockwise(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_pos);
	if(cam.normal.x == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_neg);
	if(cam.normal.y == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_pos);
	if(cam.normal.y == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_neg);
	if(cam.normal.z == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_pos);
	if(cam.normal.z == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_neg);
}

void	rot_cam_counterclock(t_img *img, t_cam cam)
{
	if(cam.normal.x == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_neg);
	if(cam.normal.x == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.x_pos);
	if(cam.normal.y == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_neg);
	if(cam.normal.y == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.y_pos);
	if(cam.normal.z == 1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_neg);
	if(cam.normal.z == -1)
		img->scene->cam->axis = rot_axis(img->scene->cam->axis, img->rotation.z_pos);
} */

/* t_rotation init_rot_matrix()
{
	t_rotation	rotation;

	rotation.x_pos = get_rotmatrix_x(ANG_ROT_POS);
	rotation.x_neg = get_rotmatrix_x(ANG_ROT_NEG);
	rotation.y_pos = get_rotmatrix_y(ANG_ROT_POS);
	rotation.y_neg = get_rotmatrix_y(ANG_ROT_NEG);
	rotation.z_pos = get_rotmatrix_z(ANG_ROT_POS);
	rotation.z_neg = get_rotmatrix_z(ANG_ROT_NEG);
	return(rotation);
} */