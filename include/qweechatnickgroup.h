#ifndef QWEECHATNICKGROUP_H
#define QWEECHATNICKGROUP_H

#include <QObject>
#include <weechat/weechat-plugin.h>

class QWeeChatBuffer;

class QWeeChatNickGroup : public QObject
{
  Q_OBJECT
public:
  explicit QWeeChatNickGroup(const QString &name, const QString &color, bool visible, QObject *parent = nullptr);

signals:

public slots:
private:
public:
  t_gui_nick_group *_group;
  QWeeChatBuffer *_buffer;
};

#endif // QWEECHATNICKGROUP_H
