#ifndef _INCLUDE_PLAYLIST
#define _INCLUDE_PLAYLIST

#include<deque>
#include "Song.hpp"
using namespace std;

const string OGG_FILE="ggo.";
const string MP3_FILE="3pm.";
const string WAV_FILE="vaw.";
const string FLAC_FILE="calf.";
const string APE_FILE="epa.";


class Playlist
{
private:

  deque<Song> PList;

  bool Check_Valid(Song ToPush)
  {
    string pth = ToPush.PATH;
    string typ;
    int len = pth.length();
    for(int i = len-1; i >= 0; i--)
      {
	typ.push_back(pth[i]);
	if(pth[i] == '.')
	  break;
      }
    if(typ != OGG_FILE &&
       typ != MP3_FILE &&
       typ != WAV_FILE &&
       typ != FLAC_FILE &&
       typ != APE_FILE)
      return false;
    return true;
  }

public:

  Playlist(){}
  Playlist(Song snd)
  {
    PList.push_back(snd);
  }


  int push_back(Song ToPush)
  {
    if(ToPush.PATH.empty()) return 1;
    if(!Check_Valid(ToPush)) return 1;
    PList.push_back(ToPush);
    return 0;
  }

  int push_front(Song ToPush)
  {
    if(ToPush.PATH.empty()) return 1;
    if(!Check_Valid(ToPush)) return 1;
    PList.push_front(ToPush);
    return 0;
  }

  bool empty()
  {
    return PList.empty();
  }

  Song front()
  {
    if(!PList.empty()) return PList.front();
    Song em("ERR_EMPTY");
    return em;
  }

  Song back()
  {
    if(!PList.empty()) return PList.back();
    Song em("ERR_EMPTY");
    return em;
  }


  int pop_front()
  {
    if(PList.empty()) return 1;
    PList.pop_front();
    return 0;
  }

  int pop_back()
  {
    if(PList.empty()) return 1;
    PList.pop_back();
    return 0;
  }

  int merge_playlist_front(Playlist b)
  {
    if(b.PList.empty()) return 1;
    while(!b.PList.empty())
      {
	PList.push_front(b.PList.back());
	b.pop_back();
      }
    return 0;
  }

  int merge_playlist_back(Playlist b)
  {
    if(b.PList.empty()) return 1;
    while(!b.PList.empty())
      {
	PList.push_back(b.PList.front());
	b.pop_front();
      }
    return 0;
  }

};

#endif
