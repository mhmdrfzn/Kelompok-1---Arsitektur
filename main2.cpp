#include <GL/glut.h>

// Camera position
float cameraX = 6.0f, cameraY = 4.0f, cameraZ = 10.0f;

// Boundaries of the room
float roomMinX = -5.0f, roomMaxX = 5.0f;
float roomMinY = -1.0f, roomMaxY = 3.0f;
float roomMinZ = -5.0f, roomMaxZ = 5.0f;

bool isLampOn = true; // Lampu awalnya menyala
GLfloat lightPosition[] = {0.0f, 2.5f, 0.0f, 1.0f}; // Posisi lampu

void init() {
    glClearColor(0.8f, 0.9f, 1.0f, 1.0f); // Background color (light blue)
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);

    GLfloat lightAmbient[4] = { 0.4f, 0.4f, 0.0f, 0.0f };
    GLfloat lightDiffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat lightSpecular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
}

void drawWall(float width, float height, float r, float g, float b) {
	
    glColor3f(r, g, b);
    glPushMatrix();
    glScalef(width, height, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();
    
}

void drawFloorOrCeiling(float width, float depth, float r, float g, float b) {
	
    glColor3f(r, g, b);
    glPushMatrix();
    glScalef(width, 0.1f, depth);
    glutSolidCube(1.0);
    glPopMatrix();
    
}

void drawWindow(float width, float height, float r, float g, float b) {
	
    glColor3f(r, g, b);
    glPushMatrix();
    glScalef(1.0f, height, 0.05f);
    glutSolidCube(0.5);
    glPopMatrix();
    
}

void drawTable() {
    // Draw the tabletop
    
    glColor3f(0.7f, 0.4f, 0.2f); // Brown color
    glPushMatrix();
    glTranslatef(0.0f, -0.5f, 0.0f);
    glScalef(1.5f, 0.1f, 1.0f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw the four legs
    glColor3f(0.9f, 0.5f, 0.2f);
    float legHeight = 0.5f;
    float legWidth = 0.1f;
    float offsets[4][3] = {
        {-0.7f, -1.0f, -0.45f},
        {0.7f, -1.0f, -0.45f},
        {-0.7f, -1.0f, 0.45f},
        {0.7f, -1.0f, 0.45f}
    };

    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(offsets[i][0], offsets[i][1] + legHeight / 2.0f, offsets[i][2]);
        glScalef(legWidth, legHeight, legWidth);
        glutSolidCube(1.0);
        glPopMatrix();
    }
    
}

void drawMeja() {
    
    glColor3f(0.5f, 0.2f, 0.1f); // Warna kayu
    glPushMatrix();
    glTranslatef(4.5f, -0.5f, 0.0f);
    glScalef(0.5f, 1.0f, 3.0f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(4.5f, -0.5f, 0.0f);
    glScalef(0.5f, 1.0f, 3.0f);
    glutWireCube(1.0);
    glPopMatrix();

    //laci tengah
    glColor3f(0.8f, 0.6f, 0.4f); // Warna kulit
    glPushMatrix();
    glTranslatef(4.3f, -0.2f, 0.0f);
    glScalef(0.2f, 0.2f, 2.0f);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3f(0.0f, 0.0f, 0.0f); 
    glPushMatrix();
    glTranslatef(4.2f, -0.2f, 0.0f);
    glutSolidSphere(0.06f, 20, 20);
    glPopMatrix();

    //laci kanan
    glColor3f(0.8f, 0.6f, 0.4f); // Warna kayu
    glPushMatrix();
    glTranslatef(4.3f, -0.5f, 1.0f);
    glScalef(0.2f, 0.2f, 0.5f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glColor3f(0.0f, 0.0f, 0.0f); 
    glPushMatrix();
    glTranslatef(4.2f, -0.5f, 1.0f);
    glutSolidSphere(0.05f, 20, 20);
    glPopMatrix();
    
    //laci kiri
    glColor3f(0.8f, 0.6f, 0.4f); // Warna kayu
    glPushMatrix();
    glTranslatef(4.3f, -0.5f, -1.0f);
    glScalef(0.2f, 0.2f, 0.5f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glColor3f(0.0f, 0.0f, 0.0f); 
    glPushMatrix();
    glTranslatef(4.2f, -0.5f, -1.0f);
    glutSolidSphere(0.05f, 20, 20);
    glPopMatrix(); 
}



void drawLamp() {
    // Draw the lamp
    glColor3f(1.0f, 1.0f, 0.8f); // Light yellow for the bulb
    glPushMatrix();
    glTranslatef(0.0f, 2.5f, 0.0f);
    glutSolidSphere(0.2f, 20, 20);
    glPopMatrix();

    glColor3f(0.5f, 0.5f, 0.5f); // Gray for the lamp base
    glPushMatrix();
    glTranslatef(0.0f, 2.7f, 0.0f);
    glScalef(0.1f, 0.6f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

}

void drawCabinet() {
    // Draw the main body of the cabinet
    glColor3f(0.6f, 0.3f, 0.1f); // Brown color
    glPushMatrix();
    glTranslatef(-4.5f, 0.1f, 0.0f);
    glScalef(0.5f, 2.0f, 1.5f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw shelves inside the cabinet
    glColor3f(0.8f, 0.4f, 0.2f); // Lighter brown
    for (float y = -0.75f; y <= 0.75f; y += 0.5f) {
        glPushMatrix();
        glTranslatef(-4.5f, y, 0.0f);
        glScalef(0.9f, 0.05f, 1.0f);
        glutSolidCube(1.0);
        glPopMatrix();
    }
}
void drawSofa(){
	
	glColor3f(0.25f, 0.25f, 0.25f); 
    glPushMatrix();
    glTranslatef(0.0f, -0.8f, -3.0f);
    glScalef(3.0f, 0.5f, 1.5f);
    glutSolidCube(1.0);
    //glColor3f(1.0f, 1.0f, 1.0f);
    //glutWireCube(1.0);
    glPopMatrix();
    
    glColor3f(0.25f, 0.25f, 0.25f); 
    glPushMatrix();
    glTranslatef(-2.19f, -0.8f, -2.28f);
    glScalef(1.5f, 0.5f, 3.0f);
    glutSolidCube(1.0);
    //glColor3f(1.0f, 1.0f, 1.0f);
    //glutWireCube(1.0);
    glPopMatrix();
    
    glColor3f(0.25f, 0.25f, 0.25f); 
    glPushMatrix();
    glTranslatef(-0.72f, -0.8f, -3.5f);
    glScalef(4.43f, 1.8f, 0.5f);
    glutSolidCube(1.0);
    //glColor3f(1.0f, 1.0f, 1.0f);
    //glutWireCube(1.0);
    glPopMatrix();
    
    glColor3f(0.25f, 0.25f, 0.25f); 
    glPushMatrix();
    glTranslatef(-2.69f, -0.8f, -2.015f);
    glScalef(0.5f, 1.8f, 2.5f);
    glutSolidCube(1.0);
    //glColor3f(1.0f, 1.0f, 1.0f);
    //glutWireCube(1.0);
    glPopMatrix();
    
    glColor3f(0.25f, 0.25f, 0.25f); 
    glPushMatrix();
    glTranslatef(1.5f, -0.8f, -3.0f);
    glScalef(0.5f, 1.8f, 1.5f);
    glutSolidCube(1.0);
    //glColor3f(1.0f, 1.0f, 1.0f);
    //glutWireCube(1.0);
    glPopMatrix();
}

void drawChair(float x, float y, float z, float rotation) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(rotation, 0.0f, 1.0f, 0.0f);

    // Chair seat
    glColor3f(0.6f, 0.3f, 0.1f); 
    glPushMatrix();
    glScalef(0.8f, 0.1f, 0.8f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Chair backrest
    glPushMatrix();
    glTranslatef(0.0f, 0.45f, -0.35f);
    glScalef(0.8f, 0.9f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Chair legs
    glColor3f(0.4f, 0.2f, 0.1f);
    float legHeight = 0.4f;
    float legWidth = 0.1f;
    float offsets[4][3] = {
        {-0.35f, -0.2f, -0.35f},
        {0.35f, -0.2f, -0.35f},
        {-0.35f, -0.2f, 0.35f},
        {0.35f, -0.2f, 0.35f}
    };
for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(offsets[i][0], offsets[i][1], offsets[i][2]);
        glScalef(legWidth, legHeight, legWidth);
        glutSolidCube(1.0);
        glPopMatrix();
    }

    glPopMatrix();
}

void drawFlowerPot(float x, float y, float z) {
    // Draw the pot
    glColor3f(0.2f, 0.3f, 0.3f); // Brown color for the pot
    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidSphere(0.2f, 20, 20);
    glPopMatrix();

// Gambar batang (gunakan kubus untuk batang)
    glColor3f(0.4f, 0.2f, 0.1f); // Warna batang (coklat)
    glPushMatrix();
    glTranslatef(x, y + 0.3f, z); // Posisi batang sedikit di atas pot
    glScalef(0.05f, 0.3f, 0.05f); // Ukuran batang (panjang dan tipis)
    glutSolidCube(1.0); // Batang menggunakan kubus yang dipanjangkan
    glPopMatrix();
    
    // Draw the flowers
    glColor3f(1.0f, 0.0f, 0.0f); // Red flowers
    glPushMatrix();
    glTranslatef(x, y + 0.4f, z); // Position flower at the top of the pot
    glutSolidSphere(0.1f, 10, 10); // Draw a flower as a sphere
    glPopMatrix();

    glColor3f(1.0f, 0.75f, 0.8f); // pinky flower
    glPushMatrix();
    glTranslatef(x + 0.1f, y + 0.4f, z); // Slightly move to the side
    glutSolidSphere(0.1f, 10, 10); // Draw the second flower
    glPopMatrix();
    
	glColor3f(0.6f, 0.2f, 0.8f); // Bunga ungu
    glPushMatrix();
    glTranslatef(x - 0.1f, y + 0.3f, z); // Geser sedikit ke kiri dan naik sedikit
    glutSolidSphere(0.1f, 10, 10); // Bunga ungu
    glPopMatrix();
}

void drawFlowerPot2(float x, float y, float z) {
    // Draw the pot
    glColor3f(0.2f, 0.3f, 0.3f); 
    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidSphere(0.2f, 20, 20);
    glPopMatrix();

// Gambar batang (gunakan kubus untuk batang)
    glColor3f(0.4f, 0.2f, 0.1f); // Warna batang (coklat)
    glPushMatrix();
    glTranslatef(x, y + 0.3f, z); // Posisi batang sedikit di atas pot
    glScalef(0.05f, 0.3f, 0.05f); // Ukuran batang (panjang dan tipis)
    glutSolidCube(1.0); // Batang menggunakan kubus yang dipanjangkan
    glPopMatrix();
    
    // Draw the flowers
    glColor3f(1.0f, 0.0f, 0.0f); // Red flowers
    glPushMatrix();
    glTranslatef(x, y + 0.4f, z); // Position flower at the top of the pot
    glutSolidSphere(0.1f, 10, 10); // Draw a flower as a sphere
    glPopMatrix();

    glColor3f(1.0f, 0.75f, 0.8f); // pinky flower
    glPushMatrix();
    glTranslatef(x + 0.1f, y + 0.4f, z); // Slightly move to the side
    glutSolidSphere(0.1f, 10, 10); // Draw the second flower
    glPopMatrix();
    
	glColor3f(0.6f, 0.2f, 0.8f); // Bunga ungu
    glPushMatrix();
    glTranslatef(x - 0.1f, y + 0.3f, z); // Geser sedikit ke kiri dan naik sedikit
    glutSolidSphere(0.1f, 10, 10); // Bunga ungu
    glPopMatrix();
}

void drawFlowerPot3(float x, float y, float z) {
    // Draw the pot
    glColor3f(0.1f, 0.2f, 0.1f); 
    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidSphere(0.3f, 30, 20);
    glPopMatrix();

// Gambar batang (gunakan kubus untuk batang)
    glColor3f(0.4f, 0.2f, 0.1f); // Warna batang (coklat)
    glPushMatrix();
    glTranslatef(x, y + 0.4f, z); // Posisi batang sedikit di atas pot
    glScalef(0.05f, 0.4f, 0.05f); // Ukuran batang (panjang dan tipis)
    glutSolidCube(1.0); // Batang menggunakan kubus yang dipanjangkan
    glPopMatrix();
    
    // Draw the flowers
    glColor3f(1.0f, 0.0f, 0.0f); // Red flowers
    glPushMatrix();
    glTranslatef(x, y + 0.7f, z); // Position flower at the top of the pot
    glutSolidSphere(0.2f, 10, 10); // Draw a flower as a sphere
    glPopMatrix();

    glColor3f(1.0f, 0.75f, 0.8f); // pinky flower
    glPushMatrix();
    glTranslatef(x + 0.2f, y + 0.4f, z); // Slightly move to the side
    glutSolidSphere(0.2f, 10, 10); // Draw the second flower
    glPopMatrix();
    
	glColor3f(0.6f, 0.2f, 0.8f); // Bunga ungu
    glPushMatrix();
    glTranslatef(x - 0.2f, y + 0.5f, z); // Geser sedikit ke kiri dan naik sedikit
    glutSolidSphere(0.2f, 10, 10); // Bunga ungu
    glPopMatrix();
}

void drawPainting(float x, float y, float z, float width, float height, float* frameColor, float* paintingColor) {
    // Menggambar bingkai lukisan
    glColor3f(frameColor[0], frameColor[1], frameColor[2]);
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.05f, height, width);  // Menyesuaikan ketebalan bingkai
    glutSolidCube(1.0);
    glPopMatrix();

    // Menggambar isi lukisan di dalam bingkai
    glColor3f(paintingColor[0], paintingColor[1], paintingColor[2]);
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.02f, height - 0.1f, width - 0.1f);  // Menyesuaikan ukuran lukisan agar pas dalam bingkai
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawCarpet(float x, float y, float z, float width, float depth) {
    glColor3f(0.8f, 0.6f, 0.4f); // Beige carpet
    glPushMatrix();
    glTranslatef(0.0f, -0.9f, 0.0);
    glScalef(width, 0.02f, depth); // Thin carpet
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawRoom() {
    // Floor
    glPushMatrix();
    glTranslatef(0.0f, -1.0f, 0.0f);
    drawFloorOrCeiling(10.0f, 10.0f, 0.7f, 0.7f, 0.7f); // Gray floor
    glPopMatrix();

    // Ceiling
    glPushMatrix();
    glTranslatef(0.0f, 3.0f, 0.0f);
    drawFloorOrCeiling(10.0f, 10.0f, 1.0f, 1.0f, 1.0f); // White ceiling
    glPopMatrix();

    // Back Wall
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, -5.0f);
    drawWall(10.0f, 4.0f, 0.8f, 0.8f, 0.8f); // Light gray wall
    glPopMatrix();
	
	//front wall
	glPushMatrix();
    glTranslatef(-0.0f, 1.0f, 5.0f);
    drawWall(10.0f, 4.0f, 0.8f, 0.8f, 0.8f); // Light gray wall
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.5f, 1.0f, 4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.9f, 1.0f, 4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.5f, 0.4f, 4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.9f, 0.4f, 4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();
    
    //kanan
    glPushMatrix();
    glTranslatef(2.5f, 1.0f, 4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.9f, 1.0f, 4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.5f, 0.4f, 4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.9f, 0.4f, 4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();
    
    // Left Wall
    glPushMatrix();
    glTranslatef(-5.0f, 1.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawWall(10.0f, 4.0f, 0.8f, 0.8f, 0.8f);
    glPopMatrix();

    // Right Wall
    glPushMatrix();
    glTranslatef(5.0f, 1.0f, 0.0f);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    drawWall(10.0f, 4.0f, 0.8f, 0.8f, 0.8f);
    glPopMatrix();

    // Add windows to the back wall
    glPushMatrix();
    glTranslatef(-2.5f, 1.0f, -4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.9f, 1.0f, -4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.5f, 0.4f, -4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.9f, 0.4f, -4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();
    
    //kanan
    glPushMatrix();
    glTranslatef(2.5f, 1.0f, -4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.9f, 1.0f, -4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.5f, 0.4f, -4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.9f, 0.4f, -4.95f);
    drawWindow(2.0f, 1.0f, 0.5f, 0.8f, 1.0f); // Light blue window
    glPopMatrix();
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Camera position
    gluLookAt(cameraX, cameraY, cameraZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Draw the room
    drawRoom();

    // Draw the table
    drawTable();
    drawSofa();
    drawMeja();
    
    drawLamp();
    
    drawCabinet();

    drawChair(-0.9f, -0.6f, 4.5f, 180.0f);
	drawChair(0.9f, -0.6f, 4.5f, 180.0f);

	drawFlowerPot(0.0f, -0.3f, 0.0f); 
	drawFlowerPot2(4.5f, 0.2f, 1.2f); 
	drawFlowerPot3(0.0f, -0.6f, 4.5f);
	
	drawCarpet(0.2f, -1.0f, 0.2f, 3.0f, 2.0f);
	
	float frameColor[3] = {0.1f, 0.1f, 0.1f};
    float paintingColor[3] = {1.0f, 0.8f, 0.6f}; 
    drawPainting(4.5f, 1.0f, 0.0f, -1.8f, 1.5f, frameColor, paintingColor);

    glutSwapBuffers();
}

// Handle keyboard input
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': // Move forward (into the room)
            cameraZ -= 0.5f;
            break;
        case 's': // Move backward (out of the room)
            cameraZ += 0.5f;
            break;
        case 'a': // Move left
            cameraX -= 0.5f;
            break;
        case 'd': // Move right
            cameraX += 0.5f;
            break;
        case 'q': // Move up
            cameraY += 0.5f;
            break;
        case 'e': // Move down
            cameraY -= 0.5f;
            break;
        case 'l': // Toggle lamp on/off
            isLampOn = !isLampOn;
            if (isLampOn) {
                glEnable(GL_LIGHT0); // Turn on the light
            } else {
                glDisable(GL_LIGHT0); // Turn off the light
            }
            break;
        case 'x':  // Escape key to exit
            exit(0);
    }

    // Ensure the camera stays within boundaries
    if (cameraX < roomMinX) cameraX = roomMinX;
    if (cameraX > roomMaxX) cameraX = roomMaxX;
    if (cameraY < roomMinY) cameraY = roomMinY;
    if (cameraY > roomMaxY) cameraY = roomMaxY;
    if (cameraZ < roomMinZ) cameraZ = roomMinZ;
    if (cameraZ > roomMaxZ) cameraZ = roomMaxZ;

    glutPostRedisplay(); // Redraw the scene with updated camera position
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Room with Table and Windows");
    init();
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress); // Register keyboard handler
    glutMainLoop();
    return 0;
}
