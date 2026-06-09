#ifndef OBJECTS_H
#define OBJECTS_H
 
#define MAX_OBJECTS 50
 
typedef enum {
    SHAPE_LINE,
    SHAPE_RECTANGLE,
    SHAPE_CIRCLE,
    SHAPE_TRIANGLE
} ShapeType;
 
typedef struct {
    ShapeType type;
    int active;
    int r1, c1, r2, c2, r3, c3;
} Object;
 
int  objects_add(ShapeType type, int r1, int c1, int r2, int c2, int r3, int c3);
int  objects_delete(int id);
int  objects_modify(int id, int r1, int c1, int r2, int c2, int r3, int c3);
void objects_redraw_all(void);
void objects_list(void);
 
#endif