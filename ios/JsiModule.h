#import <React/RCTBridgeModule.h>

#ifdef __cplusplus

#import "react-native-jsi-module.h"

#endif

@interface JsiModule : NSObject <RCTBridgeModule>
@property (nonatomic, assign) BOOL setBridgeOnMainQueue;

@end
