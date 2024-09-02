#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint lab_sound_flutter.podspec` to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'lab_sound_flutter'
  s.version          = '0.0.10'
  s.summary          = 'Access to LabSound lib from Flutter.'
  s.description      = <<-DESC
Plugin allowing a Flutter APP to use the LabSound lib.
The LabSound lib is a "Free Style" implementation of the W3C Web Audio API.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'canardoux.xyz' => 'larpoux@gmail.com' }

  # This will ensure the source files in Classes/ are included in the native
  # builds of apps using this FFI plugin. Podspec does not support relative
  # paths, so Classes contains a forwarder C file that relatively imports
  # `../src/*` so that the C sources can be shared among all target platforms.
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.public_header_files = 'Classes/**/*.h'
  s.dependency 'Flutter'
  s.platform = :ios, '12.0'

  # Flutter.framework does not contain a i386 slice.
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.swift_version = '5.0'
  s.dependency 'lab_sound_bridge', '0.0.10'
  s.library = 'c++'

end
