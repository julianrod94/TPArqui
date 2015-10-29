static void* syscalls[]{uint64_t(*readLineSyscall)(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6)
};


uint64_t syscallHandler(uint64_t syscallId, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6){
	return syscalls[syscallId](syscallId, arg1, arg2, arg3, arg4, arg5, arg6);
}

uint64_t readLineWrapper(uint64_t syscallId, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6){
	return 
}