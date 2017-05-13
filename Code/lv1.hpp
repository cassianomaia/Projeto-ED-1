#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include "fila.h"
#include <SFML/Audio.hpp>

class lv1 : public cScreen{
private:
public:
	lv1(void);
	virtual int Run(sf::RenderWindow &Tela);
};

lv1::lv1(void){

}

int lv1::Run(sf::RenderWindow &Tela){
    sf::SoundBuffer c;
    if (!c.loadFromFile("../Sounds/1.wav"))
        return -1;
    sf::SoundBuffer csharp;
    if (!csharp.loadFromFile("../Sounds/2.wav"))
        return -1;
    sf::SoundBuffer d;
    if (!d.loadFromFile("../Sounds/3.wav"))
        return -1;
    sf::SoundBuffer dsharp;
    if (!dsharp.loadFromFile("../Sounds/4.wav"))
        return -1;
    sf::SoundBuffer e;
    if (!e.loadFromFile("../Sounds/5.wav"))
        return -1;
    sf::SoundBuffer f;
    if (!f.loadFromFile("../Sounds/6.wav"))
        return -1;
    sf::SoundBuffer fsharp;
    if (!fsharp.loadFromFile("../Sounds/7.wav"))
        return -1;
    sf::SoundBuffer g;
    if (!g.loadFromFile("../Sounds/8.wav"))
        return -1;
    sf::SoundBuffer gsharp;
    if (!gsharp.loadFromFile("../Sounds/9.wav"))
        return -1;
    sf::SoundBuffer a;
    if (!a.loadFromFile("../Sounds/10.wav"))
        return -1;
    sf::SoundBuffer asharp;
    if (!asharp.loadFromFile("../Sounds/11.wav"))
        return -1;
    sf::SoundBuffer b;
    if (!b.loadFromFile("../Sounds/12.wav"))
        return -1;
    sf::SoundBuffer C;
    if (!C.loadFromFile("../Sounds/13.wav"))
        return -1;
    sf::SoundBuffer Csharp;
    if (!Csharp.loadFromFile("../Sounds/14.wav"))
        return -1;
    sf::SoundBuffer D;
    if (!D.loadFromFile("../Sounds/15.wav"))
        return -1;
    sf::SoundBuffer Dsharp;
    if (!Dsharp.loadFromFile("../Sounds/16.wav"))
        return -1;
    sf::SoundBuffer E;
    if (!E.loadFromFile("../Sounds/17.wav"))
        return -1;

    sf::Sound sound;
    

	sf::RectangleShape piano(sf::Vector2f(503, 203));
    piano.setPosition(149, 200);
    sf::Texture tpiano;
    if (!tpiano.loadFromFile("../Images/teclado_real_oficial1.bmp")){
        return EXIT_FAILURE;
    }
    piano.setTexture(&tpiano, true);

    // Loop para deixar a janela aberta
    while (Tela.isOpen()){
        sf::Event event;
        // Checa os eventos em loop
        while (Tela.pollEvent(event)){
            switch (event.type){ 
                case sf::Event::KeyPressed:
                    switch (event.key.code){
                        case sf::Keyboard::Q:
                            sound.setBuffer(c);
                            sound.play();
                        break;
                        case sf::Keyboard::Num2:
                            sound.setBuffer(csharp);
                            sound.play();
                        break;
                        case sf::Keyboard::W:
                            sound.setBuffer(d);
                            sound.play();
                        break;
                        case sf::Keyboard::Num3:
                            sound.setBuffer(dsharp);
                            sound.play();
                        break;
                        case sf::Keyboard::E:
                            sound.setBuffer(e);
                            sound.play();
                        break;
                        case sf::Keyboard::R:
                            sound.setBuffer(f);
                            sound.play();
                        break;
                        case sf::Keyboard::Num5:
                            sound.setBuffer(fsharp);
                            sound.play();
                        break;
                        case sf::Keyboard::T:
                            sound.setBuffer(g);
                            sound.play();
                        break;
                        case sf::Keyboard::Num6:
                            sound.setBuffer(gsharp);
                            sound.play();
                        break;
                        case sf::Keyboard::Y:
                            sound.setBuffer(a);
                            sound.play();
                        break;
                        case sf::Keyboard::Num7:
                            sound.setBuffer(asharp);
                            sound.play();
                        break;
                        case sf::Keyboard::U:
                            sound.setBuffer(b);
                            sound.play();
                        break;
                        case sf::Keyboard::I:
                            sound.setBuffer(C);
                            sound.play();
                        break;
                        case sf::Keyboard::Num9:
                            sound.setBuffer(Csharp);
                            sound.play();
                        break;
                        case sf::Keyboard::O:
                            sound.setBuffer(D);
                            sound.play();
                        break;
                        case sf::Keyboard::Num0:
                            sound.setBuffer(Dsharp);
                            sound.play();
                        break;
                        case sf::Keyboard::P:
                            sound.setBuffer(E);
                            sound.play();
                        break;
                    }
                break;
                case sf::Event::Closed:
                    Tela.close();
                break; 
            }
        }
        Tela.clear(sf::Color::White);
        Tela.draw(piano);
        Tela.display();
    }

	//Never reaching this point normally, but just in case, exit the Telalication
	return (-1);
}