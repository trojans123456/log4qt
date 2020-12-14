#include <QFile>
#include <QCoreApplication>
#include <QDebug>

#include "log4qt/log4qt.h"
#include "log4qt/loggerrepository.h"
#include "log4qt/logmanager.h"
#include "log4qt/propertyconfigurator.h"

using namespace Log4Qt;

int main(int argc,char *argv[])
{
    QString path = "qlog.config";


    QCoreApplication a(argc,argv);

    PropertyConfigurator::configureAndWatch(path);


    /** 获取logger */
    Logger *debug = LogManager::logger("dstDebug");
    if(!debug)
    {
        qDebug() << "fjsklfjs" ;
        return -1;
    }

    debug->info("jslkjfsdlk");
    debug->debug("ssssss\n");

    return a.exec();
}
