#include "filemanager.h"

FileManager::FileManager()
{

}

std::vector<int> FileManager::loadXml(){
    std::vector<int> mines(36, 0);

    // otevru soubor
    QFile file(":/save.xml");
    if (file.open(QIODevice::ReadOnly)){
        // napojit XML parser
        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&file);
        xmlReader.readNext();
        // hlavni smycka dokud neni konec dokumentu
        while(!xmlReader.isEndDocument()){
            // zkontroluji element, ktery prisel
            if (xmlReader.isStartElement()){
                QString name = xmlReader.name().toString();
                if (name=="field"){
                    // pozor nejdriv musime nacist atributy, pak az obsah...
                    int index = xmlReader.attributes().value("index").toInt();
                    int mineCount = xmlReader.readElementText().toInt();
                    mines.at(index) = mineCount;
                } else if (name == "mines"){
                    // skip
                } else {
                    qCritical() << "Narazil jsem na element jiny nez field" << name <<"\n";
                }
            }
            // nactu dalsi element
            xmlReader.readNext();
        }
    } else {
        qCritical() << "Soubor se nepovedlo otevrit\n";
    }

    return mines;
}
