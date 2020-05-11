#include "3D_bib.h"
Matriz::Matriz(){
    //float M[4][4];
}

Matriz::~Matriz()
{
    /*
    for(int i=0;i<4;i++){
		delete[] M[i];
		delete[] Coor[i];
	}
	delete[] M;
	delete[] Coor;
	*/
}

Operaciones3D::Operaciones3D()
{
    //Variables para operaciones trigonometricas
    pi = 3.14159265359;
}

Operaciones3D::~Operaciones3D()
{
    //Variables para operaciones trigonometricas
    pi = 3.14159265359;
}

//recordar que (pi/180 = r/g) donde "r" son radianes y "g" grados
//se aplica la formula r
float Operaciones3D::RadToDeg(float r)
{
      return ((180*r)/pi);
}

float Operaciones3D::DegToRad(float g)
{
      return ((g*pi)/180);
}

void Operaciones3D::LoadIdentity(float M[][4])
{
  int i,j;
  for(i=0;i<4;i++)
    for(j=0;j<4;j++)
      if(i==j)
         M[i][j]=1;
      else
         M[i][j]=0;
 }

void Operaciones3D::translate(float x, float y, float z)
{
  LoadIdentity(T);
  T[0][3]=x;
  T[1][3]=y;
  T[2][3]=z;
 }

void Operaciones3D::rotateX(float deg)
{
  LoadIdentity(R);
  R[1][1] = cos(deg);
  R[1][2] = -1*sin(deg);
  R[2][1] = sin(deg);
  R[2][2] = cos(deg);
}

void Operaciones3D::rotateX(float b, float c)
{
  LoadIdentity(R);
  R[1][1] = c;
  R[1][2] = -1*b;
  R[2][1] = b;
  R[2][2] = c;
}

void Operaciones3D::rotateY(float deg)
{
  LoadIdentity(R);
  R[0][0] = cos(deg);
  R[0][2] = sin(deg);
  R[2][0] = -1*sin(deg);
  R[2][2] = cos(deg);
}

void Operaciones3D::rotateY(float a, float d)
{
  LoadIdentity(R);
  R[0][0] = d/(sqrt(pow(a,2)+pow(d,2)));
  R[0][2] = a/(sqrt(pow(a,2)+pow(d,2)));
  R[2][0] = -1*a/(sqrt(pow(a,2)+pow(d,2)));
  R[2][2] = d/(sqrt(pow(a,2)+pow(d,2)));
}

void Operaciones3D::rotateZ(float deg)
{
  LoadIdentity(R);
  R[0][0] = cos(deg);
  R[0][1] = -1*sin(deg);
  R[1][0] = sin(deg);
  R[1][1] = cos(deg);
 }

void Operaciones3D::MultM(float M1[][4], float M2[][4], float Res[][4])
{
  float tmp[4][4];
  int i,j,k;
  for(i=0; i<4;i++)
     for(j=0;j<4;j++){
        tmp[i][j]=0;
        for(k=0;k<4;k++)
           tmp[i][j]+=M1[i][k]*M2[k][j];
     }
  for(i=0;i<4;i++)
     for(j=0;j<4;j++)
        Res[i][j] = tmp[i][j];
}

//multiplica la matriz m por el punto p y regresa el resultado en el punto p
void Operaciones3D::MatPoint(float m[][4], float p[3])
{
  float tmp[4];
  int i,j;
  for(i=0; i<3; i++)
    { tmp[i] = p[i];
      p[i] = 0;
    }
  tmp[3]=1;
  for(i=0;i<3;i++)
    for(j=0;j<4;j++)
        p[i] += m[i][j]*tmp[j];
}

//multiplica la matriz m por cada punto del objeto definido por la matriz p de size x 3
void Operaciones3D::MatObject(float m[][4], int size, float p[][3])
{
     int i;
     for(i=0; i<size; i++)
       MatPoint(m,p[i]);
}

//rotacion paralela a uno de los ejes
//theta: angulo de rotacion;
//distA,distB: vector (distA,distB) que separa al eje de rotacion del objeto
//con respecto a uno de los ejes del sistema carteciano. Si el eje es:
//X: (distA,distB) es el vector (0,distA,distB)
//Y: (distA,distB) es el vector (distA,0,distB)
//Z: (distA,distB) es el vector (distA,distB,0)
void Operaciones3D::RotacionParalela(char eje, float theta, float distA, float distB)
{
     switch(eje){
        case 'X':
             //se actualiza la matriz de traslacion para mover el objeto en el espacio
             translate(0,-distA,-distB);
             //se actualiza la matriz de rotacion con el angulo especificado
             rotateX(DegToRad(theta));
             //se multiplica la matriz de rotacion por la de traslacion actual
             //el resultado queda en la matriz A
             MultM(R,T,A);
             //se agrega la matriz de traslacion inversa a A
             translate(0,distA,distB);
             //se multiplica la matriz de traslacion por la matriz A y se deja el resultado en A
             MultM(T,A,A);
             break;
        case 'Y':
            //se actualiza la matriz de traslacion para mover el objeto en el espacio
             translate(0,-distA,-distB);
             //se actualiza la matriz de rotacion con el angulo especificado
             rotateY(DegToRad(theta));
             //se multiplica la matriz de rotacion por la de traslacion actual
             //el resultado queda en la matriz A
             MultM(R,T,A);
             //se agrega la matriz de traslacion inversa a A
             translate(0,distA,distB);
             //se multiplica la matriz de traslacion por la matriz A y se deja el resultado en A
             MultM(T,A,A);
             break;
        case 'Z':
            //se actualiza la matriz de traslacion para mover el objeto en el espacio
             translate(0,-distA,-distB);
             //se actualiza la matriz de rotacion con el angulo especificado
             rotateZ(DegToRad(theta));
             //se multiplica la matriz de rotacion por la de traslacion actual
             //el resultado queda en la matriz A
             MultM(R,T,A);
             //se agrega la matriz de traslacion inversa a A
             translate(0,distA,distB);
             //se multiplica la matriz de traslacion por la matriz A y se deja el resultado en A
             MultM(T,A,A);
             break;
     }
}

void Operaciones3D::rotateXYZ(float theta, float p1[3], float p2[3])
{
float a, b, c, d, V;
    float tmp[4][4];
    V = sqrt(pow((p2[0]-p1[0]),2) + pow((p2[1]-p1[1]),2) + pow((p2[2]-p1[2]),2));
    a = (p2[0]-p1[0]) / V;
    b = (p2[1]-p1[1]) / V;
    c = (p2[2]-p1[2]) / V;
    d = sqrt(pow(b,2) + pow(c,2));
    if(d!=0){
        translate(p1[0],p1[1],p1[2]);
        rotateX(-1*(b/d),(c/d));
        MultM(T,R,A);
        rotateY(-1*a,d);
        MultM(A,R,A);
        rotateZ(DegToRad(theta));
        MultM(A,R,A);
        rotateY(1*a,d);
        MultM(A,R,A);
        rotateX(1*(b/d),(c/d));
        MultM(A,R,A);
        translate(-p1[0],-p1[1],-p1[2]);
        MultM(A,T,A);
    }
    else{
        translate(-p1[0],-p1[1],-p1[2]);
        //se actualiza la matriz de rotacion con el angulo especificado
        rotateX(DegToRad(theta));
        //se multiplica la matriz de rotacion por la de traslacion actual
        //el resultado queda en la matriz A
        MultM(R,T,A);
        //se agrega la matriz de traslacion inversa a A
        translate(p1[0],p1[1],p1[2]);
        //se multiplica la matriz de traslacion por la matriz A y se deja el resultado en A
        MultM(T,A,A);
    }
}
void Operaciones3D::scale(float x, float y, float z){
    LoadIdentity(E);
    E[0][0]=x;
    E[1][1]=y;
    E[2][2]=z;
    E[3][3]=1;
}

void Operaciones3D::push(){
    Matriz temp;
    for(int i=0; i<4;i++){
        for(int j=0; j<4; j++)
            temp.M[i][j]=A[i][j];
    }
    mystack.push(temp);
}
void Operaciones3D::pop(){
    Matriz temp;
    temp = mystack.top();

    for(int i=0; i<4;i++){
        for(int j=0; j<4; j++){
            A[i][j]=temp.M[i][j];
        }
    }
    mystack.pop();
}

void Operaciones3D::imprimeMatriz(float M[][4]){
    for(int i=0; i<4;i++){
        for(int j=0; j<4; j++){
            printf("[%i][%i]=%f",i,j,M[i][j]);
            printf("\n");
        }
    }
}

void Operaciones3D::translate_R(float x, float y, float z){
    LoadIdentity(T);
    T[0][3]=x;
    T[1][3]=y;
    T[2][3]=z;
    MultM(T,A,A);
}
