Gem::Specification.new do |s|
  s.name    = "native_bsearch"
  s.version = "0.0.1"
  s.summary = "Native (C) binary search extension for arrays in Ruby"
  s.author  = "Jake Christensen"
  
  s.files = Dir.glob("ext/**/*.{c,rb}") +
            Dir.glob("lib/**/*.rb")
  
  s.extensions << "ext/native_bsearch/extconf.rb"
  
  s.add_development_dependency "rake-compiler"
end
