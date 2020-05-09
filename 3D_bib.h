//#include <GL/glut.h>
#ifndef BIB
#define BIB

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include <stack>
#include "iostream"

using namespace std;

class Matriz{
private:
    float **M, **Coor;
public:
    Matriz();
    ~Matriz();

};

class Operaciones3D{
  private:
        //Funcion que carga el vector de traslacion en la matriz T
        void translate_R(float x, float y, float z);
        //Funcion que define la matriz de rotacion con rspecto al eje X
        void rotateX_R(float deg);
        //Funcion que define la matriz de rotacion con rspecto al eje Y
        void rotateY_R(float deg);
        //Funcion que define la matriz de rotacion con rspecto al eje Z
        void rotateZ_R(float deg);
		//...

  public:
        //Variables para matrices de rotacion y traslación
        float T[4][4], R[4][4], E[4][4], A[4][4];
        Matriz A1;
        //Variables para operaciones trigonometricas
        float pi;
        //Pila para el manejo de estados
        stack<Matriz *> mystack;

        Operaciones3D();
        void MatPoint(float m[][4], float p[3]);
        void MatObject(float m[][4], int size, float p[][3]);

        //Transformacion de grados a radianes
        //recordar que (pi/180 = r/g) donde "r" son radianes y "g" grados
        //se aplica la formula r
        float RadToDeg(float r);
        float DegToRad(float g);
        //Funcion para cargar la matriz identidad en la matriz que se recibe como parametro
        //Funcion que carga el vector de traslacion en la matriz T
        void translate(float x, float y, float z);
        //Funcion que define la matriz de rotacion con rspecto al eje X
        void rotateX(float deg);
        void rotateX(float b, float c);
        //Funcion que define la matriz de rotacion con rspecto al eje Y
        void rotateY(float deg);
        void rotateY(float a, float d);
        //Funcion que define la matriz de rotacion con rspecto al eje Z
        void rotateZ(float deg);

        void RotacionParalela(char eje, float theta, float distA, float distB);
        //Rotacion libre a partir del eje de rotacion definido por los puntos
        //p1 y p2 y theta grados en sentido contrario a las manecillas del reloj
        //La matriz resultante queda almacenada en la matriz A
        void rotateXYZ(float theta, float p1[3], float p2[3]);
        //Funcion que carga la matriz de escala en la matriz E
        void scale(float x, float y, float z);

        //Funcion que multiplica la matriz M1 con la matriz M2, donde el resultado es Res
        void MultM(float M1[][4], float M2[][4], float Res[][4]);
		//...

        //manejo de una pila
        void LoadIdentity(float M[][4]);
        //void push();
        //void pop();
};

#endif // BIB
