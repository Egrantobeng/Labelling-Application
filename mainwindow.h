#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene> // Manages graphical items
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QFileDialog>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    /// Main window class
    ///
    /// Containing the GUI's functionalities
    ///
    /// Functions:
    /// ~~~~~~~~~~~~~~.cpp
    /// on_imageBrowse_clicked()
    /// ~~~~~~~~~~~~~~
    /// Allows the user to select an image from their file manager to be displayed in the graphics view
    ///
    /// ~~~~~~~~~~~~~~.cpp
    /// on_annotationSelect_clicked()
    /// ~~~~~~~~~~~~~~
    /// Allows the user to save the annotated file
    ///
    /// ~~~~~~~~~~~~~~.cpp
    /// on_classBrowse_clicked()
    /// ~~~~~~~~~~~~~~
    /// Allows the user to select a class from their file manager
    ///
    /// ~~~~~~~~~~~~~~.cpp
    /// on_annotationSave_clicked()
    /// ~~~~~~~~~~~~~~
    /// Allows the user to save an annotated image
    ///
    /// ~~~~~~~~~~~~~~.cpp
    /// on_classSort_currentTextChanged()
    /// ~~~~~~~~~~~~~~
    /// Allows the user to sort the images in ascending or descending order
    ///
    /// ~~~~~~~~~~~~~~.cpp
    /// on_ShapeSelect_clicked()
    /// ~~~~~~~~~~~~~~
    /// Allows the user to annotate with a rectangle shaped label

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void on_imageBrowse_clicked();
        void on_imageAdd_clicked();
        void on_annotationSave_clicked();
        void on_shapeSelect_clicked();
        void on_classBrowse_clicked();
        void on_imageSort_currentTextChanged(const QString &arg1);
        void on_annotationSelect_clicked();
        void on_classSort_currentTextChanged(const QString &arg1);

private:
        Ui::MainWindow *ui;
        QPixmap image;
        QImage *imageObject;
        QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
