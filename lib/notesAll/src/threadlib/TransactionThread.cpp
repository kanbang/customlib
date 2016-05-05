#include "TransactionThread.h"

Transaction * const EndTransaction = 0;

FlipTransaction::FlipTransaction(Qt::Orientation orientation)
{
    this->orientation = orientation;
}

QImage FlipTransaction::apply(const QImage &image)
{
    return image.mirrored(orientation == Qt::Horizontal,
                          orientation == Qt::Vertical);
}

QString FlipTransaction::message()
{
    if (orientation == Qt::Horizontal) {
        return QObject::tr("Flipping image horizontally...");
    } else {
        return QObject::tr("Flipping image vertically...");
    }
}

ResizeTransaction::ResizeTransaction(const QSize &size)
{
    this->size = size;
}

QString ResizeTransaction::message()
{
    return QObject::tr("Resizing image...");
}

QImage ResizeTransaction::apply(const QImage &image)
{
    return image.scaled(size, Qt::IgnoreAspectRatio,
                        Qt::SmoothTransformation);
}

ConvertDepthTransaction::ConvertDepthTransaction(int depth)
{
    this->depth = depth;
}

QImage ConvertDepthTransaction::apply(const QImage &image)
{
    QImage::Format format;

    switch (depth) {
    case 1:
        format = QImage::Format_Mono;
        break;
    case 8:
        format = QImage::Format_Indexed8;
        break;
    case 24:
    default:
        format = QImage::Format_RGB32;
    }

    return image.convertToFormat(format);
}

QString ConvertDepthTransaction::message()
{
    return QObject::tr("Converting image depth...");
}

TransactionThread::TransactionThread()
{
    start();   //等待着QWaitCondition::wakeOne();
}

TransactionThread::~TransactionThread()
{
    // 清空事务列队，并且给队列添加一个专门的指针（等于 0)标记。
    // 然后在基类析够函数被隐式调用之前，触发线程并使用QThread::wait()等待到它结束为止。
    // 如果没有用wait函数，则当线程尝试读取类的成员变量时极有可能失败（崩溃）。

    {
        QMutexLocker locker(&mutex);
        while (!transactions.isEmpty())
            delete transactions.dequeue();
        transactions.enqueue(EndTransaction);
        transactionAdded.wakeOne();
    }

    wait();
}

void TransactionThread::addTransaction(Transaction *transact)
{
    // QMutexlocker
    QMutexLocker locker(&mutex);
    transactions.enqueue(transact);
    transactionAdded.wakeOne();
}

void TransactionThread::run()
{
    Transaction *transact = 0;
    QImage oldImage;

    forever {
        {
            QMutexLocker locker(&mutex);

            if (transactions.isEmpty())
                transactionAdded.wait(&mutex);
            transact = transactions.dequeue();
            if (transact == EndTransaction)
                break;

            oldImage = currentImage;
        }

        emit transactionStarted(transact->message());
        QImage newImage = transact->apply(oldImage);
        delete transact;

        {
            QMutexLocker locker(&mutex);
            currentImage = newImage;
            if (transactions.isEmpty())
                emit allTransactionsDone();
        }
    }
}

void TransactionThread::setImage(const QImage &image)
{
    QMutexLocker locker(&mutex);
    currentImage = image;
}

QImage TransactionThread::image()
{
    QMutexLocker locker(&mutex);
    return currentImage;
}
