
[![Build Status](https://travis-ci.org/google/fruit.svg?branch=master)](https://travis-ci.org/google/fruit)
[![Coverity Scan Status](https://scan.coverity.com/projects/8486/badge.svg)](https://scan.coverity.com/projects/google-fruit)

Fruit is a [dependency injection](http://en.wikipedia.org/wiki/Dependency_injection) framework for C++, loosely inspired by the Guice framework for Java. It uses C++ metaprogramming together with some new C++11 features to detect most injection problems at compile-time.
It allows to split the implementation code in "components" (aka modules) that can be assembled to form other components.
From a component with no requirements it's then possible to create an injector, that provides an instance of the interfaces exposed by the component.

See the [wiki](https://github.com/google/fruit/wiki) for more information, including installation instructions, tutorials and reference documentation.

This fork contains edited `CMakeLists.txt` and `configuration/CMakeLists.txt`. These changes may prevent fruit
from being installed as described in [wiki](https://github.com/google/fruit/wiki), but allows fruit to be used from within a subdirectory.
Example:

    CMakeLists.txt
    vendor/
    |- fruit/
       |- configuration/
          |- CMakeLists.txt # changed
          |- ...
       |- CMakeLists.txt # changed
       |- ...

The top-level `CMakeLists.txt` contains:

    add_subdirectory(vendor/fruit)
    # ...

    add_executable(main main.cpp)
    target_link_libraries(main fruit) # link fruit
