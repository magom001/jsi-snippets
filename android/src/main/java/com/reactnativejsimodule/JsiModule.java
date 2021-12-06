package com.reactnativejsimodule;

import android.util.Log;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.JavaScriptContextHolder;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.module.annotations.ReactModule;

@ReactModule(name = JsiModule.NAME)
public class JsiModule extends ReactContextBaseJavaModule {
  public static final String NAME = "JsiModule";

  public JsiModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  public static void install(JavaScriptContextHolder jsContext) {
    nativeInstall(jsContext.get());
  }

  @Override
  @NonNull
  public String getName() {
    return NAME;
  }

  static {
    try {
      // Used to load the 'native-lib' library on application startup.
      System.loadLibrary("cpp");
    } catch (Exception ignored) {
    }
  }

  private static native void nativeInstall(long jsi);
}
