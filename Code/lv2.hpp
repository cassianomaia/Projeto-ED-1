#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "fila.h"

class lv2 : public cScreen{
private:
    int turno;   // 0 = pausa | 1 = pc | 2 = jogador
    int retira, i, z;
    Fila filap; //fila do jogador
    Fila filac; //fila do computador
    Fila filam; //fila musica

public:
	lv2(void);
	virtual int Run(sf::RenderWindow &Tela);
};

lv2::lv2(void){
}

int lv2::Run(sf::RenderWindow &Tela){

    filam.Insere(3);filam.Insere(3);filam.Insere(10);
    filam.Insere(10);filam.Insere(12);filam.Insere(12);
    filam.Insere(10);filam.Insere(10);filam.Insere(8);
    filam.Insere(8);filam.Insere(7);filam.Insere(7);
    filam.Insere(5);filam.Insere(5);filam.Insere(3);
    filam.Insere(3);   
    turno = 0;


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
                        if (filac.Contador() == 0){
                            turno = 1;
                        }else{
                            turno = 2;
                        }
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
        if (!filam.Vazia()){
                retira = filam.Retira();
                filac.Insere(retira);
                retira = filam.Retira();
                filac.Insere(retira);
                for(i = filac.Contador(); i>0; i--){
                    cout << i << endl;
                    retira = filac.Retira();
                    switch (retira){
                        case 1:
                            piano.setTexture(&tpianoc, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(c);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 2:
                            piano.setTexture(&tpianocsharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(csharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 3:
                            piano.setTexture(&tpianod, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(d);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 4:
                            piano.setTexture(&tpianodsharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(dsharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 5:
                            piano.setTexture(&tpianoe, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(e);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 6:
                            piano.setTexture(&tpianof, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(f);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 7:
                            piano.setTexture(&tpianofsharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(fsharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 8:
                            piano.setTexture(&tpianog, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(g);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 9:
                            piano.setTexture(&tpianogsharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(gsharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 10:
                            piano.setTexture(&tpianoa, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(a);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 11:
                            piano.setTexture(&tpianoasharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(asharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 12:
                            piano.setTexture(&tpianob, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(b);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 13:
                            piano.setTexture(&tpianoC, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(C);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 14:
                            piano.setTexture(&tpianoCsharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(Csharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 15:
                            piano.setTexture(&tpianoD, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(D);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 16:
                            piano.setTexture(&tpianoDsharp, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(Dsharp);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                        case 17:
                            piano.setTexture(&tpianoE, true);
                            Tela.draw(piano);
                            Tela.display();
                            sound.setBuffer(E);
                            sound.play();
                            sf::sleep(sf::milliseconds(250));
                        break;
                    }
                    filac.Insere(retira);
                    piano.setTexture(&tpiano, true);
                    Tela.draw(piano);
                    Tela.display();
                    sf::sleep(sf::milliseconds(250));
                }
                Tela.clear(sf::Color::White);
                piano.setTexture(&tpiano, true);
                Tela.draw(piano);
                Tela.display();
                turno = 2;        
            }else{
                turno = 5;
            }
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
                                filap.Insere(1);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::Num2:
                                piano.setTexture(&tpianocsharp, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(csharp);
                                sound.play();
                                filap.Insere(2);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::W:
                                piano.setTexture(&tpianod, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(d);
                                sound.play();
                                filap.Insere(3);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::Num3:
                                piano.setTexture(&tpianodsharp, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(dsharp);
                                sound.play();
                                filap.Insere(4);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::E:
                                piano.setTexture(&tpianoe, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(e);
                                sound.play();
                                filap.Insere(5);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::R:
                                piano.setTexture(&tpianof, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(f);
                                sound.play();
                                filap.Insere(6);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::Num5:
                                piano.setTexture(&tpianofsharp, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(fsharp);
                                sound.play();
                                filap.Insere(7);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::T:
                                piano.setTexture(&tpianog, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(g);
                                sound.play();
                                filap.Insere(8);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::Num6:
                                piano.setTexture(&tpianogsharp, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(gsharp);
                                sound.play();
                                filap.Insere(9);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::Y:
                                piano.setTexture(&tpianoa, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(a);
                                sound.play();
                                filap.Insere(10);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::Num7:
                                piano.setTexture(&tpianoasharp, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(asharp);
                                sound.play();
                                filap.Insere(11);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::U:
                                piano.setTexture(&tpianob, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(b);
                                sound.play();
                                filap.Insere(12);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::I:
                                piano.setTexture(&tpianoC, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(C);
                                sound.play();
                                filap.Insere(13);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::Num9:
                                piano.setTexture(&tpianoCsharp, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(Csharp);
                                sound.play();
                                filap.Insere(14);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::O:
                                piano.setTexture(&tpianoD, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(D);
                                sound.play();
                                filap.Insere(15);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::Num0:
                                piano.setTexture(&tpianoDsharp, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(Dsharp);
                                sound.play();
                                filap.Insere(16);
                                sf::sleep(sf::milliseconds(250));
                            break;
                            case sf::Keyboard::P:
                                piano.setTexture(&tpianoE, true);
                                Tela.draw(piano);
                                Tela.display();
                                sound.setBuffer(E);
                                sound.play();
                                filap.Insere(17);
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
            if (filap.Contador() == filac.Contador()){
                if (filap.Compara(filac, filap)){
                    for(i = filap.Contador(); i >0; i--){
                        retira = filap.Retira();
                    }
                    Tela.clear(sf::Color::White);
                    piano.setTexture(&tpiano, true);
                    Tela.draw(piano);
                    Tela.display();
                    sf::sleep(sf::milliseconds(500));
                    turno = 1;
                }else{
                    for(i = filap.Contador(); i >0; i--){
                        retira = filap.Retira();
                    }
                    turno = 4;
                }
            }else{
                piano.setTexture(&tpiano, true);
                Tela.draw(piano);
                Tela.display();
            }
        break;
    //caso perca
        case 4:
            Tela.clear(sf::Color::White);
            while (Tela.pollEvent(event)){
                if (event.type == sf::Event::KeyPressed){
                    if (event.key.code == sf::Keyboard::Escape){
                        return 0;
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
    //caso ganhe
        case 5:
            Tela.clear(sf::Color::White);
            while (Tela.pollEvent(event)){
                if (event.type == sf::Event::KeyPressed){
                    if (event.key.code == sf::Keyboard::Escape){
                        return 0;
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
    
        break;
        }
    }
}
