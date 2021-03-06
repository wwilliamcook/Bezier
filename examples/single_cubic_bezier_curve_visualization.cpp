#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#include "bezier.h"


#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 720
#define CONTROL_RADIUS 0.031
#define MATH_TAU 6.283185307179586
#define STEP_SIZE .01
#define FLATNESS_THRESHOLD 1.001

float control_points[4][2] = {
    {-0.63, -0.675},
    {-0.92, 0.613},
    {0.347, -0.403},
    {0.814, 0.67}
};

void drawCircle(float x, float y, float radius, float theta_step_size);

void drawBezier(float x0, float y0,
                float x1, float y1,
                float x2, float y2,
                float x3, float y3);

void drawBoundingBox(float x0, float y0,
                     float x1, float y1,
                     float x2, float y2,
                     float x3, float y3);


int main(int argc, char* argv[])
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Bezier", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "GLEW Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    int mouse_state, last_mouse_state = GLFW_PRESS + 1;
    double cursor_x, cursor_y;
    int edit_point;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        mouse_state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
        if (mouse_state == GLFW_PRESS) {
            glfwGetCursorPos(window, &cursor_x, &cursor_y);
            cursor_x = cursor_x / (double)(WINDOW_WIDTH) * 2. - 1.;
            cursor_y = -cursor_y / (double)(WINDOW_HEIGHT) * 2. + 1.;

            if (last_mouse_state != GLFW_PRESS) {
                edit_point = -1;
                for (int i = 0; i < 4; i++) {
                    if ((cursor_x - control_points[i][0])*(cursor_x - control_points[i][0]) + (cursor_y - control_points[i][1])*(cursor_y - control_points[i][1]) <= CONTROL_RADIUS*CONTROL_RADIUS) {
                        edit_point = i;
                        break;
                    }
                }
            }

            if (edit_point >= 0) {
                control_points[edit_point][0] = cursor_x;
                control_points[edit_point][1] = cursor_y;
            }
        }
        else {
            edit_point = -1;
        }
        last_mouse_state = mouse_state;
        
        for (int i = 0; i < 4; i++) {
            if (i % 3 == 0) {
                glColor3f(.1f, .3f, .8f);
            }
            else if (i % 3 == 1) {
                glColor3f(.6f, .1f, .2f);
            }
            drawCircle(control_points[i][0], control_points[i][1], CONTROL_RADIUS, MATH_TAU * .05);
        }

        glColor3f(.2f, .8f, .4f);
        drawBoundingBox(control_points[0][0], control_points[0][1],
                        control_points[1][0], control_points[1][1],
                        control_points[2][0], control_points[2][1],
                        control_points[3][0], control_points[3][1]);

        glColor3f(1.f, 1.f, 1.f);
        drawBezier(control_points[0][0], control_points[0][1],
                   control_points[1][0], control_points[1][1],
                   control_points[2][0], control_points[2][1],
                   control_points[3][0], control_points[3][1]);

        printf("arc length: %8.3f\n", bez2ArcLength(control_points[0][0], control_points[0][1],
                                                    control_points[1][0], control_points[1][1],
                                                    control_points[2][0], control_points[2][1],
                                                    control_points[3][0], control_points[3][1],
                                                    FLATNESS_THRESHOLD));

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}


void drawCircle(float x, float y, float radius, float theta_step_size) {
    glBegin(GL_POLYGON);
    for (float theta = 0; theta < MATH_TAU; theta += theta_step_size) {
        glVertex2f(x + radius*cosf(theta), y + radius*sinf(theta));
    }
    glEnd();
}

void drawBezier(float x0, float y0,
                float x1, float y1,
                float x2, float y2,
                float x3, float y3) {
    float curr_x, curr_y, last_x, last_y, t;
    glBegin(GL_LINES);
    last_x = x0;
    last_y = y0;
    for (t = STEP_SIZE; t < 1; t += STEP_SIZE) {
        bez2Evaluate(x0, y0, x1, y1, x2, y2, x3, y3, t, &curr_x, &curr_y);
        glVertex2f(last_x, last_y);
        glVertex2f(curr_x, curr_y);
        last_x = curr_x;
        last_y = curr_y;
    }
    glEnd();
}

void drawBoundingBox(float x0, float y0,
                     float x1, float y1,
                     float x2, float y2,
                     float x3, float y3) {
    float x_min, x_max, y_min, y_max;

    bez2BoundingBox(x0, y0, x1, y1, x2, y2, x3, y3, &x_min, &y_min, &x_max, &y_max);

    glBegin(GL_LINE_LOOP);
    glVertex2f(x_min, y_min);
    glVertex2f(x_min, y_max);
    glVertex2f(x_max, y_max);
    glVertex2f(x_max, y_min);
    glEnd();
}
