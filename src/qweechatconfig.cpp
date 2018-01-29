#include "../include/qweechatconfig.h"

extern t_weechat_plugin *weechat_plugin;

namespace {
int QWeeChatConfig_ReloadCallback(const void *pointer, void *, t_config_file *config_file) {
  QWeeChatConfig *config = reinterpret_cast<QWeeChatConfig*>(const_cast<void*>(pointer));

  emit config->onReload();
  return weechat_config_reload(config_file);
}
}

QWeeChatConfig::QWeeChatConfig(const QString &name, QObject *parent)
  : QObject(parent),
    _name(name)
{
  _config = weechat_config_new(name.toLocal8Bit().data(), &QWeeChatConfig_ReloadCallback, this, nullptr);
}

void QWeeChatConfig::read() {
  weechat_config_read(_config);
}

QWeeChatConfigSection *QWeeChatConfig::addSection(const QString &name, bool userCanAdd, bool userCanDelete) {
  auto section = new QWeeChatConfigSection(name, userCanAdd, userCanDelete, this);
  _sections.insert(name, section);
  return section;
}

QWeeChatConfigSection *QWeeChatConfig::getSection(const QString &name) {
  auto section = _sections.find(name);
  if(section != _sections.end())
    return *section;

  return nullptr;
}
