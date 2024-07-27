#include "AnnouncementList.h"
#include "MongoDataBase.h"
AnnouncementList *AnnouncementList::GetInstance() {
    static AnnouncementList announcementlist;
    return &announcementlist;
}
AnnouncementList::AnnouncementList(){

}
AnnouncementList::~AnnouncementList(){

}