#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <QFile>
#include <map>
#include <QtGui>
#include <QTextStream>

using namespace std;

struct ShapeInfo {
    int    tempid;
    string type;
    int    dimensions[];
    string pencolor;
    int    penwidth;
    string penstyle;
    string pencap;
    string penjoin;
    string brushcolor;
    string brushstyle;
};

void InitializeMaps();
void InitializeShapes();

class Shape : public QWidget
{
    Q_OBJECT
public:
    Shape(QWidget *parent = 0);

    // default constructor
    Shape();

    // alternative constructor
    Shape(ShapeInfo s) : x1{s.dimensions[0]}, y1{s.dimensions[0]}, id{s.tempid}{}

    // copy constructor "mark constructor delete"
    Shape(const Shape& obj) = delete;

    // disable assigment operator
    Shape & operator = (const Shape& obj) = delete;

    //string SetCoordinates(string )

    void set_id(int id_num);
    
    const int get_id() const{
        return id_num;
    }

    //void set_pen_color(string pen_color)
    int get_x1();
    int get_y1();

    void set_x1(int value);
    void set_y1(int value);

    //    bool operator== (const Shape& rhs)const {
    //        return (rhs.id == id);
    //    }

    //friend bool operator< (const Shape& sh_1, const Shape& sh_2);

    // need Qpatiner library
    virtual void draw(void) = 0;
    virtual void move(int dx, int dy) = 0; // dx --> changing x , dy -- > chnaging y
    virtual float calcPerimeter() = 0;
    virtual float calcArea() = 0;


    void printPerimeter(Shape& s);
    void printArea(Shape& s1);

public slots:
    //    void SetAll(int newId, string newStype, string newDimension, Qt::GlobalColor, int newPWidth, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, Qt::GlobalColor, Qt::BrushStyle, string newText, Qt::GlobalColor, Qt::AlignmentFlag, int newPointSize, string newFont, QFont::Style, QFont::Weight);

protected:

    QPen pen;
    QBrush brush;
    QFont font;

    int id;
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;

    /*
    int textPointerSize() {
        int TextPointSize[51];
        for (int i = -1; i < 52; i++) {
            TextPointSize[i] = i;
            return TextPointSize[i];
        }
    }
    TextFontFamily: Comic Sans MS, Courier, Helvetica, Times [string]
    enum TextFontStyle { StyleNormal, StyleItalic, StyleObliqu };
    enum TextFontWeight { Thin, Light, Normal, Bold };
    */

};

/*
bool operator< (const Shape& sh_1, const Shape& sh_2) {
    return sh_1.id < sh_2.id;
}
*/

/*
bool operator== (const Shape& rhs) const {
return (rhs.obj = obj);
}
*/

// class for Rectangle
class Rectangle : public Shape {
public:
    Rectangle(ShapeInfo s) : Shape(s), length{s.dimension[2]}, width{s.dimension[3]} {}
    float calcPerimeter();
    float calcArea();
    void draw(void) ;
    void move(int dx, int dy);
protected:
    int width;
    int length;
};


// class for Square
class Square : public Shape {
public:
    Square(int x1, int y1,int id, int length): Shape(x1, y1, id), length(length){}
    float calcPerimeter();
    float calcArea();
    void draw(void);
    void move(int dx, int dy);
protected:
    int length;
};


class Line : public Shape {
public:
    Line(int x1, int y1, int id, int x2, int y2) : Shape(x1, y1, id), x2(x2), y2(y2) {}
    float calcPerimeter();
    float calcArea();
    void draw(void);
    void move(int dx, int dy);
protected:
    int x2;
    int y2;
};

////Polyline - x1, y1, x2, y2, x3, y3, ... , xN, yN [sequence of N points]
class Polyline : public Shape {
public:
    // deep copy
    Polyline(int id, int numPoints, int* x_vals, int* y_vals) : Shape(x_vals[0], y_vals[0], id), numPoints(numPoints){
        x_values = new int[numPoints]; // dynamic array
        y_values = new int[numPoints];// dynamic array
        for (int i = 0; i < numPoints; i++) {
            x_values[i] = x_vals[i];
            y_values[i] = y_vals[i];
        }
    }

    ~Polyline() {
        if (x_values)
            delete[] x_values;
        if (y_values)
            delete[] y_values;
    }
    float calcPerimeter();
    float calcArea();
    void draw(void);
    void move(int dx, int dy);

protected:
    int numPoints;
    int* x_values;
    int* y_values;
};

//Polygon - x1, y1, x2, y2, x3, y3, ... , xN, yN
class Polygon : public Shape {
public:

    // deep copy
    Polygon(int id, int numPoints, int* x_vals, int* y_vals) : Shape(x_vals[0], y_vals[0], id), numPoints(numPoints) {
        x_values = new int[numPoints]; // dynamic array
        y_values = new int[numPoints];// dynamic array
        for (int i = 0; i < numPoints; i++) {
            x_values[i] = x_vals[i];
            y_values[i] = y_vals[i];
        }
    }

    ~Polygon() {
        if (x_values)
            delete[] x_values;
        if (y_values)
            delete[] y_values;
    }
    float calcPerimeter();
    float calcArea();
    void draw(void);
    void move(int dx, int dy);
protected:
    int* x_values;
    int* y_values;
    int numPoints;
};


class Ellipse : public Shape {
protected:
    int a;
    int b;
};

//void printPerimeter(Shape& s) {
//    cout << s.calcPerimeter() << endl;
//}
//void printArea(Shape& s1) {
//    cout << s1.calcArea() << endl;
//}

#endif
