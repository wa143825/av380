#import "Av380Plugin.h"
#if __has_include(<av380/av380-Swift.h>)
#import <av380/av380-Swift.h>
#else
// Support project import fallback if the generated compatibility header
// is not copied when this plugin is created as a library.
// https://forums.swift.org/t/swift-static-libraries-dont-copy-generated-objective-c-header/19816
#import "av380-Swift.h"
#endif

@implementation Av380Plugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftAv380Plugin registerWithRegistrar:registrar];
}
@end
