#
#  Be sure to run `pod spec lint ZWLoggers.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

spec.name         = 'ZWLoggers'
spec.summary      = 'A log component.'
spec.version      = '1.0.0'
spec.license      =  { :type => 'MIT', :file => 'LICENSE' }
spec.authors      = { 'gavin' => 'lovegavin@outlook.com' }
spec.homepage     = 'https://github.com/GavinZw/ZWLoggers'

spec.ios.deployment_target = '8.0'

spec.source       = { :git => 'https://github.com/GavinZw/ZWLoggers.git', :tag => spec.version }

spec.requires_arc          = true
spec.source_files = 'ZWLoggers/*.{h,m}'
spec.public_header_files = 'ZWLoggers/*.{h}'

spec.dependency  'CocoaLumberjack/Default'

end
