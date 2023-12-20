
#define HEIGHT 20
#define WIDTH 20

typedef struct{
    int x,y;
}Position; 


  typedef struct {
        char data[HEIGHT][WIDTH];
            } World;



            
  typedef struct {
            Position position; 
            int width, height;
            char fillCharacter;
            int regionSize;
            Position doors[4];
            Enemy enemy;


                } Region;





                 void initWorld(World *world) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
            
          
            world->data[i][j] = ' ';
            }
        }
    }




    // ispisuje world
    void ispis(World *world) {
        system("cls");
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("%c", world->data[i][j]);
            }
            printf("\n");
        }
    }


void initRegion(Region *region, World *world ){

            



}