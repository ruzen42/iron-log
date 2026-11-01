project('iron', 'c', 
  version : '2.0.0', 
  default_options: [
    'c_std=c11', 
    'warning_level=2', 
    'optimization=s'
    ]
)
cc = meson.get_compiler('c')

add_project_arguments('-D_POSIX_C_SOURCE=200809L', language: 'c')

lib = static_library('iron', ['src/logger.c', 'src/util.c'],
  include_directories: include_directories('include'),
  install: true)
install_headers('include/iron/logger.h', subdir: 'iron')
