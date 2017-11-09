#ifndef _INCLUDE_PLAYER
#define _INCLUDE_PLAYER

#include<fmod.hpp>
#include<cstdlib>

class Player
{
private:

  static Player* pInstance;
  FMOD::Channel** chn;
  FMOD::Sound* snd;
  FMOD::System* sys;

  Player()
  {
    sys =NULL;
    snd = NULL;
    chn = NULL;
    FMOD::System_Create(&sys);
    sys->init(10, FMOD_INIT_NORMAL, NULL);
    chn = (FMOD::Channel**) malloc(sizeof(FMOD::Channel*));
  }

public:
  
  static Player* GetInstance()
  {
    if(pInstance == NULL)
      {
	pInstance = new Player();
      }
    return pInstance;
  }


  int Play_a_song(const Song& ToPlay)
  {
    (*chn)->stop();
    sys->createStream(ToPlay.PATH.c_str(), 
		      FMOD_DEFAULT, 
		      NULL,
		      &snd);
    sys->playSound(snd,NULL,false,chn);
    return 0;
  }

  int getPosition()
  {
    unsigned int pos;
    (*chn)->getPosition(&pos, FMOD_TIMEUNIT_MS);
    return pos;
  }

  int Step_Forward(int dlt)  
  {
    unsigned int pos;
    (*chn)->getPosition(&pos, FMOD_TIMEUNIT_MS);
    pos += dlt;
    (*chn)->setPosition(pos, FMOD_TIMEUNIT_MS);
    return 0;
  }

  int Step_Backward(int dlt)  
  {
    unsigned int pos;
    (*chn)->getPosition(&pos, FMOD_TIMEUNIT_MS);
    int pos0 = pos;
    pos0 -= dlt;
    if(pos0<0) pos0 = 0;
    (*chn)->setPosition((unsigned int)pos0, FMOD_TIMEUNIT_MS);
    return 0;
  }


  bool isPlaying()
  {
    bool isplay;
    (*chn)->isPlaying(&isplay);
    return isplay;
  }


};

Player* Player::pInstance = NULL;
#endif
