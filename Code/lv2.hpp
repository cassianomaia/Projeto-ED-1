#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
#include "fila.h"

class lv2 : public cScreen{
private:
    int turno;   // 0 = pausa | 1 = pc | 2 = jogador
    Fila filap;
    Fila filac;
    Fila filas;
    Fila filam;

public:
	lv2(void);
	virtual int Run(sf::RenderWindow &Tela);
};

lv2::lv2(void){
}

int lv2::Run(sf::RenderWindow &Tela){
    turno = 0;

    filam.Insere('d');filam.Insere('d');filam.Insere('a');
    filam.Insere('a');filam.Insere('b');filam.Insere('b');
    filam.Insere('a');filam.Insere('a');filam.Insere('g');
    filam.Insere('g');filam.Insere('f');filam.Insere('f');
    filam.Insere('e');filam.Insere('e');filam.Insere('d');
    filam.Insere('d');   


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
    if (!tpiano.loadFromFile("../Images/teclado_real_oficial.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianoc;
    if (!tpianoc.loadFromFile("../Images/Q.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianocsharp;
    if (!tpianocsharp.loadFromFile("../Images/2.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianod;
    if (!tpianod.loadFromFile("../Images/W.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianodsharp;
    if (!tpianodsharp.loadFromFile("../Images/3.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianoe;
    if (!tpianoe.loadFromFile("../Images/E.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianof;
    if (!tpianof.loadFromFile("../Images/R.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianofsharp;
    if (!tpianofsharp.loadFromFile("../Images/5.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianog;
    if (!tpianog.loadFromFile("../Images/T.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianogsharp;
    if (!tpianogsharp.loadFromFile("../Images/6.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianoa;
    if (!tpianoa.loadFromFile("../Images/Y.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianoasharp;
    if (!tpianoasharp.loadFromFile("../Images/7.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianob;
    if (!tpianob.loadFromFile("../Images/U.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianoC;
    if (!tpianoC.loadFromFile("../Images/I.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianoCsharp;
    if (!tpianoCsharp.loadFromFile("../Images/9.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianoD;
    if (!tpianoD.loadFromFile("../Images/O.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianoDsharp;
    if (!tpianoDsharp.loadFromFile("../Images/0.bmp")){
        return EXIT_FAILURE;
    }
    sf::Texture tpianoE;
    if (!tpianoE.loadFromFile("../Images/P.bmp")){
        return EXIT_FAILURE;
    }

    // Loop para deixar a janela aberta
    while (Tela.isOpen()){
    sf::Event event;
    switch (turno){
//turno pause
    case 0:
        Tela.clear(sf::Color::White);
        while (Tela.pollEvent(event)){
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space){
                    turno = 2;
                }
            }
            if (event.type == sf::Event::Closed){
                Tela.close();
            }
        }
        piano.setTexture(&tpiano, true);
        Tela.draw(piano);
        Tela.display();
    break;
//turno da maquina
    case 1:
    
    break;
//turno do jogador
    case 2:
        Tela.clear(sf::Color::White);
        // Checa os eventos em loop
        while (Tela.pollEvent(event)){
            switch (event.type){ 
                case sf::Event::KeyPressed:
                    switch (event.key.code){
                        case sf::Keyboard::Q:
                            piano.setTexture(&tpianoc, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(c);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::Num2:
                            piano.setTexture(&tpianocsharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(csharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::W:
                            piano.setTexture(&tpianod, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(d);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::Num3:
                            piano.setTexture(&tpianodsharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(dsharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::E:
                            piano.setTexture(&tpianoe, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(e);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::R:
                            piano.setTexture(&tpianof, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(f);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::Num5:
                            piano.setTexture(&tpianofsharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(fsharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::T:
                            piano.setTexture(&tpianog, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(g);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::Num6:
                            piano.setTexture(&tpianogsharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(gsharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::Y:
                            piano.setTexture(&tpianoa, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(a);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::Num7:
                            piano.setTexture(&tpianoasharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(asharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::U:
                            piano.setTexture(&tpianob, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(b);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::I:
                            piano.setTexture(&tpianoC, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(C);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::Num9:
                            piano.setTexture(&tpianoCsharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(Csharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::O:
                            piano.setTexture(&tpianoD, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(D);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::Num0:
                            piano.setTexture(&tpianoDsharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(Dsharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::P:
                            piano.setTexture(&tpianoE, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(E);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case sf::Keyboard::Escape:
                            return 0;
                        break;
                        case sf::Keyboard::Space:
                            turno = 0;
                        break;
                    }
                break;
                case sf::Event::Closed:
                    Tela.close();
                break; 
            }
        }
        piano.setTexture(&tpiano, true);
        Tela.draw(piano);
        Tela.display();
    break;
//testando para ir para o prox level, ou fim de jogo (turno =5)
    case 4:

    break;
//caso perca
    case 5:

    break;
//caso ganhe
    case 6:

    break;
    }
    }
	//Never reaching this point normally, but just in case, exit the Telalication
	return (-1);
}
