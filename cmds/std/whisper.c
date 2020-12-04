// whisper.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg,mname,oname;
	object ob,*newob;

	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("��Ҫ��˭����Щʲô��\n");

	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("��Ҫ��˭���\n");

	if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");
	if(ob == me) return notify_fail("�����Լ���\n");
	if (!interactive(ob)) return notify_fail("����˶����ˡ�\n");
	if (!living(ob)) return notify_fail("����������޷�������Ļ���\n");

        if ( ((int)time() - (int)me->query("tell_time")) < 1 )
        return notify_fail("�л��ú�˵Ŷ��\n");

                if (
                    me->query_temp("big5")) 
                        arg = arg+"("+LANGUAGE_D->Big52GB(arg)+")"; 

mname=me->name();
if (me->query_temp("big5") && userp(me) && mname!="" ) mname=mname+"("+LANGUAGE_D->Big52GB(mname)+")"; 
oname=ob->name();
if (ob->query_temp("big5") && userp(ob) && oname!="" ) oname=oname+"("+LANGUAGE_D->Big52GB(oname)+")"; 


	write( GRN "����" + oname + "�Ķ�������˵����" + msg + "\n" NOR);
	tell_room( environment(me), mname + "��" + oname
		+ "����С����˵��Щ����\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, GRN + mname + "����Ķ�������˵����" + msg + "\n" NOR);
                     me->set("tell_time", time());
        newob = filter_array(children(USER_OB),(: userp($1) && wizardp($1) :));
if (!wizardp(me) && query_ip_name(ob)!=query_ip_name(me))
{
message("channel:snp", HIB"��������"+mname+"����"+oname+"��"+msg+"\n"NOR, newob);
}

	return 1;
}

int help(object me)
{
	write( @TEXT
ָ���ʽ��whisper <ĳ��> <ѶϢ>

���ָ�����������ͬһ�����е��˶������ NPC ���ڡ�
TEXT
	);
	return 1;
}