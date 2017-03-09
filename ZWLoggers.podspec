#
#  Be sure to run `pod spec lint ZWLoggers.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

spec.name         = 'ZWLoggers'
spec.summary      = 'A short description of ZWLoggers.'
spec.version      = '0.0.1'
spec.license      =  { :type => 'MIT', :file => 'LICENSE' }
spec.authors      = { 'gavin' => 'lovegavin@outlook.com' }
spec.homepage     = 'https://github.com/ZWLoggers/ZWLoggers'

spec.ios.deployment_target = '8.0'

spec.source       = { :git => 'https://github.com/GavinZw/ZWLoggers.git', :tag => spec.version }

spec.requires_arc          = true
spec.source_files = 'ZWLoggers/ZWLoggers/*.{h,m}'
spec.public_header_files = 'ZWLoggers/ZWLoggers/*.{h}'

spec.frameworks = 'Foundation'
spec.dependency "CocoaLumberjack"

end
