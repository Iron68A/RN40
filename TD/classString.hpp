#ifndef classString_hpp
#define classString_hpp

class classString
{
private:
    char* str;
    int capacity;
    int strlength;
public:
    classString();
    classString(const char* str);
    ~classString();
    classString operator=(const classString& str);
};


#endif // CLASSSTRING_HPP