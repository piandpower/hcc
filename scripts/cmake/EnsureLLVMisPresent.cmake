macro(ensure_llvm_is_present dest_dir name)

if(EXISTS "${dest_dir}/${name}")
    MESSAGE("LLVM already exists.")
else(EXISTS "${dest_dir}/${name}")
    Find_Package(Git)
    MESSAGE("Downloading LLVM ToT")
    execute_process( COMMAND git clone http://llvm.org/git/llvm.git ${dest_dir}/${name} )
    MESSAGE("Downloading LLD ToT")
    execute_process( COMMAND git clone http://llvm.org/git/lld.git ${dest_dir}/${name}/tools/lld )
endif()
endmacro()
