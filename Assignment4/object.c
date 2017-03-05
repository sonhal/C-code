#include <stdlib.h>
#include <stdio.h>
#include "SDL.h"
#include "drawline.h"
#include "triangle.h"
#include "object.h"
#include <strings.h>


// Create new object
object_t *CreateObject(SDL_Surface *screen, triangle_t *model, int numtriangles)
{
    // Implement me
    object_t *obj;
    obj = malloc(sizeof(object_t));
    obj->ttl = 0;
    obj->scale = 0.1;
    obj->rotation = 0;
    obj->tx = 500*obj->scale;
    obj->ty = 500*obj->scale;
    obj->speedx = rand() % 5 + 1;
    obj->speedy = rand() % 5 + 1;
    obj->numtriangles = numtriangles;
    obj->screen = screen;
    obj->model = malloc(sizeof(triangle_t)*numtriangles);
    bcopy(model, obj->model, sizeof(triangle_t)*numtriangles);
    return obj;
}


// Free memory used by object
void DestroyObject(object_t *object)
{
    // Implement me
    free(object->model);
    free(object);
}


// Draw object on screen
void DrawObject(object_t *object)
{
    // Implement me
    for(int x = 0; x < object->numtriangles; x++){
    object->model[x].tx = object->tx;
    object->model[x].ty = object->ty;
    object->model[x].scale = object->scale;
    object->model[x].rotation = object->rotation;
    DrawTriangle(object->screen, &object->model[x]);
    }
}
