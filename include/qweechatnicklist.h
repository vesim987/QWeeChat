#ifndef QWEECHATNICKLIST_H
#define QWEECHATNICKLIST_H

#include <QObject>
#include "qweechatnickgroup.h"

class QWeeChatNickList : public QObject
{
  Q_OBJECT
public:
  explicit QWeeChatNickList(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QWEECHATNICKLIST_H
