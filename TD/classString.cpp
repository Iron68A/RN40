#define CAPACITE_DEFAUT 16

class classString
{
private:
    char* str;
    int capacity;
    int strlength;
public:
    classString();
    ~classString();
};

classString::classString()
{
    str = new char[CAPACITE_DEFAUT];
    capacity = CAPACITE_DEFAUT;
    strlength = 0;

}


classString::~classString()
{
}
