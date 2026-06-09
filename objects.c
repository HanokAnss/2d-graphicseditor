#include <stdio.h>
#include "canvas.h"
#include "shapes.h"
#include "objects.h"

static Object objects[MAX_OBJECTS];
static int    object_count = 0;

/* Render one object onto the canvas */
static void draw_object(const Object *o) {
    if (!o->active) return;
    switch (o->type) {
        case SHAPE_LINE:
            draw_line(o->r1, o->c1, o->r2, o->c2);
            break;
        case SHAPE_RECTANGLE:
            draw_rectangle(o->r1, o->c1, o->r2, o->c2);
            break;
        case SHAPE_CIRCLE:
            draw_circle(o->r1, o->c1, o->r2);
            break;
        case SHAPE_TRIANGLE:
            draw_triangle(o->r1, o->c1, o->r2, o->c2, o->r3, o->c3);
            break;
    }
}

/* Add a new object; returns its id (0-based) or -1 if full */
int objects_add(ShapeType type, int r1, int c1, int r2, int c2, int r3, int c3) {
    if (object_count >= MAX_OBJECTS) {
        printf("Canvas full – max %d objects reached.\n", MAX_OBJECTS);
        return -1;
    }
    int id = object_count++;
    objects[id].type   = type;
    objects[id].active = 1;
    objects[id].r1 = r1; objects[id].c1 = c1;
    objects[id].r2 = r2; objects[id].c2 = c2;
    objects[id].r3 = r3; objects[id].c3 = c3;
    return id;
}

/* Mark an object as deleted; returns 0 on success, -1 if bad id */
int objects_delete(int id) {
    if (id < 0 || id >= object_count || !objects[id].active) {
        printf("No active object with id %d.\n", id);
        return -1;
    }
    objects[id].active = 0;
    return 0;
}

/* Update an existing object's coordinates */
int objects_modify(int id, int r1, int c1, int r2, int c2, int r3, int c3) {
    if (id < 0 || id >= object_count || !objects[id].active) {
        printf("No active object with id %d.\n", id);
        return -1;
    }
    objects[id].r1 = r1; objects[id].c1 = c1;
    objects[id].r2 = r2; objects[id].c2 = c2;
    objects[id].r3 = r3; objects[id].c3 = c3;
    return 0;
}

/* Clear the canvas and redraw every active object */
void objects_redraw_all(void) {
    canvas_clear();
    for (int i = 0; i < object_count; i++)
        draw_object(&objects[i]);
}

static const char *type_name(ShapeType t) {
    switch (t) {
        case SHAPE_LINE:      return "Line";
        case SHAPE_RECTANGLE: return "Rectangle";
        case SHAPE_CIRCLE:    return "Circle";
        case SHAPE_TRIANGLE:  return "Triangle";
        default:              return "Unknown";
    }
}

/* Print a summary of all objects */
void objects_list(void) {
    int found = 0;
    for (int i = 0; i < object_count; i++) {
        if (!objects[i].active) continue;
        printf("  [%d] %s ", i, type_name(objects[i].type));
        switch (objects[i].type) {
            case SHAPE_LINE:
                printf("(%d,%d)->(%d,%d)", objects[i].r1, objects[i].c1,
                                           objects[i].r2, objects[i].c2);
                break;
            case SHAPE_RECTANGLE:
                printf("top-left=(%d,%d) h=%d w=%d",
                       objects[i].r1, objects[i].c1, objects[i].r2, objects[i].c2);
                break;
            case SHAPE_CIRCLE:
                printf("center=(%d,%d) r=%d",
                       objects[i].r1, objects[i].c1, objects[i].r2);
                break;
            case SHAPE_TRIANGLE:
                printf("(%d,%d) (%d,%d) (%d,%d)",
                       objects[i].r1, objects[i].c1,
                       objects[i].r2, objects[i].c2,
                       objects[i].r3, objects[i].c3);
                break;
        }
        putchar('\n');
        found = 1;
    }
    if (!found) printf("  (no objects)\n");
}
