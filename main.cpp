#include "Curve.h"
#include <cmath>
#include <vector>
#include <GLFW/glfw3.h>
#include <iostream>
#include "dividing.h"

// Não achei nenhuma função específica da biblioteca para desenhar os eixos, acabeou que fiz manualmente
void static drawAxes() {
    glColor3f(1.0f, 0.0f, 0.0f);  // Vermelho para os eixos

    // Eixo X
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glEnd();

    // Eixo Y
    glBegin(GL_LINES);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();
}

void initOpenGL(const std::vector<Curve>& curves) {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "Sine Curve", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, 1.0);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        drawAxes();

        for (const Curve& curve : curves) {
            curve.drawCurve();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

int main() {
    std::vector<Point> pontos;
    float A = 500.0f;   // amplitude
    float B = 0.1f;     // fator de escala
    float C = 0.0f;     // deslocamento de fase

    for (int x = -50; x <= 50; x += 4) {
        float y = A * sin(B * x + C);
        pontos.push_back(Point(x, y));
    }

    Curve curve;
    curve.setScale(1.0f, 1.0f);
    float s1 = 1.0f;
    float s2 = 1.0f;

    for (size_t i = 0; i < pontos.size() - 1; ++i) {
        Point p1 = pontos[i];
        Point p2 = pontos[i + 1];
        if (abs(p1.getX()) > s1) {
            s1 = abs(p1.getX());
        }
        if (abs(p1.getY()) > s2) {
            s2 = abs(p1.getY());
        }
        Arest aresta("green", p1, p2);
        curve.addArest(aresta);
    }

    curve.setScale(s1, s2);
    std::vector<Curve> curvas = { curve };
    initOpenGL(curvas);

    return 0;
}

/*
#include <iostream>
#include "dividing.h"

int main() {
    dividing d1(3, 4);   // 3/4
    dividing d2(2, 5);   // 2/5

    dividing result_add = d1 + d2;
    std::cout << "Soma: (" << result_add.getX() << " / " << result_add.getY() << ")" << std::endl;

    dividing result_sub = d1 - d2;
    std::cout << "Subtracao: (" << result_sub.getX() << " / " << result_sub.getY() << ")" << std::endl;

    dividing result_mul = d1 * d2;
    std::cout << "Multiplicacao: (" << result_mul.getX() << " / " << result_mul.getY() << ")" << std::endl;

    dividing result_div = d1 / d2;
    std::cout << "Divisao: (" << result_div.getX() << " / " << result_div.getY() << ")" << std::endl;

    dividing d3;
    d3 = d1;
    std::cout << "Atribuicao: (" << d3.getX() << " / " << d3.getY() << ")" << std::endl;

    std::cout << "Valor da divisao d1: " << d1.calculate() << std::endl;
    std::cout << "Valor da divisao d2: " << d2.calculate() << std::endl;
    std::cout << "Valor da divisao resultante da soma: " << result_add.calculate() << std::endl;
    std::cout << "Valor da divisao resultante da subtracao: " << result_sub.calculate() << std::endl;
    std::cout << "Valor da divisao resultante da multiplicacao: " << result_mul.calculate() << std::endl;
    std::cout << "Valor da divisao resultante da divisao: " << result_div.calculate() << std::endl;

    return 0;
}
*/