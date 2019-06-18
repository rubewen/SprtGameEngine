#define PI 3.14159
#include <math.h>

class Object{
    public:

    //Spacial
    float radius;

    //States
    float x;
    float y;
    float vx;
    float vy;
    float ax;
    float ay;

    //Phyiscal constants
    float m;    //mass
    float k;    //spring constant
    float d;    //damping constant

    float fx[5000];
    float fy[5000];
    int forceListSize;
};

class SprtGameEngine{

    public:
    //Things
    Object objects[5000]; 
    int objectListSize;

    //AIP
    int collissions[2][5000];
    void (* actionList [5000])();
    void (* interactionList [5000])();
    void (* physicsList [5000])();

    int collisionListSize;
    int actionListSize;
    int interactionListSize;
    int physicsListSize;

    SprtGameEngine(){
        collisionListSize = 0;
        actionListSize = 0;
        interactionListSize = 0;
        physicsListSize = 0;
    }


    private:
    void addObject(Object &obj){
        objects[objectListSize] = obj;
        objectListSize++;
    }

    static bool doesCollide(Object &obj1, Object &obj2){
        if ( (obj1.radius + obj2.radius) > pow( (pow( (obj1.x - obj2.x), 2) + pow( (obj1.y - obj2.y), 2 )), 0.5)){
            return 1;
        }else{
            return 0;
        }
    }
    static void collide(Object &obj1, Object &obj2){

        //Combined spring constant
        float k = 1/(1.0/obj1.k + 1.0/obj2.k);

        //int d = 1/(1.0/obj1.k + 1.0/obj2.k);  //TODO: figure out how to implement collision damping
        //Needs to be included in the statespace somehow maybe
        
        //Depth of collision
        float depth = (obj1.radius + obj2.radius) - pow( (pow( (obj1.x - obj2.x), 2) + pow( (obj1.y - obj2.y), 2 )), 0.5);
        float tan = (obj2.y - obj1.y) / (obj2.x - obj1.x);
        //depth^2 = xDepth^2 + yDepth^2
        //depth^2 = (yDepth/tan)^2 + yDepth^2
        //depth^2 = yDepth^2(1/tan^2 + 1)
        //yDepth = depth*sqrt(1/tan^2 + 1)
        float yDepth = depth * pow(1.0/(pow(tan, 2)) + 1.0, 0.5);
        float xDepth = yDepth/tan;
        
        //Spring force
        int fx = k * xDepth;
        int fy = k * yDepth;
        obj1.fx[obj1.forceListSize] = -k * xDepth;
        obj2.fx[obj2.forceListSize] = k * xDepth;

        obj1.fy[obj1.forceListSize] = -k * yDepth;
        obj2.fy[obj2.forceListSize] = k * yDepth;

        /* This stuff is possibly not necessary
        if (obj1.x > obj2.x){
            obj1.fx[obj1.forceListSize] = fx;
            obj2.fx[obj2.forceListSize] = -fx;
        }else{
            obj1.fx[obj1.forceListSize] = -fx;
            obj2.fx[obj2.forceListSize] = fx;
        }
        if (obj1.y > obj2.y){
            obj1.fy[obj1.forceListSize] = fy;
            obj2.fy[obj2.forceListSize] = -fy;
        }else{
            obj1.fy[obj1.forceListSize] = -fy;
            obj2.fy[obj2.forceListSize] = fy;
        }
        */
        obj1.forceListSize++;
        obj2.forceListSize++;
    }

    void collisionHandeling(){
        collisionListSize = 0; 
        for (int i=0; i<objectListSize; i++){
            for (int j=1; (i+j) <objectListSize; j++){
                if (doesCollide( objects[i], objects[j])){
                    collissions[0][collisionListSize] = i;
                    collissions[1][collisionListSize] = j;
                    collide( objects[i], objects[j]);
                }
            }
        }
    }


    void actions(){
        for (int i=0; i<actionListSize; i++){
            (*actionList[i])();
            actionListSize = 0;
        }
    }

    void interactions(){
        //Dont know what to do here yet
        //Maybe use collision list to create effects
        //Based on collision
        for (int i=0; i<interactionListSize; i++){
            (*interactionList[i])();
        }
    }
    
    void physics(){
        for (int i=0; i<physicsListSize; i++){
            (*physicsList[i])();
        }
    }

    void gamestate(){

    }

    void frame(){
        //Actions causes interactions and physical efects
        //EXAMPLE: a SUPER PUNCH teleports someone 1meter back(interaction),
        //exterts a force on the victim, and transfers momentum (physics).
        //Physics include pure physics. actions and interactions creates inputs for physics
        //Interactions can be collisions as well.
        actions();
        collisionHandeling();
        interactions();
        physics();
        gamestate();
    }
};