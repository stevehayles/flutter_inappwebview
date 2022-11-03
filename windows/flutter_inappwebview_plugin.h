#ifndef FLUTTER_PLUGIN_FLUTTER_INAPPWEBVIEW_PLUGIN_H_
#define FLUTTER_PLUGIN_FLUTTER_INAPPWEBVIEW_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>
#include <windows.h>

#include <memory>
#include <string>
#include <unordered_map>

#include "webview_bridge.h"
#include "webview_host.h"
#include "webview_platform.h"
#include "util/string_converter.h"

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")

namespace flutter_inappwebview {

class FlutterInappwebviewPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  FlutterInappwebviewPlugin(flutter::TextureRegistrar* textures,
                       flutter::BinaryMessenger* messenger);

  virtual ~FlutterInappwebviewPlugin();

  // Disallow copy and assign.
  FlutterInappwebviewPlugin(const FlutterInappwebviewPlugin&) = delete;
  FlutterInappwebviewPlugin& operator=(const FlutterInappwebviewPlugin&) = delete;

 private:
  std::unique_ptr<WebviewPlatform> platform_;
  std::unique_ptr<WebviewHost> webview_host_;
  std::unordered_map<int64_t, std::unique_ptr<WebviewBridge>> instances_;

  WNDCLASS window_class_ = {};
  flutter::TextureRegistrar* textures_;
  flutter::BinaryMessenger* messenger_;

  bool InitPlatform();

  void CreateWebviewInstance(
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>>);
  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue>& method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace flutter_inappwebview

#endif  // FLUTTER_PLUGIN_FLUTTER_INAPPWEBVIEW_PLUGIN_H_