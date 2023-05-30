//
//  Thing.h
//  jun22template
//
//  Created by Iris on 6/22/22.
//

#ifndef Thing_h
#define Thing_h
class Thing{
    int x;
public:
    Thing() : x(0) {}
    Thing(int newx):x(newx){}
    int getx() const/* {return x;}*/;
    void setx(int newx)/* {x = newx;}*/;
};

#endif /* Thing_h */
