// eyu.c ����
// By River 99.5.25
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "e yu", "e", "yu" }));
        set("race", "Ұ��");
        set("age", 200);
        set("long", "һ���Ӵ��ޱ����㣬�����������װ����Ƭ��\n");
        set("str", 70);
        set("con", 50);
        set("max_qi", 30000);
         set("max_jing", 30000);
          set("max_neili", 30000);
        set("limbs", ({ "ͷ��", "����", "β��", "���"}) );
        set("verbs", ({ "bite" }));
        set("combat_exp", 3000000);

        set_temp("apply/dodge", 100);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
        setup();
}

void init()
{
    object ob;
    ::init();
    if (interactive(ob = this_player())){
           tell_object(ob,HIR"����һ�����ˮ�и��������ſ�Ѫ���ڣ��������˹�����\n"NOR);
           remove_call_out("kill_ob");
           call_out("kill_ob", 1, ob); 
          }
}

void die()
{        
        message_vision("\n����һ��������һ����һ�������Ԩ�С�\n", this_object());
        destruct(this_object());
}

void unconcious()
{
        message_vision("\n����һ��������һ����һ�������Ԩ�С�\n", this_object());
        destruct(this_object());
}