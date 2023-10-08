#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QMutex>
#include <QObject>

class Logger
{
    public:
        static bool init();

        static void debug( const QString& str );
        static void debug( const char * fmt, ... );

        static void error( const QString& str );
        static void error( const char * fmt, ... );

    private:
        explicit Logger();
        void     add(const char *type, const char * str );

        QFile   m_logfile;
        QMutex  m_logMutex;
};

#endif // LOGGER_H
