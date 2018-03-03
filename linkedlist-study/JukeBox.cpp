#include "JukeBox.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

JukeBox::JukeBox(){
    trackHead = NULL;
    numTracks = 0;
}

JukeBox::~JukeBox(){
    TrackNode *temp;
    while( trackHead!= NULL){
        temp = trackHead;
        trackHead = trackHead->next;
        temp->next = NULL;
        delete temp;
    }
}

bool JukeBox::findTrack(string trackTitle){
    TrackNode* cur = trackHead;
    //lowercase
    lowercase(trackTitle);
    string curTitle;
    while(cur != NULL) {
        lowercase(cur->entry.title);
        if( cur->entry.title.compare(trackTitle) == 0 )
            return true;
        cur = cur->next;
    }
    return false;
}

void JukeBox::addTrack(string trackTitle, int releaseYear) {
    //titles are unique
    if (findTrack(trackTitle)) {
        cout <<"Warning: Title " + trackTitle + " already exists"  << endl;
        return;
    }
    TrackNode* cur = trackHead;
    if (cur == NULL) {
        trackHead = new TrackNode;
        trackHead->entry.title = trackTitle;
        trackHead->entry.year = releaseYear;
        numTracks++;
        return;
    }

    while(cur->next != NULL) {
        cur = cur-> next;
    } //finds the last valid node
    cur ->next = new TrackNode;
    (cur->next)->entry.title = trackTitle;
    (cur->next)->entry.year = releaseYear;
    numTracks++;
    return;
}

void JukeBox::removeTrack(string trackTitle ){
    TrackNode* temp;
    TrackNode* cur = trackHead;
    lowercase(trackTitle);
    string nextTitle = trackHead->entry.title;
    //first case
    if(nextTitle.compare(trackTitle) == 0) {
        temp = trackHead;
        trackHead = trackHead->next;
        temp->next = NULL;
        numTracks--;
        delete temp;
        return;
    }
    //other cases
    while(cur->next != NULL) {
        lowercase((cur->next)->entry.title);
        nextTitle = (cur->next)->entry.title;
        if( nextTitle.compare(trackTitle) == 0 ) {
            //found ya!
            temp = cur->next;
            cur ->next = cur->next->next;
            temp->next = NULL;
            numTracks--;
            delete temp;
            return;
        }
        cur = cur->next;
    }

    //not found anywhere
    cout<<"Warning: Cannot remove, title does not exist"<<endl;
    return;
}

void JukeBox::addMusician(string trackTitle, string musicianFirstName, string musicianLastName, string musicianRole ){
    TrackNode* cur = trackHead;
    lowercase(trackTitle);
    bool success;
    while(cur != NULL) {
        lowercase(cur->entry.title);
        if( (cur->entry.title).compare(trackTitle) == 0 ) {
            //we found the track
            success = cur->entry.musicians.insert(musicianFirstName, musicianLastName, musicianRole);
            if (!success)
                cout << "Warning: Musician " + musicianFirstName + " " + musicianLastName + " already exists in track " + trackTitle << endl;
            return;
        }
        cur = cur->next;
    }
    cout <<"Warning: Cannot add musician, track title does not exist" << endl;
    return;
}

void JukeBox::removeMusician(string trackTitle, string musicianFirstName, string musicianLastName ){
    TrackNode* cur = trackHead;
    lowercase(trackTitle);
    string curTitle;
    bool found = false;

    while(cur != NULL && !found) {
        lowercase(cur->entry.title);
        if( cur->entry.title.compare(trackTitle) == 0 ) {
            found = true;
            ListNode* mscn = cur->entry.musicians.find(musicianFirstName, musicianLastName);
            if (mscn == NULL) {
                cout <<"Warning: Cannot remove musician, musician does not exist in track " + trackTitle <<endl;
                return;
            }
            else {
                cur->entry.musicians.remove(musicianFirstName, musicianLastName);
                return;
            }
        }
        cur = cur->next;
    }
    if (!found) {
        cout <<"Warning: Cannot remove musician, track does not exist" << endl;
        return;
    }
}

void JukeBox::showAllTracks(){
    if(numTracks > 0) {
        TrackNode* cur = trackHead;
        int index = 1;
        while(cur!= NULL) {
            cout << cur->entry.title << ", " << cur->entry.year << "(for the "<< index << "th track)" << endl;
            cur = cur-> next;
            index++;
        }
    }
}

void JukeBox::showTrack(string trackTitle ){
    TrackNode* cur = trackHead;
    lowercase(trackTitle);
    while(cur != NULL) {
        lowercase(cur->entry.title);
        if( (cur->entry.title).compare(trackTitle) == 0 ) {
            cout << cur->entry.title << ", "<< cur->entry.year << endl;
            cur->entry.musicians.display();
            return;
        }
        cur = cur->next;
    }
    return;
}

void JukeBox::showMusicianRoles(string musicianFirstName, string musicianLastName ){
    //go through each track
    int index = 1;
    cout << musicianFirstName + " " + musicianLastName;
    TrackNode* cur = trackHead;
    while (cur != NULL) {
        ListNode* musician = cur->entry.musicians.find(musicianFirstName, musicianLastName);
        if(musician != NULL) {
            cout << musician->role << " ," << cur->entry.title << " ," << cur->entry.year << " ," << "(for the "<< index << "th track)" << endl;
        }
    }
}

void JukeBox::lowercase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

