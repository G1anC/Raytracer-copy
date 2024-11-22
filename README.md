# RayTracer

A RayTracing algorythm that takes a .cfg file (configuration files are in scenes)
and prints the results based on the given file.
(There is almost 200 commits on the main private repo :,)

## Introduction

### Usage

```bash
$> make re
$> ./raytracer [scenes/configfile.cfg]
ppr or sfml :
--> ppm

Name your file:
--> [resultName]

The result is screenshots/[resultName].ppm !
```
or
```bash
$> make re
$> ./raytracer [scenes/configfile.cfg]
ppr or sfml :
--> sfml

Look at the result !
```

### Algorithm

The RayTracer works by parsing the file and creating a scene full of the given primitives (3D objects that you want to display), directional or diffuse lights and the camera (see the documentation in scenes/ folder).

Based on the camera infos, the program will send a ray for each pixel of the screen and will check if it intersects with any of the primitives. If it does, it will calculate the color of the pixel based on the light sources and the material of the primitive.

After all pixels are calculated, the program prints the result in the ppm file with the name you provided or on an sfml window.

![explanation diagram](https://github.com/EpitechPromo2027/B-OOP-400-STG-4-1-raytracer-noah.steiniger/blob/main/.github/diagram.png)


## Technical stuff

### Ray

The Ray class is the starting point of the project, its the class that will be sent to the primitives and lights to check if they are hit by the ray.
```cpp
class Ray {
    public:
        Ray() = default;
        Ray(Math::Point origin, Math::Vector direction);
        Ray(const Ray &other) = default;
        Ray(Ray &&other) noexcept = default;

        Ray &operator=(const Ray &other);
        Ray &operator=(Ray &&other) noexcept;

        Math::Point _origin;
        Math::Vector _direction;
    };
}
```

As you see it's fairly simple, it has an origin and a direction. The origin is the position of the camera and the direction is the vector from the camera to the screen's pixel.

### Primitves

So the primitives all have a form in common :

```cpp
class IPrimitives {
    public:
        virtual ~IPrimitives() = default;
        virtual RayTracer::HitInfo hits(RayTracer::Ray &ray) = 0;
        virtual bool castsShadow(RayTracer::Ray &ray, Math::Point &lightPos) = 0;
};
```

They have a hits function that will return a HitInfo object (that i will specify later), containing informations on wether the Ray given as argument touches/hits the primitive.

They also have a castsShadow function that returns a boolean on wether the place hit by the ray on the object is forshadowed by another object, preventing the algorithm from calculating the enligthen color.

#### These are all the primitives you can use :

- ```Sphere``` (takes a center, a radius and a material)
- ```Plane``` (takes an axis, a position from the given axis and a material)
- ```Cone``` (takes a center, a radius, a height and a material)
- ```Cylinder``` (takes a center, a radius, a height and a material)

<br>

### Lights

The lights are a bit more simple :

```cpp
class ILights {
    public:
        virtual ~ILights() = default;
        virtual RayTracer::LightInfo getEnlightement(Math::Point &point) = 0;
};
```

They have a getLightement function that will return a LightInfo object (that i will specify later), containing informations on the new Color of the pixel hit by the ray.

#### These are all the lights you can use :

- ```Directional``` (takes a position, a direction and a color)
- ```Diffuse``` (takes a position and a color)
- ```Ambient``` (takes a position and a color)

<br>

### Camera

The camera is the most important part of the scene, it is the one that will send the rays to the primitives and lights.
The result screen is almost entirely based on the camera and the information given.

This is the Camera class :

```cpp
typedef struct {
    int width;
    int height;
} resolution_t;

class Camera {
    public:
        ~Camera() = default;
        Camera();
        Camera(resolution_t resolution, Math::Point position, Math::Point rotation, float fov); 
        [[nodiscard]] Ray &ray(double u, double v) const;
        
        // Getters
        [[nodiscard]] const resolution_t &getResolution() const;
        [[nodiscard]] const Math::Point &getPosition() const;
        [[nodiscard]] const Math::Point &getRotation() const;
        [[nodiscard]] float getFov() const;
        [[nodiscard]] const Rectangle &getScreen() const;
        
    private:
        resolution_t _resolution{};
    	Math::Point _position{};
        Math::Point _rotation{};
        float _fov{};
        Rectangle _screen;
};
```

The camera has a resolution, a position, a rotation and a fov (Field of View). And all these informations will deeply impact the result of the scene.
Find your favorite configuration in the scenes/ folder !

<br>

### HitInfo

The HitInfo object is the one that will be returned by the hits function of the primitives.
It contains a lot of information, here it is:

```cpp
struct HitInfo {
    bool didHit;
    Math::Point intersectionPoint;
    Math::Vector normal;
    float distance;
};
```

- ```didHit``` is a boolean that tells wether the ray hit the object or not.
- ```intersectionPoint``` is the point where the ray hit the object.
- ```normal``` is the normal vector of the object at the intersection point.
- ```distance``` is the distance between the camera (ray starting point) and the intersection point.

<br>

### Renderers

The renderers are the classes that will make all the calculations and return the final image from the scene.

```cpp
class IRenderer {
    public:
        virtual ~IRenderer() = default;
        virtual void writePixel(const RayTracer::Scene &scene) = 0;
        virtual void render(const RayTracer::Scene &scene) = 0;
};
```

The writePixel function will write the pixel in the ppm file and the render function will render the scene.
