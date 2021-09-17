#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint av380.podspec` to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'av380'
  s.version          = '0.0.1'
  s.summary          = 'A new flutter plugin project.'
  s.description      = <<-DESC
A new flutter plugin project.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.dependency 'Flutter'
  s.platform = :ios, '9.0'
	
	s.libraries = "c++", "z", "bz2.1.0", "icucore","iconv"

	s.vendored_frameworks = 'Framework/*.framework'
	s.vendored_libraries = 'Framework/*.a'
	s.frameworks = "CFNetwork", "CoreAudio", "CoreVideo", "OpenAL", "Metal", "CoreGraphics", "AVFoundation", "QuartzCore", "Security", "Accelerate"
	
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.swift_version = '5.0'
end
