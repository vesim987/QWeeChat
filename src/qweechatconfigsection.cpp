#include "../include/qweechatconfigsection.h"

#include <QDebug>
#include "../include/qweechatconfig.h"

extern t_weechat_plugin *weechat_plugin;

/*
namespace {
int QWeeChatConfigSection_ReadCallback(const void *pointer, void *,
                                       t_config_file *configFile, t_config_section *section,
                                       const char *optionName, const char *value) {
  QWeeChatConfigSection *config = reinterpret_cast<QWeeChatConfigSection*>(const_cast<void*>(pointer));
  qWarning() << __PRETTY_FUNCTION__ << " " << optionName << " " << value;
  return WEECHAT_CONFIG_READ_OK;
}

int QWeeChatConfigSection_WriteCallback(const void *pointer, void *,
                                       t_config_file *configFile, const char *optionName) {
  QWeeChatConfigSection *config = reinterpret_cast<QWeeChatConfigSection*>(const_cast<void*>(pointer));
  qWarning() << __PRETTY_FUNCTION__ << " " << optionName;
  return weechat_config_write(configFile);
}

int QWeeChatConfigSection_WriteDefaultCallback(const void *pointer, void *,
                                       t_config_file *configFile, const char *optionName) {
  QWeeChatConfigSection *config = reinterpret_cast<QWeeChatConfigSection*>(const_cast<void*>(pointer));
  qWarning() << __PRETTY_FUNCTION__ << " " << optionName;
  return WEECHAT_CONFIG_WRITE_OK;
}

int QWeeChatConfigSection_CreateOptionCallback(const void *pointer, void *,
                                       t_config_file *configFile, t_config_section *section,
                                       const char *optionName, const char *value) {
  QWeeChatConfigSection *config = reinterpret_cast<QWeeChatConfigSection*>(const_cast<void*>(pointer));
  qWarning() << __PRETTY_FUNCTION__ << " " << optionName << " " << value;
  return WEECHAT_CONFIG_OPTION_SET_OK_CHANGED;
}

int QWeeChatConfigSection_DeleteOptionCallback(const void *pointer, void *,
                                       t_config_file *configFile, t_config_section *section,
                                       t_config_option *option) {
  QWeeChatConfigSection *config = reinterpret_cast<QWeeChatConfigSection*>(const_cast<void*>(pointer));
  qWarning() << __PRETTY_FUNCTION__ << " " << "option" << " " << "value";
  return WEECHAT_CONFIG_OPTION_UNSET_OK_NO_RESET;
}

}*/
//TODO: do something with this...

QWeeChatConfigSection::QWeeChatConfigSection(const QString &name, bool userCanAdd, bool userCanDel, QWeeChatConfig *parent)
  : QObject(parent), _parent(parent), _name(name)
{
  _section = weechat_config_new_section(parent->_config, name.toLocal8Bit().data(), userCanAdd, userCanDel,
                                        nullptr, nullptr, nullptr,
                                        //&QWeeChatConfigSection_ReadCallback, this, nullptr,
                                        nullptr, nullptr, nullptr,
                                        //&QWeeChatConfigSection_WriteCallback, this, nullptr,
                                        nullptr, nullptr, nullptr,
                                        nullptr, nullptr, nullptr,
                                        nullptr, nullptr, nullptr);
                                        //&QWeeChatConfigSection_CreateOptionCallback, this, nullptr,
                                        //&QWeeChatConfigSection_DeleteOptionCallback, this, nullptr);
}

QWeeChatConfigOption *QWeeChatConfigSection::addOption(const QString &name, const QString &defaultValue) {
  auto option = new QWeeChatConfigOption(name, defaultValue, this);
  _options.insert(name, option);
  return option;
}

QWeeChatConfigOption *QWeeChatConfigSection::getOption(const QString &name) {
  auto option = _options.find(name);
  if(option != _options.end())
    return *option;

  return nullptr;
}
