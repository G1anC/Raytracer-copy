/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main.cpp
*/

#include <iostream>
#include <thread>
#include "../include/includer.hpp"
#include "RayTracer/Scene.hpp"
#include "RayTracer/Render/ppmRenderer.hpp"
#include "RayTracer/Render/sfmlRenderer.hpp"

static int help()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
    std::cout << " SCENE_FILE: scene configuration" << std::endl;
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;

    const std::string sceneFile = av[1];
    if (sceneFile == "--help")
        return help();
    RayTracer::Scene scene(sceneFile);
    scene.run();
    return 0;
}