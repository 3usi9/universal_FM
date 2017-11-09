#include "include/Include.hpp"




int main(int argc, char** argv)
{
  system(STTY_US TTY_PATH);
  string s;
  Playlist Mylist;
  for(int i = 1; i < argc; i++)
    {
      s=argv[i];

      Mylist.push_back(Song(s));
    }

  Player* MyPlayer = Player::GetInstance();

  int ch = 0;

  while(!Mylist.empty())
    {
      if(!(MyPlayer->isPlaying()) && !Mylist.empty())
	{
	  MyPlayer->Play_a_song(Mylist.front());
	  Mylist.pop_front();
	}
      ch = get_char();
      switch(ch)
      	{
      	case 3: // C-c
      	  {system(STTY_DEF TTY_PATH);return 0;}

      	case 22: // C-v
      	  {
      	    if(!Mylist.empty())
      	      {
      		MyPlayer->Play_a_song(Mylist.front());
      		Mylist.pop_front();
      	      }
	    break;
      	  }

      	case 6: // C-f
      	  {
      	    MyPlayer->Step_Forward(2000);
	    break;
      	  }

      	case 2: // C-b
      	  {
      	    MyPlayer->Step_Backward(2000);
	    break;
      	  }

      	case 14: // C-n
      	  {
      	    MyPlayer->Step_Forward(10000);
	    break;
      	  }

      	case 16: // C-p
      	  {
      	    MyPlayer->Step_Backward(10000);
	    break;
      	  }

      	case 5: // C-e
      	  {
      	    MyPlayer->Step_Forward(30000);
	    break;
      	  }

      	case 1: // C-a
      	  {
      	    MyPlayer->Step_Backward(30000);
	    break;
      	  }

	default:
	  {
	    break;
	  }

      	}
    }
  // while(!Mylist.empty())
  //   {
  //     MyPlayer->Play_a_song(Mylist.front());
  //     pause();
  //     Mylist.pop_front();
  //   }
  
}
