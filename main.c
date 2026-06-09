#include <stdio.h>
#include "canvas.h"
#include "objects.h"
 
static void print_menu(void) {
    printf("\n=== 2D Graphics Editor ===\n");
    printf("  1) Add line\n");
    printf("  2) Add rectangle\n");
    printf("  3) Add circle\n");
    printf("  4) Add triangle\n");
    printf("  5) Delete object\n");
    printf("  6) Modify object\n");
    printf("  7) List objects\n");
    printf("  8) Display canvas\n");
    printf("  9) Clear canvas\n");
    printf("  0) Quit\n");
    printf("Choice: ");
}
 
int main(void) {
    canvas_init();
    int choice;
 
    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) break;
 
        int r1, c1, r2, c2, r3, c3, id;
 
        switch (choice) {
            case 1:
                printf("Line  r1 c1 r2 c2: ");
                scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
                id = objects_add(SHAPE_LINE, r1, c1, r2, c2, 0, 0);
                if (id >= 0) printf("Added line as id %d\n", id);
                break;
 
            case 2:
                printf("Rectangle  top-left row col, height width: ");
                scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
                id = objects_add(SHAPE_RECTANGLE, r1, c1, r2, c2, 0, 0);
                if (id >= 0) printf("Added rectangle as id %d\n", id);
                break;
 
            case 3:
                printf("Circle  center row col, radius: ");
                scanf("%d %d %d", &r1, &c1, &r2);
                id = objects_add(SHAPE_CIRCLE, r1, c1, r2, 0, 0, 0);
                if (id >= 0) printf("Added circle as id %d\n", id);
                break;
 
            case 4:
                printf("Triangle  r1 c1 r2 c2 r3 c3: ");
                scanf("%d %d %d %d %d %d", &r1, &c1, &r2, &c2, &r3, &c3);
                id = objects_add(SHAPE_TRIANGLE, r1, c1, r2, c2, r3, c3);
                if (id >= 0) printf("Added triangle as id %d\n", id);
                break;
 
            case 5:
                printf("Delete id: ");
                scanf("%d", &id);
                if (objects_delete(id) == 0) printf("Deleted object %d\n", id);
                break;
 
            case 6:
                printf("Modify id: ");
                scanf("%d", &id);
                printf("New params (r1 c1 r2 c2 r3 c3): ");
                scanf("%d %d %d %d %d %d", &r1, &c1, &r2, &c2, &r3, &c3);
                if (objects_modify(id, r1, c1, r2, c2, r3, c3) == 0)
                    printf("Modified object %d\n", id);
                break;
 
            case 7:
                printf("Objects:\n");
                objects_list();
                break;
 
            case 8:
                objects_redraw_all();
                canvas_display();
                break;
 
            case 9:
                canvas_clear();
                printf("Canvas cleared.\n");
                break;
 
            case 0:
                printf("Goodbye!\n");
                return 0;
 
            default:
                printf("Unknown option.\n");
        }
    }
    return 0;
}