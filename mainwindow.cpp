#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Add items to image sort combo box
    ui->imageSort->addItem("Descending by file name");
    ui->imageSort->addItem("Ascending by file name");

    // Add items to class sort combo box
    ui->classSort->addItem("Descending by class name");
    ui->classSort->addItem("Ascending by class name");
}

void MainWindow::on_imageSort_currentTextChanged(const QString &arg1) {
    if(arg1 == "Descending by file name") {
        ui->listImages->model()->sort(0, Qt::DescendingOrder);

    } else if(arg1 == "Ascending by file name") {
        ui->listImages->model()->sort(0, Qt::AscendingOrder);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_imageBrowse_clicked() {
    // Allows you to select a file to open
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open file"), "",
                tr("JPEG (*.jpg *.jpeg);;PNG (*.png)"));

    imageObject = new QImage();
    imageObject->load(imagePath);

    image = QPixmap::fromImage(*imageObject);

    // Adds selected image to graphics view box
    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);

    // Makes selected picture fit in proportion to the graphics window
    ui->graphicsView->ensureVisible(scene->sceneRect());
    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    ui->listImages->addItem(imagePath);
}

void MainWindow::on_imageAdd_clicked() {

}


void MainWindow::on_annotationSave_clicked() {
    QString imagePath = QFileDialog::getSaveFileName(this, tr("Save file"), "",
                tr("JPEG (*.jpg *.jpeg);;PNG (*.png)"));

    *imageObject = image.toImage();

    imageObject->save(imagePath);
}

void MainWindow::on_classBrowse_clicked() {
    ui->listClasses->clear();

    QFile file(QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Text files (*.txt)")));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&file); // Points to file

    QString line = stream.readLine();
    while(!line.isNull()){ // Checks to see if end of file is reached
        line, ui->listClasses->addItem(line); // Adds each class to list widget as single entities
        line = stream.readLine();
    }

    ui->listClasses->addItem(line);
}

void MainWindow::on_shapeSelect_clicked() {
    QModelIndex index = ui->listImages->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();

    QPainter painter;

    QGraphicsRectItem* rectItem = new QGraphicsRectItem(QRectF(0, 0, 320, 240));
    QColor brush_color(Qt::blue); // Fill colour
    brush_color.setAlpha(50); // Make fill colour more opaque
    QPen blackpen(Qt::black);
    blackpen.setWidth(2); // Border width
    rectItem->setBrush(brush_color);
    rectItem->setPen(blackpen);
    rectItem->setFlag(QGraphicsRectItem::ItemIsMovable);
    rectItem->setFlag(QGraphicsRectItem::ItemIsSelectable);
    scene->addItem(rectItem);
}

void MainWindow::on_annotationSelect_clicked() {
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open file"), "",
                tr("JPEG (*.jpg *.jpeg);;PNG (*.png)"));

    imageObject = new QImage();
    imageObject->load(imagePath);

    image = QPixmap::fromImage(*imageObject);

    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);

    ui->graphicsView->ensureVisible(scene->sceneRect());
    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::on_classSort_currentTextChanged(const QString &arg1) {
    if(arg1 == "Descending by file name") {
        ui->listClasses->model()->sort(0, Qt::DescendingOrder);

    } else if(arg1 == "Ascending by file name") {
        ui->listClasses->model()->sort(0, Qt::AscendingOrder);
    }
}
