// call.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string objname, func, param, euid;
	object obj;
	mixed *args, result;
	int i;
	int num;

	if( arg ) {
		if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
			if( (string)SECURITY_D->get_status(me) != "(admin)" )
				return notify_fail("�㲻���趨�Լ��ġ�\n");
			seteuid(euid);
		}
		else
			seteuid( geteuid(this_player(1)) );

		if( sscanf(arg, "%s %d", objname, num)!=2 )
			return notify_fail("ָ���ʽ��recharge <���> <����>, ... )\n");
	} else
		return notify_fail("ָ���ʽ��recharge <���> <����>\n");

	obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
	if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me") obj = me;
	if(!obj) return notify_fail("�Ҳ���ָ���������\n");

	if(!userp(obj)) return notify_fail("ֻ�ܶ�����Ҳ�����\n");
	if( userp(obj) ){
//		if( obj != me ) log_file("static/CALL_PLAYER",
		log_file("cmds/call",
			sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
				ctime(time()) ) );
	} else if( !master()->valid_write( base_name(obj), me, "set" ) )
		return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");

	//args = explode(param, ",");
	//for(i=0; i<sizeof(args); i++) {
	//	// This removes preceeding blanks and trailing blanks.
	//	parse_command(args[i], environment(me), "%s", args[i]);
	//	if( sscanf(args[i], "%d", args[i]) ) continue;
	//	if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
	//	//args[i] = restore_variable(args[i]);
	//}

	//args = ({ func }) + args;

	//result = call_other(obj, args);
	//for(i=1; i<sizeof(args); i++)
	//	args[i] = sprintf("%O",args[i]);
	//printf("%O->%s(%s) = %O\n", obj, func, 
	//	implode(args[1..sizeof(args)-1], ", "), result);
	obj->add("hymoney",num);
        printf(obj->query("name")+"���� %d ����ҡ���\n", num);

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : recharge <���> <�������>(<��Ϊ+-ֵ>, ...... )
 

 
HELP
    );
    return 1;
}
