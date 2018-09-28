#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

int newLog(SDL_Window *window)
{
    // Initialization of assets
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * interface = SDL_LoadBMP("Assets/images/HyperPlanningLogIn.bmp");
    SDL_Texture * textureLog = SDL_CreateTextureFromSurface(renderer, interface);
    SDL_Surface *surfaceBuffer;
    SDL_Texture *textureBuffer;
    SDL_Color fontColor= {0,0,0,255};
    SDL_Color bufferColor= {120,120,120,60};
    SDL_DisplayMode DM;
    SDL_Rect posID,posPW,posLOG;
    SDL_Event event,event1;
    string ID,PW,hiddenPW;
    int mouseX,mouseY,mouse;

    SDL_GetWindowSize(window,&DM.w,&DM.h);

    // Setting positions according to the screen resolution

    posID.x=posPW.x=posLOG.x=683*DM.w/1920;
    posID.y=392*DM.h/1080;
    posPW.y=posID.y+122*DM.h/1080;
    posLOG.y=posPW.y+80*DM.h/1080;
    posID.w=posPW.w=posLOG.w=556*DM.w/1920;
    posID.h=posPW.h=55*DM.h/1080;
    posLOG.h=111*DM.h/1080;

    SDL_RenderCopy(renderer, textureLog, NULL, NULL);
    SDL_RenderPresent(renderer);


    if(TTF_Init()<0)
    {
        cout<<"ERROR DURING TTF_INIT ERRORCODE "<<TTF_GetError()<<endl;
        exit(-1);
    }

    TTF_Font *font = TTF_OpenFont("Assets/fonts/AGENCYR.TTF",25);

    if(!font)
    {
        cout<<"AGENCYR.TTF NOT FOUND"<<endl;
        exit(-1);
    }


    while(1)
    {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:

            TTF_CloseFont(font);
            TTF_Quit();
            SDL_DestroyTexture(textureLog);
            /*SDL_DestroyTexture(textureBuffer);
            SDL_FreeSurface(interface);
            SDL_FreeSurface(surfaceBuffer);
            SDL_DestroyRenderer(renderer);*/
            SDL_DestroyWindow(window);
            SDL_Quit();
            exit(0);
            // condition d'arret ?
            break;
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&mouseX,&mouseY);
            if(posID.x<=mouseX && mouseX<=posID.x+posID.w && posID.y<=mouseY && mouseY<=posID.y+posID.h)
                mouse=1;
            else if(posPW.x<=mouseX && mouseX<=posPW.x+posPW.w && posPW.y<=mouseY && mouseY<=posPW.y+posPW.h)
                mouse=2;
            else if(posLOG.x<=mouseX && mouseX<=posLOG.x+posLOG.w && posLOG.y<=mouseY && mouseY<=posLOG.y+posLOG.h)
                mouse=3;
            else
                mouse=0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(mouse==1)
            {
                SDL_StartTextInput();
                do
                {
                    SDL_WaitEvent(&event1);
                    if(ID.length()>0 && event1.key.keysym.sym==SDLK_BACKSPACE && event1.type== SDL_KEYDOWN && event1.type!=SDL_QUIT)
                    {
                        ID=ID.substr(0,ID.length()-1);
                    }
                    else if(event1.type==SDL_TEXTINPUT && event1.key.keysym.sym!=SDLK_RETURN && event1.key.keysym.sym!=SDLK_KP_ENTER && event1.type!=SDL_QUIT)
                    {
                        ID+=event1.text.text;
                    }
                    SDL_RenderCopy(renderer, textureLog, NULL, NULL);
                    surfaceBuffer = TTF_RenderText_Solid(font,ID.c_str(),fontColor);
                    textureBuffer= SDL_CreateTextureFromSurface(renderer,surfaceBuffer);
                    SDL_QueryTexture(textureBuffer,NULL,NULL,&posID.w,&posID.h);
                    SDL_RenderCopy(renderer,textureBuffer,NULL,&posID);
                    surfaceBuffer = TTF_RenderText_Solid(font,hiddenPW.c_str(),fontColor);
                    textureBuffer= SDL_CreateTextureFromSurface(renderer,surfaceBuffer);
                    SDL_QueryTexture(textureBuffer,NULL,NULL,&posPW.w,&posPW.h);
                    SDL_RenderCopy(renderer,textureBuffer,NULL,&posPW);
                    SDL_RenderPresent(renderer);
                    if(event1.type==SDL_QUIT)
                    {
                        TTF_CloseFont(font);
                        TTF_Quit();
                        SDL_DestroyTexture(textureLog);
                        SDL_DestroyTexture(textureBuffer);
                        SDL_FreeSurface(interface);
                        SDL_FreeSurface(surfaceBuffer);
                        SDL_DestroyRenderer(renderer);
                        SDL_DestroyWindow(window);
                        SDL_Quit();
                        exit(0);
                    }
                }
                while(event1.key.keysym.sym!=SDLK_RETURN && event1.key.keysym.sym!=SDLK_KP_ENTER);
                cout<<"Quit1"<<endl;
                SDL_StopTextInput();
            }
            else if(mouse==2)
            {
                SDL_StartTextInput();
                do
                {
                    SDL_WaitEvent(&event1);
                    if(PW.length()>0 && event1.key.keysym.sym==SDLK_BACKSPACE && event1.type== SDL_KEYDOWN && event1.type!=SDL_QUIT)
                    {
                        PW=PW.substr(0,PW.length()-1);
                        hiddenPW=hiddenPW.substr(0,hiddenPW.length()-1);
                    }
                    else if(event1.type==SDL_TEXTINPUT && event1.key.keysym.sym!=SDLK_RETURN && event1.key.keysym.sym!=SDLK_KP_ENTER && event1.type!=SDL_QUIT)
                    {
                        PW+=event1.text.text;
                        hiddenPW+="*";
                    }
                    SDL_RenderCopy(renderer, textureLog, NULL, NULL);
                    surfaceBuffer = TTF_RenderText_Solid(font,ID.c_str(),fontColor);
                    textureBuffer= SDL_CreateTextureFromSurface(renderer,surfaceBuffer);
                    SDL_QueryTexture(textureBuffer,NULL,NULL,&posID.w,&posID.h);
                    SDL_RenderCopy(renderer,textureBuffer,NULL,&posID);
                    surfaceBuffer = TTF_RenderText_Solid(font,hiddenPW.c_str(),fontColor);
                    textureBuffer= SDL_CreateTextureFromSurface(renderer,surfaceBuffer);
                    SDL_QueryTexture(textureBuffer,NULL,NULL,&posPW.w,&posPW.h);
                    SDL_RenderCopy(renderer,textureBuffer,NULL,&posPW);
                    SDL_RenderPresent(renderer);

                    if(event1.type==SDL_QUIT)
                    {
                        TTF_CloseFont(font);
                        TTF_Quit();
                        SDL_DestroyTexture(textureLog);
                        SDL_DestroyTexture(textureBuffer);
                        SDL_FreeSurface(interface);
                        SDL_FreeSurface(surfaceBuffer);
                        SDL_DestroyRenderer(renderer);
                        SDL_DestroyWindow(window);
                        SDL_Quit();
                        exit(0);
                    }
                }
                while(event1.key.keysym.sym!=SDLK_RETURN && event1.key.keysym.sym!=SDLK_KP_ENTER);
                cout<<"Quit2"<<endl;
                SDL_StopTextInput();
            }
            else if(mouse==3)
                //Check(ID,MDP)
                break;
        }
    }




    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyTexture(textureBuffer);
    SDL_DestroyTexture(textureLog);
    SDL_FreeSurface(interface);
    SDL_FreeSurface(surfaceBuffer);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window=SDL_CreateWindow("HyperPlanning",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1200,650,SDL_WINDOW_RESIZABLE);
    newLog(window);
    SDL_Quit();

    return 0;
}
