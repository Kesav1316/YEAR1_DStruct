#include <stdio.h>

class room {
    int length;
    private:
        int breadth;
        int height;
    public:
        room() {
            length = 1;
            breadth = 1;
            height = 1;
        }
        ~room() {

        }

        int area(int len , int bre) {
            length = len;
            breadth = bre;
            return length * breadth;
        }
};

int main() {
    room obj;
    printf("Area:%d",obj.area(5,6));
    return 0;
}