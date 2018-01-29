#include "../include/qweechatnickgroup.h"
#include "../include/qweechatbuffer.h"

#include <QDebug>

extern t_weechat_plugin *weechat_plugin;

QWeeChatNickGroup::QWeeChatNickGroup(const QString &name, const QString &color, bool visible, QObject *parent)
  :  QObject(parent)
{
  QWeeChatNickGroup *parent_group = dynamic_cast<QWeeChatNickGroup*>(parent);
  QWeeChatBuffer *buffer = dynamic_cast<QWeeChatBuffer*>(parent);
  t_gui_nick_group *nick_group = nullptr;
  if(parent_group) {
    nick_group = parent_group->_group;
    _buffer = parent_group->_buffer;
  } else if(buffer) {
    _buffer = buffer;
  } else {
    //qFatal() << "inalid parent for QWeechatNickGroup";
  }

  _group = weechat_nicklist_add_group (_buffer->_buffer, nick_group, name.toStdString().c_str(), color.toStdString().c_str(), visible);
}
