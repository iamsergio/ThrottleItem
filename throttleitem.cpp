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

#include "throttleitem.h"

#include <QQmlEngine>
#include <QDebug>

ThrottleItem::ThrottleItem(QObject *parent)
    : QObject(parent)
{
}

void ThrottleItem::registerType()
{
    qmlRegisterType<ThrottleItem>("com.kdab.throttleitem", 1, 0, "ThrottleItem");
}

QVariant ThrottleItem::value() const
{
    return m_value;
}

void ThrottleItem::setValue(const QVariant &value)
{
    if (m_value == value)
        return;

    m_count++;

    if (m_count % m_slowdown != 0)
        return;

    m_value = value;
    emit valueChanged();
}

uint ThrottleItem::slowdown() const
{
    return m_slowdown;
}

void ThrottleItem::setSlowdown(uint s)
{
    if (m_slowdown != s) {
        m_slowdown = s;
        emit slowdownChanged();
    }
}
