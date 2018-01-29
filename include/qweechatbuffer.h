#ifndef QWEECHATBUFFER_H
#define QWEECHATBUFFER_H

#include <QObject>
#include <QDateTime>
#include <weechat/weechat-plugin.h>


class QWeeChatBuffer : public QObject
{
  Q_OBJECT
public:
  explicit QWeeChatBuffer(const QString &name, QObject *parent = nullptr);
  ~QWeeChatBuffer();

  void close();
  void clear();
  void printf(const QString &message, const QString &tags, const QDateTime &dateTime);

  void setProperty(const QString &name, const QString &value);
  QString get(const QString &name);

  void set(const QString &name, const QString &value);

private:

signals:
  void onInput(QString);
  void onClose();
public slots:
public:
//private:
  QString _name;
  t_gui_buffer *_buffer;
};

extern t_weechat_plugin *weechat_plugin;

#include "qweechatnicklist.h"
/*
class QWeeCordChannel : public QObject {
  QWeeCordChannel(QObject *parent = nullptr) : QObject(parent)
  {

  }
};


*/



#endif // QWEECHATBUFFER_H
