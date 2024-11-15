# disk_operations.rb
require 'ffi'

module DiskOperations
  extend FFI::Library
  ffi_lib './libdisk_operations.so'

  attach_function :write_to_disk, [:string, :size_t, :int], :void
  attach_function :read_from_disk, [:pointer, :size_t, :int], :void
end

# Example usage
data_to_write = "Hello, Disk!"
DiskOperations.write_to_disk(data_to_write, data_to_write.length, 0)

buffer = FFI::MemoryPointer.new(:char, 512)
DiskOperations.read_from_disk(buffer, 512, 0)
puts buffer.read_string(512).strip