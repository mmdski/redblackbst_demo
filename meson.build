project('redblackbst-demo', 'c',
    default_options : ['c_std=c99', 'c_args=-Wall', 'b_ndebug=if-release'],
    version : '0.0.0')

cc = meson.get_compiler('c')

subdir('cii')

demo_sources = ['redblackbst.c', 'chartable.c', 'demo.c']
demo = executable('demo', demo_sources, link_with : ciilib)
