#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("��������", ({ "jinnaluo" }) );
//      set("nickname",HIC"�¹���ˮ"NOR);
        set("title",RED"�˲�����֮"NOR);
        set("gender", "Ů��");
        set("age",39);
        set("combat_exp", 1200000);
         set("long",
"��ɫˮ���䣬�·��в㵭�����������������·���һ����������Ӱ���ƿ���
���֣��¹�̸������������ǡ�������������ϣ��԰����¡�\n"
        );
        set("max_neili",50000);
        set("neili",50000);
        set("force_factor",120);
        set("max_qi",50000);
        set("max_jing",50000);
        set("max_jing",50000);
                set("con",60);
                set("int",47);
                set("str",50);
                set("cor",80);
                set("agi",40);
                set("per",10);
        set_skill("move",300);
        set_skill("parry", 300);
        set_skill("blade",300);
        set_skill("dodge",300);
  
        setup();

        set_temp("shield_force/type","force");
        set_temp("shield_force/ratio",10000);
        set_temp("shield_force/msg",
                CYN"$n���ϵĹ⻪������$N�Ĺ��ơ�\n"NOR);
        set("revival",1);
} 
