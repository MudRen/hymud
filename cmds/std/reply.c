// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud,mname,oname;
	object obj;
        object *ob;        

	if( !arg || arg=="" )
		return notify_fail("��Ҫ�ش�ʲô��\n");
	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("�ղ�û���˺���˵������\n");

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj )
		return notify_fail("�ղź���˵�����������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");
	if (!wizardp(me) && obj->query("env/no_tell")=="all")
		return notify_fail("����˲���������������\n");
	if (!wizardp(me) && obj->query("env/no_tell")=="ALL")
		return notify_fail("����˲���������������\n");
	if (!wizardp(me) && obj->query("env/no_tell")==me->query("id"))
		return notify_fail("����˲���������������\n");

mname=me->name(1);
if (me->query_temp("big5") && userp(me) && mname!="" ) mname=mname+"("+LANGUAGE_D->Big52GB(mname)+")"; 
oname=obj->name(1);
if (obj->query_temp("big5") && userp(obj) && oname!="" ) oname=oname+"("+LANGUAGE_D->Big52GB(oname)+")"; 

                if (
                    me->query_temp("big5")) 
                        arg = arg+"("+LANGUAGE_D->Big52GB(arg)+")"; 

        write(HIG "��ش�" + oname + "��" + arg + "\n" NOR);


        tell_object(obj, sprintf(HIG"%s�ش��㣺%s\n"NOR,
		mname+"("+me->query("id")+")", arg));
        ob = filter_array(children(USER_OB),(: userp($1) && wizardp($1) :));
if (!wizardp(me))
{
message("channel:snp", HIB"��������"+me->query("name")+"�ش�"+obj->query("name")+"��"+arg+"\n"NOR, ob);
}
	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��reply <ѶϢ>

����������ָ��͸ղ��� tell ����˵����ʹ����˵����

see also : tell
HELP
	);
	return 1;
}
