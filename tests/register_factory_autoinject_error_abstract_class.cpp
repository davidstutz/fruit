// expect-compile-error NoBindingFoundForAbstractClassError<Scaler>|No explicit binding was found for C, and C is an abstract class
/*
 * Copyright 2014 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <fruit/fruit.h>
#include "test_macros.h"
#include <iostream>

using fruit::Component;
using fruit::Injector;
using fruit::Assisted;
using fruit::createComponent;

struct Annotation {};

struct X {};

class Scaler {
private:
  double factor;
  
public:
  Scaler(double factor, X)
    : factor(factor) {
  }
  
  virtual double scale(double x) = 0;
};

using ScalerFactory = std::function<std::unique_ptr<Scaler>(double)>;

Component<ScalerFactory> getScalerComponent() {
  return createComponent();
}
