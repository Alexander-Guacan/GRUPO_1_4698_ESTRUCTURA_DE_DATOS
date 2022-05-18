#ifndef CUADRADO_H
#define CUADRADO_H

class Cuadrado
{    
    float area, perimetro, lado;

    public:
    void leer(void);
    void imprimeArea(void);
    void imprimePerimetro(void);
    void imprimeAreaYPerimetro(void);
    void setArea(float);
    void setPerimetro(float);
    float getArea();
    float getPerimetro();
    //retorno una variable tipo cuadrado 
    Cuadrado operator +(Cuadrado D);

};

#endif