#include "htmlpage.h"

HtmlPage::HtmlPage(QWidget *parent) :
   QWebEngineView(parent)
{
    // Cached X/Y coordinates
    sX = 0 ; sY = 0 ;
    // Set up the communications channel
    this->page()->setWebChannel(&channel) ;
    channel.registerObject("widget", WebObjectInstance::instance());
    connect(WebObjectInstance::instance(),SIGNAL(signalCursorMoved(int,int)),this,SLOT(slotJsUpdated(int,int)));
    // Set the page content
    setUrl(QUrl("qrc:/index.html")) ;
}

HtmlPage::~HtmlPage()
{
}

void HtmlPage::slotJsUpdated(int x, int y)
{
    qDebug("slotJsUpdated");
     addDot(x,y,6,"#FFFFFF");
}

// Called when javascript coordinates are updated
//void HtmlPage::jsUpdated(int x, int y)
//{
//    sX = x ; sY = y ;
////    emit cursorMoved(x, y) ;
//    emit gWebObject->signalCursorMoved(x,y);
//    addDot(x, y, 4, "#FFFFFF") ;
//}

// Call to add a dot at the given x/y coordinate
void HtmlPage::addDot(int x, int y, int sz, QString colour)
{
    QString command = QString("addDot(%1,%2,%3,'%4');").arg(x).arg(y).arg(sz).arg(colour) ;
    page()->runJavaScript(command) ;
}

