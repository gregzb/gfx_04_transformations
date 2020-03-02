#pragma once

#include <vector>
#include <string>

#include "Vec4.hpp"
#include "Utils.hpp"

class Mat4
{
private:
    std::vector<std::vector<double>> m;
    int cols;

public:
    Mat4(int cols = 0);
    Mat4(std::vector<std::vector<double>> m);
    std::vector<double> &operator[](int idx);
    double operator()(int row, int col) const;
    int getRows() const;
    int getCols() const;
    std::string toString() const;

    Vec4 getPoint(int col) const;

    void clear();
    Mat4 multiply(const Mat4 &matrix) const;
    void multiplyMutate(const Mat4 &matrix);
    void addPoint(Vec4 const &v);
    void addEdge(Vec4 const &v0, Vec4 v1);

    static Mat4 identity();

    static Mat4 rotX(double theta);
    static Mat4 rotY(double theta);
    static Mat4 rotZ(double theta);
    static Mat4 translate(Vec4 const &v);
    static Mat4 scale(Vec4 const &v);
};