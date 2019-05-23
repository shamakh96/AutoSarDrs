# AutoSarDrs
Avr Modular Drivers

This folder is intended to contain some of AVR periphrals drivers, written in modular convention as possible.

a 2 configuration files will be exist in every driver, the cfg.h file is the static configuration, which the configurations
that are not likely to be changed during the project lifetime, the other PBcfg.c is the not-so-static configuration, which is 
the configurations that don't need to rebuild everything to have effect.
