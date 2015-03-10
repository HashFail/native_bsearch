Gem::Specification.new do |s|
  s.name    = "native_bsearch"
  s.version = "0.0.3"
  s.summary = "Native (C) binary search extension for arrays in Ruby"
  s.author  = "Jake Christensen"
  s.email = "jakec43@gmail.com"
  s.licenses = ['MIT']
  s.description = "A C implementation of the binary search algorithm for Ruby arrays."
  s.homepage = "https://github.com/HashFail/native_bsearch"
  
  s.files = Dir.glob("ext/**/*.{c,rb}") +
            Dir.glob("lib/**/*.rb")
  
  s.extensions << "ext/native_bsearch/extconf.rb"
  
  s.add_development_dependency "rake-compiler", "~> 0"
end
