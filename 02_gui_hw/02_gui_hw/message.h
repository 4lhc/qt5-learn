#ifndef MESSAGE_H
#define MESSAGE_H

#include <QMetaType>
#include <QString>
#include <QStringList>
#include <QDebug>

class Message
{
public:
    Message() = default;
    ~Message() = default;
    Message(const Message &) =  default;
    Message &operator=(const Message &) = default;
    Message(const QString &body, const QStringList &headers);

    QString body() const;
    QStringList headers() const;


private:
    QString m_body;
    QStringList m_headers;
};

Q_DECLARE_METATYPE(Message); //This will make the type available for use in direct signal-slot connections

QDebug operator<<(QDebug dbg, const Message &message);

#endif // MESSAGE_H
