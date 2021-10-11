function blinkEngine(self, signal_status) {
    //self.color = "000000";

    timer = new Timer();
    timer.interval = 1000;
    timer.repeat = true;
    timer.triggered.connect(function () {
        print("I'm triggered once every second");
    })

    timer.start();
}
