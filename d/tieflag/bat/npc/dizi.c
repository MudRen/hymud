 // dizi.c
#include <ansi.h> 
inherit NPC;
void create()
{ 
        set_name("���𵺵���", ({ "dizi"}) );
        set("long", "����һλ����ר�ŵ��α���֮��ĵ��ӡ�\n");
        set("attitude", "friendly"); 
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100); 
//      set("str", 30);
        set("cor", 30);
        set("cps", 25); 
        set("combat_exp", 300000+random(400000));
        set_skill("sword", 70+random(70));
        set_skill("parry", 70+random(70));
        set_skill("dodge", 70+random(70));
        set_skill("dodge", 70+random(70)); 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
} 
void init()
{
 if( interactive(this_player()) && !is_fighting() && !random(4)&& this_player()->query("class")!="bat") {
  message_vision("\n$N��Ȼ��$n���һ����ʲô�˾����ڴ��Ҵ���������\n",this_object(),this_player());
  this_object()->kill_ob(this_player());
 }
}       
