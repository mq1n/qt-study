#include "my_widget.h"

#include <QPainter>
#include <QPlainTextEdit>

MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent), log_text_edit_(nullptr) {
  // For receiving key events.
  setFocusPolicy(Qt::FocusPolicy::StrongFocus);
}

void MyWidget::paintEvent(QPaintEvent* event) {
  QPainter painter(this);

  // Draw a rectangle if have focus.
  if (hasFocus()) {
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
  }
}

void MyWidget::keyPressEvent(QKeyEvent* event) {
  QString text = event->text();
  if (text.isEmpty()) {
    text = "<Empty>";
  }

  Qt::KeyboardModifiers modifiers = event->modifiers();

  if ((modifiers & Qt::KeyboardModifier::ControlModifier) != 0) {
    text += " (Ctrl)";
  }
  if ((modifiers & Qt::KeyboardModifier::ShiftModifier) != 0) {
    text += " (Shift)";
  }
  if ((modifiers & Qt::KeyboardModifier::AltModifier) != 0) {
    text += " (Alt)";
  }

  QString message = QString("keyPressEvent: %1").arg(text);
  log_text_edit_->appendPlainText(message);
}

void MyWidget::keyReleaseEvent(QKeyEvent* event) {
  log_text_edit_->appendPlainText("keyReleaseEvent");
}
