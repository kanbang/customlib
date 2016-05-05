import QtQuick 1.1

//HardwareModelsLearn

Item {
    property alias lightModel : light
    property alias heatingModel : heating
    property alias blindModel : blind
    property alias windowModel: window

    ListModel {
        id: light

        ListElement {
            name: "Livingroom"
            iconOn: "pics/icons/light_on.png"
            iconOff: "pics/icons/light_off.png"
            on: true
            startTimeHours: 7
            endTimeHours: 19
            startTimeMinutes: 00
            endTimeMinutes:45
            lowestLux: 6
        }
        ListElement {
            name: "Hall"
            iconOn: "pics/icons/light_on.png"
            iconOff: "pics/icons/light_off.png"
            on: false
            startTimeHours: 7
            endTimeHours: 19
            startTimeMinutes: 00
            endTimeMinutes: 45
            lowestLux: 7
        }
        ListElement {
            name: "Bathroom"
            iconOn: "pics/icons/light_on.png"
            iconOff: "pics/icons/ligth_off.png"
            on: false
            startTimeHours: 6
            endTimeHours: 18
            startTimeMinutes: 00
            endTimeMinutes: 45
            lowestLux: 4
        }
    }

    /**
      *
      */
    ListModel {
        id: heating

        ListElement {
            name: "Entrance"
            iconOn: "pics/icons/radiator_on.png"
            iconOff: "pics/icons/radiator_off.png"
            on: true
            startTimeHours: 20
            endTimeHours: 7
            startTimeMinutes: 00
            endTimeMinutes: 00
            dayTemp: 24
            nightTemp: 14
        }

        ListElement {
            name: "Hall"
            iconOn: "pics/icons/radiator_on.png"
            iconOff: "pics/icons/radiator_off.png"
            on: true
            startTimeHours: 19
            endTimeHours: 6
            startTimeMinutes: 00
            endTimeMinutes: 30
            dayTemp: 24
            nightTemp: 14
        }
        ListElement {
            name: "Kitchen"
            iconOn: "pics/icons/radiator_on.png"
            iconOff: "pics/icons/radiator_off.png"
            on: false
            startTimeHours: 19
            endTimeHours: 10
            startTimeMinutes: 00
            endTimeMinutes: 55
            dayTemp: 24
            nightTemp: 14
        }

        ListElement {
            name: "Kids"
            iconOn: "pics/icons/radiator_on.png"
            iconOff: "pics/icons/radiator_off.png"
            on: false
            startTimeHours: 19
            endTimeHours: 6
            startTimeMinutes: 00
            endTimeMinutes: 20
            dayTemp: 24
            nightTemp: 14
        }
    }


    /**
    * A model for all blinds in the house that can be controlled
    */
    ListModel {
        id: blind

        ListElement {
            name: "Kitchen"
            iconOn: "pics/icons/jalousie_down.png"
            iconOff: "pics/icons/jalousie_up.png"
            on: true
            startTimeHours: 19
            endTimeHours: 7
            startTimeMinutes: 00
            endTimeMinutes: 45
            closeTemp: 22
            closeWind: 7
            automaticWindClose: true
        }

        ListElement {
            name: "Bedroom"
            iconOn: "pics/icons/jalousie_down.png"
            iconOff: "pics/icons/jalousie_up.png"
            on: false
            startTimeHours: 21
            endTimeHours: 10
            startTimeMinutes: 00
            endTimeMinutes: 30
            closeTemp: 18
            closeWind: 6
            automaticWindClose: false
        }
    }

    /**
    * A model for all windows in the house that can be controlled
    */
    ListModel {
        id: window

        ListElement {
            name: "Kitchen"
            iconOn: "pics/icons/window_open.png"
            iconOff: "pics/icons/window_closed.png"
            on: false
            closeWind: 6
            closeRain: 32
        }

        ListElement {
            name: "Bedroom"
            iconOn: "pics/icons/window_open.png"
            iconOff: "pics/icons/window_closed.png"
            on: true
            closeWind: 7
            closeRain: 38
        }

        ListElement {
            name: "Library"
            iconOn: "pics/icons/window_open.png"
            iconOff: "pics/icons/window_closed.png"
            on: false
            closeWind: 6
            closeRain: 18
        }
    }
}
