#include "renderwindow.h"
#include "renderarea.h"
#include "client.h"

#include <QApplication>

// This is an unimportant function.
// Client should be seen as the root of this program.

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); // because it's a Qt application

    RenderArea ra;
    Client cli(&ra);
    RenderWindow win(&ra, &cli);

    win.show();

    return app.exec();            // because it's a Qt application
}

