#include "shape.h"

Shape::Shape(QWidget *parent) : QWidget(parent)
{

}

//void Shape::set_id(int i) {
//id = i;
//cout << "ID == " << id << endl;
//}

//int Shape::get_x1() {
//    return x1;
//}
//int Shape::get_y1() {
//    return y1;
//}

//void Shape::set_x1(int value) {
//    x1 = value;
//}
//void Shape::set_y1(int value) {
//    y1 = value;
//}

void  Shape::printPerimeter(Shape& s) {
    cout << s.calcPerimeter() << endl;
}
void  Shape::printArea(Shape& s1) {
    cout << s1.calcArea() << endl;
}

//void Shape::SetDimensions(int dim[])
//{
//    switch (mapShapeType[tempShape.type])
//    {
//    case LINE: switch (dimIndex)
//        {
//        case 0: x1 = dim;
//            break;
//        case 1: y1 = dim;
//            break;
//        case 2: x2 = dim;
//            break;
//        case 3: y2 = dim;
//            break;
//        }
//        break;
//    case POLYLINE:
//        break;
//    case POLYGON:
//        break;
//    case RECTANGLE:
//        break;
//    case SQUARE:
//        break;
//    case ELLIPSE:
//        break;
//    case CIRCLE:
//        break;
//    case TEXT:
//        break;
//    }
//}

void Shape::InitializeMap()
{
    mapShapeType["Rectangle"] = RECTANGLE;
    mapShapeType["Polygon"]   = POLYGON;
    mapShapeType["Ellipse"]   = ELLIPSE;
    mapShapeType["Circle"]    = CIRCLE;
    mapShapeType["Line"]      = LINE;
    mapShapeType["Polyline"]  = POLYLINE;
    mapShapeType["Square"]    = SQUARE;
    mapShapeType["Text"]      = TEXT;
}


/******************************************************************************
 * This function will receive the input file from main() and store the file
 * appropriately into the vector of Shapes. It will store each line into its own
 * specified category.
 * returns - nothing
 ******************************************************************************/
void Shape::InitializeShapes()
{
    ifstream inFile;
    ShapeInfo tempShape;
    vector<ShapeInfo> temp;
    stringstream ss;
    string fileString;
    string tempString;
    string token;
    int    tempDim[8];
    int    loopCount;
    char   commaHold;

    inFile.open("ShapeInfo.txt");
    InitializeMap();
    loopCount = 0;

    /***************************************************************************
    * While Loop - loops through storing all information on the input file into
    * the correct category. Will continue until it reaches the end of the file
    * or the pointer is NULL
    ***************************************************************************/
    while (inFile)
    {
        getline(inFile, fileString);
        ss.str(fileString);
        ss >> tempString >> id;
        ss.clear();

        getline(inFile, fileString);
        ss.str(fileString);
        ss >> tempString >> tempShape.type;
        ss.clear();

        getline(inFile, tempString, ':');
        getline(inFile, fileString);
        istringstream stringSS(fileString);

        getline(stringSS, token, ',');
        istringstream intSS(token);

        while (intSS >> tempDim[loopCount] >> commaHold)
        {
            getline(stringSS, token, ',');
            istringstream intSS(token);

            loopCount++;
        }

        for (int index = 0; index < 4; index++)
        {
            cout << tempDim[index];
        }

//        switch (mapShapeType[tempShape.type])
//        {
//        case LINE:
//            break;
//        case POLYLINE:
//            break;
//        case POLYGON:
//            break;
//        case RECTANGLE:
//            break;
//        case SQUARE:
//            break;
//        case ELLIPSE:
//            break;
//        case CIRCLE:
//            break;
//        case TEXT:
//            break;
//        }

    }
}



//---------------------------Rectangle ----------------------------------
//float Rectangle::calcPerimeter(){
//    return ((width + length ) * 2 );
//}

//float Rectangle::calcArea(){
//    return (width * length);
//}
//void Rectangle::draw(void) {
//    // use QPainter object here
//    cout << "Drawing rect x1:" << x1 << " y1:" << y1 << " length: " << length << " width: " << width << endl;
//}
//void Rectangle::move(int dx, int dy) {
//    x1 += dx;
//    y1 += dy;
//}


////---------------------------Square----------------------------------------
//float Square::calcPerimeter() {
//    return (4 * length);
//}

//float Square::calcArea() {
//    return (length * length);
//}

//void Square::draw(void) {
//    // use QPainter object here
//    cout << "Drawing Square x1:" << x1 << " y1:" << y1 << " length: " << length  << endl;
//}
//void Square::move(int dx, int dy) {
//    x1 += dx;
//    y1 += dy;
//}

//// ------------------------Line----------------------------------------------------


//float Line::calcPerimeter() {
//    double dx = x2 - x1;
//    double dy = y2 - y1;
//    return sqrt(dx*dx + dy*dy);
//}

//float Line::calcArea() {
//    return 0;
//}

//void Line::draw(void) {
//    // use QPainter object here
//    cout << "Drawing Line x1:" << x1 << " y1:" << y1 << " x2:" << x2 << " y2 : " << y2 << endl;
//}

//void Line::move(int dx, int dy) {
//    x1 += dx;
//    y1 += dy;
//}

//// ------------------------PolyLine----------------------------------------------------

//float Polyline::calcPerimeter() {
//    double sum = 0;
//    for (int i = 0; i < numPoints - 1; i++){
//        double dx = x_values[i + 1] - x_values[i];
//        double dy = y_values[i + 1] - y_values[i];
//        sum += sqrt(dx*dx + dy*dy);
//    }
//    return sum;
//}

//float Polyline::calcArea() {
//    return 0;
//}

//void Polyline::draw(void) {
//    // use QPainter object here
//    cout << "Drawing Polyline " << endl;
//    for (int i = 0; i < numPoints; i++) {
//        cout << "(" << x_values[i] << "," << y_values[i] << ")" << endl;
//    }
//}

//void Polyline::move(int dx, int dy) {
//    for (int i = 0; i < numPoints; i++) {
//        x_values[i] += dx;
//        y_values[i] += dy;
//    }
//}

//// ------------------------Polygon----------------------------------------------------

//float Polygon::calcPerimeter() {
//    float sum = 0;
//    for (int i = 0; i < numPoints ; i++) {
//        double dx = x_values[(i + 1)%numPoints] - x_values[i];
//        double dy = y_values[(i + 1) % numPoints] - y_values[i];
//        sum += sqrt(dx*dx + dy*dy);
//    }
//    return (float)sum;
//}

//float Polygon::calcArea() {
//    float area = 0;
//    for (int i = 0; i < numPoints ; i++) {
//        area += -y_values[i] * x_values[(i + 1)%numPoints] + x_values[i] * y_values[(i + 1)%numPoints];
//    }
//    area = 0.5 * abs(area);
//    return area;
//}

//void Polygon::draw(void) {
//    // use QPainter object here
//    cout << "Drawing Polygon " << endl;
//    for (int i = 0; i < numPoints; i++) {
//        cout << "(" << x_values[i] << "," << y_values[i] << ")" << endl;
//    }
//}

//void Polygon::move(int dx, int dy) {
//    for (int i = 0; i < numPoints; i++) {
//        x_values[i] += dx;
//        y_values[i] += dy;
//    }
//}

/*
    int dimension(){
        return (r * )
    }
    */
