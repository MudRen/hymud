// who2.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
    object where, ob, *ob_list;
    int i,sex;
    string stri;
    seteuid(getuid());
/*
    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str = HIG" ���     ID       �ȼ�      ���ɹ���   ���ӷ�����     ����ɱ����              ����       \n"NOR;
    str += "��������������������������������������������������������������������������\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        where = environment(ob);

        str += sprintf(WHT"%-8s:  ",ob->name());
        str += sprintf(HIG"%-10s ", ob->query("id"));
        str += sprintf(HIG"%-10d ", ob->query("levels"));
        str += sprintf(HIG"%-10d ", ob->query("mpgx"));
        str += sprintf(HIR"%-10d ", ob->query_temp("apply/armor"));
        str += sprintf(HIY"%-10d ", ob->query_temp("apply/damage"));

    if (where) str += sprintf(HIM"%-10s ", where->query("short"));
    if (!where) str += sprintf("\n"NOR);
       else str += sprintf(HIC"%s\n"NOR, file_name(where));
    }
    str += "��������������������������������������������������������������������������\n";
    str = sprintf("%s���� %d λʹ���������С�\n", str, sizeof(ob_list));*/


    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str = HIG" ���     ID       �ȼ�      ���ɹ���   ���ӷ�����     ����ɱ����              ����       \n"NOR;
    str += "��������������������������������������������������������������������������\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
    	sex=0;
    	if (ob->query("gender")=="Ů��") sex=1;

        str +="(['id':";
        str += "'"+ob->query("id")+"',";
        str +="'title':";
        str += "'"+ob->query("title")+"',";
        str +="'name':";
        str += "'"+ob->query("name")+"',";
        str +="'sex':";
        str += sex+",";
        str+="]),\n";

    }
    str += "��������������������������������������������������������������������������\n";
    str = sprintf("%s���� %d λʹ���������С�\n", str, sizeof(ob_list));
    me->start_more(str);
    return 1;
}
int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}
int help(object me)
{
        write(@HELP
ָ���ʽ��who2

�����Ϣ��ѯ��
HELP
        );
        return 1;
}