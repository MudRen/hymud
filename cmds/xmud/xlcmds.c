// localcmds.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *cmds;
	int i;
        string names,str,str2;
	cmds = me->query_commands();
	
	 
	
	write("$xcmds\n");
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		//if(present(cmds[i][2], me)) continue;
names=cmds[i][2]->query("name");
if (!names) names=cmds[i][2]->query("short");
//		printf("%-15s   %O\n", "("+cmds[i][0]+")", cmds[i][2]);
	write(names+"("+cmds[i][0]+")"+"\n");
	}
	write("$#\n");
str="$botten#";
str2="";
if (!environment(me)->query("roomif"))
{
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		if(present(cmds[i][2], me)) continue;
  if (str=="$botten#")
	str +=cmds[i][0];
	else str +="|"+cmds[i][0];
	}
  if (str!="$botten#")
  str +=":";
	
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		if(present(cmds[i][2], me)) continue;
  if (str2=="")
	str2 +=cmds[i][0];
	else str2 +="|"+cmds[i][0];
	}
	
str +=str2;
str +="\n$#\n";
if (str2!="") write(str);
}

	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��localcmds

�г������ϼ����ܵ���Ʒ�����ڵĻ����ṩ������ָ�
TEXT
	);
	return 1;
}

