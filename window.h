#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QBoxLayout>

#include <windows.h>

class Window : public QWidget
{
  Q_OBJECT

public:
  Window(QWidget *parent = 0) {
    QVBoxLayout* layout = new QVBoxLayout();

    QPushButton* run = new QPushButton("Run", parent);
    QObject::connect(run, SIGNAL(clicked()), this, SLOT(runLongComputation()));
    layout->addWidget(run);
    
    QPushButton* runWithProcessEvents = new QPushButton("Run With Process Events", parent);
    QObject::connect(runWithProcessEvents, SIGNAL(clicked()), this, SLOT(runLongComputationWithProcessEvents()));
    layout->addWidget(runWithProcessEvents);

    QPushButton* abort = new QPushButton("abort", parent);
    QObject::connect(abort, SIGNAL(clicked()), this, SLOT(abort()));
    layout->addWidget(abort);

    this->setLayout(layout);
    this->setWindowTitle(tr("Abort Text"));
    resize(480, 320);
  }

public slots:

  void runLongComputation() {
    qDebug() << "Start running --";
    for (int i = 0; i < 5; ++i)
    {
      Sleep(1000); // sleep 1sec
    }
    qDebug() << "-- Stop running";
  }

  void runLongComputationWithProcessEvents() {
    qDebug() << "Start running (with process events) --";
    for (int i = 0; i < 5; ++i)
    {
      Sleep(1000); // sleep 1sec
      QApplication::processEvents();
    }
    qDebug() << "-- Stop running (with process events)";
  }

  void abort() {
    qDebug() << "Abort called !";
  }


};
#endif
