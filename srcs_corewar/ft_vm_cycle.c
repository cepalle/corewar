/* FT_VM_CYCLE

	for process in vm.process:
		ft_process_exec(vm, player.num, process.num)

 */

/* FT_PROCESS_EXEC (t_vm *vm, int num_player, int num_process)

	if not cmd_save.cmd
 		if (!init cmd data in process init_cmd_save(*vm, *proc))
 		{
 			proc.PC++;
 			return;
 		}

 	proc.cycle_wating--;
	if proc.cycle_wating <= 0
 		proc.cmd(t_vm *vm, t_proc *proc)

 */


