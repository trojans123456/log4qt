#include <QFile>
#include <QCoreApplication>
#include <QDebug>
#include <QTextCodec>
#include <QTimer>
#include <QTextStream>

#ifdef __linux__
#include <unistd.h>
#endif

#include "log4qt/log4qt.h"
#include "log4qt/loggerrepository.h"
#include "log4qt/logmanager.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "log4qt/ttcclayout.h"
#include "log4qt/consoleappender.h"

using namespace Log4Qt;



int xx_main(int argc,char *argv[])
{
    QCoreApplication a(argc,argv);
#if 0
    Logger *logger = Logger::rootLogger();


    TTCCLayout *layout = new TTCCLayout();
    layout->setName("debugLayout");
    layout->activateOptions();

    /** console appender */
    ConsoleAppender *appender = new ConsoleAppender();
    appender->setName("debugAppender");
    appender->setLayout(layout);
    appender->setEncoding(QTextCodec::codecForName("UTF-8"));  // 设置编码
    appender->setTarget(Log4Qt::ConsoleAppender::STDOUT_TARGET);  // 输出到 stdout
    appender->setImmediateFlush(true);  // 立即刷新
    appender->setThreshold(Log4Qt::Level::ALL_INT);  // 设置阈值级别为 INFO
    appender->activateOptions();

    /** logger 上添加 apender */
    logger->addAppender(appender);

    logger->setLevel(Level::ALL_INT);

    logger->debug("jfdslkjdslkjs\n");
    logger->info("jflkdsjflkds");
#endif

    PropertyConfigurator::configure("log4qt.proerties.cfg");

    Logger *logger = LogManager::logger("mylogger");
    //Logger *logger = LogManager::rootLogger();

    logger->info("jfdslj");
    logger->debug("jskljfds");

    return a.exec();
}

int logcfg_main(int argc,char *argv[])
{
    QCoreApplication a(argc,argv);



    /* 加载配置 */
    PropertyConfigurator::configure("log.cfg");

    Logger *logger = LogManager::logger("forDebug");

    int cnt = 0;
    while(0)
    {
        logger->info("cnt = %1",cnt++);
        usleep(10 *1000);
    }
    logger->info("info....");
    logger->debug("debug....");

    return a.exec();
}

int main(int argc,char *argv[])
{
    QCoreApplication a(argc,argv);

    PropertyConfigurator::configure("log.cfg");

    Logger *logger = LogManager::logger("forDebug");

    Layout *layout = logger->appender("appenderFile")->layout();

    WriterAppender *appender = new WriterAppender();

    QFile f("write.log");
    f.open(QIODevice::WriteOnly);

    QTextStream text(&f);

    appender->setWriter(&text);
    appender->setLayout(layout);
    appender->activateOptions();

    logger->addAppender(appender);

    int cnt = 0;
    while(1)
    {
        logger->debug("jfdksljfsld=%1\n",cnt++);
        usleep(10 * 1000);
    }


    return a.exec();
}
