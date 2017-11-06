import QtQuick 2.4
import com.kdab.throttleitem 1.0

Rectangle {
    id: root
    color: "blue"
    opacity: ti.value

    ThrottleItem {
        id: ti
        value: 0.5
        slowdown: 2
        NumberAnimation on value {
            from: 0
            to: 1.0
            loops: Animation.Infinite
        }
    }
}
