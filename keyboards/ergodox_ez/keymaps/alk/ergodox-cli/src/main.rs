use std::thread::sleep;
use std::time::Duration;

fn main() {
    let api = hidapi::HidApi::new().unwrap();
    if let Some(device) = find_device(&api) {
        for led in [1u8, 2, 4].iter().cycle() {
            manage_led(&device, *led);
            sleep(Duration::from_millis(500));
        }
    } else {
        println!("Device not found");
    }
}

fn manage_led(device: &hidapi::HidDevice, leds: u8) {
    let buf = [0, leds];
    device.write(&buf).unwrap();
}

fn find_device(api: &hidapi::HidApi) -> Option<hidapi::HidDevice> {
    let (vendor_id, product_id) = (0xFEED, 0x1307);
    api.device_list()
        .find(|infos| {
            infos.vendor_id() == vendor_id
                && infos.product_id() == product_id
                && infos.interface_number() == 1
        })
        .map(|infos| infos.open_device(&api).unwrap())
}
