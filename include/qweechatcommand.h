#ifndef QWEECHATCOMMAND_H
#define QWEECHATCOMMAND_H

#include <QObject>

class t_hook;

class QWeeChatCommand : public QObject
{
  Q_OBJECT
public:
  explicit QWeeChatCommand(const QString &name, const QString &desc, QObject *parent = nullptr);

signals:
  void onCommand(); //TODO: add support for arguments

private:
  t_hook *_hook;
};

#endif // QWEECHATCOMMAND_H
