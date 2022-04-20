#include <QCoreApplication>
#include <QDir>
#include <QDirIterator>
#include <QFileInfoList>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QTimer>

void searchdir(const QString &dirpath, const QStringList &dirnames)
{
    QDirIterator iterator(dirpath, dirnames, QDir::NoDotAndDotDot|QDir::Dirs|QDir::Hidden|QDir::System,
                          QDirIterator::Subdirectories);
    while (iterator.hasNext())
    {
        QString strMatchedFilename = iterator.next(); // We will get the location
        qDebug() << __FUNCTION__ << "Filename:" <<  strMatchedFilename;

        //to unblock UI freeze (based on requirement we can enable below code)
        QEventLoop loop;
        QTimer::singleShot(2, &loop, SLOT(quit()));
        loop.exec();
    }
}

void searchfile(const QString &dirpath, const QStringList &filenames)
{
    QDirIterator iterator(dirpath, filenames, QDir::NoDotAndDotDot|QDir::Files|QDir::Hidden|QDir::System,
                          QDirIterator::Subdirectories);
    while (iterator.hasNext())
    {
        QString strMatchedFilename = iterator.next(); // We will get the location
        qDebug() << __FUNCTION__ << "Filename:" <<  strMatchedFilename;

        //to unblock UI freeze (based on requirement we can enable below code)
        QEventLoop loop;
        QTimer::singleShot(2, &loop, SLOT(quit()));
        loop.exec();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString dirpath="C:\\Users\\admin\\OneDrive\\Documents\\data";
    searchfile(dirpath, QStringList() << "abc*" );
    searchdir(dirpath, QStringList() << "data1*");

   //searchfile(dirpath, QStringList() << "123*" << "abc*");//multiple files search
    //searchfile(dirpath, QStringList() << "data1*" << "data2*");//multiple dir's search

    return a.exec();
}
