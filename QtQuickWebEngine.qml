import QtQuick 2.0
import QtQuick.Window 2.0
import QtWebEngine 1.0

Item {
    width: 1024
    height: 750
    visible: true
    WebEngineView {
        anchors.fill: parent
        url: "http://www.heilqt.com"
    }
}
