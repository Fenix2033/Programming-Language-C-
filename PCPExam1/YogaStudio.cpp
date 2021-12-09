#include "YogaStudio.hpp"

YogaStudio::YogaStudio(){}


void YogaStudio::addLesson(Lesson lesson){
    m_lessons.push_back(lesson);
}

void YogaStudio::registerParticipant(long lessonId, Participant participant){
        auto it = std::find_if(m_lessons.begin(), m_lessons.end(),
                               [lessonId](const Lesson &les) -> bool {
                                   return les.getId() == lessonId;
                               });
        if (it != m_lessons.end()) {
            m_lessons.at(lessonId).addParticipants(participant);
        } else {
            throw std::out_of_range("Lesson not found");
        }

//    for (int i = 0; i < m_lessons.size(); i++){
//        if (m_lessons.at(i).getId() == lessonId){
//            m_lessons.at(i).addParticipants(participant);
//        }
//    }

}

void YogaStudio::printTimetable(std::string fileName) {
    std::ofstream file(fileName);

    if (file.is_open()) {

//        file << "ID" << "           " << std::endl;
//        file << "name" << "           " << std::endl;
//        file << "content" << "           " << std::endl;
//        file << "duration: " << "           " << std::endl;
//        file.close();
//    }
//        std::for_each(m_lessons.begin(), m_lessons.end(),
//                    [fileName](const Lesson &les) -> void {
//                        std::ofstream file(fileName);
//                        if (file.is_open()){
//                            file << les.getId();
//                            file << les.getName();
//                            file << les.getContent();
//                            file << les.getDuration() / 3600;
//                        } else {
//                            std::cout << "File is not open" << std::endl;
//                        }
//                        file.close();
//        });
//    file.close();
//    }
//
        file << "ID                     ";
        for (int i = 0; i < m_lessons.size(); i++) {
            file << "| "  << m_lessons.at(i).getId() << "                               ";
        }
        file << std::endl;

        file << "name                   ";
        for (int i = 0; i < m_lessons.size(); i++) {
            file << "| " << m_lessons.at(i).getName() << "                    ";
        }
        file << std::endl;

        file << "content                ";
        for (int i = 0; i < m_lessons.size(); i++) {
            file << "| " << m_lessons.at(i).getContent() << "           ";
        }
        file << std::endl;

        file << "duration  [h]            ";
        for (int i = 0; i < m_lessons.size(); i++) {
            file << "| " << m_lessons.at(i).getDuration() / 3600 << " hours" << "                       ";
        }
        file << std::endl;

        float time;
        file << "number of participants" << " ";
        for (int i = 0; i < m_lessons.size(); i++) {
            time = m_lessons.at(i).getCountParticipants();
            file << "| " << time / 3600 << "                              ";
        }
        file << std::endl;

    } else {
        std::cout << "File is not open" << std::endl;
    }

    file.close();
}

// 5 body
/// Vrati vsechny lekce s nula ucastniky.
/// Pouzije STL algoritmus a lambda vyraz.
std::vector<Lesson>YogaStudio::getEmptyLessons() const{
    std::vector<Lesson> empty;

    auto foundLesson = std::find_if(m_lessons.begin(), m_lessons.end(),
                            [](const Lesson &les)->bool
                            {les.getCountParticipants() == 0;});

        if(foundLesson != m_lessons.end()){
            std::cout << "Is not found empty lesson" << std::endl;
        }

    for (int i = 0; i < m_lessons.size(); i++) {
        if (m_lessons.at(i).getCountParticipants() == 0) {
            std::cout << m_lessons.at(i).getName() << " empty" << std::endl;
            empty.push_back(m_lessons.at(i));
        }

        return empty;

    }
};



// 7 bodu
/// Vratte seznam lekci, jejichz roszsah je mezi min a max, vcetne.
/// Pokud je max mensi jak min, vyhodte vhodnou vyjimku.
/// Pouzijte STL algoritmus a lambda vyraz.
std::vector<Lesson> YogaStudio::getLessonsWithDurationInRange(long min, long max) const{

}

// 5 body
/// Vratte podil muzu a zen na vsech lekcich.
/// Celkovy pocet muzu deleno celkovy pocet zen.
float YogaStudio::getRatioOfManAndWoman() const{

}
