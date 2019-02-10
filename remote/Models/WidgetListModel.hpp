#pragma once
#include <QDebug>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QPixmap>
#include <functional>
#include <RemoteContext.hpp>
namespace RemoteUI
{
class GUIItem;
using ItemFactory = std::function<GUIItem*(Context&, QQuickItem* )>;
/** An instance of this class represents a type of widget that can be
 * instantiated.
 */
class WidgetListData : public QObject
{
  Q_OBJECT

  Q_PROPERTY(QString name READ name NOTIFY nameChanged)
  Q_PROPERTY(QString prettyName READ prettyName NOTIFY prettyNameChanged)
  Q_PROPERTY(QString dragImageSource READ dragImageSource NOTIFY
                 dragImageSourceChanged)
  Q_PROPERTY(QQmlComponent* component READ component)
  Q_PROPERTY(QUrl image READ image)
public:
  WidgetListData(QString name, QString prettyName,
      QString dragImageSource, QUrl comp, QUrl image,
      ItemFactory widgetFactory,
      QQmlApplicationEngine& eng)
      : m_name {name}
      , m_prettyName {prettyName}
      , m_dragImageSource {dragImageSource}
      , m_component {&eng, comp}
      , m_image {image}
      , m_widgetFactory{widgetFactory}
  {
    auto e = m_component.errorString();
    if (!e.isEmpty())
      qDebug() << "Error while creating" << name << ": " << e;
  }

  ~WidgetListData();

  QString name() const
  {
    return m_name;
  }

  QString dragImageSource() const
  {
    return m_dragImageSource;
  }

  const QQmlComponent* component() const
  {
    return &m_component;
  }
  QQmlComponent* component()
  {
    return &m_component;
  }

  QString prettyName() const
  {
    return m_prettyName;
  }

  const QUrl& image() const
  {
    return m_image;
  }

  const ItemFactory& widgetFactory() const
  {
    return m_widgetFactory;
  }

Q_SIGNALS:
  void nameChanged(QString name);
  void prettyNameChanged(QString prettyName);
  void dragImageSourceChanged(QString dragImageSource);

private:
  QString m_name;
  QString m_prettyName;
  QString m_dragImageSource;
  QQmlComponent m_component;
  QUrl m_image;
  ItemFactory m_widgetFactory;
};

//! Register new widgets in this class
struct WidgetListModel
{
  WidgetListModel(QQmlApplicationEngine& engine);
  QHash<QString, RemoteUI::WidgetListData*> componentList;
  QList<QObject*> objectList;
};
}
