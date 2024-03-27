# **miniRT**

## :speech_balloon: **About**
MiniRT is a collaborative project that serves as an introduction to the captivating world of Raytracing.
It's about rendering simple Computer-Generated-Images using the ray-tracing technique. 
It simulates light behavior by tracing rays from the camera's eye to the scene and from object intersection points to lights.
This method enables lifelike images by accurately modeling how light interacts with surfaces and environments.
The project is coded in C, utilizing the mlx library.

## 🙋‍♀️ **Authorship**

- [Bruno Camarinha](https://github.com/bcamarinha92)
- [Rita Marques](https://github.com/rimarque)

## :inbox_tray: **Cloning the repository**

```shell
git clone git@github.com:rimarque/minirt.git 
```

## 💎 **Features**
```
- Scene file parser
- Display of planes, spheres and cylinders
- Ambient and diffuse lighting
- Shadows
- Camera rotation and translation
- Object rotation, translation and resize
- Light translation
```
<tbody>
		<tr>
			<td><image src="img/temple_translatedlight.png"></td>
   	</tr>
  </tbody>

## :link: **Compilation**
To compile the program you should run `make`.

This rule will generate an executable file named `miniRT`. To launch the executable you should follow this syntax:

```sh
$ ./minirt ./scenes/mandatory/scene_name.rt
```
Or, if you have your own scenes you want to render:

```sh
$ ./minirt ./path_to_scene/scene_name.rt
```

## :clapper: **Use the keyboard to change the scene**

### 🚦 **Select mode**
- The program's default mode is camera mode, use the keyboard to translate or rotate the camera
- The movement of the camera is relative to its axes
- Press **L** for light mode, use the keys to translate the light (press again to deactivate)
- Press **TAB** to cycle through objects, use the keyboard to translate, rotate or resize the selected object
- If there are no more objects to select, pressing **TAB** will take you back to camera mode
- The movement of light and objects is relative to real-world axes

### 🚗 **Translation**
- **W** - foward
- **S** - backward
- **A** - left
- **D** - right
- **SHIFT_LEFT** - up
- **CTRL_LEFT** - down

### :carousel_horse: **Rotation**
- ⬆️ rotate along the x axis up
- ⬇️ rotate along the x axis down
- ➡️ rotate along the y axis to the right
- ⬇️ rotate along the y axis to the left
- **SHIFT_RIGHT** - rotate along the z axis clockwise
- **CTRL_RIGHT** - rotate along the z axis counterclockwise

### :straight_ruler: **Resize**
- **H** - activates height mode, if not pressed the diameter is the default mesure to be resized (press again to deactivate)
- **+** - Increses object size
- **-** - Decreses object size

⚠️ **Note**: directions are relative to the camera's axes, with object and light movements potentially differing if the camera's view is not (0,0,-1).
