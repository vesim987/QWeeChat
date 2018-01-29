#include "../include/qweechatbuffer.h"

#include <QMutex>
#include <QDebug>

extern t_weechat_plugin *weechat_plugin;

namespace {
int QWeechatBuffer_InputCallback(const void *pointer, void *, t_gui_buffer *, const char* input_data){

  QWeeChatBuffer *buffer = reinterpret_cast<QWeeChatBuffer*>(const_cast<void*>(pointer));

  emit buffer->onInput(input_data);
  return WEECHAT_RC_OK;
}

int QWeechatBuffer_CloseCallback(const void *pointer, void *, t_gui_buffer *){
  Q_UNUSED(pointer);
  //QWeeChatBuffer *buffer = reinterpret_cast<QWeeChatBuffer*>(const_cast<void*>(pointer));
  //buffer->close();
  return WEECHAT_RC_ERROR;
}
}

QWeeChatBuffer::QWeeChatBuffer(const QString &name, QObject *parent) : QObject(parent), _name(name)
{
 _buffer = weechat_buffer_new(name.toStdString().c_str(),
                              &QWeechatBuffer_InputCallback, this, nullptr,
                              &QWeechatBuffer_CloseCallback, this, nullptr);
}

QWeeChatBuffer::~QWeeChatBuffer() {
  close();
}

void QWeeChatBuffer::close() {
  if(_buffer) {
    weechat_buffer_close(_buffer);
    _buffer = nullptr;
    emit onClose();
  }
}

void QWeeChatBuffer::clear() {
  if(_buffer)
    weechat_buffer_clear(_buffer);
}

void QWeeChatBuffer::printf(const QString &message, const QString &tags, const QDateTime &dateTime) {
  static QMutex mutex {};
  QMutexLocker locker(&mutex);
  weechat_printf_date_tags(_buffer, dateTime.toTime_t(), tags.toLocal8Bit().data(), message.toLocal8Bit().data());
}

void QWeeChatBuffer::setProperty(const QString &name, const QString &value) {
  weechat_buffer_set(_buffer, (QString("localvar_set_") + name).toLocal8Bit().data(), value.toLocal8Bit().data());
}

QString QWeeChatBuffer::get(const QString &name) {
  return weechat_buffer_get_string(_buffer, name.toLocal8Bit().data());
}

void QWeeChatBuffer::set(const QString &name, const QString &value) {
  weechat_buffer_set(_buffer, name.toLocal8Bit().data(), value.toLocal8Bit().data());
}
