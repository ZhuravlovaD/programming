#include "point.hpp"

#include <cmath>
#include <iostream>

Point::Point(double a1, double a2, CoordSystem coord_system) {
    switch (coord_system) {
    case CoordSystem::Cartesian:
        x = a1;
        y = a2;
        break;
    case CoordSystem::Polar:
        x = cos(a2) * a1;
        y = sin(a2) * a1;
        break;
    }
}
std::ostream& operator <<(std::ostream& out, const Point& conPoin) {
    out << '(' << conPoin.get_x() << ',' << conPoin.get_y() << ')';
    return out;
};
std::istream& operator >>(std::istream& in, Point& poin) {
    double buffer;
    in.ignore(g_maxCharToSkip, '(');
    in >> buffer;
    poin.set_x(buffer);
    in.ignore(g_maxCharToSkip, ',');
    in >> buffer;
    poin.set_y(buffer);
    in.ignore(g_maxCharToSkip, ')');
    return in;
};

bool Point::operator==(const Point& other) const {
    return fabs(x - other.x) < g_percision
        && fabs(y - other.y) < g_percision;
}

bool Point::operator!=(const Point& other) const {
    return !this->operator==(other);
}

double Point::get_x() const { return x; }

void Point::set_x(double x) { this->x = x; }

double Point::get_y() const { return y; }

void Point::set_y(double y) { this->y = y; }

double Point::get_r() const { return sqrt(x * x + y * y); }

double Point::get_phi() const { return atan(y / x) + (x < 0 ? PI : 0); }

void Point::set_phi(double phi) {
    double r = get_r();
    x = r * cos(phi);
    y = r * sin(phi);
}

