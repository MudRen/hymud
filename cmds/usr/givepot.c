// nick.c
// by jackyboy @ cctx 98/12/12
#include <ansi.h>

inherit F_CLEAN_UP;
string replace_color(string,int);
int help(object);
int wiz_set(string,string,string,int);

int main(object me, string arg)
{
	string dest;
	int pot;
	object obj;
	if( !arg ) return help(me);	

	if(sscanf(arg,"%d %s",pot,dest)!=2)
         return help(me);	

    if (1==1)
return notify_fail("�������Ѿ�ͣ�ã�\n");
	
	//return notify_fail("����û��"+pot+"���"+dest+"��\n");
	
 if(!objectp(obj = present(dest, environment(me))))
        return notify_fail("����û�����"+dest+"��\n");
 
 if (!userp(obj))	return notify_fail("����û�������ҡ�\n");
 if (!userp(me))	return notify_fail("����û�������ҡ�\n");

if (pot<30)	return notify_fail("������Ҫ30��Ǳ�ܣ�\n");

//    if ( me->query("zhuanshen"))
//return notify_fail("ת��������ת����\n");



	//if (me->query("jing")*10 < pot )	return notify_fail("��ľ���״̬������ת����ô��Ǳ�ܣ�\n");

    if( ((int)me->query("potential")-(int)me->query("learned_points")) >= pot ){
		//me->add("jing",-pot/10);
		me->add("potential",-pot);
		obj->add("potential",pot/10);
       	write("OK!\n");
	} else 	return notify_fail("��û����ô��Ǳ����ת�ƣ�\n");
	
	
	message_vision("$N����"+pot/10+"��Ǳ�ܸ�$n ��\n", me,obj);
	write("ת���ɹ�.\n");
	return 1;
}




int help(object me)
{
	write(@HELP
ָ���ʽ :givepot <Ǳ�ܵ�> <���ID>

      ��Ǳ���͸����ˡ�10��Ǳ��ת��1������
see also : hp
HELP
	);
	return 1;
}
