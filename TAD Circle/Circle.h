#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
#include <cmath>

/**
 * Classe 'Circle' que implementa um círculo
 */
class Circle {
private:
    /**
     * Declaração dos atributos do círculo
     */
    double radius; // o raio do círculo
    Point center; // o centro do círculo
    
public:
    // Construtor default
    Circle() {
        radius = 0.0;
        center = {0.0,0.0};
    }

    Circle(Point& center, double radius) {
        this->center = center;
        this->radius = radius;
    }

    // getters
    Point getCenter() {
        return center;
    }
    double getRadius() {
        return radius;
    }
    
    // setters
    void setRadius(double radius) {
        this->radius = radius;
    }
    void setCenter(double x, double y) {
        this->center = {x,y};
    }
    void setCenter(Point& center) {
        this->center = center;
    }

    // Operação que calcula a área do círculo
    double area() {
        return M_PI*radius*radius;
    }

    // Operação que verifica se um dado ponto p dado 
    // como entrada está ou não dentro do círculo
    bool interior(Point& p) {
        double d = center.distance(p);
        if(d > radius){
            return false;
        }else{
            return true;
        }
    }

    // Retorna uma string com os dados do círculo
    std::string toString(){
        std::string Circulo = "Circle[radius: " + std::to_string(getRadius()) + ", center: (" + std::to_string(center.getX()) + "," + std::to_string(center.getY()) + ")]";
        return Circulo;
    }
};

#endif
