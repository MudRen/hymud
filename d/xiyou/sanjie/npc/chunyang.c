// chunyang.c ������ʦ

#include <ansi.h>
string ask_me();

inherit NPC;
inherit F_MASTER;

void create()
{
     set_name(HIW"������ʦ"NOR, ({"master chunyang", "master"}));
       set("long", "��һ�������ˣ��İ���ǰ��һ��֮����������ħ��\n");
       set("title", HIC"��һ��"NOR);
       set("per", 40);
       set("str", 60);
       set("gender", "����");
       set("age", 40);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����ʦ");
       set("max_kee", 20000);
       set("max_gin", 100);
       set("max_sen", 20000);
       set("force", 6000);
       set("max_force", 6000);
       set("force_factor", 240);
       set("max_mana", 4000);
       set("mana", 5000);
       set("mana_factor", 300);
       set("combat_exp", 8000000);
       set("daoxing", 8000000);

     

        create_family("����ɽ", 1, "��");
        
        set("inquiry", ([
        "name"     : "�Ϸ�����һ�������ˡ�����������\n",
        "here"     : "������һ�ɸ�Ҳ���ܽ�����Ҳ���㸣��ǳ��\n",

        ]));
        
        set("time", 1);
        
        setup();
        carry_object("/d/xiyou/sanjie/obj/xuantian"); 
        carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
         carry_object("/d/xiyou/sanjie/obj/zhaoyangjian.c")->wield();
}
