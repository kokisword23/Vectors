class Element {
private:
    double x;
    double y;
    double z;

protected:
    Element(double x, double y, double z);
    Element();
public:
    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double getZ() const;

    void setZ(double z);
};
