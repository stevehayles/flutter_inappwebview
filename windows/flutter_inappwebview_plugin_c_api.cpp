#include "include/flutter_inappwebview/flutter_inappwebview_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "flutter_inappwebview_plugin.h"

void FlutterInappwebviewPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  flutter_inappwebview::FlutterInappwebviewPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}