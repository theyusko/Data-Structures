#include "List.h"
#include <string>

using namespace std;

 struct TrackEntry{
        string title;
        int year;
        List musicians;
    };


struct TrackNode{
        TrackEntry entry;
        TrackNode* next;
    };


class JukeBox {
public:
    JukeBox();
    ~JukeBox();
    void addTrack( string trackTitle, int releaseYear );

    void removeTrack( string trackTitle );

    void addMusician( string trackTitle, string musicianFirstName,
    string musicianLastName, string musicianRole ); //musician == course

    void removeMusician( string trackTitle, string musicianFirstName,
    string musicianLastName );

    void showAllTracks(); //showallstudents

    void showTrack( string trackTitle ); //showstudent

    void showMusicianRoles( string musicianFirstName,
    string musicianLastName );


    TrackNode* trackHead;

private:
    bool findTitle(string trackTitle);
    bool findTrack(string trackTitle);

    int numTracks;

    void lowercase(string str);
};

