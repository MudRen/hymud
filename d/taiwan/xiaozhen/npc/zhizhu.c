#include <ansi.h>
inherit NPC;
void chan(); 
void create()
{
        set_name(RED"��֩��"NOR, ({ "zhizhu"}));
        set("race", "Ұ��");
        set("age", 4);
        set("long",
                "һֻȫ��ѩ��Ĵ�֩��,��\n");
	set("str", 26);
	set("cor", 30);
	set("chat_chance", 40);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 5);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 5);
        setup();
}
void init()
{
    object ob;
    ::init();
    if (interactive(ob=this_player())&&!is_fighting())
         {  set_leader(ob);
message_vision("$N�������³�һ�������İ�ɫ��˿,��$n�ɾ��ȥ!\n",this_object(),ob);
    if (random(ob->query("cps"))<16)
           {  message_vision("�����$N��������,��ʱ��������!\n",ob);
              ob->start_busy(2);
              kill_ob(ob);
              return;
           }
    else
    message_vision("�����$N���ݵض��,�����ƻ���.\n",ob);
    ob->kill_ob(this_object());
    start_busy(1);

          }
}
