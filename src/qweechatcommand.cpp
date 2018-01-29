#include "../include/qweechatcommand.h"

#include <QDebug>
#include <weechat/weechat-plugin.h>

extern t_weechat_plugin *weechat_plugin;

namespace {
int QWeeChatCommand_Command(const void *pointer, void *data,
                            struct t_gui_buffer *buffer,
                            int argc, char **argv, char **argv_eol) {
  QWeeChatCommand *command = reinterpret_cast<QWeeChatCommand*>(const_cast<void*>(pointer));
  qWarning() << __PRETTY_FUNCTION__;
  emit command->onCommand();
  return true;
}

}


QWeeChatCommand::QWeeChatCommand(const QString &name, const QString &desc, QObject *parent)
{
  _hook = weechat_hook_command(name.toLocal8Bit().data(), desc.toLocal8Bit().data(),
                       nullptr, nullptr,
                       NULL, &QWeeChatCommand_Command, this, NULL);
}
