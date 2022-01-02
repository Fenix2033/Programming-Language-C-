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
        file << "name                   ";
        file << "content                ";
        file << "duration  [h]          ";
        file << "number of participants ";
        file << std::endl;
        auto write = std::for_each(m_lessons.begin(), m_lessons.end(),
                                   [&file](Lesson &les)->void{
                                       file << les.getId() << "                     ";
                                       file << les.getName() << "                     ";
                                       file << les.getContent() << "                     ";
                                       float time = les.getDuration() / 3600;
                                       file << time << "                     ";
                                       file << les.getCountParticipants() << "                     ";
                                       file << std::endl;
                                   });
    } else {
        throw std::domain_error("File is not found");
    }
        file.close();
}

std::vector<Lesson>YogaStudio::getEmptyLessons() const{
    std::vector <Lesson> empty;

    auto foundLesson = m_lessons.begin();

    while (foundLesson != m_lessons.end()){
        foundLesson = std::find_if(foundLesson, m_lessons.end(),
                                   [](const Lesson &les) -> bool{
                                       return les.getCountParticipants() == 0;
                                   });

        if (foundLesson != m_lessons.end()){
           empty.push_back(*foundLesson);
        }

        foundLesson++;
    }

    return empty;

}

std::vector<Lesson> YogaStudio::getLessonsWithDurationInRange(long min, long max) const{
    std::vector<Lesson> duration;

    if (max < min){
        long a = max;
        max = min;
        min = a;
    }

    assert(max > min);

    auto foundLesson = m_lessons.begin();

    while (foundLesson != m_lessons.end()){
        foundLesson = std::find_if(foundLesson, m_lessons.end(),
                                    [min, max](const Lesson &les) -> bool{
                                        return les.getDuration() > min and les.getDuration() < max;
                                    });

        if (foundLesson != m_lessons.end()){
            duration.push_back(*foundLesson);
        }

        foundLesson++;
    }

    return duration;

}

// 5 body
/// Vratte podil muzu a zen na vsech lekcich.
/// Celkovy pocet muzu deleno celkovy pocet zen.
float YogaStudio::getRatioOfManAndWoman() const{

    int male = 0;
    int female = 0;

    auto ratio = std::for_each(m_lessons.begin(), m_lessons.end(),
            [&male, &female](const Lesson &les)->void{
        male += les.getCountMale();
        female += les.getCountFemale();
    });

    if (female == 0){
        return 100;
    }

    if (male == 0){
        return 0;
    }

    return 100 / (male + female) * male;
}
