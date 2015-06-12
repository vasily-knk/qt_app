struct my_widget
    : QWidget
{
    my_widget(QImage *img)
        : QWidget(nullptr)
        , img_(img)
    {}

    void paintEvent(QPaintEvent *) 
    {
        QPainter p(this);
        p.drawImage(QPoint(0, 0), img_);
    }

private:
    QImage *img_;
};

int main(int argv, char **args)
{
    QApplication app(argv, args);

    vector<char> buffer(256 * 256 * 4, 0);

    my_widget w;

    QVBoxLayout *layout = new QVBoxLayout(&w);
    QImage *img = new QImage(reinterpret_cast<uchar*>(buffer.data()), 256, 256, QImage::Format_RGBA8888);

    w.show();

    return app.exec();
}