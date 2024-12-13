import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import com.myinc.StateMashin 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Игровой автомат")
    color: "blue"
    StateMashin{
        id: mashin
        onFirstDrumpRotait: firstItemsView.decrementCurrentIndex()
        onSecondDrumpRotait: secondItemsView.decrementCurrentIndex()
        onThirdDrumpRotait: thirdItemsView.decrementCurrentIndex()
        onEnableStartChanged: start.enabled = enableStart
        onEnableStopChanged: stop.enabled = enableStop
        onNeedRaschet: setPrize(firstItemsView.currentIndex, secondItemsView.currentIndex, thirdItemsView.currentIndex)
        onPrizeValueChanged: prizeTextField.text = prize;
    }

    RowLayout {
        spacing: 30
        anchors.fill: parent
        anchors.margins: 30

        Rectangle{

            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth: 270
            Layout.minimumHeight: 90
            Component {
                id: delegate
                Image {
                    width: 90
                    height: 90
                    source: img
                    smooth: true
                }
            }
            Path {
                id: itemsPath
                startX: firstDrum.width/2
                startY: 60
                PathLine {x: firstDrum.width/2; y: firstDrum.height + 60}
            }
            RowLayout {
                spacing: 30
                anchors.fill: parent
                anchors.margins: 30
                Rectangle {
                    id: firstDrum
                    color: "red"
                    Layout.fillHeight: parent
                    Layout.fillWidth: parent.width/3
                    PathView {
                        id: firstItemsView
                        model: FigureModel{}
                        delegate: delegate
                        path: itemsPath
                        pathItemCount: 3
                    }
                }
                Rectangle{
                    id: secondDrum
                    color: "yellow"
                    Layout.fillHeight: parent
                    Layout.fillWidth: parent.width/3
                    PathView {
                        id: secondItemsView
                        model: FigureModel{}
                        delegate: delegate
                        path: itemsPath
                        pathItemCount: 3
                    }
                }
                Rectangle {
                    id: thirdDrum
                    color: "green"
                    Layout.fillHeight: parent
                    Layout.fillWidth: parent.width/3
                    PathView {
                        id: thirdItemsView
                        model: FigureModel{}
                        delegate: delegate
                        path: itemsPath
                        pathItemCount: 3
                        focus: true
                    }
                }
            }
            Rectangle{
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                height: 30
                color: "white"
            }
        }
        ColumnLayout{
            Layout.fillHeight: true
            Button {
                id: start
                text: qsTr("Старт")
                enabled: mashin.enableStart
                Layout.minimumHeight: 50
                Layout.maximumHeight: 100
                Layout.minimumWidth: 100
                Layout.maximumWidth: 100
                onClicked: {
                    mashin.nextStep();
                }
            }
            Item {
                Layout.fillHeight: true
            }
            TextField {
                id: prizeTextField
                Layout.minimumHeight: 20
                Layout.maximumHeight: 20
                Layout.minimumWidth: 100
                Layout.maximumWidth: 100
                enabled: false
                text: qsTr("0")
                visible: true
                clip: false
                horizontalAlignment: Text.AlignRight
            }
            Item {
                Layout.fillHeight: true
            }
            Button {
                id: stop
                text: qsTr("Стоп")
                enabled: mashin.enableStop
                Layout.minimumHeight: 50
                Layout.maximumHeight: 100
                Layout.minimumWidth: 100
                Layout.maximumWidth: 100
                onClicked: {
                    mashin.nextStep();
                }
            }
        }
    }
    Rectangle{
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 30
        color: "blue"
    }
}
