#ifndef QWEECHATCONFIGSECTION_H
#define QWEECHATCONFIGSECTION_H

#include <QObject>
#include <QMap>
#include <weechat/weechat-plugin.h>

#include "qweechatconfigoption.h"

class QWeeChatConfig;

class QWeeChatConfigSection : public QObject
{
  friend QWeeChatConfigOption;
  Q_OBJECT
public:
  QWeeChatConfigSection(const QString &name, bool userCanAdd, bool userCanDel, QWeeChatConfig *parent);
  QWeeChatConfigOption* addOption(const QString &name, const QString &defaultValue);
  QWeeChatConfigOption* getOption(const QString &name);
private:
  QWeeChatConfig *_parent;
  QString _name;
  t_config_section *_section;

  QMap<QString, QWeeChatConfigOption*> _options;
};

#endif // QWEECHATCONFIGSECTION_H
