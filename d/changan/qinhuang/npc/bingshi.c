#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc.c"


void set_from_me(object me);
void create()
{
        string *names = ({ "��ٸ��ʿ" }); 
        
        ::create();
        set_name( names[random(sizeof(names))], ({ "bing shi"}) );
        set("long", @LONG
����һ����˯�ڻ���ǧ����ٸ��ʿ�����������࣬���������ƶ��ɣ�������ʮ�ּ�
Ӳ�����ֳ�һ����ͭ��ì��������Ϊ���䡣�ڻ�����Ϣ�������£�������֫���Ի��
���ؽ���Ҳ��ģ���������ܹ鲻��ǳ���
LONG);
        set("title", YEL "���껤��" NOR); 
 
        set("str", 50);
        set("con", 50);
        set("dex", 50); 
        set("int", 50);
        set("max_qi", 10000);
        set("max_jing", 15000);
        set("neili", 150000);
        set("max_neili", 150000);
        set("max_jingli", 10000);
        set("attitude", "peaceful");

        set("combat_exp", 2000000);
        set("death_msg",YEL"\n$N������һ�ѻ�����\n\n"NOR);

        set("bonus", 5000);
        set_temp("apply/attack", 1000);
        set_temp("apply/parry", 1000);
        set_temp("apply/damage", 500);
        set_temp("apply/unarmed_damage", 500);
        set_temp("apply/armor", 1000);          
        setup();
initlvl(220+random(70));        
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
 
