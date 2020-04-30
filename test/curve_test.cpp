#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>

#include "curve.h"

#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 720
#define CONTROL_RADIUS 0.031
#define MATH_TAU 6.283185307179586
#define STEP_SIZE .01

typedef std::array<BEZ_DTYPE, BEZ_DIMS> bezVect;

void drawCircle(float x, float y, float radius, float theta_step_size) {
    glBegin(GL_POLYGON);
    for (float theta = 0; theta < MATH_TAU; theta += theta_step_size) {
        glVertex2f(x + radius * cosf(theta), y + radius * sinf(theta));
    }
    glEnd();
}

void drawCurve(const Curve& c) {
    if (c.anchorCount() == 0) {
        return;
    }
    bezVect curr_pos;
    if (c.anchorCount() == 1) {
        curr_pos = c.getPositionAt(0);
        drawCircle(curr_pos[0], curr_pos[1], .006, STEP_SIZE);
    }

    float t;
    glBegin(GL_LINES);
    bezVect last_pos;
    last_pos = c.getPositionAt(0);
    for (t = STEP_SIZE; t <= 1; t += STEP_SIZE) {
        curr_pos = c.getPositionAt(t);
        glVertex2f(last_pos[0], last_pos[1]);
        glVertex2f(curr_pos[0], curr_pos[1]);
        last_pos = curr_pos;
    }
    glEnd();
}

int main() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Bezier", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "GLEW Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;


    std::vector<bezVect> anchor_points;

    anchor_points.push_back(bezVect{.0, .1});
    anchor_points.push_back(bezVect{.2, .3});
    anchor_points.push_back(bezVect{.4, .5});
    anchor_points.push_back(bezVect{.6, .7});
    anchor_points.push_back(bezVect{.8, .9});

    Curve c0();
    Curve c1(anchor_points);
    bezVect v;

    printf("\nAnchor points according to getPositionAt(...):\n");
    for (float t = 0; t < 5.; t++) {
        v = c1.getPositionAt(t / (float)(c1.bezier_count));
        printf("(%6.1f, %6.1f)\n", v[0], v[1]);
    }

    int mouse_state, last_mouse_state = GLFW_PRESS + 1;
    double cursor_x, cursor_y;
    int edit_point;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        mouse_state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
        if (mouse_state == GLFW_PRESS) {
            glfwGetCursorPos(window, &cursor_x, &cursor_y);
            cursor_x = cursor_x / (double)(WINDOW_WIDTH) * 2. - 1.;
            cursor_y = -cursor_y / (double)(WINDOW_HEIGHT) * 2. + 1.;

            if (last_mouse_state != GLFW_PRESS) {
                edit_point = -1;
                for (int i = 0; i < c1.anchorCount(); i++) {
                    v = c1.getAnchor(i);
                    if ((cursor_x - v[0]) * (cursor_x - v[0]) + (cursor_y - v[1]) * (cursor_y - v[1]) <= CONTROL_RADIUS * CONTROL_RADIUS) {
                        edit_point = i;
                        break;
                    }
                }
            }

            if (edit_point >= 0) {
                v[0] = cursor_x;
                v[1] = cursor_y;
                c1.setAnchor(v, edit_point);
            }
            c1.updateControlPoints();
        }
        else {
            edit_point = -1;
        }
        last_mouse_state = mouse_state;

        glColor3f(.1f, .3f, .8f);
        for (int i = 0; i < c1.anchorCount(); i++) {
            v = c1.getAnchor(i);
            drawCircle(v[0], v[1], CONTROL_RADIUS, MATH_TAU * .05);
        }

        bezVect v2 = c1.getAnchor(0);
        glColor3f(.6f, .1f, .2f);
        drawCircle(v2[0], v2[1], CONTROL_RADIUS * .5, MATH_TAU * .05);
        for (int i = 1; i < c1.anchorCount(); i++) {
            v = c1.B_points[i];
            drawCircle(v[0], v[1], CONTROL_RADIUS * .5, MATH_TAU * .05);

            glBegin(GL_LINES);
            glVertex2f(v2[0], v2[1]);
            glVertex2f(v[0], v[1]);
            glEnd();
            v2 = v;
        }

        glColor3f(1.f, 1.f, 1.f);
        drawCurve(c1);

 /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

int WinMain() {
    return main();
}
