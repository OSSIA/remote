import QtQuick 2.11
import QtQuick.Controls 2.4

DynamicHSliderForm
{
    id: widg
    signal valueChange(real val)
    signal addressChanged(string addr)
    property real from: 0.
    property real to: 1.

    slider.mapFunc: function(val) { return from + (to - from) * val; }

   // slider.onPositionChanged: { valueChange(slider.from + slider.position * (slider.to - slider.from)); }
    slider.onValueChanged: {
        valueChange(slider.value);
    }

    property alias dropper: dropper
    AddressDrop
    {
        id: dropper
        item: widg
    }
}
