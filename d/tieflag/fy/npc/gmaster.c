 // teacher.c
//Modified by justdoit 04/11/2001 
inherit NPC;
#include <ansi.h> 
int test_dart();
void create_level(object who,string name, int exp); 
void create()
{
    set_name("����", ({ "meng", "zha meng" }) );
    set("nickname", HIY "��ʨ��"NOR);
    set("gender", "����" );
    set("age", 32);
    set("skill_public",1);
    set("reward_npc", 1);
    set("difficulty", 4);
    
    set("neili",500);
    set("force_factor",20);
    set("max_neili",500);
    
    set("inquiry",      ([
        "mission" : (: test_dart :),
        "����" : (: test_dart :),
       ]));
    set("int", 30);
    create_family("����", 21, "�׼ҵ���");
    set("long",
        "��ʨ�Ʋ����������׼ҵ��ӣ��˲��������ˬ���ҹ㽻���ѣ�
������������̵ģ�ֻҪΪ�ھֳ����������ͿϽ̣�\n"
        );
    set("chat_chance", 2);
    set("chat_msg", ({
        "����˵����������ھ����ⲻ��\n",
            "����˵�������ڣ�����������£�������\n",
            }) );
    set("attitude", "peaceful");
                switch (random(3)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",30);
                   break;
                default: set("resistance/kee",30);
                }
    
    set_skill("unarmed", 150);
        set_skill("xianglong-zhang",250);
        set_skill("dodge", 150);
        set_skill("move",200);
        set_skill("parry",150);
        set_skill("wuxing-dun",150);
        
        map_skill("dodge","wuxing-dun");
        map_skill("unarmed","xianglong-zhang");
        
    
    set("combat_exp", 3500000);
    setup();
    carry_object(__DIR__"obj/jinzhuang")->wear();
} 
