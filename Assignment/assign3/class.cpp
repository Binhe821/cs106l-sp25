#include "class.h"
#include<string>
Movies::Movies(std::string name, int id, int score):name{name}, id{id}, score{score} {};
int Movies::get_data() const{
    return this->score;
}
Movies::~Movies(){

}
void Movies::set_data() {
    this->like = "Yes";
}
bool Movies::whether_to_publish() {
    if(this->score > 8) return true;
    else return false;
}