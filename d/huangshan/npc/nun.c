 inherit NPC;
#include <ansi.h> 
void create()
{
    object armor;
    set_name( "С���" , ({ "ni gu" }) );
    set("gender", "Ů��");
    set("title", "�ɹ���");
    set("nickname", HIC"��������"NOR);
    set("age", 18);
    set("per",45);
    set("long", "һ��С������ļ������,ò���绨.\n");
    set("combat_exp", 2300000);
    set("score", 200);
    set("class", "huangshan"); 
    set("resistance/kee",30);
    set("no_busy",4);
    set("fly_target",1);
    set("int", 30);
    set("cor", 30);
    set("cps", 30);
    set("spi", 30); 
    set("neili", 1000);
    set("max_neili", 1000);
    set("force_factor", 30);
    set("atman", 1000);
    set("max_atman", 1000);
    set("mana", 500);
    set("max_mana", 500);
    set("mana_factor", 5); 
    set_skill("force", 180);
    set_skill("move", 100);
    set_skill("unarmed", 150);
    set_skill("parry", 140);
    set_skill("dodge", 150);
    set_skill("liuquan-steps", 120);
        
    map_skill("dodge", "liuquan-steps"); 
    setup();
    armor=new("/clone/misc/cloth");
        armor->set_name(WHT"��ɫ������"NOR,({"cloth"}) );
        armor->move(this_object());
        armor->wear(); 
}         
