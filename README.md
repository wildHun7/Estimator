# Estimator

A desktop application for estimating project costs by managing sections and items with associated costs and quantities.

## Features

- CRUD operations to manage **sections** and **items** 
- **SQLite** – manually save and load data
- **Qt 6 GUI** – Responsive and intuitive Desktop User Interface.

## Tech Stack

- **C++20** 
- **Qt 6.x** (Widgets, SQL)
- **SQLite** via Qt SQL module
- **CMake 3.16** build system

## Project Structure

```
Estimator/
├── db/
│   ├── database_handler.h
│   └── database_handler.cpp      # SQLite CRUD operations
├── gui/
│   ├── mainwindow.h/cpp/ui       # Main application window
│   ├── section_table_model.h
│   └── section_table_model.cpp   # Qt table model (MVC)
├── items/
│   ├── item.h/cpp                # Abstract base class
│   ├── item_type1.h/cpp          # Labor cost item
│   └── item_type2.h/cpp          # (planned)
├── manager/
│   ├── section_manager.h
│   └── section_manager.cpp       # Business logic + DB integration
└── sections/
    ├── section.h/cpp             # Abstract base class
    ├── section_type1.h/cpp       # Labor section
    └── section_type2.h/cpp       # (planned)
```

## Planned

in progress
