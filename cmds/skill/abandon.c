// abandon.c

#include <ansi.h>
inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	string skill;
        int level, lvl = 0;
	object sk;

	
        if( !arg ) return notify_fail("ָ���ʽ��abandon|fangqi <��������> [����]\n");

        sscanf(arg, "%s %d", arg, lvl);
          
        level = me->query_skill(arg, 1);

        if (!intp(lvl) || lvl < 0) 
                return notify_fail("��������Ϊ������\n");
                
if (arg=="magic-dark")
                return notify_fail("������ܲ��ܷ�����\n");
if (arg=="magic-light")
                return notify_fail("������ܲ��ܷ�����\n");
if (arg=="biguan")
                return notify_fail("������ܲ��ܷ�����\n");

	if( !me->query_skill(arg, 1) )
		return notify_fail("�㲻�����ּ��ܡ�\n");
if
(	(int)me->query_temp("apply/attack",1) > 200
	|| (int)me->query_temp("apply/armor",1) >8500
	|| (int)me->query_temp("apply/dexerity",1) >200
        || (int)me->query_temp("apply/strength",1)>200
        || (int)me->query_temp("apply/dodge",1)>200
        || (int)me->query_temp("apply/damage",1)>8500
        || (int)me->query_temp("apply/intelligence",1)>200
        || (int)me->query_temp("apply/constitution",1)>200)

return notify_fail("������ʹ��ĳЩ�������书����������״̬�·����书!\n");
        if( (int)me->query_temp("powerupxtg") ) 
        return notify_fail("���Ѿ���������ˣ���������״̬�·����书!\n");
        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("��������̫�����ˣ���������״̬�·����书!\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("�������˿����޵й��ˣ���������״̬�·����书!\n");
        if(me->query_temp("wdpowerup") )
        return notify_fail("����������ʹ�á��嶾�񹦡��ľ�������������״̬�·����书!\n"); 
        if(me->query_temp("zhuihun/lpf")) 
        return notify_fail("������ʹ���嶾׷�깳֮�������硹����������״̬�·����书!\n"); 
        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˣ���������״̬�·����书!\n");
        if( me->query_temp("qzj_tong") ) 
                return notify_fail("���Ѿ�����ͬ�齣�����ˣ���������״̬�·����书!\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ�����������״̬�·����书!\n");
        if( me->query_temp("fumo")   )
                return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ������������״̬�·����书!\n");
        if( me->query_temp("jingang")   )
                return notify_fail("������ʹ�ô���ȭ�����⹥����������ͨ������������״̬�·����书!\n");
        if( me->query_temp("fanzhen")   )  
                return notify_fail("���������á���ղ������񹦡�����������״̬�·����书!\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ�����������״̬�·����书!\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˣ���������״̬�·����书!\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ�����������״̬�·����书!\n");
       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ����������������״̬�·����书!\n"); 
        if( me->query_temp("qzjtong") ) 
                return notify_fail("���Ѿ�����ͬ�齣�������ˣ���������״̬�·����书!\n");
        if (lvl <= 0 || lvl >= level) {
                write("\nע�⣡�㽫Ҫ����ȫ�� "HIW + to_chinese(arg) + "("+arg+")"NOR" ��ȷ����[Y|N]\n>");
                input_to("delete_all", me, arg);
                } 
        else if (level < 100)
                return notify_fail("������ܻ�û�е����շ�����ĵز���\n");
        else {
                write("\nע�⣡�㽫Ҫ����" + chinese_number(lvl)+ "�� "HIW+to_chinese(arg)+"("+arg+")"NOR" ��ȷ����[Y|N]\n>");
                input_to("delete_skill", me, arg, level, lvl);
                }
        return 1;
}

private void delete_all(string arg, object me, string skill)
{

        if( arg[0]=='y' || arg[0]=='Y' ){
                me->delete_skill(skill);
                if(userp(me) && !wizardp(me))
                     log_file("ABANDON", sprintf("%s(%s)  abandoned ALL  %s  on %s\n",
                          me->name(1),me->query("id"), to_chinese(skill) , ctime(time()) ));
                write("�������"+ to_chinese(skill) +"��\n");
                }
        else write("���������"+ to_chinese(skill) +"("+skill+")��\n\n");
        
}

private void delete_skill(string arg, object me, string skill, int level, int lvl)
{
        if( arg[0]=='y' || arg[0]=='Y' ){
		me->map_skill(skill);
                me->reset_action();
                me->set_skill(skill, level - lvl);
                if(userp(me) && !wizardp(me))
                     log_file("ABANDON", sprintf("%s(%s)  abandoned  %d levels of %s  on %s\n",
                          me->name(1),me->query("id"), lvl, to_chinese(skill) , ctime(time()) ));
                write("�������" + chinese_number(lvl)+ "��"+ to_chinese(skill) +"("+skill+")��\n\n");
                }
        else write("���������"+ to_chinese(skill) +"("+skill+")��\n\n");
        
}

int help()
{
	write(@TEXT
ָ���ʽ��abandon|fangqi <��������> [����]

����һ������ѧ���ļ��ܣ�ע��������˵�ġ���������ָ������ܴ�������
��������ɾ����������Ժ�Ҫ��������ӣ���ʼ����������ؿ��������

��������ڷ�������ʱ�����뼶�𣬽�ֻ������ָ������

���ָ��ʹ�õĳ���ͨ��������ɾ��һЩ����С�ġ��������ļ��ܣ�����ÿ��
�����Ų�ͬ���츳������ϰ���书Ҳ������ͬ�����������ѧ����ͷ��ֻ����
��������
TEXT
	);
	return 1;
}
