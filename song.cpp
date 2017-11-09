#include<iostream>
#include<fmod.hpp>
#include<cstdlib>
#include<cstdio>
#include "include/Song.hpp"
#include "include/Image.hpp"
using namespace std;
using namespace FMOD;

Song Create_a_song(const string& PATH)
{
  Song NewSong;
  NewSong.PATH = PATH;
  return NewSong;
}

int Play_a_song(const song& ToPlay)
{

}
   
   


int main()
{


  System* sys =NULL;
  Sound* snd1 = NULL;
  Sound* snd2 = NULL;
  Channel** chn = (Channel**) malloc(sizeof(Channel*));
  System_Create(&sys);
  sys->init(10, FMOD_INIT_NORMAL, NULL);
  sys->createStream("/home/bi/Music/oath sign-LiSA.mp3", FMOD_DEFAULT, NULL, &snd1);  

  sys->playSound(snd1,NULL,false,chn);
   

  char buf = 0;
  while(buf != 'q' && buf != 'Q')
    {
      buf=getchar();
      if(buf == 'p')
	(*chn)->setPaused(1);
      if(buf == 'c')
	(*chn)->setPaused(0);
      if(buf == 'g')
	{
	  unsigned int pos;
	  (*chn)->getPosition(&pos,FMOD_TIMEUNIT_MS);
	  pos /= 1000;
	  int min = pos/60;
	  pos %= 60;
	  printf("%02d:%02d\n",min,pos);
	}
      if(buf =='u')
	{
	  (*chn)->setPitch(2.0);
	}

      if(buf =='d')
	{
	  (*chn)->setPitch(1.0);
	}
    }

  
}
