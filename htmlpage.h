
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
//    ///
//    /// 此处声明多个槽函数用于处理与js之间的交互 供js代码直接调用
//    /// 也可能接收外界C++来的数据 通过信号槽链接
//    ///
    void slotJsUpdated(int x, int y) ;// Callback from javascript (save X & Y)

//    void cplusplusUpdate(const QVariant& var);// connect slot from c++
//signals:
//    /// 此处声明多个信号与外界C++进行通知
//    void cursorMoved(int x, int y) ; // Indicate cursor has moved

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
