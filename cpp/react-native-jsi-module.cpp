#include <thread>
#include <chrono>
#include <iostream>
#include "react-native-jsi-module.h"
#include <jsi/jsi.h>

using namespace facebook::jsi;
using namespace std::chrono_literals;
using namespace std;

namespace example {
    void install(Runtime &jsiRuntime) {
        auto testThread = Function::createFromHostFunction(jsiRuntime,
                                                           PropNameID::forAscii(jsiRuntime,
                                                                                "testThread"), 1,
                                                           [](Runtime &runtime,
                                                              const Value &thisValue,
                                                              const Value *arguments,
                                                              size_t count) -> Value {

                                                               auto promise = runtime.global().getPropertyAsFunction(
                                                                       runtime,
                                                                       "Promise").callAsConstructor(
                                                                       runtime,
                                                                       Function::createFromHostFunction(
                                                                               runtime,
                                                                               PropNameID::forAscii(
                                                                                       runtime,
                                                                                       "executor"),
                                                                               2,
                                                                               [](Runtime &runtime,
                                                                                  const Value &thisValue,
                                                                                  const Value *args,
                                                                                  size_t) -> Value {

                                                                                   thread t1(
                                                                                           [&runtime, resolve{
                                                                                                   std::make_shared<Value>(
                                                                                                           runtime,
                                                                                                           args[0])}] {


                                                                                               this_thread::sleep_for(
                                                                                                       5s);
                                                                                               resolve->asObject(
                                                                                                       runtime).asFunction(
                                                                                                       runtime).call(
                                                                                                       runtime,
                                                                                                       42);
                                                                                           });

                                                                                   t1.detach();


                                                                                   return {};
                                                                               })
                                                               );


                                                               return promise;
                                                           });

        auto helloWorld = Function::createFromHostFunction(jsiRuntime,
                                                           PropNameID::forAscii(jsiRuntime,
                                                                                "helloWorld"), 0,
                                                           [](Runtime &runtime,
                                                              const Value &thisValue,
                                                              const Value *arguments,
                                                              size_t count) -> Value {
                                                               string helloworld = "helloworld";
                                                               return Value(runtime,
                                                                            String::createFromUtf8(
                                                                                    runtime,
                                                                                    helloworld));
                                                           });


        jsiRuntime.global().setProperty(jsiRuntime, "testThread", move(testThread));
        jsiRuntime.global().setProperty(jsiRuntime, "helloWorld", move(helloWorld));
    }
}

