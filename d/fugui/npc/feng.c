#include <ansi.h>
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("������", ({ "feng qiwu", "feng" }) );
        set("nickname","��Ȯ����");
        set("long",
"��˵�еĴ����һ��͵���������ųơ�ҹ���ٻ�����Ȯ��������\n");
        set("age", 50);
        set("combat_exp", 1000000);
        set("max_jing",1000);
    set("max_qi",2000);
        set("max_jing",6000);
        set("max_neili", 1000);
        set("force", 2000);
        set("force_factor", random(100));
    set_temp("apply/armor",150);
    set_temp("apply/damage",50);
    set_temp("apply/attack",50);
        set("no_arrest",1);
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("changquan",150);
        map_skill("unarmed", "changquan");
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void die()
{
        object ob;
        object *enemy;
        ob = query_temp("last_damage_from");
        if(!ob){ 
                enemy = this_object()->query_enemy();
                ob=enemy[0];
        }
        if(userp(ob))   ob->set_temp("marks/fugui_killed_feng",1);
        ::die();
}     
