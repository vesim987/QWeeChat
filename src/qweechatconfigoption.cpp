#include "../include/qweechatconfigoption.h"

#include <QDebug>

#include <weechat/weechat-plugin.h>
#include "../include/qweechatconfig.h"
#include "../include/qweechatconfigsection.h"

extern t_weechat_plugin *weechat_plugin;

namespace {
int QWeeChatConfigOption_CheckValue(const void *pointer, void *data,
                                    struct t_config_option *option, const char *value) {
  QWeeChatConfigOption *config = reinterpret_cast<QWeeChatConfigOption*>(const_cast<void*>(pointer));
  qWarning() << __PRETTY_FUNCTION__ << " " << value;
  return true;
}

void QWeeChatConfigOption_Change(const void *pointer, void *data,
                                    struct t_config_option *option) {
  QWeeChatConfigOption *config = reinterpret_cast<QWeeChatConfigOption*>(const_cast<void*>(pointer));

  qWarning() << __PRETTY_FUNCTION__;
}

void QWeeChatConfigOption_ChangeData(const void *pointer, void *data,
                                    struct t_config_option *option) {
  QWeeChatConfigOption *config = reinterpret_cast<QWeeChatConfigOption*>(const_cast<void*>(pointer));

  qWarning() << __PRETTY_FUNCTION__;
  //return WEECHAT_CONFIG_READ_OK;
}
}

QWeeChatConfigOption::QWeeChatConfigOption(const QString &name, const QString &defaultValue, QWeeChatConfigSection* parent)
  : _parent(parent),
    QObject(parent)
{

  _option = weechat_config_new_option(_parent->_parent->_config, _parent->_section,
                                      name.toLocal8Bit().data(), "string",
                                      "my weird option", nullptr,
                                      0, 0,
                                      "default", nullptr,
                                      true,
                                      &QWeeChatConfigOption_CheckValue, this, nullptr,
                                      //nullptr, nullptr, nullptr,
                                      &QWeeChatConfigOption_Change, this, nullptr,
                                      //nullptr, nullptr, nullptr,
                                      &QWeeChatConfigOption_ChangeData, this, nullptr
                                      //nullptr, nullptr, nullptr
                                      );
}

template<>
QString QWeeChatConfigOption::value<QString>()
{
  return weechat_config_string(_option);
}
