// This is an open source non-commercial project. Dear PVS-Studio, please check
// it. PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "WidgetListModel.hpp"
namespace RemoteUI
{
WidgetListData::~WidgetListData()
{
}

WidgetListModel::WidgetListModel(QQmlApplicationEngine& engine)
{
  componentList.push_back(new RemoteUI::WidgetListData {
      WidgetKind::HSlider, "HSlider", "Horizontal Slider", "drag_hslider.png",
      QUrl("qrc:///qml/widgets/dynamic/DynamicHSlider.qml"),
      QUrl("qrc:///qml/widgets/static/StaticHSlider.qml"), engine});

  componentList.push_back(new RemoteUI::WidgetListData {
      WidgetKind::VSlider, "VSlider", "Vertical Slider", "drag_vslider.png",
      QUrl("qrc:///qml/widgets/dynamic/DynamicVSlider.qml"),
      QUrl("qrc:///qml/widgets/static/StaticVSlider.qml"), engine});

  componentList.push_back(new RemoteUI::WidgetListData {
      WidgetKind::CheckBox, "Switch", "CheckBox", "drag_switch.png",
      QUrl("qrc:///qml/widgets/dynamic/DynamicSwitch.qml"),
      QUrl("qrc:///qml/widgets/static/StaticSwitch.qml"), engine});

  componentList.push_back(new RemoteUI::WidgetListData {
      WidgetKind::LineEdit, "LineEdit", "LineEdit", "",
      QUrl("qrc:///qml/widgets/dynamic/DynamicLineEdit.qml"),
      QUrl("qrc:///qml/widgets/static/StaticLineEdit.qml"), engine});

  componentList.push_back(new RemoteUI::WidgetListData {
      WidgetKind::Label, "Label", "Label", "",
      QUrl("qrc:///qml/widgets/dynamic/DynamicLabel.qml"),
      QUrl("qrc:///qml/widgets/static/StaticLabel.qml"), engine});

  componentList.push_back(new RemoteUI::WidgetListData {
      WidgetKind::PushButton, "Button", "Button", "drag_switch.png",
      QUrl("qrc:///qml/widgets/dynamic/DynamicButton.qml"),
      QUrl("qrc:///qml/widgets/static/StaticButton.qml"), engine});

  // QML absolutely wants a QList<QObject*>
  for (auto l : componentList)
    objectList.push_back(l);
}
}
