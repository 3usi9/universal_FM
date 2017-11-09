#include "include/Include.hpp"



void pause()
{
  Player* MyPlayer = Player::GetInstance();

  while(MyPlayer->isPlaying());





}

int main(int argc, char** argv)
{
  string s;
  Playlist Mylist;
  for(int i = 1; i < argc; i++)
    {
      s=argv[i];

      Mylist.push_back(Song(s));
    }
  Player* MyPlayer = Player::GetInstance();

  while(!Mylist.empty())
    {
      MyPlayer->Play_a_song(Mylist.front());
      pause();
      Mylist.pop_front();
    }
  
}
