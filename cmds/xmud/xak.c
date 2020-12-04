// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
#include <ansi.h>
inherit F_CLEAN_UP;
string query_inquiry(object me, object ob);
string *msg_dunno = ({
	"$nҡҡͷ��˵����û��˵����\n",
	"$n�����۾�����$N����Ȼ��֪��$P��˵ʲô��\n",
	"$n�����ʼ磬�ܱ�Ǹ��˵���޿ɷ�档\n",
	"$n˵������....���ҿɲ��������������ʱ��˰ɡ�\n",
	"����Ȼ��$n��������ش�$P�����⡣\n",
	"$n����һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n",
	"$n�����۾�����$N����ô�򵥵�����ҲҪ����\n",
});
int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;
	seteuid(getuid());
	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲô�£�\n");
	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("����û������ˡ�\n");
	if( !ob->is_character() ) {
		message_vision("$N����$n��������....\n", me, ob);
		return 1;
	}
	if( !ob->query("can_speak") ) {
		message_vision("$N��$n�����йء�" + topic + "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
		return 1;
	}
	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);
	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n",
			me, ob);
		return 1;
	}
	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
			return 1;
		}
	} else
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
	return 1;
}
// �� npc ���϶�ȡ inquiry
string query_inquiry(object me, object ob)
{
        int i = 0;
        mapping inq;
        string str = "", *indexs;
        
        if (mapp(inq = ob->query("inquiry")))
        {
                indexs = keys(inq);
                for (i = 0; i < sizeof(indexs); i++)
                {
                        str = indexs[i] + " " + str;
                }
                str = "�й���\n   " HIB + str + NOR"\n��Щ���飬������֪���Ļ��������ң�";    
                tell_room(environment(me), CYN + ob->name() + "��" + me->name() + "����С����˵��Щ����\n" NOR, ({ me, ob }));
                tell_object( me, GRN + ob->name() + "����Ķ�������˵����" + str + "\n" NOR);
                return "\n";
        }
        tell_object( me, ob->name(1) + "����˵����ʵ���ǶԲ�����ʲôҲ��֪��ѽ��\n");
        return "\n";
}
int help(object me)
{
   write( @HELP
ָ���ʽ: ask <someone> about <something>
���ָ���ڽ���ʱ����Ҫ, ͨ��������ɴ�һָ�����
��ý�һ������Ѷ��
HELP
   );
   return 1;
}
