#include<string>
class Movies {
    private:
        std::string name;
        int id;
        int score;
        std::string like;
        bool whether_to_publish();
    public:
        Movies(std::string name, int id, int score);
        ~Movies();
        int get_data() const;
        void set_data();
};