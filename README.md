#	miniRT 42

<p>
	This is a 42 project that reqires building out own raytracer and display shapes on the screen.
</p>
<p>
	This was a parter-project, so thanks to <a href="https://github.com/N03l-MG" target="_blank">Noel</a> for working on this project with me! :D
</p>
<p>
	<img src="https://github.com/Cimex404/42-miniRT/blob/master/og_test_scene.png" alt="og_test_scene" width="960">
</p>

##	Setup
Simply copy and paste this command into your terminal and the program will automatically set itself up:
```
git clone git@github.com:Cimex404/42-miniRT.git miniRT
cd miniRT
git submodule init
git submodule update
```
We use two submodules for this project, namely <a href="https://github.com/N03l-MG/libft" target="_blank">Noel's libft42</a> as well as the official  <a href="https://github.com/codam-coding-college/MLX42" target="_blank">MLX42 graphics library</a>.

##	Features
This miniRT can do all of the following:
-	Three geometric shapes (Sphere, Plane, Cylinder)
-	Ambient Lighting
-	Colored Point Lights
-	Soft Shadow casting
-	Shadow Falloff
-	Ambient Occlusion
-	Specular Reflections
-	Dynamic Reflection
-	Movement (only works smoothly with low shadow samples and a small window size)
-	Shadow sample control (+/- keys)

##	Input
The input is managed through **.rt** files. Here is an example:
```
A    0.1             0,255,255
C    -50,40.5,50     1,-0.3,-0.75  60
L    -5,10,60        0.75          255,255,255

pl   0,-10,0         0,1,0         0,255,0
pl   100,0,0         -1,0,0        255,0,0
pl   0,0,-100        0,0,1         0,0,255
cy   50.0,10,20.6    1,-.25,-1     20         15.5  0,255,255
sp   0,0,0           20            255,0,255
sp   -10,20,0        5             60,60,60   1     .6
cy   10,30,-30       .5,1,.5       10         20    255,255,0
```

- **A: Ambient light**
  - Brightness  
  - Position  

- **C: Camera**
  - Position
  - Rotation
  - Field of view (FOV)

- **L: Point light**
  - Position
  - Brightness
  - Color

- **sp: Sphere object**
  - Position
  - Diameter
  - Color
  - [Roughness]
  - [Reflectiveness]

- **pl: Plane object**
  - Position
  - Rotation
  - Color
  - [Roughness]
  - [Reflectiveness]

- **cy: Cylinder object**
  - Position
  - Rotation
  - Diameter
  - Height
  - Color
  - [Roughness]
  - [Reflectiveness]
 
##	Cake
<p>
	<img src="https://github.com/Cimex404/42-miniRT/blob/master/cake.png" alt="cake" width="960">
</p>
