#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("����", ({ "moon spirit","spirit" }) );
        set("nickname",HIC"�¹���ˮ"NOR);
        set("title","����ɽׯ   ��С��");
        set("gender", "Ů��");
        set("quality","good");
        set("reward_npc", 1);
       set("difficulty", 2);
        set("age",19);
        set("combat_exp", 25300000);
         set("long",
"��ɫˮ���䣬�·��в㵭�����������������·���һ����������Ӱ���ƿ���
���֣��¹�̸������������ǡ�������������ϡ��԰׵Ĺɣ��԰����¡�\n"
        );
        set("max_neili",50000);
        set("neili",50000);
        set("force_factor",900);
                set("max_jing",33000);
                set("max_jing",33000);
                set("con",40);
                set("int",27);
                set("str",25);
                set("cor",80);
                set("agi",40);
                set("per",100);
        set_skill("move",150);
        set_skill("parry", 300);
        set_skill("blade",300);
        set_skill("dodge",150);
          
        setup();
        set_temp("shield_force/type","force");
        set_temp("shield_force/ratio",10000);
        set_temp("shield_force/msg",
                CYN"$n���ϵĹ⻪������$N�Ĺ��ơ�\n"NOR);
        set("revival",1);
} 
