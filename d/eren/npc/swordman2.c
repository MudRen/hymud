#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("title","���а���");
        set("long", "���а���֮�ף�������⣬����������\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 4800000);
        
        set("str",40);  
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1500);
        set("neili",1500);
        set("force_factor",110); 
        set("reward_npc", 1);
        set("difficulty", 5); 
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30); 
        set("inquiry", ([
                "������" : "������ǵ�һ���Ҵ�����˹ȵ��������ˡ�\n",
                "���˹�" : "ʮ�����ɢ��ɢ�������������˹�����̫ƽ���ˡ�\n",
        ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ƽ������������书��ߣ����������壬С����������������ĸ���
��������Ȼ���壬����������ɷ����\n",
                
        }) );

   set_name("��ƽ",({"yang ping"}));
        set("force_factor",50);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/hat")->wear();
        
}       
