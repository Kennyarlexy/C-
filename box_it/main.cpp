#include <iostream>
#include <string>

class Box
{
    int l, b, h;
    public:
        Box()
        {
            // std::cout << "Called A" << std::endl;
            l = 0;
            b = 0;
            h = 0;
        }

        Box(int l, int b, int h)
        {
            // std::cout << "Called B" << std::endl;
            this->l = l;
            this->b = b;
            this->h = h;
        }

        Box(const Box &B)
        {
            // std::cout << "Called C" << std::endl;
            l = B.l;
            b = B.b;
            h = B.h;
        }

        int getLength()
        {
            return l;
        }

        int getBreadth()
        {
            return b;
        }

        int getheight()
        {
            return h;
        }

        long long CalculateVolume()
        {
            return l * b * h;
        }

        bool operator < (const Box &B)
        {
            if (l < B.l) {
                return true;
            } else if (b < B.b &&  l == B.l) {
                return true;
            } else if (h < B.h && b == B.b && l == B.l) {
                return true;
            } else {
                return false;
            }
        }

        friend std::ostream& operator << (std::ostream &output, const Box &B);
};

std::ostream& operator << (std::ostream &output, const Box &B)
{
    output << B.l << " " << B.b << " " << B.h;

    return output;
}

int main()
{
    Box b1; // Should set b1.l = b1.b = b1.h = 0;
    Box b2(2, 3, 4); // Should set b1.l = 2, b1.b = 3, b1.h = 4;
    std::cout << b2.getLength() << std::endl;	// Should return 2
    std::cout << b2.getBreadth() << std::endl; // Should return 3
    std::cout << b2.getheight() << std::endl;	// Should return 4
    std::cout << b2.CalculateVolume() << std::endl; // Should return 24
    bool x = (b1 < b2);	// Should return true based on the conditions given
    std::cout<<b2; // Should print 2 3 4 in order.

    return 0;
}