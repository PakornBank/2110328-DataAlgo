#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};


//  you have to write something below this line 
class compareP1{
  public:
    bool operator()(const Song& lhs, const Song& rhs){
      if (lhs.artist > rhs.artist)
      {
        return true;
      }
      if(lhs.artist == rhs.artist && lhs.title > rhs.title){
          return true;
      }
      if(lhs.artist == rhs.artist && lhs.title == rhs.title && lhs.count > rhs.count){
          return true;
      }
      return false;
    }

};

auto compareP2 = [](const Song &lhs, const Song &rhs)
{
  if(lhs.count < rhs.count)
  {
    return true;
  }
  if(lhs.count == rhs.count && lhs.artist > rhs.artist)
  {
    return true;
  }
  if(lhs.count == rhs.count && lhs.artist == rhs.artist && lhs.title > rhs.title)
  {
    return true;
  }
  return false;
};

//  you *MIGHT* have to change the declaration of pq1 and pq2
CP::priority_queue<Song,compareP1> pq1;
CP::priority_queue<Song,decltype(compareP2)> pq2(compareP2);

#endif
