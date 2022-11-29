#include <memory>

#include <ftxui/component/screen_interactive.hpp>  // for Component, ScreenInteractive

#include "forensicpp/ui/main_component.h"

using namespace ftxui;

int main(int argc, const char* argv[]) {
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