#include "message.h"

Message::Message(const QString &body, const QStringList &headers)
{
    m_body = body;
    m_headers = headers;
}

QDebug operator<<(QDebug dbg, const Message &message)
{
    const QString body = message.body();
    QVector<QStringRef> pieces = body.splitRef("\r\n", QString::SkipEmptyParts);
    if (pieces.isEmpty())
        dbg.nospace() << "Message()";
    else if (pieces.size() == 1)
        dbg.nospace() << "Message(" << pieces.first() << ")";
    else
        dbg.nospace() << "Message(" << pieces.first() << " ...)";
    return dbg.maybeSpace();
}

QString Message::body() const
{
    return m_body;
}

QStringList Message::headers() const
{
    return m_headers;
}
