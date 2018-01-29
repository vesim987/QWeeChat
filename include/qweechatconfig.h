#ifndef QWEECHATCONFIG_H
#define QWEECHATCONFIG_H

#include <QObject>
#include <QMap>
#include <weechat/weechat-plugin.h>

#include "qweechatconfigsection.h"

class QWeeChatConfig : public QObject
{
  friend QWeeChatConfigSection;
  friend QWeeChatConfigOption;
  Q_OBJECT
public:
  explicit QWeeChatConfig(const QString &name, QObject *parent = nullptr);

  void read();

  QWeeChatConfigSection* addSection(const QString &name, bool userCanAdd, bool userCanDelete);
  QWeeChatConfigSection* getSection(const QString &name);

signals:
  void onReload();
public slots:

private:
  t_config_file *_config;
  QString _name;
  QMap<QString, QWeeChatConfigSection*> _sections;
};

#endif // QWEECHATCONFIG_H
