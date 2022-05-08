#ifndef NODO_H
#define NODO_H


class Nodo {
    private:
        int x = 0;
        int y = 0;
    public:
        Nodo(int x = 0, int y = 0);
        void setX(int x);
        void setY(int y);
        int getY();
        int getX();
};

#endif // NODO_H
