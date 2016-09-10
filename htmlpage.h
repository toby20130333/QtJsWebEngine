
#ifndef HTMLPAGE_H
#define HTMLPAGE_H

#include <QWidget>
#include <QString>
#include <QtWebEngineWidgets>
#include <QtWebChannel/QtWebChannel>
#include "webobjectinstance.h"

///
/// \brief The HtmlPage class
///  自定义WebengineView
/// 此类作为C++与JS之间通讯的桥梁
/// 也可以自定义QObject类作为注入到js的对象
/// 此对象是否可以为单例呢？
///
class HtmlPage : public QWebEngineView
{
    Q_OBJECT
public:
    explicit HtmlPage(QWidget *parent = 0);
    virtual ~HtmlPage() ;

public slots:
    void slotJsUpdated(int x, int y) ;// Callback from javascript (save X & Y)

private:
    int sX, sY ;                     // X and Y coordinate stores
    QWebChannel channel ;  // Channel for C++ to Javascript comms

private:
    ///
    /// 此处声明多个私有方法
    /// 通过c++注入代码字符串进行通知js
    ///
    void addDot(int x, int y, int sz, QString colour) ;   // Creates dot at current X and Y
};

#endif // HTMLPAGE_H
