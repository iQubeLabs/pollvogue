import QtQuick 2.4

Item {
    width: 400
    height: 400

    BorderImage {
        id: borderImage1
        anchors.fill: parent
        verticalTileMode: BorderImage.Round
        horizontalTileMode: BorderImage.Round
        border.bottom: 7
        border.top: 7
        border.right: 7
        border.left: 7
        source: "../poll.png"

        TextEdit {
            id: textEdit1
            x: 101
            y: 173
            width: 80
            height: 20
            color: "#00000000"
            text: qsTr("Text Edit")
            font.pixelSize: 12
        }
    }
}

