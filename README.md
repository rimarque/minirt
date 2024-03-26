# **miniRT**

## **About**

## 📝 **Authorship**

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

## **Controls**
- **W** - Translate foword
- **S** - Translate backwords
- **A** - Translate right
- **D** - Translate left
