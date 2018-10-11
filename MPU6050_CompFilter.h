/*  Obtención del angulo del MPU6050 aplicando un flitro complementario
    Autor: Javier Vargas
    Basado en Robologs --> https://robologs.net/
    https://creativecommons.org/licenses/by/4.0/
*/

#ifndef _MPU6050_CompFilter_h
#define _MPU6050_CompFilter_h

#include "Wire.h"
#include "Arduino.h"

class MPU6050_CompFilter {

private:

float t_m; //Tiempo de muestreo
float K; // Costante del filtro complementario
int MPU; //Direccion I2C del dispositivo
int16_t AcX, AcY, AcZ, GyX, GyY, GyZ; //MPU-6050 da los valores en enteros de 16 bits
//Angulos
float Acc[3];
float Gy[3];
float Angle[3];
float AngleAnt[2];
float VelAngle[2];

public:
    MPU6050_CompFilter(int direccion);
    void Iniciar(float t_muestreo); //Inicia las comunicaciones con el dispositivo
    void setKcompFilter(float K_in); //Ajusta la costante del filtro complementario
    void Lectura(boolean leerX, boolean leerY); //Lee y filtra los datos
    void Lectura(boolean leerX, boolean leerY, boolean leerZ); //Lee y filtra los datos
    //--//MEDIDAS CON FILTRO COMPLEMENTARIO
    float angX(); //Devuelve el angulo en el eje x
    float angY(); //Devuelve el angulo en el eje y
    float angZ(); //Devuelve el angulo en el eje y
    float VelAngX(); //Devuelve la velocidad angular en el eje x (º/s)
    float VelAngY(); //Devuelve la velocidad angular en el eje y (º/s)
    //--//MEDIDAS SIN FILTRO
    float Xgyro(); //Valor del giróscopo en el eje X
    float Ygyro(); //Valor del giróscopo en el eje Y
    float Xacc(); //Valor del ángulo del acelerómetro X
    float Yacc(); //Valor del ángulo del acelerómetro Y
    //--//OFFSET DE CÁLCULO
    // XA_OFFS_* registers
    void setXAccelOffset(int16_t offset);
    // YA_OFFS_* register
    void setYAccelOffset(int16_t offset);
    // ZA_OFFS_* register
    void setZAccelOffset(int16_t offset);
    // XG_OFFS_USR* registers
    void setXGyroOffset(int16_t offset);
    // YG_OFFS_USR* register
    void setYGyroOffset(int16_t offset);
    // ZG_OFFS_USR* register
    void setZGyroOffset(int16_t offset);
};

#endif
