#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc.c"

void create()
{
        string *names = ({ "��ٸ���˳�" }); 
        
        ::create();
        set_name( names[random(sizeof(names))], ({ "bai renzhang" }));
        set("long", @LONG
����һ����˯�ڻ���ǧ����ٸ���˳�������������࣬���������ƶ��ɣ�������ʮ��
��Ӳ�����ֳ�һ����ͭ��ǹ��������Ϊ���䡣�ڻ�����Ϣ�������£�������֫���Ի�
�������ؽ���Ҳ��ģ���������ܹ鲻��ǳ���
LONG);
        set("title", YEL "������Ʒ����" NOR); 
 
        set("str", 50);
        set("con", 50);
        set("dex", 50); 
        set("int", 50);
        set("max_qi", 10000);
        set("max_jing", 10000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("max_jingli", 10000);
        set("attitude", "killer");

        set("combat_exp", 6000000);
        set("death_msg",YEL"\n$N������һ�ѻ�����\n\n"NOR);

        set("bonus", 8000);
        set_temp("apply/attack", 3000);
        set_temp("apply/parry", 3000);
        set_temp("apply/damage", 2000);
        set_temp("apply/unarmed_damage", 2000);
        set_temp("apply/armor", 3000);          
        setup();
initlvl(220+random(170));     
}

void init()
{
        object me;

        ::init();
        if (! interactive(me = this_player()) || 
            this_object()->is_fighting())
                return;
                

        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}
 
