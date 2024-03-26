# **miniRT**

## **About**
MiniRT is a collaborative project that serves as an introduction to the captivating world of Raytracing.
It's about rendering simple Computer-Generated-Images using the ray-tracing technique. 
It simulates light behavior by tracing rays from the camera's eye to the scene and from object intersection points to lights.
This method enables lifelike images by accurately modeling how light interacts with surfaces and environments.
The project is coded in C, utilizing the mlx library.

## **Authorship**

- [Bruno Camarinha](https://github.com/bcamarinha92)
- [Rita Marques](https://github.com/rimarque)

## **Cloning the repository**

```shell
git clone https://github.com/maricard18/42-miniRT.git 
```

## **Features**
```
- Scene file parser
- Display of planes, spheres and cylinders
- Ambient and diffuse lighting
- Shadows
- Camera rotation and translation
- Objects rotation, translation and resize
- Light translation
```

## **Compilation**
To compile the mandatory part of the ray tracer you should run `make`.

This rule will generate an executable file named `minirt`. To launch the executable you should follow this syntax:

```sh
$ ./miniRT ./scenes/mandatory/scene_name.rt
```
or, if you have your own scenes you want to render

```sh
$ ./miniRT ./path_to_scene/scene_name.rt
```

## **Use the keyboard to change the scene!**

### **Move the camera**
- The programs default mode is camera mode, so if no mode is selected the keys will move the camera
- You can use the keyboard to translate ou rotate the camera
- The movement of the camera is relative to the camera's axes

### **Select mode**
- You can press **TAB** to select an object or **L** to select light
- Press **L** to activate light mode, use the keys to translate the light and press it again to deactivate
- Every time you press **TAB** a new object will be selected and it will turn red, you can use the keyboard to translate, rotate or resize the selected object
- If there are no more object to select pressing **TAB** will take you back to camera mode
- The movement of light and objects is relative to the axes of the real world

### **Translation**
- **W** - foword
- **S** - backwords
- **A** - right
- **D** - left
- **SHIFT_LEFT** - up
- **CTRL_LEFT** - down

### **Rotation**
- **ARROW_UP** - along the x axis up
- **ARROW_DOWN** - along the x axis down
- **ARROW_RIGTH** - along the y axis to the right
- **ARROW_LEFT** - along the y axis to the left
- **SHIFT_RIGHT** - along the z axis clockwise
- **CTRL_RIGHT** - along the z axis counterclockwise

### **Resize**
- **H** - activates height mode, if not pressed the diameter is the default mesure to be resized (pressed a secund time deactivates height mode)
- **+** - Increses object size
- **-** - Decreses object size

**Note**: Directions are relative to the camera's axes, with the disclaimer the objects and light movements may have different directions if the camera's view is not (0,0,-1).
