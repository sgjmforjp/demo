#[macro_use]
extern crate log;
extern crate log4rs;

fn main() {
    log4rs::init_file("config/log4rs.yml", Default::default()).unwrap();

    // debug!("this is a debug {}", "message");
    // info!("this is a info {}", "message");
    // warn!("this is a warn {}", "message");
    // error!("this is a error {}", "message");

    debug!(target: "debug", "this is a debug {}", "message");
    info!(target: "info", "this is a info {}", "message");
    warn!(target: "warn", "this is a warn {}", "message");
    error!(target: "error", "this is a error {}", "message");
}
