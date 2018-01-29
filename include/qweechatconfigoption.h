#ifndef QWEECHATCONFIGOPTION_H
#define QWEECHATCONFIGOPTION_H

#include <QObject>
#include <weechat/weechat-plugin.h>

class QWeeChatConfigSection;


class QWeeChatConfigOption : public QObject
{
  Q_OBJECT
public:
  explicit QWeeChatConfigOption(const QString &name, const QString &defaultValue, QWeeChatConfigSection* parent = nullptr);

  template<class T>
  T value();

signals:

public slots:

private:
  t_config_option *_option;
  QWeeChatConfigSection *_parent;
};

#endif // QWEECHATCONFIGOPTION_H
