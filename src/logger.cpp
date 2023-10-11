#include "logger.h"

#include <stdarg.h>
#include <stdio.h>

#include <QDir>
#include <QDateTime>
#include <QApplication>
#include <QMessageBox>
#include <QStandardPaths>

#include "logger.h"

static Logger * pLogger;

Logger::Logger()
{
}

void Logger::add( const char * type, const char *str)
{
    qDebug("%s %s", type, str );

    QMutexLocker m( &m_logMutex );

    if (m_logfile.isOpen()) {
        QDateTime now = QDateTime::currentDateTime();
        QString prefix = QString("%1 %2 ") .arg( now.toString( "yyyy-MM-dd hh:mm:ss" )) .arg(type);
        m_logfile.write( qPrintable(prefix) );
        m_logfile.write( str );
        m_logfile.write( "\n" );
        m_logfile.flush();
    }
}

bool Logger::init()
{
    pLogger = new Logger();

    QStringList paths;

    paths << QApplication::applicationDirPath() << QStandardPaths::writableLocation( QStandardPaths::CacheLocation ) << QStandardPaths::writableLocation( QStandardPaths::TempLocation );

    Q_FOREACH( const QString& path, paths )
    {
        QString logpath = path + QDir::separator() + "karaoke.log";

        pLogger->m_logfile.setFileName( logpath );

        if ( pLogger->m_logfile.open( QIODevice::WriteOnly ) )
            break;
    }

    if ( !pLogger->m_logfile.isOpen() )
    {
        QMessageBox::critical( 0, "Cannot write log file",
                               QString("Cannot write log file to %1: %2")
                               .arg( pLogger->m_logfile.fileName() ) .arg( pLogger->m_logfile.errorString()) );
        return false;
    }

    return true;
}

void Logger::debug(const QString &str)
{
    pLogger->add( "DEBUG", str.toUtf8() );
}

void Logger::debug(const char *fmt, ... )
{
    va_list vl;
    char buf[1024];

    va_start( vl, fmt );
    vsnprintf( buf, sizeof(buf) - 1, fmt, vl );
    va_end( vl );

    pLogger->add( "DEBUG", buf );
}

void Logger::error(const QString &str)
{
    pLogger->add( "ERROR", str.toUtf8() );
}

void Logger::error(const char *fmt, ... )
{
    va_list vl;
    char buf[1024];

    va_start( vl, fmt );
    vsnprintf( buf, sizeof(buf) - 1, fmt, vl );
    va_end( vl );

    pLogger->add( "ERROR", buf );
}

