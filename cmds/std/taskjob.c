// who2.c

inherit F_CLEAN_UP;
string  zuji(string str);
#include <ansi.h>
int main(object me, string str)
{
    object where, ob, *ob_list;
    int i,j;
    string stri;
    string *dir2;
    string room;
//    object me;
    seteuid(getuid());
    me=this_player();
    if (me->is_busy()) 
    return notify_fail("����Ъ������˵���ɡ�\n");
   str = sprintf(HIR"--------�������Ű�--------\n"NOR);
if (me->query_temp("nhdjob2lb"))
{
    str += sprintf(HIR"�������:%s��"NOR, me->query_temp("nhdjob2sc"));
}

    str +=read_file("/log/taskjob");
    me->start_more(str);
    me->start_busy(1);
    return 1;
}
int sort_user(object ob1, object ob2)
{
	//if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	//if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	//if( wizardp(ob1) && wizardp(ob2) )
	//	return (int)SECURITY_D->get_wiz_level(ob2) 
	//		- (int)SECURITY_D->get_wiz_level(ob1);
	//
	//return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}
int help(object me)
{
        write(@HELP
ָ���ʽ��taskjob

��ѯ��ǰ�������
HELP
        );
        return 1;
}

