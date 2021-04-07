inherit F_CLEAN_UP;
#include <ansi.h>

int help();

nosave mapping gift_desc = ([
"kar":"��Ե",
"per":"��ò",
"str":"����",
"con":"����",
"dex":"��",
"int":"����"
]);

nosave string *gift = keys(gift_desc);

string check(object me)
{
string msg;

if (me->is_ghost())
msg = HIY"ϵͳ��ʾ��"NOR"��Ǹ�����״̬���ȶ��������޷��޸����ԡ�\n";
return msg;
}


int main(object me, string arg)
{
string msg, from, to;
int exp, num, newexp, tmpexp;

if (!me) return 0;
if (!arg) return help();

if ( stringp(msg = check(me)) )
return notify_fail(msg);
if (me->query("cgiftok",1)>3)
return notify_fail("���ֻ���޸������츳!\n");

if (sscanf(arg, "%d %s to %s", num, from, to) == 3){
if (member_array(from, gift) < 0)
return notify_fail("��Ҫ�۳�ʲô�츳��\n");
if (member_array(to, gift) < 0)
return notify_fail("��Ҫ����ʲô�츳��\n");

if (num>20 )
return notify_fail("���һ�£��������Բ��ܳ���20�㡣\n");

if (from == to || num<0 )
return notify_fail("���һ�£�������󣬿����ۻ���\n");
if (me->query(from) <= 10)
return notify_fail("���"+gift_desc[from]+"�����ټ����ˡ�\n");
if ( ((int)me->query(from) - num) < 10)
return notify_fail("���"+gift_desc[from]+"����"+num+"�������10�㣬�����޸ġ�\n");
if (me->query(to) >= 30 )
return notify_fail("���"+gift_desc[to]+"�Ѿ�����30�㣬�����������ˡ�\n");
if ( ((int)me->query(to) + num) > 30)
return notify_fail("���"+gift_desc[to]+"����"+num+"��󽫳���30�㣬�����޸ġ�\n");
if ( num > 120 )
return notify_fail("�������ֵ����������������Ժϡ�\n");
}
write(HIR"������������������,������������ȡ��������\n"NOR);
write(HIR"�����������ȷ�ϣ�\n"NOR);
input_to("confirm_passwd", me, from, to, num);
return 1;
}

private void confirm_passwd(string pass, object me, string from, string to, int num)
{
me->start_busy(1);

me->add(from, -num);
me->add(to, num);

write("�㽫"+num+"��"+gift_desc[from]+"������"+gift_desc[to]+"�ϡ�\n", me);
me->add("cgiftok",1);
me->setup();
me->save();
return;
}

int help()
{
write("��ָ�������޸��������ԡ�\n");
write(HIR"������������������,������������ȡ��������\n"NOR);
write("���磺��Ҫ��һ�������ӵ������ϣ�������ã�"HIG" cgift 1 str to int "NOR"\n");
write("�����������Դ�������:����:str,����:con,��:dex,����:int,��Ե:kar,��ò:per,\n");
write("������ʹ�á�\n");
return 1;
}
