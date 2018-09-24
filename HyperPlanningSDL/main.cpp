#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

using namespace std;

void drawLoginInterface(SDL_Window *window, SDL_Renderer *loginInterface,SDL_Rect ID, SDL_Rect PW, int colored, SDL_Color bufferColor)
{
    switch(colored)
    {
    case 0:
        SDL_SetRenderDrawColor(loginInterface,255,255,255,255);
        SDL_RenderFillRect(loginInterface,&ID);
        SDL_RenderFillRect(loginInterface,&PW);
        break;
    case 1:
        SDL_SetRenderDrawColor(loginInterface,bufferColor.r,bufferColor.g,bufferColor.b,bufferColor.a);
        SDL_RenderFillRect(loginInterface,&ID);
        SDL_SetRenderDrawColor(loginInterface,255,255,255,255);
        SDL_RenderFillRect(loginInterface,&PW);
        break;
    case 2:
        SDL_SetRenderDrawColor(loginInterface,bufferColor.r,bufferColor.g,bufferColor.b,bufferColor.a);
        SDL_RenderFillRect(loginInterface,&PW);
        SDL_SetRenderDrawColor(loginInterface,255,255,255,255);
        SDL_RenderFillRect(loginInterface,&ID);
        break;
    }
    SDL_RenderPresent(loginInterface);
}
char** login(SDL_Window *window)
{
    if(TTF_Init()<0)
    {
        cout<<"ERROR DURING TTF_INIT ERRORCODE "<<TTF_GetError()<<endl;
        exit(-1);
    }

    TTF_Font *font = TTF_OpenFont("Assets/fonts/AGENCYR.TTF",20);

    if(!font)
    {
        cout<<"AGENCYR.TTF NOT FOUND"<<endl;
        exit(-1);
    }

    SDL_Surface *textSurface;
    SDL_Texture *textTexture;

    SDL_Color fontColor= {0,0,0,255};
    SDL_Color bufferColor= {120,120,120,60};
    SDL_Renderer *loginInterface = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Rect ID;
    SDL_Rect PW;
    SDL_Rect textID;
    SDL_Rect textPW;

    string bufferID,bufferPW;
    SDL_DisplayMode DM;
    SDL_GetWindowSize(window,&DM.w,&DM.h);


    int mouseX,mouseY,mouse;
    bool isRunning=true;


    ID.h= PW.h= textID.h= textPW.h=20;
    ID.w= PW.w= textID.w= textPW.w=200;
    ID.x= PW.x= textID.x=textPW.x=DM.w/2-ID.w/2;
    ID.y= PW.y=DM.h/2-ID.h/2-(ID.h+10);

    PW.y+=ID.h+10;

    textID.y=ID.y-3;
    textPW.y=PW.y-3;


    drawLoginInterface(window,loginInterface,ID,PW,0,bufferColor);


    SDL_Event event;
    SDL_Event event2;

    while(SDL_WaitEvent(&event)==1)
    {
        switch(event.type)
        {
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&mouseX,&mouseY);
            if(mouseX>=ID.x && mouseX<=ID.x+ID.w && mouseY>=ID.y && mouseY<= ID.y+ID.h)
            {
                mouse=1;
            }
            else
            {
                if(mouseX>=PW.x && mouseX<=PW.x+PW.w && mouseY>=PW.y && mouseY<= PW.y+PW.h)
                {

                    mouse=2;
                }
                else
                {
                    mouse=0;
                }
            }
            drawLoginInterface(window, loginInterface,ID,PW,mouse,bufferColor);
            if(bufferID.length()>0)
            {
                textSurface = TTF_RenderText_Solid(font,bufferID.c_str(),fontColor);
                textTexture= SDL_CreateTextureFromSurface(loginInterface,textSurface);
                SDL_QueryTexture(textTexture,NULL,NULL,&textID.w,&textID.h);
                SDL_RenderCopy(loginInterface,textTexture,NULL,&textID);
                SDL_RenderPresent(loginInterface);
            }
            if(bufferPW.length()>0)
            {
                textSurface = TTF_RenderText_Solid(font,bufferPW.c_str(),fontColor);
                textTexture= SDL_CreateTextureFromSurface(loginInterface,textSurface);
                SDL_QueryTexture(textTexture,NULL,NULL,&textPW.w,&textPW.h);
                SDL_RenderCopy(loginInterface,textTexture,NULL,&textPW);
                SDL_RenderPresent(loginInterface);
            }
            break;
        case SDL_QUIT:
            SDL_DestroyRenderer(loginInterface);
            SDL_Quit();
            isRunning=false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch(mouse)
            {
            case 1:
                SDL_StartTextInput();
                isRunning=true;
                while(isRunning)
                {
                    fflush(stdin);
                    SDL_WaitEvent(&event2);


                    if(event2.key.keysym.sym != SDLK_RETURN && (event2.type==SDL_TEXTINPUT || event2.type==SDL_KEYDOWN))
                    {


                        if(event2.type==SDL_KEYDOWN && event2.key.keysym.sym==SDLK_BACKSPACE && bufferID.length()>0)
                        {
                            bufferID=bufferID.substr(0,bufferID.length()-1);
                        }
                        else if(event2.type==SDL_TEXTINPUT)
                        {
                            bufferID+=event2.text.text;
                        }

                        drawLoginInterface(window, loginInterface,ID,PW,mouse,bufferColor);

                        textSurface = TTF_RenderText_Solid(font,bufferID.c_str(),fontColor);
                        textTexture= SDL_CreateTextureFromSurface(loginInterface,textSurface);
                        SDL_QueryTexture(textTexture,NULL,NULL,&textID.w,&textID.h);
                        SDL_RenderCopy(loginInterface,textTexture,NULL,&textID);


                        textSurface = TTF_RenderText_Solid(font,bufferPW.c_str(),fontColor);
                        textTexture= SDL_CreateTextureFromSurface(loginInterface,textSurface);
                        SDL_QueryTexture(textTexture,NULL,NULL,&textPW.w,&textPW.h);
                        SDL_RenderCopy(loginInterface,textTexture,NULL,&textPW);
                        SDL_RenderPresent(loginInterface);

                    }
                    else
                    {
                        if(event2.key.keysym.sym==SDLK_RETURN)
                        {
                            isRunning=false;
                        }
                        else
                        {
                            if(event2.type==SDL_QUIT)
                            {
                                SDL_DestroyRenderer(loginInterface);
                                SDL_Quit();
                                isRunning=false;
                                exit(0);
                            }
                            else if(event2.type == SDL_MOUSEBUTTONDOWN)
                            {
                                SDL_GetMouseState(&mouseX,&mouseY);
                                if(mouseX>=ID.x && mouseX<=ID.x+ID.w && mouseY>=ID.y && mouseY<= ID.y+ID.h)
                                {
                                    mouse=1;
                                }
                                else
                                {
                                    if(mouseX>=PW.x && mouseX<=PW.x+PW.w && mouseY>=PW.y && mouseY<= PW.y+PW.h)
                                    {

                                        mouse=2;
                                    }
                                    else
                                    {
                                        mouse=0;
                                    }
                                }

                                if(mouse!=1)
                                {
                                    isRunning=false;

                                }
                            }


                        }

                    }
                }
                SDL_StopTextInput();

                break;
            case 2:
                SDL_StartTextInput();
                isRunning=true;
                while(isRunning)
                {
                    fflush(stdin);
                    SDL_WaitEvent(&event2);


                    if(event2.key.keysym.sym != SDLK_RETURN && (event2.type==SDL_TEXTINPUT || event2.type==SDL_KEYDOWN))
                    {

                        if(event2.type==SDL_KEYDOWN && event2.key.keysym.sym==SDLK_BACKSPACE && bufferPW.length()>0)
                        {
                            bufferPW=bufferPW.substr(0,bufferPW.length()-1);
                        }
                        else if(event2.type==SDL_TEXTINPUT)
                        {
                            bufferPW+=event2.text.text;
                        }

                        drawLoginInterface(window, loginInterface,ID,PW,mouse,bufferColor);

                        textSurface = TTF_RenderText_Solid(font,bufferPW.c_str(),fontColor);
                        textTexture= SDL_CreateTextureFromSurface(loginInterface,textSurface);
                        SDL_QueryTexture(textTexture,NULL,NULL,&textPW.w,&textPW.h);
                        SDL_RenderCopy(loginInterface,textTexture,NULL,&textPW);


                        textSurface = TTF_RenderText_Solid(font,bufferID.c_str(),fontColor);
                        textTexture= SDL_CreateTextureFromSurface(loginInterface,textSurface);
                        SDL_QueryTexture(textTexture,NULL,NULL,&textID.w,&textID.h);
                        SDL_RenderCopy(loginInterface,textTexture,NULL,&textID);
                        SDL_RenderPresent(loginInterface);

                    }
                    else
                    {
                        if(event2.key.keysym.sym==SDLK_RETURN)
                        {
                            isRunning=false;
                        }
                        else
                        {
                            if(event2.type==SDL_QUIT)
                            {
                                SDL_DestroyRenderer(loginInterface);
                                SDL_Quit();
                                isRunning=false;
                                exit(0);
                            }
                            else if(event2.type == SDL_MOUSEBUTTONDOWN)
                            {
                                SDL_GetMouseState(&mouseX,&mouseY);
                                if(mouseX>=ID.x && mouseX<=ID.x+ID.w && mouseY>=ID.y && mouseY<= ID.y+ID.h)
                                {
                                    mouse=1;
                                }
                                else
                                {
                                    if(mouseX>=PW.x && mouseX<=PW.x+PW.w && mouseY>=PW.y && mouseY<= PW.y+PW.h)
                                    {

                                        mouse=2;
                                    }
                                    else
                                    {
                                        mouse=0;
                                    }
                                }

                                if(mouse!=2)
                                {
                                    isRunning=false;

                                }
                            }
                        }

                    }
                }
                SDL_StopTextInput();

                break;
            }
            break;
        }


    }
    TTF_Quit();
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyRenderer(loginInterface);
    SDL_Quit();
}
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window=SDL_CreateWindow("HyperPlanning",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_RESIZABLE);
    //SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP );


    /*SDL_Event event;
    string buffer;
    bool isRunning=true;
    while(SDL_PollEvent(&event)==1 || isRunning)
    {
        switch(event.type)
        {
        case SDL_QUIT:
        case SDL_WINDOWEVENT: // Événement de la fenêtre
            if ( event.window.event == SDL_WINDOWEVENT_CLOSE ) // Fermeture de la fenêtre
            {
                SDL_DestroyWindow(window);
                SDL_Quit();
                isRunning
            }
            break;
        case SDL_KEYDOWN:
            SDL_StartTextInput();
            buffer+=event.key.keysym.sym;
            system("cls");
            cout<<buffer<<endl;
        }
    }*/
    login(window);
    //SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window


    // Clean up
    //SDL_Quit();

    return 0;
}
