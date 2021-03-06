#include<string>
#include "Image.hpp"
#ifndef _INCLUDE_SONG
#define _INCLUDE_SONG



struct Song
{
  std::string Source;
  // From Xiami? Amazon? iTunes?
  // You can custom by yourself
  std::string ID;
  std::string PATH;
  // url or local path
  ////////////////
  ////use ID3 Standard///
  // Basic Tags  
  std::string Title;
  std::string Artist;
  std::string Album;
  std::string Year;
  std::string Comment;
  std::string Track;
  std::string Genre;

  // Extended Tags
  std::string Speed;
  std::string Start_time;
  std::string End_time;

  std::string Cover;

  ///////////////////////
  std::string Note;
  // This value will pass to your program..
  
  Song(){}
  Song(std::string PATH)
  {
    this->PATH = PATH;
  }

};

#endif
