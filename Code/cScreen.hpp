#ifndef cScreenclass
#define cScreenclass

class cScreen
{
public :
    virtual int Run (sf::RenderWindow &App) = 0;
};

#endif