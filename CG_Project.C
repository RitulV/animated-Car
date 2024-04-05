#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int isEven(int n);
void drawQuadrants();
void drawLine(int arr[4]);
void drawRect(int x1, int y1, int x2, int y2);
void drawCircle(int x, int y, int r);
void drawArc(int x, int y, int r);
void multiplyMatrices(int mat1[3][3], int mat2[3][2], int result[3][2]);
void translateLine(int arr[4], int dx, int dy);
void scaleLine(int arr[4], int sx, int sy);
void rotateLine(int arr[4], int angle, char ch);

int whRad = 50; //wheel radius
void drawRoad(int lvl);
void drawCar(int x, int y); //car height is 300units
void drawCar2(int x, int y);
void drawWheels(int x, int y);
void drawWheels2(int x, int y);
void drawBody(int x_center, int y_center);
void drawDoors(int x_center, int y_center);
void drawWindows(int x_center, int y_center);
void drawLights(int x_center, int y_center);
void drawDiamond(int xc, int yc, int size);
void drawSign(int xc, int yc);
void drawCross(int xc, int yc);

int main() {

	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
    initwindow(getmaxwidth(), getmaxheight());


    for(int i=-650; i<-220; i=i+10){
        drawRoad(-150);
        drawSign(400,200);  
        drawCar(i,-100);
        delay(100);
        cleardevice();
    }
    drawRoad(-150);
    drawSign(400,200);  
    drawCar(-220,-100);
    delay(2000);
    cleardevice();
    for(int i=-220; i>-800; i=i-10){
        drawRoad(-150);
        drawSign(400,200);  
        drawCar(i,-100);
        delay(100);
        cleardevice();
    }

    // Wait for a key press
    getch();
    closegraph();
    return 0;
}

int isEven(int n){
    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

void drawRect(int x1, int y1, int x2, int y2){
    //take top-left(x1,y1) and bottom-right(x2,y2) coordinates
    int xmid = getmaxx()/2, ymid = getmaxy()/2;
    rectangle(x1+xmid, ymid-y1, x2+xmid, ymid-y2);
}

void drawCircle(int x, int y, int r){
    int xmid = getmaxx()/2, ymid = getmaxy()/2;
    circle(x+xmid, ymid-y, r);    
}

void drawQuadrants(){
    int xmax = getmaxx(), ymax = getmaxy(), xmid = getmaxx()/2, ymid = getmaxy()/2;
    // line(xmid, 0, xmid, ymax);
    line(0, ymid, xmax, ymid);
}

void drawLine(int arr[4]){
    int x1 = arr[0];
    int y1 = arr[1];
    int x2 = arr[2];
    int y2 = arr[3];
    int xmid = getmaxx()/2, ymid = getmaxy()/2;
    line(x1+xmid, ymid-y1, x2+xmid, ymid-y2);
}

void drawLine(int x1, int y1, int x2, int y2){
    int xmid = getmaxx()/2, ymid = getmaxy()/2;
    line(x1+xmid, ymid-y1, x2+xmid, ymid-y2);
}

void multiplyMatrices(int mat1[3][3], int mat2[3][2], int result[3][2]) {
    int i, j, k;

    // Initialize the result matrix to all zeros
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void multiplyMatrices(int mat1[3][3], int mat2[3][3], int result[3][3]) {
    int i, j, k;

    // Initialize the result matrix to all zeros
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void multiplyMatrices(double mat1[3][3], double mat2[3][2], double result[3][2]) {
    int i, j, k;

    // Initialize the result matrix to all zeros
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void multiplyMatrices(double mat1[3][3], double mat2[3][3], double result[3][3]) {
    int i, j, k;

    // Initialize the result matrix to all zeros
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void translateLine(int arr[4], int dx, int dy) {

    printf("\nNew coordinate of line before translating are: (%d,%d) & (%d,%d)",arr[0], arr[1], arr[2], arr[3]);

    int x1 = arr[0];
    int y1 = arr[1];
    int x2 = arr[2];
    int y2 = arr[3];
    int M1[3][3] = {{1,0,dx},{0,1,dy},{0,0,1}}; 
    int M2[3][2] = {{x1,x2},{y1,y2},{1,1}}; 
    int R[3][2];
    multiplyMatrices(M1,M2,R);

    //drawLine(R[0][0], R[1][0], R[0][1], R[1][1]);

    arr[0] =  R[0][0];
    arr[1] =  R[1][0];
    arr[2] =  R[0][1];
    arr[3] =  R[1][1];

    printf("\nNew coordinate of line after translating are: (%d,%d) & (%d,%d)",R[0][0], R[1][0], R[0][1], R[1][1]);
}

void scaleLine(int arr[4], int sx, int sy) {

    printf("\nCoordinates of the line before scaling are: (%d,%d) & (%d,%d)", arr[0], arr[1], arr[2], arr[3]);

    int x1 = arr[0];
    int y1 = arr[1];
    int x2 = arr[2];
    int y2 = arr[3];

    // Calculate the midpoint of the line
    int xmid = (x1 + x2) / 2;
    int ymid = (y1 + y2) / 2;

    // Translate the line to the origin
    x1 -= xmid;
    y1 -= ymid;
    x2 -= xmid;
    y2 -= ymid;

    // Apply scaling
    x1 *= sx;
    y1 *= sy;
    x2 *= sx;
    y2 *= sy;

    // Translate the line back to its original position
    x1 += xmid;
    y1 += ymid;
    x2 += xmid;
    y2 += ymid;

    // Update the coordinates in the array
    arr[0] = x1;
    arr[1] = y1;
    arr[2] = x2;
    arr[3] = y2;

    printf("\nCoordinates of the line after scaling are: (%d,%d) & (%d,%d)", arr[0], arr[1], arr[2], arr[3]);
}

void rotateLine(int arr[4], int angle, char ch) {
    double x1 = (double)arr[0];
    double y1 = (double)arr[1];
    double x2 = (double)arr[2];
    double y2 = (double)arr[3];
    double radians = (double)(angle * (M_PI / 180.0));
    double cos_theta = cos(radians);
    double sin_theta = sin(radians);

    double x1_rotated, y1_rotated, x2_rotated, y2_rotated;

    if (ch == 'c') {
        x1_rotated = x1 * cos_theta - y1 * sin_theta;
        y1_rotated = x1 * sin_theta + y1 * cos_theta;
        x2_rotated = x2 * cos_theta - y2 * sin_theta;
        y2_rotated = x2 * sin_theta + y2 * cos_theta;
    } else if (ch == 'a') {
        x1_rotated = x1 * cos_theta + y1 * sin_theta;
        y1_rotated = -x1 * sin_theta + y1 * cos_theta;
        x2_rotated = x2 * cos_theta + y2 * sin_theta;
        y2_rotated = -x2 * sin_theta + y2 * cos_theta;
    }

    arr[0] = (int)x1_rotated;
    arr[1] = (int)y1_rotated;
    arr[2] = (int)x2_rotated;
    arr[3] = (int)y2_rotated;

    printf("\nNew coordinates of the line are: (%d,%d) & (%d,%d)", arr[0], arr[1], arr[2], arr[3]);
}

void rotateLine(double x1, double y1, double x2, double y2, int angle, char ch) {
    double radians = (double)(angle * (M_PI / 180.0));
    double cos_theta = cos(radians);
    double sin_theta = sin(radians);

    double x1_rotated, y1_rotated, x2_rotated, y2_rotated;

    if (ch == 'c') {
        x1_rotated = x1 * cos_theta - y1 * sin_theta;
        y1_rotated = x1 * sin_theta + y1 * cos_theta;
        x2_rotated = x2 * cos_theta - y2 * sin_theta;
        y2_rotated = x2 * sin_theta + y2 * cos_theta;
    } else if (ch == 'a') {
        x1_rotated = x1 * cos_theta + y1 * sin_theta;
        y1_rotated = -x1 * sin_theta + y1 * cos_theta;
        x2_rotated = x2 * cos_theta + y2 * sin_theta;
        y2_rotated = -x2 * sin_theta + y2 * cos_theta;
    }

    int arr[4];
    arr[0] = (int)x1_rotated;
    arr[1] = (int)y1_rotated;
    arr[2] = (int)x2_rotated;
    arr[3] = (int)y2_rotated;

    drawLine(arr[0], arr[1], arr[2], arr[3]);
}

void drawRoad(int lvl){
    int xmax = getmaxx();
    drawLine(-xmax, lvl, xmax, lvl);
}

void drawCar(int x, int y){
    drawWheels(x, y);
    drawBody(x, y);
    drawDoors(x, y);
    drawWindows(x, y);
    drawLights(x, y);
}

void drawCar2(int x, int y){
    drawWheels2(x, y);
    drawBody(x, y);
    drawDoors(x, y);
    drawWindows(x, y);
    drawLights(x, y);
}

void drawWheels(int x, int y){
    int di=6*whRad;

    // wheel 1
    drawCircle(x, y, whRad);
    drawLine(x, y+whRad, x, y-whRad);
    drawLine(x+whRad, y, x-whRad, y);
    //wheel 2
    drawCircle(x+di, y, whRad);
    drawLine(x+di, y+whRad, x+di, y-whRad);
    drawLine(x+whRad+di, y, x-whRad+di, y);
}

void drawWheels2(int x, int y){
    int di=6*whRad;
    double rt = 1.40;

    //wheel 1
    drawCircle(x, y, whRad);
    drawLine(x+(whRad*rt)/2, y-(whRad*rt)/2, x-(whRad*rt)/2, y+(whRad*rt)/2);
    drawLine(x+(whRad*rt)/2, y+(whRad*rt)/2, x-(whRad*rt)/2, y-(whRad*rt)/2);
    //wheel 2
    drawCircle(x+di, y, whRad);
    drawLine(x+di+(whRad*rt)/2+12, y+whRad-(whRad*rt)/2, x+di-(whRad*rt)/2-12, y-whRad+(whRad*rt)/2);
    drawLine(x+di+(whRad*rt)/2+12, y-whRad+(whRad*rt)/2, x+di-(whRad*rt)/2-12, y+whRad-(whRad*rt)/2);
}

void drawArc(int x, int y, int r){
    int xmid = getmaxx()/2, ymid = getmaxy()/2;
    arc(x+xmid, ymid-y, 0, 180, r);  
}

void drawBody(int x_center, int y_center) {
    drawArc(x_center, y_center, whRad+20);
    drawArc(x_center + (6*whRad), y_center, whRad+20);
    drawLine(x_center + whRad +20, y_center, x_center + (4*whRad) +30, y_center);
    drawLine(x_center - (2*whRad) -30, y_center, x_center - whRad -20, y_center); //backside lower body bumper
    drawLine(x_center + (6*whRad) +70, y_center, x_center + (12*whRad), y_center); //frontside lower body bumper
    drawLine(x_center + (12*whRad), y_center, x_center + (12*whRad), y_center+(2*whRad)); //front bumper
    drawLine(x_center + (8*whRad)+7, y_center+(2*whRad), x_center + (12*whRad), y_center+(2*whRad));
    drawLine(x_center + (8*whRad)+7, y_center+(2*whRad),x_center + (8*whRad)+7, y_center+(2*whRad)+15);

    drawLine(x_center + (8*whRad)-7, y_center+(2*whRad)+15, x_center+(11.5*whRad), y_center+(2*whRad)+15); //hood
    drawLine(x_center+(11.5*whRad), y_center+(2*whRad)+15 ,x_center + (12*whRad), y_center+(2*whRad));

    drawLine(x_center + (6.5*whRad), y_center + (5*whRad), x_center + (8*whRad)-7, y_center+(2*whRad)+15);//windshield
    drawLine(x_center, y_center + (5*whRad), x_center + (6.5*whRad), y_center + (5*whRad)); // roof
    drawLine(x_center, y_center + (5*whRad), x_center - (2*whRad) -30, y_center + (1.8*whRad)); //trunk
    drawLine(x_center - (2*whRad) -30, y_center, x_center - (2*whRad) -30, y_center + (1.8*whRad)); //trunk height

    drawCircle(x_center - (1.4*whRad) , y_center+(2*whRad),15); //fuel entry
}

void drawDoors(int x_center, int y_center){
    int xmid = getmaxx()/2, ymid = getmaxy()/2;

    // rear door
    drawLine(x_center + (3*whRad) -10 , y_center + (4.5*whRad), x_center + (3*whRad) -10, y_center + (0.5*whRad)); // middle frame line
    drawLine(x_center, y_center + (4.5*whRad), x_center + (3*whRad) - 10, y_center + (4.5*whRad)); // top
    drawLine(x_center, y_center + (4.5*whRad), x_center, y_center + (1*whRad) + 40); // left (-150,140)
    drawLine(x_center + (1*whRad) + 35 , y_center + (0.5*whRad), x_center + (3*whRad) -10, y_center + (0.5*whRad)); //bottom (-60,75) 
    arc(x_center+xmid, ymid-y_center, 15, 89, (1*whRad) + 40 );

    // front door
    drawLine(x_center + (3*whRad) , y_center + (4.5*whRad), x_center + (3*whRad), y_center + (0.5*whRad)); // middle frame line
    drawLine(x_center + (3*whRad), y_center + (4.5*whRad), x_center+ (6*whRad), y_center + (4.5*whRad)); // top
    drawLine(x_center+ (6*whRad), y_center + (4.5*whRad), x_center+ (6*whRad), y_center + (1*whRad) + 40); // right
    drawLine(x_center + (3*whRad), y_center + (0.5*whRad), x_center + (4.2*whRad) + 3, y_center + (0.5*whRad)); //bottom 
    arc(x_center + (6*whRad) + xmid, ymid - y_center, 90, 164, (1*whRad) + 40 );
}

void drawWindows(int x_center, int y_center){
    //rear windows
    drawRect(x_center +10, y_center + (4.5*whRad) -10, x_center + (2.5*whRad) , y_center + (2.5*whRad)+10);
    drawRect(x_center +10, y_center + (2.3*whRad) -10, x_center + 30 , y_center + (2.3*whRad) -15);

    //front windows
    drawRect(x_center + (3*whRad) +10, y_center + (4.5*whRad)-10, x_center+ (6*whRad)-10, y_center + (2.5*whRad)+10);
    drawRect(x_center + (3*whRad) +10, y_center + (2.3*whRad) -10, x_center + (3*whRad) +30 , y_center + (2.3*whRad) -15);
}

void drawLights(int x_center, int y_center){
    int xmid = getmaxx()/2, ymid = getmaxy()/2;

    // tail-lights
    drawRect(x_center - (2*whRad) -30, y_center + (1.5*whRad), x_center - (2*whRad) -15, y_center + (0.25*whRad));
    drawRect(x_center - (2*whRad) -30, y_center + (1.3*whRad), x_center - (2*whRad) -20, y_center + (0.35*whRad));

    // head-lights
    arc(xmid + x_center + (12*whRad), ymid-(y_center+whRad), 90, 270, 30);
    arc(xmid + x_center + (12*whRad), ymid-(y_center+whRad), 90, 270, 25);
}

void drawDiamond(int xc, int yc, int size){
    drawLine(xc, yc - size, xc + size, yc);
    drawLine(xc + size, yc, xc, yc + size);
    drawLine(xc, yc + size, xc - size, yc);
    drawLine(xc - size, yc, xc, yc - size);
}

void drawSign(int xc, int yc){
    drawDiamond(xc,yc,50);
    drawDiamond(xc,yc,60);
    drawCircle(xc,yc, 25);
    drawRect(xc-15,yc+5,xc+15,yc-5);
    drawLine(xc-5, yc-55, xc-5, yc-350);
    drawLine(xc+5, yc-55, xc+5, yc-350);
}