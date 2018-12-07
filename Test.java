import com.pi4j.io.gpio.GpioController;
import com.pi4j.io.gpio.GpioFactory;
import com.pi4j.io.gpio.GpioPin;
import com.pi4j.io.gpio.GpioPinDigitalInput;
import com.pi4j.io.gpio.GpioPinDigitalOutput;
import com.pi4j.io.gpio.PinDirection;
import com.pi4j.io.gpio.PinMode;
import com.pi4j.io.gpio.PinPullResistance;
import com.pi4j.io.gpio.PinState;
import com.pi4j.io.gpio.RaspiPin;
import com.pi4j.io.gpio.trigger.GpioCallbackTrigger;
import com.pi4j.io.gpio.trigger.GpioPulseStateTrigger;
import com.pi4j.io.gpio.trigger.GpioSetStateTrigger;
import com.pi4j.io.gpio.trigger.GpioSyncStateTrigger;
import com.pi4j.io.gpio.event.GpioPinListener;
import com.pi4j.io.gpio.event.GpioPinDigitalStateChangeEvent;
import com.pi4j.io.gpio.event.GpioPinEvent;
import com.pi4j.io.gpio.event.GpioPinListenerDigital;
import com.pi4j.io.gpio.event.PinEventType;
import com.pi4j.io.gpio.exception.UnsupportedBoardType;
import com.pi4j.io.serial.*;
import com.pi4j.util.CommandArgumentParser;
import com.pi4j.util.Console;
import java.io.IOException;
import java.util.Date;

class Test extends Throwable {
	public static void main(String[] args) throws Exception {
		// final GpioController gpio = GpioFactory.getInstance();
		// GpioPinDigitalOutput pin10 = gpio.provisionDigitalOutputPin(RaspiPin.GPIO_10);
		// pin10.high();
		// try{Thread.sleep(5000);} catch(Exception e) { System.out.println("caught");}
		// pin10.low();
		// System.out.println("pulsing");
		
		
        // create Pi4J console wrapper/helper
        // (This is a utility class to abstract some of the boilerplate code)
        final Console console = new Console();

        // print program title/header
        console.title("<-- The Pi4J Project -->", "Serial Communication Example");

        // allow for user to exit program using CTRL-C
        console.promptForExit();

        // create an instance of the serial communications class
        final Serial serial = SerialFactory.createInstance();

        // create and register the serial data listener
        serial.addListener(new SerialDataEventListener() {
            @Override
            public void dataReceived(SerialDataEvent event) {

                // NOTE! - It is extremely important to read the data received from the
                // serial port.  If it does not get read from the receive buffer, the
                // buffer will continue to grow and consume memory.

                // print out the data received to the console
                try {
                    console.println("[HEX DATA]   " + event.getHexByteString());
                    console.println("[ASCII DATA] " + event.getAsciiString());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });

        try {
            // create serial config object
            SerialConfig config = new SerialConfig();

            // set default serial settings (device, baud rate, flow control, etc)
            //
            // by default, use the DEFAULT com port on the Raspberry Pi (exposed on GPIO header)
            // NOTE: this utility method will determine the default serial port for the
            //       detected platform and board/model.  For all Raspberry Pi models
            //       except the 3B, it will return "/dev/ttyAMA0".  For Raspberry Pi
            //       model 3B may return "/dev/ttyS0" or "/dev/ttyAMA0" depending on
            //       environment configuration.
            config.device(SerialPort.getDefaultPort())
                  .baud(Baud._9600)
                  .dataBits(DataBits._8)
                  .parity(Parity.NONE)
                  .stopBits(StopBits._1)
                  .flowControl(FlowControl.NONE);

            // parse optional command argument options to override the default serial settings.
            if(args.length > 0){
                config = CommandArgumentParser.getSerialConfig(config, args);
            }

            // display connection details
            console.box(" Connecting to: " + config.toString(),
                    " We are sending ASCII data on the serial port every 1 second.",
                    " Data received on serial port will be displayed below.");


        	// open the default serial device/port with the configuration settings
			serial.open(config);

			// continuous loop to keep the program running until the user terminates the program
			while(console.isRunning()) {
				try {
					// write a formatted string to the serial transmit buffer
					serial.write("CURRENT TIME: " + new Date().toString());

					// write a individual bytes to the serial transmit buffer
					serial.write((byte) 13);
					serial.write((byte) 10);

					// write a simple string to the serial transmit buffer
					serial.write("Second Line");

					// write a individual characters to the serial transmit buffer
					serial.write('\r');
					serial.write('\n');

					// write a string terminating with CR+LF to the serial transmit buffer
					serial.writeln("Third Line");
				}
				catch(IllegalStateException ex){
					ex.printStackTrace();
				}

				// wait 1 second before continuing
				Thread.sleep(1000);
			}

		}
		catch(IOException ex) {
			console.println(" ==>> SERIAL SETUP FAILED : " + ex.getMessage());
			return;
		}
	}
}