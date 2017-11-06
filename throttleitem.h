/*
Copyright (C) 2017 Sérgio Martins <iamsergio@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef THROTTLEITEM_H
#define THROTTLEITEM_H

#include <QObject>
#include <QVariant>
#include <QElapsedTimer>

class ThrottleItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int slowdown READ slowdown WRITE setSlowdown NOTIFY slowdownChanged)
public:
    explicit ThrottleItem(QObject *parent = nullptr);
    static void registerType();

    QVariant value() const;
    void setValue(const QVariant &value);

    uint slowdown() const;
    void setSlowdown(uint);

signals:
    void valueChanged();
    void slowdownChanged();

private:
    QVariant m_value;
    uint m_count = 0;
    uint m_slowdown = 1;
};

#endif
