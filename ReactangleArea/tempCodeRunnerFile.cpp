class Rectangle
{
    int width, height;
    public:
        void display()
        {
            cout << width << " " << height << endl;
        }
        friend class RectangleArea;
};

class RectangleArea : public Rectangle
{
    public:
        void read_input()
        {
            cin >> width >> height;
        }
        void display()
        {
            cout << width * height << endl;
        }
};
