#include "YogaStudio.hpp"

YogaStudio::YogaStudio(){}


void YogaStudio::addLesson(Lesson lesson) {
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

}

void YogaStudio::printTimetable(std::string fileName) {
    std::ofstream file(fileName);

    if (file.is_open()) {
        file << "ID                     ";
        for (int i = 0; i < m_lessons.size(); i++) {
            file << "| "  << m_lessons.at(i).getId() << "                              ";
        }
        file << std::endl;

        file << "name                   ";
        for (int i = 0; i < m_lessons.size(); i++) {
            file << "| " << m_lessons.at(i).getName() << "                            ";
        }
        file << std::endl;

        file << "content                ";
        for (int i = 0; i < m_lessons.size(); i++) {
            file << "| " << m_lessons.at(i).getContent() << "                            ";
        }
        file << std::endl;

        float time;
        file << "duration  [h]          ";
        for (int i = 0; i < m_lessons.size(); i++) {
            time = m_lessons.at(i).getDuration();
            file << "| " << time / 3600 << " hours" << "                  ";
        }
        file << std::endl;


        file << "number of participants" << " ";
        for (int i = 0; i < m_lessons.size(); i++) {
            file << "| " << m_lessons.at(i).getCountParticipants() << "                              ";
        }

        file << std::endl;

    } else {
        std::cout << "File is not open" << std::endl;
    }

    file.close();

}

std::vector<Lesson>YogaStudio::getEmptyLessons() const{

    auto foundLesson = std::for_each(m_lessons.begin(), m_lessons.end(),
                                   [](const Lesson &les)->Lesson
                            {if (les.getCountParticipants() == 0){
                                return les;
                            };});
}

std::vector<Lesson> YogaStudio::getLessonsWithDurationInRange(long min, long max) const{

    long tmpMin = min;
    long tmpMax = max;
    if (max < min){
        long a = max;
        max = min;
        min = a;
        tmpMax = max;
        tmpMin = min;
    }
    assert(max > min);

    auto foundLesson = std::for_each(m_lessons.begin(), m_lessons.end(),
                                        [min, max](const Lesson &les)->Lesson
                                        {if(les.getDuration() > min and les.getDuration() < max){
                                            return les;
                                        }});
}

// 5 body
/// Vratte podil muzu a zen na vsech lekcich.
/// Celkovy pocet muzu deleno celkovy pocet zen.
float YogaStudio::getRatioOfManAndWoman() const{

    int male = 0;
    int female = 0;

    for(int i = 0; i < m_lessons.size(); i++){
        male += m_lessons.at(i).getCountMale();
        female += m_lessons.at(i).getCountFemale();
    }

//    if (female == 0){
//        std::cout << "female = 0" << std::endl;
//        return 0;
//    }

    if (male == 0){
        std::cout << "male = 0" << std::endl;
        return 0;
    }

    return male / female;
}

std::vector<Lesson>  YogaStudio::getLesson() const{
    return m_lessons;
}