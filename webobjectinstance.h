#ifndef WEBOBJECTINSTANCE_H
#define WEBOBJECTINSTANCE_H

#include <QObject>

class WebObjectInstance : public QObject
{
    Q_OBJECT
public:
    static WebObjectInstance *instance();
public slots:
    ///
    /// 此处声明多个槽函数用于处理与js之间的交互 供js代码直接调用
    /// 也可能接收外界C++来的数据 通过信号槽链接
    ///
    void slotJsUpdated(int x, int y) ;// Callback from javascript (save X & Y)

    void slotCplusplusUpdate(const QVariant& var);// connect slot from c++
signals:
    /// 此处声明多个信号与外界C++进行通知
    void signalCursorMoved(int x, int y) ; // Indicate cursor has moved

private:
    ///
    /// 此处声明多个私有方法
    /// 通过c++注入代码字符串进行通知js
    ///
    void addDot(int x, int y, int sz, QString colour) ;   // Creates dot at current X and Y
private:
    explicit WebObjectInstance(QObject *parent = 0);
    Q_DISABLE_COPY(WebObjectInstance)
};
#ifndef gWebObject_GLOBAL
#define gWebObject WebObjectInstance::instance();
#endif
#endif // WEBOBJECTINSTANCE_H
