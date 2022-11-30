#include <memory>
#include <iostream>
#include <cstring>
#include <mariadb/conncpp.hpp>

#include <ftxui/component/screen_interactive.hpp>  // for Component, ScreenInteractive

#include "forensicpp/ui/main_component.h"
#include "forensicpp/db/credentials.h"

using namespace ftxui;

int main(int argc, const char* argv[]) {
  // TODO : CLI parsing
  
  /*
    Connect to MariaDB (TODO : move it somewhere else.
    Typically, `conn` should be member of the `Manager` class
  */
  try {
    // Instantiate Driver
    sql::Driver* driver = sql::mariadb::get_driver_instance();

    // Configure Connection
    std::string database_access = "jdbc:mariadb://" + std::string(DEFAULT_MARIADB_FORENSICK_HOST) + ":" + std::string(DEFAULT_MARIADB_FORENSICK_PORT) + "/" + std::string(DEFAULT_MARIADB_FORENSICK_DATABASE);  
    sql::SQLString url(database_access.c_str());
    sql::Properties properties({{"user", DEFAULT_MARIADB_FORENSICK_USER}, {"password", DEFAULT_MARIADB_FORENSICK_PASSWORD}});

    // Establish Connection
    std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
  } catch(sql::SQLException& e) {
    std::cerr << "Error Connecting to MariaDB Platform: " << e.what() << std::endl;
    // Exit (Failed)
    return 1;
  }

  auto screen = ScreenInteractive::Fullscreen();
  auto ui = std::make_shared<MainComponent>();

  // std::atomic<bool> refresh_ui_continue = true;
  // std::thread refresh_ui([&] {
  //   while (refresh_ui_continue) {
  //     using namespace std::chrono_literals;
  //     std::this_thread::sleep_for(0.05s);
  //     // After updating the state, request a new frame to be drawn. This is done
  //     // by simulating a new "custom" event to be handled.
  //     screen.Post(Event::Custom);
  //   }
  // });

  screen.Loop(ui);
  // refresh_ui_continue = false;
  // refresh_ui.join();

  return EXIT_SUCCESS;
}