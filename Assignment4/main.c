#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "SDL.h"
#include "drawline.h"
#include "triangle.h"
#include "list.h"
#include "teapot_data.h"
#include "sphere_data.h"
#include "object.h"

#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)


// Clear screen by filling it with 0
void ClearScreen(SDL_Surface *screen)
{
    SDL_Rect rect;

    // Define a rectangle covering the entire screen
    rect.x = 0;
    rect.y = 0;
    rect.w = screen->w;
    rect.h = screen->h;

    // And fill screen with 0
    SDL_FillRect(screen, &rect, 0);
}


// Add some speed to an object
void AccelerateObject(object_t *a, float boost, float maxspeed)
{
    float s;
    float news;

    // Calculate lenght of speed vector
    s = sqrtf(a->speedx * a->speedx + a->speedy * a->speedy);

    // Boost speed
    news = s * boost;
    if (news < 0.0)
        news = 0.0;
    if (news > maxspeed)
        news = maxspeed;
    a->speedx *= news/s;
    a->speedy *= news/s;
}


void BouncingBalls(SDL_Surface *screen)
{
    // Implement me
    // Wait for ctrl-c from user
    // Initialize SDL
    SDL_Event event;
    object_t *object;
    object = CreateObject(screen, sphere_model, SPHERE_NUMTRIANGLES);

    list_t *list;
    list = list_create();

    list_iterator_t *iter;
    iter = list_createiterator(list);

    int done;
    float radius = 500 * object->scale;
    float gravity = 0.05;
    int d = SDL_GetTicks();
    done = 0;
    while (done == 0) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                done = 1;
                break;
            }
        }

        if(list_size(list) < 5 && SDL_GetTicks() %1000 == 0)
        {
            list_addfirst(list, CreateObject(screen, sphere_model, SPHERE_NUMTRIANGLES));
        }
        list_resetiterator(iter);
        SDL_UpdateRect(screen, 0, 0, screen->w, screen->h);
        ClearScreen(screen);
        for(int i = 0; i < list_size(list); i++)
        {
          object = list_next(iter);
          DrawObject(object);
          //printf("%d\n", d);


          object->rotation = object->rotation + object->speedx;
          object->tx = object->tx + object->speedx;
          object->ty = object->ty + object->speedy;
          if(object->ty < screen->h -radius)
          {
            object->speedy += gravity;
          }
          AccelerateObject(object, 0.9981, 8);



          if (object->tx + radius > screen->w)
          {
            object->tx = screen->w - radius;
            object->speedx = object->speedx * -0.9;
          }
          if (object->tx < radius)
          {
            object->tx = radius;
            object->speedx = object->speedx * -0.9;
          }
          if (object->ty + radius > screen->h)
          {
            object->ty = screen->h - radius;
            object->speedy = object->speedy * -0.9;
          }
          if (object->ty < radius)
          {
            object->ty = radius;
            object->speedy = object->speedy * -0.9;
          }

          if(object->speedx > 0.1 && object->speedx < -0.1)
          {
            if(object->speedy > 0.5 && object->speedy < -0.5)
            {
              if(screen->h - (object->ty - radius) < 0.8)
              {
                object->ty = screen->h - radius;
              }
            }
          }

          if(object->ty == screen->h - 100)
          {
            object->speedx = 0;
            object->speedy = 0;
          }
          // printf("check1\n");
          if(object->speedy < 0.05 && object->speedy > -0.05)
          {
            //printf("check2\n");
            if(object->speedx < 0.001 && object->speedx > -0.001)
            {
              //printf("check3\n");
              if(object->ttl == 0)
              {
                //printf("check4\n");
                object->ttl = SDL_GetTicks();
              }
              if(object->ttl - SDL_GetTicks() <= 5000)
              {
                //printf("check5\n");
                list_remove(list, object);
                DestroyObject(object);
              }
            }
          }
        }
        d++;
    }
}



// First function run in your program
int main(int argc, char **argv)
{
    int retval;
    SDL_Surface *screen;

    // Initialize SDL
    retval = SDL_Init(SDL_INIT_VIDEO);
    if (retval == -1) {
        printf("Unable to initialize SDL\n");
        exit(1);
    }

    // Create a 1024x768x32 window
    screen = SDL_SetVideoMode(1024, 768, 32, 0);
    if (screen == NULL) {
        printf("Unable to get video surface: %s\n", SDL_GetError());
        exit(1);
    }

    // Start bouncing some balls
    BouncingBalls(screen);

    // Shut down SDL
    SDL_Quit();

    // Wait a little bit jic something went wrong (so that printfs can be read)
    SDL_Delay(5000);

    return 0;
}
